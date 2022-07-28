#ifndef _ALFY_DEFS_H_
#define _ALFY_DEFS_H_

#include "alfy_conf.h"

#define CONFIGSETTINGS_MAGIC 0xDEADBEEF

enum
{
  MENUITEM_END_OF_TABLE = 0,
  MENUITEM_MAIN,
  MENUITEM_REMOTE,
  MENUITEM_FOCUS,
  MENUITEM_INTERVAL,
  MENUITEM_ASTRO,
  MENUITEM_UTILS,
  MENUITEM_CONFIG,
  MENUITEM_WIFIINFO,
  MENUITEM_BACK,
  MENUITEM_FOCUSSTACK_FAR_1,
  MENUITEM_FOCUSSTACK_FAR_2,
  MENUITEM_FOCUSSTACK_FAR_3,
  MENUITEM_FOCUSSTACK_NEAR_1,
  MENUITEM_FOCUSSTACK_NEAR_2,
  MENUITEM_FOCUSSTACK_NEAR_3,
  MENUITEM_FOCUS_9POINT,
  MENUITEM_SHUTTERSTEP,
  MENUITEM_REMOTESHUTTER_NOW,
  MENUITEM_REMOTESHUTTER_2S,
  MENUITEM_REMOTESHUTTER_5S,
  MENUITEM_REMOTESHUTTER_10S,
  MENUITEM_RECORDMOVIE,
};

enum
{
  MENUFLAG_CAN_GO_DOWN,
  MENUFLAG_DRAW_PAGES,
};

enum
{
  ANGLE_IS_FLAT = 0,
  ANGLE_IS_UP,
  ANGLE_IS_DOWN,
};

enum
{
  LEDMODE_NORMAL,
  LEDMODE_BLINK,
  LEDMODE_ON,
};

enum
{
  CFGFMT_NONE   =    0,
  CFGFMT_BOOL   = 0x01,
  CFGFMT_TIME   = 0x02,
  CFGFMT_BULB   = 0x04,
  CFGFMT_TIMEMS = 0x08,
  CFGFMT_TIMELONG = 0x10,
  CFGFMT_BYTENS = 0x80,
};

#endif
