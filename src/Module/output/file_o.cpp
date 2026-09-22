// #include "file_o.h"






// file_o::file_o(const std::string& file_name) {
//     // std::ios::out — открытие на запись (по умолчанию перезаписывает файл)
//     stream_.open(file_name, std::ios::out);
    
//     if (!stream_) {
//         // На Linux при неудачном открытии через fstream переменная errno сохраняет системную причину
//         int error_code = errno;
//         throw std::runtime_error("Failed to open file for writing '" + file_name + 
//                                 "': " + std::strerror(error_code));
//     }
// }

// bool file_o::set_data(const std::array<double, stream_over_flag::arr_len> &to_set,
//                       size_t elem_to_print) {
//   for (size_t i = 0; i < elem_to_print; ++i) {
//     std::cout  << to_set[i] << ' ';
//   }
//   if (stream_over) {
//     std::cout << '\n';
//     return true;
//   }
//   return false;
// }