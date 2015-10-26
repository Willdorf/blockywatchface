#include <pebble.h>

static Window *window;
static Layer *s_layer;
static TextLayer *s_time_layer;

static uint8_t s_hour;
static uint8_t s_min;
static uint8_t s_sec;

static GColor background_color;

static GRect one;
static GRect two;
static GRect three;
static GRect four;
static GRect five;
static GRect six;
static GRect seven;
static GRect eight;
static GRect nine;
static GRect ten;
static GRect eleven;
static GRect twelve;

static void update_time(struct tm *tick_time) {
	s_hour = tick_time->tm_hour;
	s_min = tick_time->tm_min;
	s_sec = tick_time->tm_sec;
	layer_mark_dirty(s_layer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
	update_time(tick_time);

	static char buffer[] = "00";

	//update minutes
	strftime(buffer, sizeof("00"), "%M", tick_time);
	text_layer_set_text(s_time_layer, buffer);
}

static void setup_blocks() {
	one = GRect(0, 52, 24, 24);
	two = GRect(24, 52, 24, 24);
	three = GRect(48, 28, 24, 24);
	four = GRect(72, 52, 24, 24);
	five = GRect(96, 52, 24, 24);
	six = GRect(120, 28, 24, 24);
	seven = GRect(0, 116, 24, 24);
	eight = GRect(24, 116, 24, 24);
	nine = GRect(48, 92, 24, 24);
	ten = GRect(72, 116, 24, 24);
	eleven = GRect(96, 116, 24, 24);
	twelve = GRect(120, 92, 24, 24);
}

static void draw_watchface(Layer *layer, GContext *ctx) {
	graphics_context_set_fill_color(ctx, gcolor_legible_over(background_color));

	//draw the blocks
	graphics_context_set_stroke_color(ctx, gcolor_legible_over(background_color));
	graphics_context_set_stroke_width(ctx, 3);

	graphics_draw_rect(ctx, one);
	graphics_draw_rect(ctx, two);
	graphics_draw_rect(ctx, three);
	graphics_draw_rect(ctx, four);
	graphics_draw_rect(ctx, five);
	graphics_draw_rect(ctx, six);
	graphics_draw_rect(ctx, seven);
	graphics_draw_rect(ctx, eight);
	graphics_draw_rect(ctx, nine);
	graphics_draw_rect(ctx, ten);
	graphics_draw_rect(ctx, eleven);
	graphics_draw_rect(ctx, twelve);

	uint8_t cur_hour = s_hour % 12;
	if (cur_hour == 0) {
		cur_hour = 12;
	}

	GRect f = layer_get_frame((Layer *) s_time_layer);
	int shift = 5;
	switch (cur_hour) {
		case 1:
			f.origin.x = 0;
			f.origin.y = 52 - shift;
			break;
		case 2:
			f.origin.x = 24;
			f.origin.y = 52 - shift;
			break;
		case 3:
			f.origin.x = 48;
			f.origin.y = 28 - shift;
			break;
		case 4:
			f.origin.x = 72;
			f.origin.y = 52 - shift;
			break;
		case 5:
			f.origin.x = 96;
			f.origin.y = 52 - shift;
			break;
		case 6:
			f.origin.x = 120;
			f.origin.y = 28 - shift;
			break;
		case 7:
			f.origin.x = 0;
			f.origin.y = 116 - shift;
			break;
		case 8:
			f.origin.x = 24;
			f.origin.y = 116 - shift;
			break;
		case 9:
			f.origin.x = 48;
			f.origin.y = 92 - shift;
			break;
		case 10:
			f.origin.x = 72;
			f.origin.y = 116 - shift;
			break;
		case 11:
			f.origin.x = 96;
			f.origin.y = 116 - shift;
			break;
		case 12:
			f.origin.x = 120;
			f.origin.y = 92 - shift;
			break;
		default :
			APP_LOG(APP_LOG_LEVEL_DEBUG, "invalid hour: %d", cur_hour);
	}

	layer_set_frame((Layer *) s_time_layer, f);
}

static void window_load(Window *window) {
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);

	s_layer = layer_create(layer_get_bounds(window_get_root_layer(window)));
	layer_add_child(window_get_root_layer(window), s_layer);
	layer_set_update_proc(s_layer, draw_watchface);

	s_time_layer = text_layer_create(GRect(0, 0, 24, 24));
	text_layer_set_background_color(s_time_layer, GColorClear);
	text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
	text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));

	background_color = GColorWhite;

	setup_blocks();
}

static void window_unload(Window *window) {
	text_layer_destroy(s_time_layer);
}

static void init(void) {
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
			.load = window_load,
			.unload = window_unload,
			});
	const bool animated = true;
	window_stack_push(window, animated);

	//Register with TickTimerService
	tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

	time_t start_time = time(NULL);
	update_time(localtime(&start_time));
}

static void deinit(void) {
	window_destroy(window);
}

int main(void) {
	init();

	APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

	app_event_loop();
	deinit();
}
