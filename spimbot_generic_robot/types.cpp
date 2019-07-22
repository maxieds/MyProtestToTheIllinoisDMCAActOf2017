/* types.cpp : code for classes defined in types.h 
 * Author: Maxie D. Schmidt (created 5/6/2006)       */

#include "types.h"
#include "envobject.h"

void env_object_list::add_object(env_object *obj) {

     obj_list.push_back(obj);

}

unsigned int env_object_list::size() {

     return obj_list.size();

}

void env_object_list::delete_object(char key) {

     vector<env_object *>::iterator i = obj_list.begin();
     for(int k = 0; k < obj_list.size(); k++) {
 
          if(obj_list[k]->obj_key == key) {
          
               delete obj_list[k];
               obj_list.erase(i);
               return;
               
          }

          if(k != (obj_list.size() - 1))
               i++;

     }

}

env_object * env_object_list::operator[](char key) {

     for(int i = 0; i < obj_list.size(); i++) {

          if(obj_list[i]->obj_key == key)
               return obj_list[i];

     }

     return NULL;

}

env_object * env_object_list::operator[](int index) {

     if((index >= 0) && (index < obj_list.size()))
          return obj_list[index];

     return NULL;

}
