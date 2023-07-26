#include "jdprofile.h"
#include "jacdac/dist/c/relay.h"

FIRMWARE_IDENTIFIER(0x3412171b, "Breakout Board+Servo+Pump");

const servo_params_t servo_0 = {
    .pin = PA_6,
    .fixed = 0,
    .min_angle = -90 << 16,
    .min_pulse = 600,
    .max_angle = 90 << 16,
    .max_pulse = 2500,
    .power_pin = PB_7
};

const servo_params_t servo_1 = {
    .pin = PA_7,
    .fixed = 0,
    .min_angle = -90 << 16,
    .min_pulse = 600,
    .max_angle = 90 << 16,
    .max_pulse = 2500,
    .power_pin = PC_15
};

const servo_params_t servo_2 = {
    .pin = PA_4,
    .fixed = 0,
    .min_angle = -90 << 16,
    .min_pulse = 600,
    .max_angle = 90 << 16,
    .max_pulse = 2500,
    .power_pin = PC_15
    //NO_PIN
};    

const relay_params_t hi_power = {
    .relay_variant = JD_RELAY_VARIANT_ELECTROMECHANICAL,
    .max_switching_current = 20,
    .pin_relay_drive = PA_0,
    .pin_relay_feedback = NO_PIN,
    .pin_relay_led = NO_PIN,
    .drive_active_lo = false,
    .led_active_lo = false,
    .initial_state = false
};

void app_init_services() {
    // high power mode when we get there
    
    servo_init(&servo_0);
    servo_init(&servo_1);
    servo_init(&servo_2);
    relay_service_init(&hi_power);
}

const char *app_get_instance_name(int service_idx) {
    switch (service_idx) {
    case 1:
        return "Left";
    case 2:
        return "Middle";
    case 3:
        return "Right";
    case 4:
        return "Pump";
    }
    return NULL;
}