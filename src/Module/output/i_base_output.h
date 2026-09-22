#ifndef I_BASE_OUTPUT_H
#define I_BASE_OUTPUT_H

#include <array>
#include "../stream_over_flag.h"
/**
 * @brief Чисто виртуальный класс для передпчи данных
 * 
 */
class i_base_output : protected stream_over_flag
{
    public:
   
    /**
     * @brief Get the data object
     * 
     * @param to_get кнонтейнер для приема данных  
     * @return true во входной сущности больше нет данных;
     * @return false во входной сущности еще остались данные;
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