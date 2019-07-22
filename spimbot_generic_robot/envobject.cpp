/* envobject.cpp : code for env_objects and the list
 * Author: Maxie D. Schmidt (created 4/17/2006)         */

#include "envobject.h"
#include "genericrobot.h"

env_object::env_object() {
     
     // inherit from the class to change these:
     props.type = "env_object";
     props.movable = false;
     props.visible = true;
     props.shares_space = false;
     props.color = "blue";

}

void env_object::maintenence() {}

/////// derived classes:
green_wall::green_wall() {

     props.type = "green_wall";
     props.movable = false;
     props.visible = true;
     props.shares_space = false;
     props.color = "darkgreen";

}

void green_wall::maintenence() {

     for(int i = 0; i < robot_contact.size(); i++)
          robot_contact.pop();

}

pink_wall::pink_wall() {

     props.type = "pink_wall";
     props.movable = false;
     props.visible = true;
     props.shares_space = false;
     props.color = "pink";

}

void pink_wall::maintenence() {

     for(int i = 0; i < robot_contact.size(); i++)
          robot_contact.pop();

}

blue_wall::blue_wall() {

     props.type = "blue_wall";
     props.movable = false;
     props.visible = true;
     props.shares_space = false;
     props.color = "blue";

}

void blue_wall::maintenence() {

     for(int i = 0; i < robot_contact.size(); i++)
          robot_contact.pop();

}

pacman_pebble::pacman_pebble() {
    
     props.type = "pacman_pebble";
     props.movable = false;
     props.visible = true;
     props.shares_space = true;
     props.color = "pink";

}

void pacman_pebble::maintenence() {

     // delete the object when it comes in contact with the pacbot:
     while(!robot_contact.empty()) {

          if((bot_admin.robot_list[robot_contact.front()].robot != NULL) &&
             (bot_admin.robot_list[robot_contact.front()].robot->
                                                props.bot_type == "pacbot")) {
               // TODO: check me on segfault
               //printf("before delete obj\n");
               bot_admin.envobj_list.delete_object(obj_key);
               //printf("after delete object\n\n");
               return;

          }

          robot_contact.pop();

     }

}

env_object * create_env_object(string type) {

     if(type == "green_wall")
          return new green_wall();
     else if(type == "pink_wall")
          return new pink_wall();
     else if(type == "blue_wall")
          return new blue_wall();
     else if(type == "pacman_pebble")
          return new pacman_pebble();
     else
          return new env_object();

}
