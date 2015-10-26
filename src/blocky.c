#include <pebble.h>

#define KEY_BLOCK_ONE_COLOR 0
#define KEY_BLOCK_TWO_COLOR 1
#define KEY_BLOCK_THREE_COLOR 2
#define KEY_BLOCK_FOUR_COLOR 3
#define KEY_BLOCK_FIVE_COLOR 4
#define KEY_BLOCK_SIX_COLOR 5
#define KEY_BLOCK_SEVEN_COLOR 6
#define KEY_BLOCK_EIGHT_COLOR 7
#define KEY_BLOCK_NINE_COLOR 8
#define KEY_BLOCK_TEN_COLOR 9
#define KEY_BLOCK_ELEVEN_COLOR 10
#define KEY_BLOCK_TWELVE_COLOR 11

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

static GColor blockOneColor;
static GColor blockTwoColor;
static GColor blockThreeColor;
static GColor blockFourColor;
static GColor blockFiveColor;
static GColor blockSixColor;
static GColor blockSevenColor;
static GColor blockEightColor;
static GColor blockNineColor;
static GColor blockTenColor;
static GColor blockElevenColor;
static GColor blockTwelveColor;

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

	if (persist_read_int(KEY_BLOCK_ONE_COLOR)) {
		blockOneColor = GColorFromHEX(persist_read_int(KEY_BLOCK_ONE_COLOR));
	} else {
		blockOneColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_TWO_COLOR)) {
		blockTwoColor = GColorFromHEX(persist_read_int(KEY_BLOCK_TWO_COLOR));
	} else {
		blockTwoColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_THREE_COLOR)) {
		blockThreeColor = GColorFromHEX(persist_read_int(KEY_BLOCK_THREE_COLOR));
	} else {
		blockThreeColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_FOUR_COLOR)) {
		blockFourColor = GColorFromHEX(persist_read_int(KEY_BLOCK_FOUR_COLOR));
	} else {
		blockFourColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_FIVE_COLOR)) {
		blockFiveColor = GColorFromHEX(persist_read_int(KEY_BLOCK_FIVE_COLOR));
	} else {
		blockFiveColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_SIX_COLOR)) {
		blockSixColor = GColorFromHEX(persist_read_int(KEY_BLOCK_SIX_COLOR));
	} else {
		blockSixColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_SEVEN_COLOR)) {
		blockSevenColor = GColorFromHEX(persist_read_int(KEY_BLOCK_SEVEN_COLOR));
	} else {
		blockSevenColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_EIGHT_COLOR)) {
		blockEightColor = GColorFromHEX(persist_read_int(KEY_BLOCK_EIGHT_COLOR));
	} else {
		blockEightColor = GColorRed; 
	}

	if (persist_read_int(KEY_BLOCK_NINE_COLOR)) {
		blockNineColor = GColorFromHEX(persist_read_int(KEY_BLOCK_NINE_COLOR));
	} else {
		blockNineColor = GColorRed; 
	}

	if (persist_read_int(KEY_BLOCK_TEN_COLOR)) {
		blockTenColor = GColorFromHEX(persist_read_int(KEY_BLOCK_TEN_COLOR));
	} else {
		blockTenColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_ELEVEN_COLOR)) {
		blockElevenColor = GColorFromHEX(persist_read_int(KEY_BLOCK_ELEVEN_COLOR));
	} else {
		blockElevenColor = GColorRed;
	}

	if (persist_read_int(KEY_BLOCK_TWELVE_COLOR)) {
		blockTwelveColor = GColorFromHEX(persist_read_int(KEY_BLOCK_TWELVE_COLOR));
	} else {
		blockTwelveColor = GColorRed;
	}
}

static void draw_watchface(Layer *layer, GContext *ctx) {

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

	switch (cur_hour) {
		case 12:
			graphics_context_set_fill_color(ctx, blockTwelveColor);
			graphics_fill_rect(ctx, twelve, 0 , 0);
		case 11:
			graphics_context_set_fill_color(ctx, blockElevenColor);
			graphics_fill_rect(ctx, eleven, 0 , 0);
		case 10:
			graphics_context_set_fill_color(ctx, blockTenColor);
			graphics_fill_rect(ctx, ten, 0 , 0);
		case 9:
			graphics_context_set_fill_color(ctx, blockNineColor);
			graphics_fill_rect(ctx, nine, 0 , 0);
		case 8:
			graphics_context_set_fill_color(ctx, blockEightColor);
			graphics_fill_rect(ctx, eight, 0 , 0);
		case 7:
			graphics_context_set_fill_color(ctx, blockSevenColor);
			graphics_fill_rect(ctx, seven, 0 , 0);
		case 6:
			graphics_context_set_fill_color(ctx, blockSixColor);
			graphics_fill_rect(ctx, six, 0 , 0);
		case 5:
			graphics_context_set_fill_color(ctx, blockFiveColor);
			graphics_fill_rect(ctx, five, 0 , 0);
		case 4:
			graphics_context_set_fill_color(ctx, blockFourColor);
			graphics_fill_rect(ctx, four, 0 , 0);
		case 3:
			graphics_context_set_fill_color(ctx, blockThreeColor);
			graphics_fill_rect(ctx, three, 0 , 0);
		case 2:
			graphics_context_set_fill_color(ctx, blockTwoColor);
			graphics_fill_rect(ctx, two, 0, 0);
		case 1:
			graphics_context_set_fill_color(ctx, blockOneColor);
			graphics_fill_rect(ctx, one, 0, 0);
		default :
			APP_LOG(APP_LOG_LEVEL_DEBUG, "invalid hour: %d", cur_hour);
	}

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