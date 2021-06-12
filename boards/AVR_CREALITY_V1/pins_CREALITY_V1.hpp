/**
 * @brief a pins configuration file for a Creality V1 OAT.
 */

#pragma once

#ifndef RA_STEP_PIN
  #define RA_STEP_PIN 1  // Z - STEP
#endif
#ifndef RA_DIR_PIN
  #define RA_DIR_PIN  0  // Z - DIR
#endif
#ifndef RA_EN_PIN
  #define RA_EN_PIN   14  // Z - EN
#endif

#ifndef DEC_STEP_PIN
  #define DEC_STEP_PIN 22  // Y - STEP
#endif
#ifndef DEC_DIR_PIN
  #define DEC_DIR_PIN  23  // Y - DIR
#endif
#ifndef DEC_EN_PIN
  #define DEC_EN_PIN   14  // Y - EN
#endif

//Pin to turn on dew heater MOSFET
#ifndef DEW_HEATER_PIN
  #define DEW_HEATER_PIN 12
#endif

#define SW_SERIAL_UART 0