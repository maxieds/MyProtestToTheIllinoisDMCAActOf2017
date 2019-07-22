/* peripherals.cpp : peripherals and interrupts
 * Author: Maxie D. Schmidt (created 4/17/2006)   */

#include "peripherals.h"
#include "genericrobot.h"

peripheral::peripheral(int reg_context, generic_robot *robot) : 
                                                 ack_addr(robot, reg_context) {
     
     context = reg_context;
     int_mask = INT_MASK_GENERIC_PERIPH;
     ack_addr.set_mask(int_mask);
     self = robot;
     
}

bool peripheral::interrupt() {

     printf("inside base class interrupt\n");
     return false;

}

void peripheral::on_interrupt() {}

bonk_periph::bonk_periph(int reg_context, generic_robot *robot) : 
                                                peripheral(reg_context, robot) { 
     int_mask = INT_MASK_BONK;         
     ack_addr.set_mask(int_mask);
                                        
}

bool bonk_periph::interrupt() {

     //printf("beginning of bonk interrupt()\n");
     vector<int> x_points, y_points;
     vector<xy_point> grid_points;
     int x, y;

     // find all x grid points covered:
     x = (int) (self->props.next_pos.x);
     x_points.push_back(x);
     x += GRID_SCALING;
     while(x < (((int) self->props.next_pos.x) + 2*(self->props.radius))) {
          
          x_points.push_back(x);
          x += GRID_SCALING;

     }
     // this is so the rightmost part of the robot gets included in
     // the grid points; if the robot is aligned with the grid, there
     // will be a duplicate x point.
     if((((int) self->props.next_pos.x) % GRID_SCALING) != 0)
          x_points.push_back(x - 1);
     
     // find all y grid points covered:
     y = (int) (self->props.next_pos.y);
     y_points.push_back(y);
     y += GRID_SCALING;
     while(y < (((int) self->props.next_pos.y) + 2*(self->props.radius))) {

          y_points.push_back(y);
          y += GRID_SCALING;

     }
     if((((int) self->props.next_pos.y) % GRID_SCALING) != 0)
          y_points.push_back(y - 1);
     
     // get list of grid point indices:
     xy_point point;
     for(int i = 0; i < y_points.size(); i++) {

          point.y = y_points[i] / GRID_SCALING;
          for(int k = 0; k < x_points.size(); k++) {

               point.x = x_points[k] / GRID_SCALING;
               grid_points.push_back(point);

          }

     }

     // check for bonks with env. objects:
     char id;
     env_object *obj = NULL;
     bool interrupt = false;
     for(int i = 0; i < grid_points.size(); i++) {

          id = bot_admin.environment->grid[grid_points[i].y][grid_points[i].x];
          if(id == 'x')
               continue;

          obj = bot_admin.envobj_list[id];
          if(obj != NULL) {
               
               if(!(obj->props.shares_space)) {
                    //printf("grid cell: row=%d, col=%d\n", grid_points[i].y, 
                    //          grid_points[i].x);
                    interrupt = true;

               }
               
               self->env_obj_contact.push(id);
               obj->robot_contact.push(self->context);
               
          }

     } 
              
     // TODO: (fix me) add in logic for robot / robot collisions
     
     if(interrupt)
          on_interrupt();
    
     //printf("end of bonk interrupt()\n\n");
     return interrupt;

}

void bonk_periph::on_interrupt() {
     
     self->mmIO_properties[MMIO_PROP_VELOCITY]->write(0);
     self->props.next_pos.x = self->props.cur_pos.x; // stop robot
     self->props.next_pos.y = self->props.cur_pos.y;

}

timer_periph::timer_periph(int context, generic_robot *robot) : 
                                                   peripheral(context, robot) { 

     int_mask = INT_MASK_TIMER;
     ack_addr.set_mask(int_mask);

}

bool timer_periph::interrupt() {

     if((bot_admin.CYCLE != 0) && (bot_admin.CYCLE == 
               self->mmIO_properties[MMIO_PROP_TIMER_INT]->value)) {
          
          on_interrupt();
          return true;

     }

     return false;

}

void timer_periph::on_interrupt() {

     self->mmIO_properties[MMIO_PROP_TIMER_INT]->write(SPIMBOT_MAXINT_32);

}

key_arrow_up::key_arrow_up(int context, generic_robot *robot) : 
                                                   peripheral(context, robot) {
     int_mask = INT_MASK_PACBOT_ARROW_UP;
     ack_addr.set_mask(int_mask);

}

bool key_arrow_up::interrupt() {

     if(bot_admin.keyboard_input.up) {

          on_interrupt();
          return true;

     }
     else
          return false;
     
}

void key_arrow_up::on_interrupt() {

     bot_admin.keyboard_input.up = false;

}

key_arrow_down::key_arrow_down(int context, generic_robot *robot) : 
                                                   peripheral(context, robot) {
     int_mask = INT_MASK_PACBOT_ARROW_DOWN;
     ack_addr.set_mask(int_mask);

}

bool key_arrow_down::interrupt() {

     if(bot_admin.keyboard_input.down) {

          on_interrupt();
          return true;

     }
     else 
          return false;

}

void key_arrow_down::on_interrupt() {

     bot_admin.keyboard_input.down = false;
     
}

key_arrow_left::key_arrow_left(int context, generic_robot *robot) : 
                                                   peripheral(context, robot) {
     int_mask = INT_MASK_PACBOT_ARROW_LEFT;
     ack_addr.set_mask(int_mask);

}

bool key_arrow_left::interrupt() {

     if(bot_admin.keyboard_input.left) {

          on_interrupt();
          return true;

     }
     else 
          return false;

}

void key_arrow_left::on_interrupt() {

     bot_admin.keyboard_input.left = false;

}

key_arrow_right::key_arrow_right(int context, generic_robot *robot) : 
                                                   peripheral(context, robot) {
     int_mask = INT_MASK_PACBOT_ARROW_RIGHT;
     ack_addr.set_mask(int_mask);

}

bool key_arrow_right::interrupt() {

     if(bot_admin.keyboard_input.right) {

          on_interrupt();
          return true;

     }
     else 
          return false;

}

void key_arrow_right::on_interrupt() {

     bot_admin.keyboard_input.right = false;

}

grid_align::grid_align(int reg_context, generic_robot *robot) : 
                                                   peripheral(context, robot) {
     int_mask = INT_MASK_GRID_ALIGN;
     ack_addr.set_mask(int_mask);
     last_grid_align.x = last_grid_align.y = -1;
     //last_grid_align_grid.x = last_grid_align_grid.y = -1;

}


bool grid_align::interrupt() {

     int x_pos, y_pos;
     
     x_pos = (int) (self->props.next_pos.x);
     y_pos = (int) (self->props.next_pos.y);

     if((x_pos == last_grid_align.x) && (y_pos == last_grid_align.y))
          return false;

     if(((x_pos % GRID_SCALING) == 0) && ((y_pos % GRID_SCALING) == 0)) {

          last_grid_align.x = x_pos;
          last_grid_align.y = y_pos;
          //last_grid_align_grid.x = x_grid;
          //last_grid_align_grid.y = y_grid;
          
          on_interrupt();
          return true;

     }
     
     return false;

}

void grid_align::on_interrupt() {}

position::position(int reg_context, generic_robot *robot) 
                                                 : peripheral(context, robot) {

     int_mask = INT_MASK_POSITION;
     ack_addr.set_mask(int_mask);

}

bool position::interrupt() {

     int xpos = self->mmIO_properties[MMIO_PROP_ROBOT_X]->read(),
         ypos = self->mmIO_properties[MMIO_PROP_ROBOT_Y]->read();
     int request_x = self->mmIO_properties[MMIO_PROP_REQUEST_X]->read(),
         request_y = self->mmIO_properties[MMIO_PROP_REQUEST_Y]->read();

     if((xpos == request_x) && (ypos == request_y)) {

          on_interrupt();
          return true;

     }
     else 
          return false;

}

void position::on_interrupt() {

     self->mmIO_properties[MMIO_PROP_REQUEST_X]->write(-1),
     self->mmIO_properties[MMIO_PROP_REQUEST_Y]->write(-1);

}
 
