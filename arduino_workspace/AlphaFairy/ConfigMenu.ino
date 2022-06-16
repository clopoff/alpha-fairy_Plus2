#include "AlphaFairy.h"

extern configsettings_t config_settings;

const configitem_t config_items[] = {
  { (int32_t*)&(config_settings.focus_pause_time_ms  ), 1000, 0, 25, "focus pause"            },
  { (int32_t*)&(config_settings.shutter_press_time_ms), 1000, 0, 25, "shutter press duration" },
  { (int32_t*)&(config_settings.manual_focus_return  ),    1, 0,  1, "manual focus return"    },
  { (int32_t*)&(config_settings.nine_point_dist      ),  240, 0, 20, "9 point dist"           },
  { (int32_t*)&(config_settings.infrared_enabled     ),    1, 0,  1, "infrared enabled"       },
  { NULL, 0, 0, 0, "" },
};

uint8_t submenu_idx = 0;
uint8_t submenu_cnt = 0;

void conf_settings(void* mip)
{
  submenu_idx = 0;
  // count the number of items
  for (submenu_cnt = 0; ; submenu_cnt++) {
    if (config_items[submenu_cnt].ptr_val == NULL) {
      break;
    }
  }

  gui_startPrint();

  while (true)
  {
    app_poll();

    if (btnSide_hasPressed(true))
    {
      submenu_idx = (submenu_idx >= submenu_cnt) ? 0 : (submenu_idx + 1);
      M5Lcd.fillScreen(TFT_BLACK);
    }

    configitem_t* cfgitm = (configitem_t*)&(config_items[submenu_idx]);
    if (submenu_idx == submenu_cnt)
    {
      M5Lcd.setCursor(SUBMENU_X_OFFSET, SUBMENU_Y_OFFSET);
      M5Lcd.print("Save and Go Back");
      if (btnBig_hasPressed(true))
      {
        settings_save();
        return;
      }
    }
    else
    {
      configitem_t* cfgitm = (configitem_t*)&(config_items[submenu_idx]);
      M5Lcd.setCursor(SUBMENU_X_OFFSET, SUBMENU_Y_OFFSET);
      M5Lcd.print(cfgitm->text);
      M5Lcd.println();
      M5Lcd.setCursor(SUBMENU_X_OFFSET, M5Lcd.getCursorY());
      int32_t* ptr_x = (int32_t*)(cfgitm->ptr_val);
      int32_t x = *ptr_x;
      bool is_bool = false;
      if (cfgitm->val_max == 1 && cfgitm->val_min == 0 && cfgitm->step_size == 1)
      {
          is_bool = true;
          if (x == 0) {
              M5Lcd.print("no ");
          }
          else {
              M5Lcd.print("yes ");
          }
      }
      else
      {
        M5Lcd.print(x, DEC);
      }
      M5Lcd.print(" ");
      if (imu_angle == ANGLE_IS_UP)
      {
          M5Lcd.print("+ ");
          if (btnBig_hasPressed(true))
          {
              (*ptr_x) += cfgitm->step_size;
              if ((*ptr_x) > cfgitm->val_max) {
                  (*ptr_x) = cfgitm->val_max;
              }
          }
      }
      else if (imu_angle == ANGLE_IS_DOWN)
      {
          M5Lcd.print("- ");
          if (btnBig_hasPressed(true))
          {
              (*ptr_x) -= cfgitm->step_size;
              if ((*ptr_x) < cfgitm->val_min) {
                  (*ptr_x) = cfgitm->val_min;
              }
          }
      }
      else
      {
          M5Lcd.print("  ");
      }
    }
  }
}
