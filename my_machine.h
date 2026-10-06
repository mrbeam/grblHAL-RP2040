#ifndef MRBEAM_MY_MACHINE_H
#define MRBEAM_MY_MACHINE_H

/*
  my_machine.h - configuration for Raspberry RP2040 ARM processors

  Part of grblHAL

  Copyright (c) 2021-2026 Terje Io

  grblHAL is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grblHAL is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grblHAL. If not, see <http://www.gnu.org/licenses/>.
*/

// NOTE: Only one board may be enabled!
#define BOARD_MRBEAM
// If none is enabled pin mappings from generic_map.h will be used.
//#define BOARD_BOLANGSK //change PICO_BOARD to pimoroni_pga2350 in CMakeLists.txt for this to compile
//#define BOARD_BTT_SKR_PICO_10
//#define BOARD_BTT_SKR_PICO_10_HOTWIRE // Swaps spindle PWM and coolant outputs to utilize the bed heater (HB) output to control the hotwire. 
//#define BOARD_PICOBOB
//#define BOARD_PICOBOB_G540
//#define BOARD_PICOBOB_DLX
//#define BOARD_PICOBOB_DLX_G540
//#define BOARD_PICOHAL
//#define BOARD_PICO_CNC
//#define BOARD_RP23U5XBB
//#define BOARD_SLB_LITE
//#define BOARD_CNC_BOOSTERPACK
//#define BOARD_CITOH_CX6000    // C.ITOH CX-6000 HPGL plotter
//#define BOARD_GENERIC_4AXIS
//#define BOARD_GENERIC_8AXIS
//#define BOARD_MY_MACHINE      // Add my_machine_map.h before enabling this!

// Configuration
// Uncomment to enable.

#ifndef USB_SERIAL_CDC
#define USB_SERIAL_CDC          0 // Serial communication via native USB.
#endif
//#define BLUETOOTH_ENABLE        2 // Set to 2 for HC-05 module, enable in CMakeLists.txt if for Pico W Bluetooth.
// Spindle selection:
// Up to four specific spindle drivers can be instantiated at a time
// depending on N_SPINDLE and N_SYS_SPINDLE definitions in grbl/config.h.
// If none are specified the default PWM spindle is instantiated.
// Spindle definitions can be found in grbl/spindle_control.h.
// More here https://github.com/grblHAL/Plugins_spindle
//#define SPINDLE0_ENABLE         SPINDLE_HUANYANG1
//#define SPINDLE1_ENABLE         SPINDLE_PWM0
//#define SPINDLE2_ENABLE         SPINDLE_NONE 
//#define SPINDLE2_ENABLE         SPINDLE_NONE
//#define SPINDLE_OFFSET          1 // Set to 1 to add offset move when switching between laser and spindle
// **********************
//#define MODBUS_ENABLE           1 // Set to 1 for auto direction, 2 for direction signal on auxiliary output pin.
//#define WIFI_ENABLE             0 // Do NOT enable here, enable in CMakeLists.txt!
//#define WIFI_SOFTAP             1 // Use Soft AP mode for WiFi. NOTE: WIP - not yet complete!
//#define ETHERNET_ENABLE         0 // Do NOT enable here, enable in CMakeLists.txt!
//#define _WIZCHIP_            5500 // Selects WIZnet ethernet breakout connected via SPI.
                                    // Uncomment to enable W5500 chip, default is W5100S. Requires ethernet enabled in CMakeLists.txt.
//#define WEBUI_ENABLE            3 // Enable ESP3D-WEBUI plugin along with networking and SD card plugins. Requires WiFi enabled.
//#define WEBUI_AUTH_ENABLE       1 // Enable ESP3D-WEBUI authentication.
//#define WEBUI_INFLASH           0 // Uncomment to store WebUI files on SD card instead of in flash (littlefs).
//#define SDCARD_ENABLE           2 // Run gcode programs from SD card. Set to 2 to enable YModem upload.
//#define MPG_ENABLE              2 // Enable MPG interface. Requires a serial stream and means to switch between normal and MPG mode.
                                    // 1: Mode switching is by handshake pin.
                                    // 2: Mode switching is by the CMD_MPG_MODE_TOGGLE (0x8B) command character.
//#define KEYPAD_ENABLE           1 // 1: uses a I2C keypad for input.
                                    // 2: uses a serial stream for input. If MPG_ENABLE is set > 0 the serial stream is shared with the MPG.
//#define DISPLAY_ENABLE          9 // Set to 9 for I2C display protocol, 17 for I2C LED protocol.
//#define ODOMETER_ENABLE         1 // Odometer plugin.
//#define PLASMA_ENABLE           1 // Plasma (THC) plugin. To be completed.
//#define LASER_COOLANT_ENABLE    1 // Laser coolant plugin. To be completed.
//#define LASER_OVD_ENABLE        1 // Enable M-code for overdrive PWM output during spindle off in RPM controlled mode.
//#define LB_CLUSTERS_ENABLE      1 // LaserBurn cluster support.
//#define FANS_ENABLE             1 // Enable fan control via M106/M107. Activates fan plugin.
//#define EMBROIDERY_ENABLE       1 // Embroidery plugin. To be completed.
//#define TRINAMIC_ENABLE         1 // Trinamic TMC2130 stepper driver support. NOTE: work in progress.
//#define TRINAMIC_I2C            1 // Trinamic I2C - SPI bridge interface.
//#define TRINAMIC_DEV            1 // Development mode, adds a few M-codes to aid debugging. Do not enable in production code.
//#define EEPROM_ENABLE          16 // I2C EEPROM/FRAM support. Set to 16 for 2K, 32 for 4K, 64 for 8K, 128 for 16K and 256 for 16K capacity.
//#define EEPROM_IS_FRAM          1 // Uncomment when EEPROM is enabled and chip is FRAM, this to remove write delay.
//#define STEP_INJECT_ENABLE      1
//#define RGB_LED_ENABLE          2 // Set to 1 to enable strip length settings $536 and $537, set to 2 to also enable M150 LED strip control.
//#define PWM_SERVO_ENABLE        1 // Enable M280 PWM servo support, requires at least one PWM capable auxiliary output.
//#define BLTOUCH_ENABLE          1 // Enable M401/M402 BLTouch support. Requires and claims one auxiliary PWM servo output.
//#define EVENTOUT_ENABLE         1 // Enable binding events (triggers) to control auxiliary outputs.
//#define ESP_AT_ENABLE           1 // Enable support for Telnet communication via UART connected ESP32 running ESP-AT.
//#define FEED_OVERRIDE_ENABLE    1 // Enable M200 feed override control.
//#define HOMING_PULLOFF_ENABLE   1 // Enable per axis homing pulloff distance settings.

// IO expanders:
//
//#define MCP3221_ENABLE          1 // MCP3221 I2C 12 bit ADC input, default address is 0x9A (MCP3221_ADDRESS).
//#define MCP4725_ENABLE          1 // MCP4725 I2C 12 bit DAC output, default address is 0xC0 (MCP3221_ADDRESS).
//#define MCP23017_ENABLE         1 // MCP23017 I2C 16 channel digital I/O, default address is 0x40 (MCP23017_ADDRESS).
                                    // 1: Port A as outputs, port B as inputs.
                                    // 2: Port A and B as outputs.
                                    // 3: Port A and B as inputs.
//#define PCA9654E_ENABLE         1 // PCA9654E I2C 8 channel digital out, default address is 0x40 (PCA9654E_ADDRESS).
//#define THCAD2_ENABLE           1 // Mesa THCAD2 analog to frequency converter. Not yet completed!

// Optional control signals:
// These will be assigned to aux input pins. Use the $pins command to check which pins are assigned.
// NOTE: If not enough pins are available assignment will silently fail.
//#define PROBE_ENABLE            0 // Default enabled, remove comment to disable probe input.
//#define PROBE2_ENABLE           1 // Enable second regular probe input, depending on the board the input assigned may be predefined.
//#define TOOLSETTER_ENABLE       1 // Enable toolsetter input, depending on the board the input assigned may be predefined.
//#define SAFETY_DOOR_ENABLE      1
//#define MOTOR_FAULT_ENABLE      1
//#define MOTOR_WARNING_ENABLE    1
//#define PROBE_DISCONNECT_ENABLE 1
//#define STOP_DISABLE_ENABLE     1
//#define BLOCK_DELETE_ENABLE     1
//#define SINGLE_BLOCK_ENABLE     1
//#define LIMITS_OVERRIDE_ENABLE  1

// If the selected board map supports more than three motors ganging and/or auto-squaring
// of axes can be enabled here.
//#define X_GANGED             1
//#define X_AUTO_SQUARE        1
//#define Y_GANGED             1
//#define Y_AUTO_SQUARE        1
//#define Z_GANGED             1
//#define Z_AUTO_SQUARE        1
// For ganged axes the limit switch input (if available) can be configured to act as a max travel limit switch.
// NOTE: If board map already has max limit inputs defined this configuration will be ignored.
//#define X_GANGED_LIM_MAX     1
//#define Y_GANGED_LIM_MAX     1
//#define Z_GANGED_LIM_MAX     1
//

#if WIFI_ENABLE || ETHERNET_ENABLE || WEBUI_ENABLE
#define TELNET_ENABLE        1 // Telnet daemon - requires WiFi streaming enabled.
#define WEBSOCKET_ENABLE     1 // Websocket daemon - requires WiFi streaming enabled.
//#define MDNS_ENABLE          0 // mDNS daemon. Do NOT enable here, enable in CMakeLists.txt!
//#define SSDP_ENABLE          1 // SSDP daemon - requires HTTP enabled.
#if SDCARD_ENABLE || WEBUI_ENABLE
#define FTP_ENABLE           1 // Ftp daemon - requires SD card enabled.
//#define HTTP_ENABLE          1 // http daemon - requires SD card enabled.
//#define WEBDAV_ENABLE        1 // webdav protocol - requires http daemon and SD card enabled.
#endif
// The following symbols have the default values as shown, uncomment and change as needed.
//#define NETWORK_STA_HOSTNAME    "grblHAL"
//#define NETWORK_STA_IPMODE      1 // 0 = static, 1 = DHCP, 2 = AutoIP
//#define NETWORK_STA_IP          "192.168.5.1"
//#define NETWORK_STA_GATEWAY     "192.168.5.1"
//#define NETWORK_STA_MASK        "255.255.255.0"
#if WIFI_SOFTAP > 0
//#define NETWORK_AP_SSID         "grblHAL_AP"
//#define NETWORK_AP_PASSWORD     "grblHALap"
//#define NETWORK_AP_HOSTNAME     "grblHAL_AP"
//#define NETWORK_AP_IPMODE       0              // Do not change!
//#define NETWORK_AP_IP           "192.168.4.1"  // Do not change!
//#define NETWORK_AP_GATEWAY      "192.168.4.1"  // Do not change!
//#define NETWORK_AP_MASK         "255.255.255.0"
#endif
//#define NETWORK_FTP_PORT     21
//#define NETWORK_TELNET_PORT  23
//#define NETWORK_HTTP_PORT    80
#if HTTP_ENABLE
//#define NETWORK_WEBSOCKET_PORT  81
#else
//#define NETWORK_WEBSOCKET_PORT  80
#endif
#endif // WIFI_ENABLE

/**/

// Mr Beam RP2040 shield defaults matching the reference except runtime-only backlash.
// $160/$161/$162 use upstream zero defaults; the plugin sets $161=1 at runtime.
// Saved NVS settings take precedence; apply these with $RST=$ after flashing.
// $22=9: homing enabled and force origin; $10=255: status bits 0 through 7.
// $370/$372, $486 and $703 have no DEFAULT_* macro here; their fields default to zero.
#ifndef BAUD_RATE
#define BAUD_RATE 250000 // UART baud rate; no $ setting
#endif
#ifndef ENABLE_BACKLASH_COMPENSATION
#define ENABLE_BACKLASH_COMPENSATION 1 // Enables $160/$161/$162 backlash settings
#endif
#ifndef DEFAULT_STEP_PULSE_MICROSECONDS
#define DEFAULT_STEP_PULSE_MICROSECONDS 10.0f // $0
#endif
#ifndef DEFAULT_STEPPER_IDLE_LOCK_TIME
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // $1
#endif
#ifndef DEFAULT_STEP_SIGNALS_INVERT_MASK
#define DEFAULT_STEP_SIGNALS_INVERT_MASK 0 // $2
#endif
#ifndef DEFAULT_DIR_SIGNALS_INVERT_MASK
#define DEFAULT_DIR_SIGNALS_INVERT_MASK 0 // $3
#endif
#ifndef DEFAULT_ENABLE_SIGNALS_INVERT_MASK
#define DEFAULT_ENABLE_SIGNALS_INVERT_MASK 7 // $4
#endif
#ifndef DEFAULT_LIMIT_SIGNALS_INVERT_MASK
#define DEFAULT_LIMIT_SIGNALS_INVERT_MASK 7 // $5
#endif
#ifndef DEFAULT_PROBE_SIGNAL_INVERT
#define DEFAULT_PROBE_SIGNAL_INVERT 1 // $6
#endif
#ifndef DEFAULT_SPINDLE_ENABLE_OFF_WITH_ZERO_SPEED
#define DEFAULT_SPINDLE_ENABLE_OFF_WITH_ZERO_SPEED 0 // $9 bit 1; PWM enabled supplies bit 0
#endif
#ifndef DEFAULT_PWM_SPINDLE_DISABLE_LASER_MODE
#define DEFAULT_PWM_SPINDLE_DISABLE_LASER_MODE 0 // $9 bit 2
#endif
#ifndef DEFAULT_PWM_SPINDLE_ENABLE_RAMP
#define DEFAULT_PWM_SPINDLE_ENABLE_RAMP 0 // $9 bit 3
#endif
#ifndef DEFAULT_PWM_SPINDLE_IGNORE_DELAYS
#define DEFAULT_PWM_SPINDLE_IGNORE_DELAYS 0 // $9 bit 4
#endif
#ifndef DEFAULT_JUNCTION_DEVIATION
#define DEFAULT_JUNCTION_DEVIATION 0.020f // $11
#endif
#ifndef DEFAULT_ARC_TOLERANCE
#define DEFAULT_ARC_TOLERANCE 0.001f // $12
#endif
#ifndef DEFAULT_REPORT_INCHES
#define DEFAULT_REPORT_INCHES 0 // $13
#endif
#ifndef DEFAULT_CONTROL_SIGNALS_INVERT_MASK
#define DEFAULT_CONTROL_SIGNALS_INVERT_MASK 70 // $14
#endif
#ifndef DEFAULT_INVERT_COOLANT_FLOOD_PIN
#define DEFAULT_INVERT_COOLANT_FLOOD_PIN 0 // $15
#endif
#ifndef DEFAULT_INVERT_COOLANT_MIST_PIN
#define DEFAULT_INVERT_COOLANT_MIST_PIN 0 // $15
#endif
#ifndef DEFAULT_INVERT_SPINDLE_ENABLE_PIN
#define DEFAULT_INVERT_SPINDLE_ENABLE_PIN 0 // $16
#endif
#ifndef DEFAULT_INVERT_SPINDLE_CCW_PIN
#define DEFAULT_INVERT_SPINDLE_CCW_PIN 0 // $16
#endif
#ifndef DEFAULT_INVERT_SPINDLE_PWM_PIN
#define DEFAULT_INVERT_SPINDLE_PWM_PIN 0 // $16
#endif
#ifndef DEFAULT_DISABLE_CONTROL_PINS_PULL_UP_MASK
#define DEFAULT_DISABLE_CONTROL_PINS_PULL_UP_MASK 0 // $17
#endif
#ifndef DEFAULT_LIMIT_SIGNALS_PULLUP_DISABLE_MASK
#define DEFAULT_LIMIT_SIGNALS_PULLUP_DISABLE_MASK 0 // $18
#endif
#ifndef DEFAULT_PROBE_SIGNAL_DISABLE_PULLUP
#define DEFAULT_PROBE_SIGNAL_DISABLE_PULLUP 0 // $19
#endif
#ifndef DEFAULT_SOFT_LIMIT_ENABLE
#define DEFAULT_SOFT_LIMIT_ENABLE 1 // $20
#endif
#ifndef DEFAULT_HARD_LIMIT_ENABLE
#define DEFAULT_HARD_LIMIT_ENABLE 0 // $21
#endif
#ifndef DEFAULT_CHECK_LIMITS_AT_INIT
#define DEFAULT_CHECK_LIMITS_AT_INIT 0 // $21
#endif
#ifndef DEFAULT_HARD_LIMITS_DISABLE_FOR_ROTARY
#define DEFAULT_HARD_LIMITS_DISABLE_FOR_ROTARY 0 // $21
#endif
#ifndef DEFAULT_HOMING_ENABLE
#define DEFAULT_HOMING_ENABLE 1 // $22 bit 0
#endif
#ifndef DEFAULT_HOMING_SINGLE_AXIS_COMMANDS
#define DEFAULT_HOMING_SINGLE_AXIS_COMMANDS 0 // $22 bit 1
#endif
#ifndef DEFAULT_HOMING_INIT_LOCK
#define DEFAULT_HOMING_INIT_LOCK 0 // $22 bit 2
#endif
#ifndef DEFAULT_HOMING_FORCE_SET_ORIGIN
#define DEFAULT_HOMING_FORCE_SET_ORIGIN 1 // $22 bit 3
#endif
#ifndef DEFAULT_HOMING_ALLOW_MANUAL
#define DEFAULT_HOMING_ALLOW_MANUAL 0 // $22 bit 5
#endif
#ifndef DEFAULT_HOMING_OVERRIDE_LOCKS
#define DEFAULT_HOMING_OVERRIDE_LOCKS 0 // $22 bit 6
#endif
#ifndef DEFAULT_HOMING_USE_LIMIT_SWITCHES
#define DEFAULT_HOMING_USE_LIMIT_SWITCHES 0 // $22 bit 8
#endif
#ifndef DEFAULT_RUN_STARTUP_SCRIPTS_ONLY_ON_HOMED
#define DEFAULT_RUN_STARTUP_SCRIPTS_ONLY_ON_HOMED 0 // $22 bit 10
#endif
#ifndef DEFAULT_LIMITS_TWO_SWITCHES_ON_AXES
#define DEFAULT_LIMITS_TWO_SWITCHES_ON_AXES 0 // $22 bit 4
#endif
#ifndef DEFAULT_HOMING_DIR_MASK
#define DEFAULT_HOMING_DIR_MASK 0 // $23
#endif
#ifndef DEFAULT_HOMING_FEED_RATE
#define DEFAULT_HOMING_FEED_RATE 25.0f // $24
#endif
#ifndef DEFAULT_HOMING_SEEK_RATE
#define DEFAULT_HOMING_SEEK_RATE 2000.0f // $25
#endif
#ifndef DEFAULT_HOMING_DEBOUNCE_DELAY
#define DEFAULT_HOMING_DEBOUNCE_DELAY 100 // $26
#endif
#ifndef DEFAULT_HOMING_PULLOFF
#define DEFAULT_HOMING_PULLOFF 2.0f // $27
#endif
#ifndef DEFAULT_G73_RETRACT
#define DEFAULT_G73_RETRACT 0.1f // $28
#endif
#ifndef DEFAULT_STEP_PULSE_DELAY
#define DEFAULT_STEP_PULSE_DELAY 0.0f // $29
#endif
#ifndef DEFAULT_SPINDLE_RPM_MAX
#define DEFAULT_SPINDLE_RPM_MAX 1000.0f // $30
#endif
#ifndef DEFAULT_SPINDLE_RPM_MIN
#define DEFAULT_SPINDLE_RPM_MIN 0.0f // $31
#endif
#ifndef DEFAULT_LASER_MODE
#define DEFAULT_LASER_MODE 1 // $32
#endif
#ifndef DEFAULT_SPINDLE_PWM_FREQ
#define DEFAULT_SPINDLE_PWM_FREQ 5000 // $33
#endif
#ifndef DEFAULT_SPINDLE_PWM_OFF_VALUE
#define DEFAULT_SPINDLE_PWM_OFF_VALUE 0.0f // $34
#endif
#ifndef DEFAULT_SPINDLE_PWM_MIN_VALUE
#define DEFAULT_SPINDLE_PWM_MIN_VALUE 0.0f // $35
#endif
#ifndef DEFAULT_SPINDLE_PWM_MAX_VALUE
#define DEFAULT_SPINDLE_PWM_MAX_VALUE 100.0f // $36
#endif
#ifndef DEFAULT_STEPPER_DEENERGIZE_MASK
#define DEFAULT_STEPPER_DEENERGIZE_MASK 0 // $37
#endif
#ifndef DEFAULT_LEGACY_RTCOMMANDS
#define DEFAULT_LEGACY_RTCOMMANDS 1 // $39
#endif
#ifndef DEFAULT_JOG_LIMIT_ENABLE
#define DEFAULT_JOG_LIMIT_ENABLE 1 // $40
#endif
#ifndef DEFAULT_PARKING_ENABLE
#define DEFAULT_PARKING_ENABLE 0 // $41
#endif
#ifndef DEFAULT_DEACTIVATE_PARKING_UPON_INIT
#define DEFAULT_DEACTIVATE_PARKING_UPON_INIT 0 // $41
#endif
#ifndef DEFAULT_ENABLE_PARKING_OVERRIDE_CONTROL
#define DEFAULT_ENABLE_PARKING_OVERRIDE_CONTROL 0 // $41
#endif
#ifndef DEFAULT_PARKING_AXIS
#define DEFAULT_PARKING_AXIS 2 // $42
#endif
#ifndef DEFAULT_N_HOMING_LOCATE_CYCLE
#define DEFAULT_N_HOMING_LOCATE_CYCLE 1 // $43
#endif
#ifndef DEFAULT_HOMING_CYCLE_0
#define DEFAULT_HOMING_CYCLE_0 3 // $44
#endif
#ifndef DEFAULT_HOMING_CYCLE_1
#define DEFAULT_HOMING_CYCLE_1 0 // $45
#endif
#ifndef DEFAULT_HOMING_CYCLE_2
#define DEFAULT_HOMING_CYCLE_2 0 // $46
#endif
#ifndef DEFAULT_PARKING_PULLOUT_INCREMENT
#define DEFAULT_PARKING_PULLOUT_INCREMENT 5.0f // $56
#endif
#ifndef DEFAULT_PARKING_PULLOUT_RATE
#define DEFAULT_PARKING_PULLOUT_RATE 100.0f // $57
#endif
#ifndef DEFAULT_PARKING_TARGET
#define DEFAULT_PARKING_TARGET -5.0f // $58
#endif
#ifndef DEFAULT_PARKING_RATE
#define DEFAULT_PARKING_RATE 500.0f // $59
#endif
#ifndef DEFAULT_RESET_OVERRIDES
#define DEFAULT_RESET_OVERRIDES 0 // $60
#endif
#ifndef DEFAULT_DOOR_IGNORE_WHEN_IDLE
#define DEFAULT_DOOR_IGNORE_WHEN_IDLE 0 // $61
#endif
#ifndef DEFAULT_DOOR_KEEP_COOLANT_ON
#define DEFAULT_DOOR_KEEP_COOLANT_ON 0 // $61
#endif
#ifndef DEFAULT_SLEEP_ENABLE
#define DEFAULT_SLEEP_ENABLE 0 // $62
#endif
#ifndef DEFAULT_DISABLE_LASER_DURING_HOLD
#define DEFAULT_DISABLE_LASER_DURING_HOLD 1 // $63
#endif
#ifndef DEFAULT_RESTORE_AFTER_FEED_HOLD
#define DEFAULT_RESTORE_AFTER_FEED_HOLD 1 // $63
#endif
#ifndef DEFAULT_FORCE_INITIALIZATION_ALARM
#define DEFAULT_FORCE_INITIALIZATION_ALARM 0 // $64
#endif
#ifndef DEFAULT_ALLOW_FEED_OVERRIDE_DURING_PROBE_CYCLES
#define DEFAULT_ALLOW_FEED_OVERRIDE_DURING_PROBE_CYCLES 0 // $65
#endif
#ifndef DEFAULT_SOFT_LIMIT_PROBE_CYCLES
#define DEFAULT_SOFT_LIMIT_PROBE_CYCLES 0 // $65
#endif
#ifndef DEFAULT_X_STEPS_PER_MM
#define DEFAULT_X_STEPS_PER_MM 100.0f // $100
#endif
#ifndef DEFAULT_Y_STEPS_PER_MM
#define DEFAULT_Y_STEPS_PER_MM 100.0f // $101
#endif
#ifndef DEFAULT_Z_STEPS_PER_MM
#define DEFAULT_Z_STEPS_PER_MM 250.0f // $102
#endif
#ifndef DEFAULT_X_MAX_RATE
#define DEFAULT_X_MAX_RATE 10000.0f // $110
#endif
#ifndef DEFAULT_Y_MAX_RATE
#define DEFAULT_Y_MAX_RATE 10000.0f // $111
#endif
#ifndef DEFAULT_Z_MAX_RATE
#define DEFAULT_Z_MAX_RATE 500.0f // $112
#endif
#ifndef DEFAULT_X_ACCELERATION
#define DEFAULT_X_ACCELERATION 3000.0f // $120
#endif
#ifndef DEFAULT_Y_ACCELERATION
#define DEFAULT_Y_ACCELERATION 1000.0f // $121
#endif
#ifndef DEFAULT_Z_ACCELERATION
#define DEFAULT_Z_ACCELERATION 10.0f // $122
#endif
#ifndef DEFAULT_X_MAX_TRAVEL
#define DEFAULT_X_MAX_TRAVEL 515.1f // $130
#endif
#ifndef DEFAULT_Y_MAX_TRAVEL
#define DEFAULT_Y_MAX_TRAVEL 391.1f // $131
#endif
#ifndef DEFAULT_Z_MAX_TRAVEL
#define DEFAULT_Z_MAX_TRAVEL 200.0f // $132
#endif
#ifndef DEFAULT_TOOLCHANGE_MODE
#define DEFAULT_TOOLCHANGE_MODE 0 // $341
#endif
#ifndef DEFAULT_TOOLCHANGE_PROBING_DISTANCE
#define DEFAULT_TOOLCHANGE_PROBING_DISTANCE 30.0f // $342
#endif
#ifndef DEFAULT_TOOLCHANGE_FEED_RATE
#define DEFAULT_TOOLCHANGE_FEED_RATE 25.0f // $343
#endif
#ifndef DEFAULT_TOOLCHANGE_SEEK_RATE
#define DEFAULT_TOOLCHANGE_SEEK_RATE 200.0f // $344
#endif
#ifndef DEFAULT_TOOLCHANGE_PULLOFF_RATE
#define DEFAULT_TOOLCHANGE_PULLOFF_RATE 200.0f // $345
#endif
#ifndef DEFAULT_TOOLCHANGE_NO_RESTORE_POSITION
#define DEFAULT_TOOLCHANGE_NO_RESTORE_POSITION 0 // $346 bit 0 (inverse)
#endif
#ifndef DEFAULT_TOOLCHANGE_AT_G30
#define DEFAULT_TOOLCHANGE_AT_G30 0 // $346
#endif
#ifndef DEFAULT_TOOLCHANGE_FAST_PROBE_PULLOFF
#define DEFAULT_TOOLCHANGE_FAST_PROBE_PULLOFF 0 // $346
#endif
#ifndef DEFAULT_DISABLE_G92_PERSISTENCE
#define DEFAULT_DISABLE_G92_PERSISTENCE 0 // $384
#endif
#ifndef DEFAULT_SAFETY_DOOR_SPINDLE_DELAY
#define DEFAULT_SAFETY_DOOR_SPINDLE_DELAY 4.0f // $392
#endif
#ifndef DEFAULT_SAFETY_DOOR_COOLANT_DELAY
#define DEFAULT_SAFETY_DOOR_COOLANT_DELAY 1.0f // $393
#endif
#ifndef DEFAULT_SPINDLE_ON_DELAY
#define DEFAULT_SPINDLE_ON_DELAY 0 // $394
#endif
#ifndef DEFAULT_SPINDLE_OFF_DELAY
#define DEFAULT_SPINDLE_OFF_DELAY 0 // $539
#endif
#ifndef DEFAULT_PLANNER_BUFFER_BLOCKS
#define DEFAULT_PLANNER_BUFFER_BLOCKS 100 // $398
#endif
#ifndef DEFAULT_AUTOREPORT_INTERVAL
#define DEFAULT_AUTOREPORT_INTERVAL 0 // $481
#endif
#ifndef DEFAULT_NO_UNLOCK_AFTER_ESTOP
#define DEFAULT_NO_UNLOCK_AFTER_ESTOP 0 // $484=1 (inverse: allow unlock after E-stop)
#endif
#ifndef DEFAULT_PERSIST_TOOL
#define DEFAULT_PERSIST_TOOL 0 // $485
#endif
#ifndef DEFAULT_COOLANT_ON_DELAY
#define DEFAULT_COOLANT_ON_DELAY 0 // $673
#endif
#ifndef DEFAULT_HOMING_KEEP_STATUS_ON_RESET
#define DEFAULT_HOMING_KEEP_STATUS_ON_RESET 0 // $676 bit 0 (inverse); also $22 bit 7
#endif
#ifndef DEFAULT_KEEP_OFFSETS_ON_RESET
#define DEFAULT_KEEP_OFFSETS_ON_RESET 0 // $676 bit 1 (inverse)
#endif
#ifndef DEFAULT_KEEP_RAPIDS_OVR_ON_RESET
#define DEFAULT_KEEP_RAPIDS_OVR_ON_RESET 0 // $676 bit 2 (inverse)
#endif
#ifndef DEFAULT_KEEP_FEED_OVR_ON_RESET
#define DEFAULT_KEEP_FEED_OVR_ON_RESET 0 // $676 bit 3 (inverse)
#endif
#ifndef DEFAULT_STEPPER_ENABLE_DELAY
#define DEFAULT_STEPPER_ENABLE_DELAY 0 // $680
#endif
#ifndef DEFAULT_REPORT_MACHINE_POSITION
#define DEFAULT_REPORT_MACHINE_POSITION 1 // $10 bit 0
#endif
#ifndef DEFAULT_REPORT_BUFFER_STATE
#define DEFAULT_REPORT_BUFFER_STATE 1 // $10 bit 1
#endif
#ifndef DEFAULT_REPORT_LINE_NUMBERS
#define DEFAULT_REPORT_LINE_NUMBERS 1 // $10 bit 2
#endif
#ifndef DEFAULT_REPORT_CURRENT_FEED_SPEED
#define DEFAULT_REPORT_CURRENT_FEED_SPEED 1 // $10 bit 3
#endif
#ifndef DEFAULT_REPORT_PIN_STATE
#define DEFAULT_REPORT_PIN_STATE 1 // $10 bit 4
#endif
#ifndef DEFAULT_REPORT_WORK_COORD_OFFSET
#define DEFAULT_REPORT_WORK_COORD_OFFSET 1 // $10 bit 5
#endif
#ifndef DEFAULT_REPORT_OVERRIDES
#define DEFAULT_REPORT_OVERRIDES 1 // $10 bit 6
#endif
#ifndef DEFAULT_REPORT_PROBE_COORDINATES
#define DEFAULT_REPORT_PROBE_COORDINATES 1 // $10 bit 7
#endif
#ifndef DEFAULT_REPORT_SYNC_ON_WCO_CHANGE
#define DEFAULT_REPORT_SYNC_ON_WCO_CHANGE 0 // $10 bit 8
#endif
#ifndef DEFAULT_REPORT_PARSER_STATE
#define DEFAULT_REPORT_PARSER_STATE 0 // $10 bit 9
#endif
#ifndef DEFAULT_REPORT_ALARM_SUBSTATE
#define DEFAULT_REPORT_ALARM_SUBSTATE 0 // $10 bit 10
#endif
#ifndef DEFAULT_REPORT_RUN_SUBSTATE
#define DEFAULT_REPORT_RUN_SUBSTATE 0 // $10 bit 11
#endif
#ifndef DEFAULT_REPORT_WHEN_HOMING
#define DEFAULT_REPORT_WHEN_HOMING 0 // $10 bit 12
#endif
#ifndef DEFAULT_REPORT_DISTANCE_TO_GO
#define DEFAULT_REPORT_DISTANCE_TO_GO 0 // $10 bit 13
#endif



#endif // MRBEAM_MY_MACHINE_H
