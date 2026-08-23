/**
 * @file eye_firmware.ino
 * @brief 6 CW/CCW Vein Phase Control, Graded Honeycomb Focusing,
 *        and Universal Puck Interface Management
 * @status: SYSTEM FREEZE ACTIVE -- HARDWARE DEPENDENCY LOCK ENFORCED
 * @3-6-9: 9mm→6mm→3mm graded honeycomb, 18° CW/CCW veins, 6 pins at 60°
 */

#include <Arduino.h>
#include <SPI.h>

// ============================================================================
// 3-6-9 HARMONIC CONSTANTS
// ============================================================================
#define BASE_CLOCK_HZ 70.47f
#define MODULATION_CLOCK_HZ 634.23f      // 9 × 70.47 Hz
#define NUM_VEINS 6
#define VEIN_ANGLE_DEG 18.0f
#define PIN_COUNT 6
#define PIN_SPACING_DEG 60.0f
#define PHASE_MAX 16384                  // 14-bit DDS resolution
#define PRE_STRESS_MPA 15.0f

// Graded Honeycomb Apertures
#define APERTURE_OUTER_MM 9.0f
#define APERTURE_MID_MM 6.0f
#define APERTURE_INNER_MM 3.0f

// ============================================================================
// PIN DEFINITIONS
// ============================================================================
// AD9959 DDS SPI Bus (12 Channels: 6 CW + 6 CCW)
#define DDS_CS    5
#define DDS_SCK   18
#define DDS_SDI   23
#define DDS_SDO   19
#define DDS_UPDATE 4
#define DDS_RESET 2

// Puck Interface Pins (6 pins at 60° spacing)
const int puck_pins[PIN
