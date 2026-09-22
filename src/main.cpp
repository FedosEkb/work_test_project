#include "main.h"

int main(int argc, char **argv) {
  input_param param;
  if(int parse_res = parse_input(argc, argv, param)){
    if(parse_res == -1){
      return 0; // пользователь запросил справку и получил ее
    }
    return 1; // ошибка парсинга
  }

  std::unique_ptr<i_base_input> input = nullptr;
  std::unique_ptr<i_base_output> output = nullptr;

  try {
    switch (param.in_type) {
    case io_type::std:
      input = std::make_unique<std_i>();
    break;
    case io_type::file:
      input = std::make_unique<file_i>(param.input);
    break;
    default:
      assert(false && "Параметры были обработаны некорректно.\n"); // NOTE тут проще перенаправлять потоки, ну пусть будет так для примера
      return 42;
  }
  switch (param.out_type) {
    case io_type::std:
      output = std::make_unique<std_o>();
    break;
    case io_type::file:
      output = std::make_unique<file_o>(param.output);
    break;
    default:
      assert(false && "Параметры были обработаны некорректно.\n"); // NOTE тут проще перенаправлять потоки, ну пусть будет так для примера
      return 43;
  }
  } catch (const std::exception& e) {
    std::cerr << "Критическая ошибка: " << e.what() << std::endl;
    return 1;
  }

  if(input && output){
    while (true) {
      std::array<double , stream_over_flag::arr_len> temp; 
      size_t number_was_got;
      input->get_data(temp, number_was_got);
      
      //  NOTE тут можно опереировать полученными данными

      try {
        if (output->set_data(temp, number_was_got)) {
          break;
        }
      } catch (const std::exception &e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
      }
    }
  } else {
    assert(false && "Не удалось породить классы для работы с вводом/выводом\n");
    return 44;
  }
  return 0;
}

int parse_input(int argc, char **argv, input_param &param) {
  CLI::App app{"Программа переправляет последовательность вещественных (разделённых "
               "пробельными символами) чисел из одного потока в другой. "
               "Последовательность должна быть терминирована EOF или любым "
               "символом, который не может быть распознан как часть числа. "};

  // группа для ввода
  auto input_group = app.add_option_group("input", "Тип ввода.");

  auto opt_std = input_group->add_flag("--i_std", [&param](std::int64_t count) {
    if (count > 0) param.in_type = io_type::std;
  }, "считать данные из нулевого потока. Значение по умолчанию");
  
  auto opt_file = input_group->add_option("--i_file", param.input, "считать данные из файла")
    ->each([&param](const std::string&) { param.in_type = io_type::file; });
 
  input_group->require_option(0, 1);


  // группа для вывода
  auto output_group = app.add_option_group("output", "Тип вывода.");

    auto opt_std_o = output_group->add_flag("--o_std", [&param](std::int64_t count) {
    if (count > 0) param.out_type = io_type::std;
  }, "выводить данные в первый поток. Значение по умолчанию");
    
  auto opt_file_o = output_group->add_option("--o_file", param.output, "выводить данные в файл")
    ->each([&param](const std::string&) { param.out_type = io_type::file; });

  output_group->require_option(0, 1);

  // Парсинг аргументов
  try {
    app.parse(argc, argv);
  } catch (const CLI::ParseError &e) {
    int exit_code = app.exit(e);
    if (exit_code == 0) {
      return -1; // Был вызван --help, завершаем работу корректно
    }
    return exit_code;
  }

  if (param.input == param.output && param.input.size()) {
    std::cerr << "Ввод и вывод в один и тот же файл не поддерживается.\n";
    return 42;
  }

  // Если в группу ввода ничего не передали, выставляем дефолт
  if (opt_std->count() == 0 && opt_file->count() == 0 ) {
    param.in_type = io_type::std;
  }
  // Если в группу вывода ничего не передали, выставляем дефолт
  if (opt_std_o->count() == 0 && opt_file_o->count() == 0) {
    param.out_type = io_type::std;
  }

  return 0;
}


