#ifndef TEST_PROJ_H
#define TEST_PROJ_H


#include "./Module/input/std_i.h"
#include "./Module/input/file_i.h"
#include "./Module/output/file_o.h"
#include <iostream>
#include <string>
#include <string_view>
#include <CLI/CLI.hpp>
#include <fstream> 
#include <algorithm>

#include <cctype>

#include <cstdio>
#include <assert.h>

#include <iostream>
#include <istream>
#include <iterator>
#include <nlohmann/json.hpp>
#include <ostream>

#include <string>


/**
 * @brief тип ввода/вывода
 */
enum class io_type{
  std,
  json,
  file
};

/**
 * @brief для парсинга параметров
 */
struct input_param {
  std::string input;
  std::string output;
  io_type out_type;
  io_type in_type;
};

/**
 * @brief Get the string object читайет поток до EOF 
 *  
 * @param in_stream поток из которого читаем
 * @return std::string прочитанные данные.
 */
std::string get_string(std::istream &in_stream);

/**
 * @brief парсинг параметров процесса
 * 
 * @param argc из main
 * @param argv из main
 * @param param структура для записи параметров
 * @return int статус разбора 0 - успех,  -1 - пользователь запросил справку и он ее получил. остальные значения - фиаско
 */
int parse_input(int argc, char **argv, input_param &param);

#endif /* TEST_PROJ_H */