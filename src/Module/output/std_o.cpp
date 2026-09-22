#include "std_o.h"
#include <cstddef>
#include <iostream>

bool std_o::set_data(const std::array<double, stream_over_flag::arr_len> &to_set,
                      size_t elem_to_print) {
  for (size_t i = 0; i < elem_to_print; ++i) {
    std::cout  << to_set[i] << ' ';
  }
  if (stream_over) {
    std::cout << '\n';
    return true;
  }
  return false;
}
