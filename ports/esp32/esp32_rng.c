#include "esp32_rng.h"
#include "esp_system.h"

// Wrapper function for esp_random()
mp_obj_t esp32_rng_get_random_obj(void) {
    return mp_obj_new_int(esp_random());
}
MP_DEFINE_CONST_FUN_OBJ_0(esp32_rng_get_random, esp32_rng_get_random_obj);
