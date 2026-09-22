#ifndef TEST_PROJ_H
#define TEST_PROJ_H

#include "./Module/input/std_i.h"
#include "./Module/input/file_i.h"
#include "Module/output/std_o.h"
#include "./Module/output/file_o.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <CLI/CLI.hpp>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <string>


/**
 * @brief тип ввода/вывода
 */
enum class io_type{
  std,
  file
};

/**
 * @brief для парсинга параметров
 */
struct input_param {
  std::string input;  //!< имя файла для считывания 
  std::string output; //!< имя файла для записи
  io_type out_type;   
  io_type in_type;
};


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