/**
 * @file i_base_output.h
 * @author Baranov (you@domain.com)
 * @brief Интерфейс для записи
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef I_BASE_OUTPUT_H
#define I_BASE_OUTPUT_H

#include <array>
#include "../stream_over_flag.h"
/**
 * @brief Чисто виртуальный класс для передачи данных
 * 
 */
class i_base_output : protected stream_over_flag
{
    public:
   
    /**
     * @brief Запись данных
     * 
     * @param to_set контейнер задля записи
     * @param elem_to_print количество элементов для записи в контейнере
     * @return true была произведена последняя запись 
     * @return false запись не закончина
     */
    virtual bool set_data(const std::array<double, stream_over_flag::arr_len> & to_set, size_t elem_to_print) = 0;

    i_base_output() = default;
    virtual ~i_base_output() = default;

    // Данная логика не заложена, так что отключим
    i_base_output(const i_base_output&) = delete;
    i_base_output& operator=(const i_base_output&) = delete;
    
    i_base_output(i_base_output&&) = delete;
    i_base_output& operator=(i_base_output&&) = delete;
};

#endif /* I_BASE_OUTPUT_H */