/**
 * @file i_base_input.h
 * @author Baranov (you@domain.com)
 * @brief Иyтерфейс для чтения
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I_BASE_INPUT_H
#define I_BASE_INPUT_H

#include <array>
#include <cstddef>
#include "cstddef"
#include "../stream_over_flag.h"
/**
 * @brief Чисто виртуальный класс для приема данных
 * 
 */
class i_base_input : protected stream_over_flag
{
    public:
    
    /**
     * @brief Get the data object
     * 
     * @param to_get кнонтейнер для приема данных  
     * @return всегда false
     */
    virtual bool get_data(std::array<double, stream_over_flag::arr_len> & to_get, size_t & elem_was_added) noexcept = 0;


    i_base_input() = default;
    virtual ~i_base_input() = default;

    // Данная логика не заложена, так что отключим
    i_base_input(const i_base_input&) = delete;
    i_base_input& operator=(const i_base_input&) = delete;
    
    i_base_input(i_base_input&&) = delete;
    i_base_input& operator=(i_base_input&&) = delete;
};

#endif /* I_BASE_INPUT_H */