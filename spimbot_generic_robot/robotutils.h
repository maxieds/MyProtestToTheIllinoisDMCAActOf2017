/* robotutils.h : this is basically the replacement for robot.{c,h} in the
 *                original spimbot code.
 * Author: Maxie D. Schmidt (created 4/22/2006)                            */

#ifndef _ROBOT_UTILS_H_
#define _ROBOT_UTILS_H_

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>

#include <vector>
using namespace std;

#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xlib.h>

#include "spim.h"
#include "xspim.h"
#include "types.h"
#include "externs.h"
#include "utility.h"
#include "envobject.h"
#include "genericrobot.h"
#include "gameparser.h"
#include "reg.h"
#include "mem.h"

extern int SPIMBOT_TOURNAMENT;
extern int GRADING;
extern int cycle_limit;
extern int EXIT_WHEN_DONE;

extern Widget mapshell;
extern Widget mappane;
extern Widget map;

extern char *game_file;

// initialize:
void world_initialize();
void create_map_display(void);

// drawing:
void redraw_map_window(Widget w, XEvent *event, String *params, 
                       Cardinal *num_params);

// IO:
void write_spimbot_IO(int context, mem_addr addr, mem_word value);
mem_word read_spimbot_IO(int context, mem_addr addr);

// running the prog:
void arrow_key_up(Widget w, XEvent *event, String *params, 
                  Cardinal *num_params);
void arrow_key_down(Widget w, XEvent *event, String *params, 
                  Cardinal *num_params);
void arrow_key_left(Widget w, XEvent *event, String *params, 
                  Cardinal *num_params);
void arrow_key_right(Widget w, XEvent *event, String *params, 
                  Cardinal *num_params);
void spimbot_map_click();
int world_update();

#endif
