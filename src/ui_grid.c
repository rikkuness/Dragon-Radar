#include "ui_grid.h"
#include "lvgl.h"

static void draw_grid_cb(lv_event_t * e)
{
	/* draw_ctx and target */
	lv_draw_ctx_t * draw_ctx = lv_event_get_draw_ctx(e);
	lv_obj_t * obj = lv_event_get_target(e);

	/* size */
	lv_coord_t w = lv_obj_get_width(obj);
	lv_coord_t h = lv_obj_get_height(obj);

	const int cols = 10;
	const int rows = 10;

	/* line descriptor */
	lv_draw_line_dsc_t dsc;
	lv_draw_line_dsc_init(&dsc);
	dsc.color = lv_color_hex(0x000000);
	dsc.width = 1;

	/* vertical lines (cols -> cols+1 lines to form cols columns) */
	for (int i = 0; i <= cols; ++i) {
		lv_point_t p1 = { (lv_coord_t)((i * w) / cols), 0 };
		lv_point_t p2 = { (lv_coord_t)((i * w) / cols), (lv_coord_t)(h - 1) };
		lv_draw_line(draw_ctx, &dsc, &p1, &p2);
	}

	/* horizontal lines */
	for (int j = 0; j <= rows; ++j) {
		lv_point_t p1 = { 0, (lv_coord_t)((j * h) / rows) };
		lv_point_t p2 = { (lv_coord_t)(w - 1), (lv_coord_t)((j * h) / rows) };
		lv_draw_line(draw_ctx, &dsc, &p1, &p2);
	}
}

void ui_grid_init(void)
{
	/* create a fresh screen */
	lv_obj_t * scr = lv_obj_create(NULL);

	/* set dark green background */
	lv_obj_set_style_bg_color(scr, lv_color_hex(0x003300), 0);
	lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);

	/* attach draw callback to render grid lines */
	lv_obj_add_event_cb(scr, draw_grid_cb, LV_EVENT_DRAW_MAIN, NULL);

	/* make it the active screen */
	lv_scr_load(scr);
}
