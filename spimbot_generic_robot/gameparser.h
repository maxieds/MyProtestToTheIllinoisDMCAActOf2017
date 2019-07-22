/* gameparser.h : parse the input game file to setup the env. and robots
 *                (the game file should be input from the commandline).
 * Author: Maxie D. Schmidt (created 4/17/2006)                          */

#ifndef _GAMEPARSER_H_
#define _GAMEPARSER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <string>
using namespace std;

#include "reg.h"
#include "mem.h"

#include "types.h"
#include "externs.h"
#include "envobject.h"
#include "genericrobot.h"


/////// gamefile documentation:
//        * comments are "//"
//        * grid blank space is or 'x'

// keywords:
const string ENV_FILE = "ENV_FILE";

// robot keywords:
const string BEGIN_ROBOT = "BEGIN_ROBOT";
const string END_ROBOT = "END_ROBOT";

const string TYPE = "TYPE";
const string BOT_NAME = "BOT_NAME";
const string COLOR = "COLOR";
const string RADIUS = "RADIUS";
const string ASM_FILE = "ASM_FILE";
const string START_X = "START_X";
const string START_Y = "START_Y";

// envfile keywords:
const string HEIGHT = "HEIGHT";
const string WIDTH = "WIDTH";
const string START_GRID = "START_GRID";
const string END_GRID = "END_GRID";

// checklists:
typedef struct {

     bool height;
     bool width;
     bool grid;

} env_parse_chklst;

typedef struct {

     bool env_file;
     bool robots;

} game_parse_chklst;

typedef struct {

     bool type;
     //bool color;
     bool bot_name;
     bool radius;
     bool asm_file;
     bool start_x;
     bool start_y;

} robot_chklst;

// error codes:
#define PARSE_OK          1010
#define PARSE_OTHER_ERROR 1001010
#define UNEXPECTED_EOF    -2
#define NO_SUCH_FILE      -1
#define LAYOUT_ERROR      1
#define ROBOT_SETUP_ERROR 1010101

// parsing the env:
bot_env * parse_env_file(const char *env_file);

// fills in the externed bot_admin:
void parse_game_file(const char *game_file);

#endif
