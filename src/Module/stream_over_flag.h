#ifndef STR_OVER_F_H
#define STR_OVER_F_H

#include <stddef.h>


struct stream_over_flag {
    static constexpr size_t arr_len = 1024;    
    protected:
    static bool stream_over; 
    stream_over_flag() = default;
};

#endif /* STR_OVER_F_H */