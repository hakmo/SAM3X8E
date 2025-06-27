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
#define BOARD_URL "https://shop.eccentricworkshop.com/products/grblduino-mega-shield-v1-1"

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

// Define auxiliary output pins
// #define AUXOUTPUT0_PORT     PIO
// #define AUXOUTPUT0_PIN      
// #define AUXOUTPUT1_PORT     PIO
// #define AUXOUTPUT1_PIN      
#define AUXOUTPUT2_PORT     PIOC // Spindle PWM, Due Digital Pin 7 / PWML6 B
#define AUXOUTPUT2_PIN      23
#define AUXOUTPUT3_PORT     PIOC // Spindle direction, Due Digital Pin 5
#define AUXOUTPUT3_PIN      25
#define AUXOUTPUT4_PORT     PIOC // Spindle enable, Due Digital Pin 6
#define AUXOUTPUT4_PIN      24
#define AUXOUTPUT5_PORT     PIOC // Coolant flood, Due Digital Pin 8
#define AUXOUTPUT5_PIN      22
#define AUXOUTPUT6_PORT     PIOC // Coolant mist, Due Digital Pin 9
#define AUXOUTPUT6_PIN      21

// Define driver spindle pins

#if DRIVER_SPINDLE_PWM_ENABLE
#define SPINDLE_PWM_CHANNEL     6
#define SPINDLE_PWM_PORT        AUXOUTPUT2_PORT
#define SPINDLE_PWM_PIN         AUXOUTPUT2_PIN
#endif

#if DRIVER_SPINDLE_DIR_ENABLE
#define SPINDLE_DIRECTION_PORT  AUXOUTPUT3_PORT
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT3_PIN
#endif

#if DRIVER_SPINDLE_ENABLE
#define SPINDLE_ENABLE_PORT     AUXOUTPUT4_PORT
#define SPINDLE_ENABLE_PIN      AUXOUTPUT4_PIN
#endif

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT  AUXOUTPUT5_PORT
#define COOLANT_FLOOD_PIN   AUXOUTPUT5_PIN
#define COOLANT_MIST_PORT   AUXOUTPUT6_PORT
#define COOLANT_MIST_PIN    AUXOUTPUT6_PIN

#define AUXINPUT0_PORT      PIOB // Probe
#define AUXINPUT0_PIN       20   // Due Analog Pin 11
#define AUXINPUT1_PORT      PIOA // Safety door
#define AUXINPUT1_PIN       11   // Due Digital Pin 18
// #define AUXINPUT2_PORT      PIO
// #define AUXINPUT2_PIN       
// #define AUXINPUT3_PORT      PIO 
// #define AUXINPUT3_PIN       
#define AUXINPUT4_PORT      PIOB // Reset/EStop
#define AUXINPUT4_PIN       17   // Due Analog Pin 8
#define AUXINPUT5_PORT      PIOB // Feed hold
#define AUXINPUT5_PIN       18   // Due Analog Pin 9
#define AUXINPUT6_PORT      PIOB // Cycle start
#define AUXINPUT6_PIN       19   // Due Analog Pin 10

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
#if CONTROL_ENABLE & CONTROL_HALT
#define RESET_PORT          AUXINPUT4_PORT
#define RESET_PIN           AUXINPUT4_PIN
#endif
#if CONTROL_ENABLE & CONTROL_FEED_HOLD
#define FEED_HOLD_PORT      AUXINPUT5_PORT
#define FEED_HOLD_PIN       AUXINPUT5_PIN
#endif
#if CONTROL_ENABLE & CONTROL_CYCLE_START
#define CYCLE_START_PORT    AUXINPUT6_PORT
#define CYCLE_START_PIN     AUXINPUT6_PIN
#endif

#if PROBE_ENABLE
#define PROBE_PORT          AUXINPUT0_PORT
#define PROBE_PIN           AUXINPUT0_PIN
#endif

#if SAFETY_DOOR_ENABLE
#define SAFETY_DOOR_PORT    AUXINPUT1_PORT
#define SAFETY_DOOR_PIN     AUXINPUT1_PIN
#elif MOTOR_FAULT_ENABLE
#define MOTOR_FAULT_PORT    AUXINPUT0_PORT
#define MOTOR_FAULT_PIN     AUXINPUT0_PIN
#elif MOTOR_WARNING_ENABLE
#define MOTOR_WARNING_PORT  AUXINPUT0_PORT
#define MOTOR_WARNING_PIN   AUXINPUT0_PIN
#endif

/**/
