#include "template.h"

void pico_led_init(void) {
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
}

void pico_set_led(bool led_on) {
    gpio_put(25, led_on);
}