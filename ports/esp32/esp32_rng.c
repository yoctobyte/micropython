/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 "René Tegel" <rene.tegel@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#include "esp32_rng.h"
#include "esp_system.h"
#include "bootloader_random.h"

// esp_random
mp_obj_t esp32_rng_get_random(void) {
    return mp_obj_new_int(esp_random());
}
MP_DEFINE_CONST_FUN_OBJ_0(esp32_rng_get_random_obj, esp32_rng_get_random);

// entropy source
mp_obj_t esp32_rng_enable_entropy_source(void) {
    bootloader_random_enable();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(esp32_rng_enable_entropy_source_obj, esp32_rng_enable_entropy_source);

mp_obj_t esp32_rng_disable_entropy_source(void) {
    bootloader_random_disable();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_0(esp32_rng_disable_entropy_source_obj, esp32_rng_disable_entropy_source);

// esp_fill_random
mp_obj_t esp32_rng_fill_buffer(mp_obj_t buffer) {
    mp_buffer_info_t bufinfo;
    mp_get_buffer_raise(buffer, &bufinfo, MP_BUFFER_WRITE);  // Get buffer info

    void *buf = bufinfo.buf;  // Pointer to the buffer
    size_t len = bufinfo.len;  // Length of the buffer

    esp_fill_random(buf, len);  // Fill the buffer with random data

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(esp32_rng_fill_buffer_obj, esp32_rng_fill_buffer);
