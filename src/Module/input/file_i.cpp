#include "file_i.h"

bool file_i::get_data(std::array<double, arr_len> &to_get, size_t &elem_was_added) {
    elem_was_added = 0;

    // Читаем из stream_ вместо std::cin
    while (elem_was_added < arr_len && stream_ >> to_get[elem_was_added]) {
        ++elem_was_added;
    }

    if (elem_was_added == arr_len) {
        // Проверяем, есть ли дальше данные, не сдвигая указатель безвозвратно
        stream_ >> std::ws; 
        if (stream_.peek() != EOF) {
            return false; // в файле еще есть данные
        }
    }
  
    // Очистка и пропуск остатка строки (как в вашем исходном коде)
    if (stream_ >> std::ws) {
        stream_.clear();
        stream_.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    stream_over = true;
    return false;
}

file_i::file_i(const std::string &file_name) {
  stream_.open(file_name);
  if (!stream_) {
    // В C++ ifstream не всегда выставляет errno, но на Linux при неудачном
    // open() errno валиден
    int error_code = errno;
    throw std::runtime_error("Failed to open file '" + file_name +
                             "': " + std::strerror(error_code));
  }
}