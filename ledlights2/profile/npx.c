#include "jdprofile.h"
#include "jacdac/dist/c/led.h"

FIRMWARE_IDENTIFIER(0x3ed2e79f, "LED Lights 2");

void app_init_services() {
    leddisplay_init(LIGHT_TYPE_WS2812B_GRB, 8, 200, JD_LED_VARIANT_RING);
}
