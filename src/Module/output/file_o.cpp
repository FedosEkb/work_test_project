#include "file_o.h"

file_o::file_o(const std::string& file_name) {
    
    stream_.open(file_name, std::ios::out); 
    
    if (!stream_) {
        int error_code = errno;
        throw std::runtime_error("Failed to open file for writing '" + file_name + 
                                "': " + std::strerror(error_code));
    }
}

bool file_o::set_data(const std::array<double, stream_over_flag::arr_len> &to_set,
                      size_t elem_to_print) {
  
  for (size_t i = 0; i < elem_to_print; ++i) {
    stream_ << to_set[i] << ' ';
  }

  if (!stream_) {
    throw std::runtime_error(
        "Critical error: breakdown or out of space while writing to file.");
  }

  if (stream_over) {
    stream_ << '\n';
    stream_.flush(); // NOTE Принудительно выталкиваем буфер на диск
    return true;
  }
    

  return false;
}
