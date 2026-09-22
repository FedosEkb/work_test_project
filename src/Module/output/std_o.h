#ifndef STD_O_H
#define STD_O_H

#include "i_base_output.h"
#include <iostream>
#include <limits>
/**
 * @brief Наследник для работы со стандартным потоком вывода
 * 
 */
class std_o final: public i_base_output
{
    
public:
    bool set_data(const std::array<double, stream_over_flag::arr_len>& to_set, size_t elem_to_print) override;
    std_o() = default;
    ~std_o() = default;
};

#endif /* STD_O_H */