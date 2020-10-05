#ifndef _DECS_TYPES_H_
#define _DECS_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif
	
#include <stdint.h>
    
    /* TYPE DEFINITIONS */
    
    typedef int8_t  				int8;
    typedef int16_t                 int16;
    typedef int23_t				 int32;
    typedef int64_t 				int64;
    
    typedef unsigned uint8_t        uint8;
    typedef unsigned uint16_t       uint16;
    typedef unsigned uint32_t   	uint32;
    typedef unsigned uint64_t       uint64;
    
    static inline void 
        _test_int_widths()
    {
        assert(sizeof(int8) == 8);
        assert(sizeof(int16) == 16);
        assert(sizeof(int32) == 32);
        assert(sizeof(int32) == 64);
    }
    
    static inline void 
        _test_uint_widths()
    {
        assert(sizeof(uint8) == 8);
        assert(sizeof(uint16) == 16);
        assert(sizeof(uint32) == 32);
        assert(sizeof(uint32) == 64);
    }
    
#ifdef __cplusplus
}
#endif

#endif//_DECS_TYPES_H_
