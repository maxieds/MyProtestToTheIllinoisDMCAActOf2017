/* types.h : definitions of various types.
 * Author: Maxie D. Schmidt (cretated 4/17/2006) */

#ifndef _GENROBOT_TYPES_H_
#define _GENROBOT_TYPES_H_

#include <string>
#include <vector>
#include <queue>
using namespace std;

#include <X11/Xlib.h>

#include "SPIMbot.h"

/////// positional:
typedef struct {

     int x, y;

} xy_point;

typedef struct {

     float x, y;

} xy_point_float;

//typedef struct {
//
//     xy_point xy;
//     int horiz_len, vert_len;
//
//} box_t;

//enum arrow_direction {UP = 1, DOWN, LEFT, RIGHT};
typedef struct {

     bool up;
     bool down;
     bool left;
     bool right;

} key_presses;


/////// parser error handling:
typedef struct {
     
     string msg;
     int error_code;
     int line;

} bot_error_t;

// keep track of mmIO addrs:
class mmIO_prop;

typedef struct {

     mem_addr address;
     mmIO_prop *location;

} addr_list_node;

/////// environment:
typedef vector< vector<char> > env_grid;

typedef struct {
     
     int height, width;
     env_grid grid;
     
} bot_env;

/////// robot:
class generic_robot;
class pacbot;
class ghostbot;

typedef struct {

     int reg_context; // multiple bots/file
     generic_robot *robot;

} robot_context;

/////// env. objects:
class env_object;

class env_object_list {

     public:
          void add_object(env_object *obj);

          unsigned int size();
          void delete_object(char key);
          
          // returns NULL if no key matches in the list:
          env_object * operator[](char key); // access objs by list['a'], ...
          env_object * operator[](int index);

     private:
          vector<env_object*> obj_list;

};

/////// admin:
typedef struct {

     unsigned int CYCLE;
     bool game_over;
     
     vector<string> filenames; // asm source files
     vector<robot_context> robot_list;
     env_object_list envobj_list;

     bot_env *environment;

     key_presses keyboard_input;
     
} robot_admin;
     
#endif
