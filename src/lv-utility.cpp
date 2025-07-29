#include "lv-utility.h"

void ToggleVisibility(lv_obj_t *obj)
{
    if (lv_obj_has_flag(obj, LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN); 
    }
}

void HideObject(lv_obj_t *obj)
{
    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
};

void ShowObject(lv_obj_t *obj)
{
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
};