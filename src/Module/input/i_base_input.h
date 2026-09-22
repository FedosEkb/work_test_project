#ifndef I_BASE_INPUT_H
#define I_BASE_INPUT_H

#include <array>
#include <cstddef>
#include "stddef.h"
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
     * @return true во входной сущности больше нет данных;
     * @return false во входной сущности еще остались данные;
     */
    virtual bool get_data(std::array<double, stream_over_flag::arr_len> & to_get, size_t & elem_was_added) = 0;

    i_base_input() = default;
    virtual ~i_base_input() = default;

    // Данная логика не заложена, так что отключим
    i_base_input(const i_base_input&) = delete;
    i_base_input& operator=(const i_base_input&) = delete;
    
    i_base_input(i_base_input&&) = delete;
    i_base_input& operator=(i_base_input&&) = delete;
};

#endif /* I_BASE_INPUT_H */