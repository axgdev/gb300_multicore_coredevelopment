/* Start of simplified libretro.h */
#ifndef LIBRETRO_H__
#define LIBRETRO_H__

#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <stdbool.h>  /* Adding stdbool.h for bool type */

/* System-specific defines */
#define RETRO_DEVICE_JOYPAD 0
#define RETRO_DEVICE_MOUSE 2
#define RETRO_DEVICE_ID_JOYPAD_B 0
#define RETRO_DEVICE_ID_JOYPAD_Y 1
#define RETRO_DEVICE_ID_JOYPAD_SELECT 2
#define RETRO_DEVICE_ID_JOYPAD_START 3
#define RETRO_DEVICE_ID_JOYPAD_UP 4
#define RETRO_DEVICE_ID_JOYPAD_DOWN 5
#define RETRO_DEVICE_ID_JOYPAD_LEFT 6
#define RETRO_DEVICE_ID_JOYPAD_RIGHT 7
#define RETRO_DEVICE_ID_JOYPAD_A 8
#define RETRO_DEVICE_ID_JOYPAD_X 9
#define RETRO_DEVICE_ID_JOYPAD_L 10
#define RETRO_DEVICE_ID_JOYPAD_R 11

#define RETRO_ENVIRONMENT_SET_PIXEL_FORMAT 10
#define RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME 18
#define RETRO_API_VERSION 1

#define RETRO_REGION_NTSC 0
#define RETRO_REGION_PAL 1

enum retro_pixel_format {
   RETRO_PIXEL_FORMAT_0RGB1555 = 0,
   RETRO_PIXEL_FORMAT_XRGB8888 = 1,
   RETRO_PIXEL_FORMAT_RGB565 = 2
};

struct retro_system_info {
   const char *library_name;
   const char *library_version;
   const char *valid_extensions;
   bool need_fullpath;
   bool block_extract;
};

struct retro_game_geometry {
   unsigned base_width;
   unsigned base_height;
   unsigned max_width;
   unsigned max_height;
   float aspect_ratio;
};

struct retro_system_timing {
   double fps;
   double sample_rate;
};

struct retro_system_av_info {
   struct retro_game_geometry geometry;
   struct retro_system_timing timing;
};

/* Add this missing structure definition */
struct retro_game_info {
   const char *path;           /* Path to game, UTF-8 encoded. */
   const void *data;           /* Memory buffer of loaded game. */
   size_t      size;           /* Size of memory buffer. */
   const char *meta;           /* String of implementation specific meta-data. */
};

typedef bool (*retro_environment_t)(unsigned cmd, void *data);
typedef void (*retro_video_refresh_t)(const void *data, unsigned width, unsigned height, size_t pitch);
typedef void (*retro_audio_sample_t)(int16_t left, int16_t right);
typedef size_t (*retro_audio_sample_batch_t)(const int16_t *data, size_t frames);
typedef void (*retro_input_poll_t)(void);
typedef int16_t (*retro_input_state_t)(unsigned port, unsigned device, unsigned index, unsigned id);typedef int16_t (*retro_input_state_t)(unsigned port, unsigned device, unsigned index, unsigned id);

#endif /* LIBRETRO_H__ */