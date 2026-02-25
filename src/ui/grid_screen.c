#include "grid_screen.h"

#define ROWS 10
#define COLS 10

void grid_screen_show(void)
{
	/* create screen */
	lv_obj_t * scr = lv_obj_create(NULL);

	/* display size */
	int scr_w = lv_disp_get_hor_res(NULL);
	int scr_h = lv_disp_get_ver_res(NULL);

	int cell_w = scr_w / COLS;
	int cell_h = scr_h / ROWS;

	/* shared style for all cells */
	static lv_style_t style_cell;
	lv_style_init(&style_cell);
	lv_style_set_bg_color(&style_cell, lv_color_hex(0x006400)); /* dark green */
	lv_style_set_bg_opa(&style_cell, LV_OPA_COVER);
	lv_style_set_border_color(&style_cell, lv_color_black());
	lv_style_set_border_width(&style_cell, 1);
	lv_style_set_radius(&style_cell, 0);

	for (int r = 0; r < ROWS; ++r) {
		for (int c = 0; c < COLS; ++c) {
			lv_obj_t * cell = lv_obj_create(scr);
			lv_obj_remove_style_all(cell);
			lv_obj_add_style(cell, &style_cell, 0);
			lv_obj_set_size(cell, cell_w, cell_h);
			lv_obj_set_pos(cell, c * cell_w, r * cell_h);
			/* prevent default scroll/click behavior */
			lv_obj_clear_flag(cell, LV_OBJ_FLAG_CLICKABLE);
		}
	}

	lv_scr_load(scr);
}
