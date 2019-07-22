/* genericrobot.h : base class for different types of robots
 * Author: Maxie D. Schmidt (created 4/17/2006)               */

#ifndef _GENERIC_ROBOT_H_
#define _GENERIC_ROBOT_H_

#include <stdio.h>
#include <assert.h>

#include <string>
#include <vector>
#include <queue>
using namespace std;

#include "SPIMbot.h"
#include "types.h"
#include "utility.h"
#include "mmappedIO.h"
#include "peripherals.h"
#include "reg.h"

typedef struct {

     // many of the props not listed in this struct are handled as 
     // mmappedIO properties; for example robot x and y coordinates.
     string bot_name;
     string bot_type;
     
     // display:
     string color;
     int radius;
     
     float orientation;
     
     // the robot can move around in the grid pixel by pixel; it is also
     // useful to be able to tell the position of the robot in the
     // scaled grid.
     xy_point_float cur_pos; // since the mmappedIO prop only stores an int
     xy_point_float next_pos;
     xy_point next_grid_pos;
     
} bot_props;

class generic_robot {

     public:
          generic_robot(int context);
          ~generic_robot();
          
          virtual void maintenence(); // on cycle
          #ifdef DEBUGGING
               void print_info();
          #endif

          int context;
          bot_props props;
          queue<int> robot_contact; // gets set in the bonk interrupt for
                                    // this robot
          queue<int> incoming_robot_contact; // gets set from another robot's
                                             // interrupt; fixes if one bot
                                             // bonks this one, but this one
                                             // has lower (or zero) vel and
                                             // doesn't hit the other bot in
                                             // the current position.
          queue<char> env_obj_contact;
          
          // to add more of these use this class as a base class:
          vector<peripheral *> peripherals;
          vector<mmIO_prop *> mmIO_properties;

};

// derived classes:
class pacbot : public generic_robot {

     public:
          pacbot(int reg_context);
          void maintenence();

          int num_pebbles_eaten;

};

class ghostbot : public generic_robot {

     public:
          ghostbot(int reg_context);
          void maintenence();

          generic_robot *pacman;

};

// functions:
generic_robot * create_generic_robot(string type, int context);

#endif
