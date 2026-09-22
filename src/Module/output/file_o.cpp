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
  // Записываем переданные элементы в файл
  for (size_t i = 0; i < elem_to_print; ++i) {
    stream_ << to_set[i] << ' ';
  }

  // stream_over доступен напрямую, так как file_o наследуется от предка
  if (stream_over) {
    stream_ << '\n';
    
    // Принудительно выталкиваем буфер на диск, так как это финальный аккорд записи
    stream_.flush(); 
    return true;
  }
  
  // Проверяем, не переполнился ли диск и не отвалился ли носитель в процессе работы
  if (!stream_) {
      throw std::runtime_error("Critical error: breakdown or out of space while writing to file.");
  }
  return false;
}
