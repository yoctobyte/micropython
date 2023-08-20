#ifndef ESP32_RNG_H
#define ESP32_RNG_H

#include "py/obj.h"
#include "py/runtime.h"


// Function prototype for the RNG function
mp_obj_t esp32_rng_get_random_obj(void);

extern const mp_obj_fun_builtin_fixed_t esp32_rng_get_random;


#endif // ESP32_RNG_H
