/**
 * @file std_i.h
 * @author Baranov (you@domain.com)
 * @brief Реализация для работы с нулевым потоком
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */

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

    /**
     * @brief Get the data object
     * 
     * @param to_get кнонтейнер для приема данных  
     * @return всегда false
     */
    bool get_data(std::array<double, stream_over_flag::arr_len>& to_get,  size_t & elem_was_added) noexcept override;
    std_i() = default;
    ~std_i() = default;
};

#endif /* STD_I_H */