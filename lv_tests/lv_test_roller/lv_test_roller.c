/**
 * @file lv_test_roller.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_test_roller.h"

#if USE_LV_ROLLER != 0

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a default object and test the basic functions
 */
void lv_test_roller_1(void)
{
    /* Default object*/
    lv_obj_t *roller1 = lv_roller_create(lv_scr_act(), NULL);
    lv_obj_set_pos_scale(roller1, 10, 10);


    static lv_style_t bg;
    lv_style_copy(&bg, &lv_style_pretty);
    bg.body.color_main = COLOR_GRAY;
    bg.body.color_gradient = COLOR_WHITE;
    bg.body.shadow.width = 5 << LV_ANTIALIAS;
    bg.text.line_space = 10 << LV_ANTIALIAS;
    bg.text.opa = OPA_60;

    lv_obj_t *roller2 = lv_roller_create(lv_scr_act(), NULL);
    lv_obj_set_size_scale(roller2, 80, 120);
    lv_roller_set_options(roller2, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9");
    lv_obj_align_scale(roller2, roller1, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
    lv_roller_set_anim_time(roller2, 500);
    lv_roller_set_style(roller2, &bg, &lv_style_plain);
//    lv_roller_set_selected(roller2, 4, true);

    lv_obj_t *roller3 = lv_roller_create(lv_scr_act(), roller2);
    lv_obj_align_scale(roller3, roller2, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);
    lv_roller_set_hor_fit(roller3, false);
    lv_obj_set_width_scale(roller3, 150);

}


/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*USE_LV_ROLLER*/
