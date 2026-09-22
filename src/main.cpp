#include "main.h"
#include "Module/input/std_i.h"
#include "Module/output/std_o.h"
#include <cassert>
#include <cstddef>

using json = nlohmann::json; // TODO Выкинуть в json

int main(int argc, char **argv) {

  input_param param;
  if(int parse_res = parse_input(argc, argv, param)){
    if(parse_res == -1){
      return 0; // пользователь запросил справку и получил ее
    }
    return 1; // ошибка парсинга
  }

  std::unique_ptr<i_base_input> input = nullptr;
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

  std::unique_ptr<i_base_output> output = nullptr;
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

  if(input && output){
    while (true) {
      std::array<double , stream_over_flag::arr_len> temp; 
      size_t number_was_got;
      input->get_data(temp, number_was_got);
      if(output->set_data(temp, number_was_got)){
        break;
      }
    }
  } else {
      assert(false && "Не удалось породить классы для работы с вводом/выводом\n");
      return 44;
  }
  

#define DEBUG_INFO
#ifdef DEBUG_INFO
  switch (param.in_type) {
  case io_type::std:
    std::cout << "std\n";
    break;
  case io_type::json:
    std::cout << "json " << param.input << '\n';
    break;
  case io_type::file:
    std::cout << "file " << param.input << '\n';
    break;
  }
    switch (param.out_type) {
  case io_type::std:
    std::cout << "std\n";
    break;
  case io_type::json:
    std::cout << "json " << param.output << '\n';
    break;
  case io_type::file:
    std::cout << "file " << param.output << '\n';
    break;
  }
  //std::cout <<  temp.size() << '\n';
#endif /* DEBUG_INFO */

  return 0;
}

std::string get_string(std::istream &in_stream) {
  std::string to_ret = {std::istreambuf_iterator<char>(in_stream),
                        std::istreambuf_iterator<char>()};
  return to_ret;
}

int parse_input(int argc, char **argv, input_param &param) {
  CLI::App app{"Программа последовательность вещественных (разделенныъ "
               "пробельными символами) чисел из одного потока в другой. "
               "Последовательность должна быть терминированна EOF."};

  // --- ГРУППА ДЛЯ ВВОДА ---
  auto input_group = app.add_option_group("input", "Тип ввода.");

  auto opt_std = input_group->add_flag("--i_std", [&param](std::int64_t count) {
    if (count > 0) param.in_type = io_type::std;
  }, "брать данные из нулевого потока. Значение по умолчанию");
  
  auto opt_file = input_group->add_option("--i_file", param.input, "брать данные из файла")
    ->each([&param](const std::string&) { param.in_type = io_type::file; });
  
  auto opt_json = input_group->add_option("--i_json", param.input, "брать данные из json")
    ->each([&param](const std::string&) { param.in_type = io_type::json; });
 
  input_group->require_option(0, 1);


  // --- ГРУППА ДЛЯ ВЫВОДА ---
  auto output_group = app.add_option_group("output", "Тип вывода.");

    auto opt_std_o = output_group->add_flag("--o_std", [&param](std::int64_t count) {
    if (count > 0) param.out_type = io_type::std;
  }, "выводить данные в первый поток. Значение по умолчанию");
    
  auto opt_file_o = output_group->add_option("--o_file", param.output, "выводить данные в файл")
    ->each([&param](const std::string&) { param.out_type = io_type::file; });
  
  auto opt_json_o = output_group->add_option("--o_json", param.output, "выводить данные в json")
    ->each([&param](const std::string&) { param.out_type = io_type::json; });
 
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
  if (opt_std->count() == 0 && opt_file->count() == 0 && opt_json->count() == 0) {
    param.in_type = io_type::std;
  }
  // Если в группу вывода ничего не передали, выставляем дефолт
  if (opt_std_o->count() == 0 && opt_file_o->count() == 0 && opt_json_o->count() == 0) {
    param.out_type = io_type::std;
  }

  return 0;
}


