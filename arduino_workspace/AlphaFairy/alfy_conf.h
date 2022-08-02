#ifndef _ALFY_CONF_H_
#define _ALFY_CONF_H_

//#define WIFI_AP_UNIQUE_NAME
//#define DISABLE_STATUS_BAR
//#define DISABLE_POWER_SAVE
//#define DISABLE_ALL_MSG
//#define DISABLE_CMD_LINE

#define USE_SPRITE_MANAGER
#define DISABLE_WELCOME

#define LEDBLINK_USE_PWM
#define LEDBLINK_PWM_DUTY_ON  (0xFF - 16)
#define LEDBLINK_PWM_DUTY_OFF 0xFF

#define SHUTTER_GPIO 26
#define SHUTTER_GPIO_ACTIVE_LOW
//#define SHUTTER_GPIO_ACTIVE_HIGH

#define SUBMENU_X_OFFSET 5
#define SUBMENU_Y_OFFSET 5

#define PAGINATION_DOT_SIZE      2
#define PAGINATION_SPACE_SIZE    2
#define PAGINATION_BOTTOM_MARGIN 0

#define WELCOME_TIME_MS        10000
#define WELCOME_CONN_TIME_MS   (WELCOME_TIME_MS + 3000)

#define BTN_DEBOUNCE 50

#define ANGLE_THRESH 40
#define ANGLE_HYSTER 20

#endif
