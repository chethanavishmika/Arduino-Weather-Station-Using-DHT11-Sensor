#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <avr/pgmspace.h>

#ifdef __cplusplus
extern "C" {
#endif

// 12x16 px thermometer icon (temperature)
extern const uint8_t thermometerIcon[] PROGMEM;

// 12x16 px water-droplet icon (humidity)
extern const uint8_t dropletIcon[] PROGMEM;

#ifdef __cplusplus
}
#endif

#endif // GRAPHICS_H
