#ifndef FILE_O_H
#define FILE_O_H

#include "i_base_output.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <stdexcept>
#include <cerrno>
#include <cstring>
#include <cstddef>
#include <string>

/**
 * @brief Наследник для работы со стандартным потоком вывода
 * 
 */
class file_o final: public i_base_output
{
    std::ofstream stream_;
public:
    bool set_data(const std::array<double, stream_over_flag::arr_len>& to_set, size_t elem_to_print) override;
    file_o(const std::string& file_name);
    ~file_o() = default;
};

#endif /* FILE_O_H */