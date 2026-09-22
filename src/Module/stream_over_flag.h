/**
 * @file stream_over_flag.h
 * @author Baranov (you@domain.com)
 * @brief Флаг конца потока и длинна для std::arr  
 * @version 0.1
 * @date 2026-09-22
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#ifndef STR_OVER_F_H
#define STR_OVER_F_H

#include <cstddef>


struct stream_over_flag {
    static constexpr size_t arr_len = 1024;    
    protected:
    static bool stream_over;  //!< признак замерфыения потока
    stream_over_flag() = default;
};

#endif /* STR_OVER_F_H */