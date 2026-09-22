#ifndef STD_I_H
#define STD_I_H

#include "i_base_input.h"
#include <iostream>
#include <limits>
#include <iostream>
/**
 * @brief Наследник для работы со стандартным потоком ввода
 * 
 */
class std_i final: public i_base_input 
{
public:
    bool get_data(std::array<double, stream_over_flag::arr_len>& to_get,  size_t & elem_was_added) override;
    std_i() = default;
    ~std_i() = default;
};

#endif /* STD_I_H */