#ifndef ESP32_RNG_H
#define ESP32_RNG_H

#include "py/obj.h"
#include "py/runtime.h"

mp_obj_t esp32_rng_get_random(void);
extern const mp_obj_fun_builtin_fixed_t esp32_rng_get_random_obj;

mp_obj_t esp32_rng_enable_entropy_source(void);
extern const mp_obj_fun_builtin_fixed_t esp32_rng_enable_entropy_source_obj;

mp_obj_t esp32_rng_disable_entropy_source(void);
extern const mp_obj_fun_builtin_fixed_t esp32_rng_disable_entropy_source_obj;

mp_obj_t esp32_rng_fill_buffer(mp_obj_t buffer);
extern const mp_obj_fun_builtin_fixed_t esp32_rng_fill_buffer_obj;

#endif // ESP32_RNG_H
