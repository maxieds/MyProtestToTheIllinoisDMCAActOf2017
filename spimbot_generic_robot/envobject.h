/* envobject.h : environment objects (walls, pacman pebbles,...) and 
 *               corresponding list indexed by the char key for the
 *               object
 * Author: Maxie D. Schmidt (created 4/17/2006)                              */

#ifndef _ENVOBJECT_H_
#define _ENVOBJECT_H_

#include <stdlib.h>
#include <stdio.h>

#include <vector>
#include <string>
#include <queue>
using namespace std;

#include "SPIMbot.h"
#include "types.h"
#include "externs.h"

typedef struct {

     string type;
     bool movable;
     bool visible;
     bool shares_space;
     string color;

} env_object_props;

class env_object {

     public:
          env_object();
          
          virtual void maintenence(); // runs on cycle
          #ifdef DEBUGGING
               void print_info(const char *indent);
          #endif

          char obj_key;
          env_object_props props;
          queue<int> robot_contact; // contexts of the robot(s)

};

// derived class:
class green_wall : public env_object {

     public:
          green_wall();
          void maintenence();

};

class pink_wall : public env_object {

     public:
          pink_wall();
          void maintenence();

};

class blue_wall : public env_object {

     public:
          blue_wall();
          void maintenence();

};

class pacman_pebble : public env_object {

     public:
          pacman_pebble();
          void maintenence();

};

// need to update this when create new types:
env_object * create_env_object(string type);

#endif
