/**
 * @file std_i.cpp
 * @author your name (you@domain.com)
 * @brief Реалтизация работы со стондартным вводом
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "std_i.h"


bool std_i::get_data(std::array<double, stream_over_flag::arr_len> &to_get,
                      size_t &elem_was_added) {
  elem_was_added = 0;
  while (elem_was_added < arr_len && std::cin >> to_get[elem_was_added]) {
    ++elem_was_added;
  }

  if (elem_was_added == arr_len) {
    return false; // в потоке еще могут быть данные.
  }
    
  if (std::cin >> std::ws) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  stream_over = true;
    
  return false;
}

