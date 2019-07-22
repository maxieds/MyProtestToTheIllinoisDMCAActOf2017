/* utility.h : various utils 
 * Author: Maxie D. Schmidt (created 4/17/2006) */

#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <vector>
using namespace std;

#include <X11/Xlib.h>

#include "types.h"
#include "externs.h"
#include "mem.h"

// string related:
vector<string> split_string(string line, char delimeter);
string trim_whitespace(string input);

// error handling:
bot_error_t bot_error(int error_code, string msg, int line_num);
void print_error_msg(bot_error_t e, string error_type);

// display props:
//unsigned int string_to_color(string input);
void setup_xcolor(string color, XColor &xcolor);
//xy_point calculate_grid_pos(int context);

// handling of mmappedIO addresses: each property and peripheral (for ack)
// gets an address. The source code can call 
// robot.periph[something].read/write(), but coming from the asm code there
// is a list of addresses along with the pointer to the mmIO_prop so
// scanning for the address is simpler: for example:
// asm writes 0xffff0010: look up address, get pointer, call ptr->read/write()
mem_addr get_mmappedIO_address(int context, mmIO_prop *ptr);

#endif
