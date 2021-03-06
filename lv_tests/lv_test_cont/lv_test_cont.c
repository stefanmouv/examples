/**
 * @file lv_test_cont.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_test_cont.h"

#if USE_LV_CONT != 0

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
void lv_test_cont_1(void)
{
    /* Create a default object*/
    lv_obj_t * cont1 = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_pos_scale(cont1, 10, 10);
    lv_cont_set_style(cont1, &lv_style_pretty);

    /*Test fit wit adding two labels*/
    lv_obj_t * cont2 = lv_cont_create(lv_scr_act(), cont1);
    lv_cont_set_fit(cont2, true, true);

    lv_obj_t * obj2_1 = lv_label_create(cont2, NULL);
    lv_label_set_text(obj2_1, "Short");

    lv_obj_t * obj2_2 = lv_label_create(cont2, NULL);
    lv_label_set_text(obj2_2, "A longer text");
    lv_obj_set_pos_scale(obj2_2, 80, 30);

    lv_obj_align_scale(cont2, cont1, LV_ALIGN_OUT_RIGHT_TOP, 20, 0);

    /*Test layout and fit togother*/
    lv_obj_t * cont3 = lv_cont_create(lv_scr_act(), cont2);
    lv_label_create(cont3, obj2_1);
    lv_label_create(cont3, obj2_2);
    lv_cont_set_layout(cont3, LV_CONT_LAYOUT_COL_L);

    lv_obj_align_scale(cont3, cont2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);



    /*Set a new style with new padding*/
    static lv_style_t cont4_style;
    lv_style_copy(&cont4_style, &lv_style_pretty_color);
    cont4_style.body.padding.hor = 20 << LV_ANTIALIAS;
    cont4_style.body.padding.ver = 40 << LV_ANTIALIAS;
    cont4_style.body.padding.inner = 1 << LV_ANTIALIAS;

    lv_obj_t * cont4 = lv_cont_create(lv_scr_act(), cont3);
    lv_label_create(cont4, obj2_1);
    lv_label_create(cont4, obj2_2);
    lv_cont_set_style(cont4, &cont4_style);

    lv_obj_align_scale(cont4, cont3, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);

}

/**
 * Test nested style inheritance on padding update
 */
void lv_test_cont_2(void)
{

    /*Create a new style with big paddings*/
    static lv_style_t cont4_style;
    lv_style_copy(&cont4_style, &lv_style_pretty_color);
    cont4_style.body.padding.hor = 10 << LV_ANTIALIAS;
    cont4_style.body.padding.ver = 20 << LV_ANTIALIAS;
    cont4_style.body.padding.inner = 1 << LV_ANTIALIAS;

    /* Create a main container*/
    lv_obj_t * cont_main = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_pos_scale(cont_main, 50, 50);
    lv_cont_set_style(cont_main, &lv_style_pretty);
    lv_cont_set_fit(cont_main, true, true);
    lv_cont_set_layout(cont_main, LV_CONT_LAYOUT_ROW_M);

    /*Create two containers on the main* with two-two labels*/
    lv_obj_t * cont_sub1 = lv_cont_create(cont_main, NULL);
    lv_cont_set_style(cont_sub1, NULL);      /*Inherit style from parent*/
    lv_cont_set_fit(cont_sub1, true, true);
    lv_cont_set_layout(cont_sub1, LV_CONT_LAYOUT_COL_M);

    lv_obj_t * obj1_1 = lv_label_create(cont_sub1, NULL);
    lv_label_set_text(obj1_1, "Short");

    lv_obj_t * obj1_2 = lv_label_create(cont_sub1, NULL);
    lv_label_set_text(obj1_2, "A long text");

    lv_obj_t * cont_sub2 = lv_cont_create(cont_main, cont_sub1);
    lv_label_create(cont_sub2, obj1_1);
    lv_label_create(cont_sub2, obj1_2);

    /*Set the new style*/
    lv_cont_set_style(cont_main, &cont4_style);

}


/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /*USE_LV_CONT*/
