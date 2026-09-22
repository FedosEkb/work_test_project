#ifndef FILE_I_H
#define FILE_I_H

#include "i_base_input.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <cstring>
/**
 * @brief Наследник для работы со стандартным потоком ввода
 * 
 */
class file_i final: public i_base_input 
{
    std::ifstream stream_; 
public:
    bool get_data(std::array<double, stream_over_flag::arr_len>& to_get,  size_t & elem_was_added) override;
    explicit file_i(const std::string& file_name);
    ~file_i() = default;
};

#endif /* FILE_I_H */