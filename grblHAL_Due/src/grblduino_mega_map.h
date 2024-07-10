/*
  grblduino_mega_map.h - driver code for Atmel SAM3X8E ARM processor, pin mappings compatible with GRBLDuino Mega
  https://shop.eccentricworkshop.com/product/grblduino-mega-shield-v1/?v=7516fd43adaa
  https://forum.eccentricworkshop.com/viewtopic.php?f=4&t=10

  Part of grblHAL

  Copyright (c) 2019-2023 hakmo

  Mappings according to https://forum.eccentricworkshop.com/viewtopic.php?f=4&t=10

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  grblHAL with Grbl. If not, see <http://www.gnu.org/licenses/>.
*/


#if (N_AUTO_SQUARED && N_AUTO_SQUARED < N_ABC_MOTORS) || N_ABC_MOTORS > 3
#error "Axis configuration is not supported!"
#endif

#define BOARD_NAME "GRBLDuino Mega"
#define BOARD_URL "https://shop.eccentricworkshop.com/product/grblduino-mega-shield-v1/?v=7516fd43adaa"

 // Define step pulse output pins.
#define X_STEP_PORT         PIOA
#define X_STEP_PIN          15  // Due Digital Pin 24
#define Y_STEP_PORT         PIOD
#define Y_STEP_PIN          0   // Due Digital Pin 25
#define Z_STEP_PORT         PIOD
#define Z_STEP_PIN          1   // Due Digital Pin 26

// Define step direction output pins.
#define X_DIRECTION_PORT    PIOD
#define X_DIRECTION_PIN     9   // Due Digital Pin 30
#define Y_DIRECTION_PORT    PIOA
#define Y_DIRECTION_PIN     7   // Due Digital Pin 31
#define Z_DIRECTION_PORT    PIOD
#define Z_DIRECTION_PIN     10  // Due Digital Pin 32

// Define stepper driver enable/disable output pin(s).
#define X_ENABLE_PORT       PIOB
#define X_ENABLE_PIN        27  // Due Digital Pin 13

/*
#define Y_ENABLE_PORT      PIOA
#define Y_ENABLE_PIN       23
#define Z_ENABLE_PORT      PIOB
#define Z_ENABLE_PIN       17

*/
// Define homing/hard limit switch input pins.
#define X_LIMIT_PORT        PIOC
#define X_LIMIT_PIN         29  // Due Digital Pin 10
#define Y_LIMIT_PORT        PIOD
#define Y_LIMIT_PIN         7   // Due Digital Pin 11
#define Z_LIMIT_PORT        PIOD
#define Z_LIMIT_PIN         8   // Due Digital Pin 12

// Define homing/hard limit switch max input pins.
#if X_AUTO_SQUARE
#define M3_LIMIT_PORT       PIOD
#define M3_LIMIT_PIN        5   // Due Digital Pin 15
#else
#define X_LIMIT_PORT_MAX    PIOD
#define X_LIMIT_PIN_MAX     5   // Due Digital Pin 15
#endif
#if Y_AUTO_SQUARE
#define M3_LIMIT_PORT       PIOA
#define M3_LIMIT_PIN        12  // Due Digital Pin 17
#else
#define Y_LIMIT_PORT_MAX    PIOA
#define Y_LIMIT_PIN_MAX     12  // Due Digital Pin 17
#endif
#if Z_AUTO_SQUARE
#define M3_LIMIT_PORT       PIOA
#define M3_LIMIT_PIN        10  // Due Digital Pin 19
#else
#define Z_LIMIT_PORT_MAX    PIOA
#define Z_LIMIT_PIN_MAX     10  // Due Digital Pin 19
#endif

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 0
#define M3_AVAILABLE
#define M3_STEP_PORT        PIOD
#define M3_STEP_PIN         2   // Due Digital Pin 27
#define M3_DIRECTION_PORT   PIOC
#define M3_DIRECTION_PIN    1   // Due Digital Pin 33
//#define M3_ENABLE_PORT      PIOC
//#define M3_ENABLE_PIN       1   // Due Digital Pin 33
#ifndef M3_LIMIT_PORT
#define M3_LIMIT_PORT       PIOB
#define M3_LIMIT_PIN        14  // Due Digital Pin 53
#endif
//#define M3_LIMIT_PORT_MAX   PIOA
//#define M3_LIMIT_PIN_MAX    4   // Due Analog Pin 5
#endif

// Define ganged axis or B axis step pulse and step direction output pins.
#if N_ABC_MOTORS > 1
#define M4_AVAILABLE
#define M4_STEP_PORT        PIOD
#define M4_STEP_PIN         3   // Due Digital Pin 28
#define M4_DIRECTION_PORT   PIOC
#define M4_DIRECTION_PIN    2   // Due Digital Pin 34
//#define M4_ENABLE_PORT      PIOC
//#define M4_ENABLE_PIN       7   // Due Digital Pin 39
#define M4_LIMIT_PORT       PIOB
#define M4_LIMIT_PIN        21  // Due Digital Pin 52
//#define M4_LIMIT_PORT_MAX   PIOA
//#define M4_LIMIT_PIN_MAX    2   // Due Analog Pin 7
#endif

// Define ganged axis or C axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 3
#define M5_AVAILABLE
#define M5_STEP_PORT        PIOD
#define M5_STEP_PIN         6   // Due Digital Pin 29
#define M5_DIRECTION_PORT   PIOC
#define M5_DIRECTION_PIN    3   // Due Digital Pin 35
//#define M5_ENABLE_PORT      PIOC
//#define M5_ENABLE_PIN       19  // Due Digital Pin 44
#define M5_LIMIT_PORT       PIOC
#define M5_LIMIT_PIN        12  // Due Digital Pin 51
//#define M5_LIMIT_PORT_MAX   PIOC
//#define M5_LIMIT_PIN_MAX    12  // Due Digital Pin 51
#endif

// Define driver spindle pins

#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_CHANNEL     6
#define SPINDLE_PWM_PORT        PIOC
#define SPINDLE_PWM_PIN         23 // Due Digital Pin 7 / PWML6 B
#else
#define AUXOUTPUT0_PORT         PIOC
#define AUXOUTPUT0_PIN          23
#endif

#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PORT  PIOC
#define SPINDLE_DIRECTION_PIN   25  // Due Digital Pin 5
#else
#define AUXOUTPUT1_PORT         PIOC
#define AUXOUTPUT1_PIN          25
#endif

#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PORT     PIOC
#define SPINDLE_ENABLE_PIN      24  // Due Digital Pin 6
#else
#define AUXOUTPUT2_PORT         PIOC
#define AUXOUTPUT2_PIN          24
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT  PIOC
#define COOLANT_FLOOD_PIN   22  // Due Digital Pin 8
#define COOLANT_MIST_PORT   PIOC
#define COOLANT_MIST_PIN    21  // Due Digital Pin 9

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
#define RESET_PORT          PIOB
#define RESET_PIN           17  // DUE Analog Pin 8
#define FEED_HOLD_PORT      PIOB
#define FEED_HOLD_PIN       18  // DUE Analog Pin 9
#define CYCLE_START_PORT    PIOB
#define CYCLE_START_PIN     19  // DUE Analog Pin 10

#define AUXINPUT0_PORT      PIOB
#define AUXINPUT0_PIN       20 // DUE Analog Pin 11
#define AUXINPUT1_PORT      PIOA
#define AUXINPUT1_PIN       0  // DUE Analog Pin CANTX

#if PROBE_ENABLE
#define PROBE_PORT          AUXINPUT1_PORT
#define PROBE_PIN           AUXINPUT1_PIN
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT    AUXINPUT0_PORT
#define SAFETY_DOOR_PIN     AUXINPUT0_PIN
#elif MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PORT    AUXINPUT0_PORT
#define MOTOR_FAULT_PIN     AUXINPUT0_PIN
#elif MOTOR_WARNING_ENABLE
#define MOTOR_WARNING_PORT  AUXINPUT0_PORT
#define MOTOR_WARNING_PIN   AUXINPUT0_PIN
#endif

/**/
