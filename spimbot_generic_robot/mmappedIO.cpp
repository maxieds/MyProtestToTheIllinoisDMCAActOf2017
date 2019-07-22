/* mmappedIO.cpp : read and write memory mapped properties
 * Author: Maxie D. Schmidt                                 */

#include "mmappedIO.h"
#include "genericrobot.h"

/////// base class:
mmIO_prop::mmIO_prop(generic_robot *robot){

     self = robot;

}

mem_word mmIO_prop::read() {

     return value;

}

void mmIO_prop::write(mem_word val) {

     value = val;

}

mem_addr mmIO_prop::get_address() {

     return address;

}

void mmIO_prop::set_address(mem_addr addr) {

     address = addr;

}

/////// velocity:
mmIO_velocity::mmIO_velocity(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_velocity::read() {

     return value;

}

void mmIO_velocity::write(mem_word val) {

     if(val < -10)
          value = -10;
     else if(val > 10)
          value = 10;
     else
          value = val;

}

/////// orientation value:
mmIO_orient_val::mmIO_orient_val(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_orient_val::read() {

     return value;

}

void mmIO_orient_val::write(mem_word val) {

     if(val < -360)
          value = -360;
     else if(val > 360)
          value = 360;
     else
          value = val;

}

/////// orientation ctrl:
mmIO_orient_ctrl::mmIO_orient_ctrl(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_orient_ctrl::read() {

     return value;

}

void mmIO_orient_ctrl::write(mem_word val) {

     if((val != 0) && (val != 1))
          value = 1;
     else
          value = val;

     // update the robot's orientation:
     int turn_value = self->mmIO_properties[MMIO_PROP_ORIENT_VAL]->read();
     if(value) // absolute
          self->props.orientation = turn_value * (M_PI / 180.0);
     else
          self->props.orientation += turn_value * (M_PI / 180.0);

     // check that the orientation is within bounds:
     if(self->props.orientation > (2*M_PI + PI_DELTA))
          self->props.orientation -= 2*M_PI;
     else if(self->props.orientation < (0 - PI_DELTA))
          self->props.orientation += 2*M_PI;
     assert((self->props.orientation <= (2*M_PI + PI_DELTA)) &&
                                  (self->props.orientation >= (0 - PI_DELTA)));

}

/////// robot x (range checking will be done elsewhere):
mmIO_robot_x::mmIO_robot_x(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_robot_x::read() {

     return value;

}

void mmIO_robot_x::write(mem_word val) {

     value = val;

}

/////// robot y (range checking elsewhere):
mmIO_robot_y::mmIO_robot_y(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_robot_y::read() {

     return value;

}

void mmIO_robot_y::write(mem_word val) {

          value = val;

}

mmIO_robot_grid_x::mmIO_robot_grid_x(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_robot_grid_x::read() {

     return value;

}

void mmIO_robot_grid_x::write(mem_word val) {

     if(val < 0)
          value = 0;
     else if(val >= bot_admin.environment->width)
          value = bot_admin.environment->width - 1;
     else
          value = val;

}

mmIO_robot_grid_y::mmIO_robot_grid_y(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_robot_grid_y::read() {

     return value;

}

void mmIO_robot_grid_y::write(mem_word val) {

     if(val < 0)
          value = 0;
     else if(val >= bot_admin.environment->height)
          value = bot_admin.environment->height - 1;
     else
          value = val;

}

mmIO_pacman_grid_x::mmIO_pacman_grid_x(generic_robot *robot, 
                                generic_robot *pacman_ref) : mmIO_prop(robot) {
     pacman = pacman_ref;

}

mem_word mmIO_pacman_grid_x::read() {

     if(pacman == NULL)
          return 1; // -1
     else
          return pacman->mmIO_properties[MMIO_PROP_ROBOT_GRID_X]->read();

}

void mmIO_pacman_grid_x::write(mem_word val) {} // no writing

mmIO_pacman_grid_y::mmIO_pacman_grid_y(generic_robot *robot, 
                                 generic_robot *pacman_ref): mmIO_prop(robot) {
     pacman = pacman_ref;

}

mem_word mmIO_pacman_grid_y::read() {

     if(pacman == NULL)
          return 1; // -1
     else
          return pacman->mmIO_properties[MMIO_PROP_ROBOT_GRID_Y]->read();

}

void mmIO_pacman_grid_y::write(mem_word val) {} // no writing

mmIO_request_x::mmIO_request_x(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_request_x::read() {

     return value;

}

void mmIO_request_x::write(mem_word val) {

     value = val;

}

mmIO_request_y::mmIO_request_y(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_request_y::read() {

     return value;

}

void mmIO_request_y::write(mem_word val) {

     value = val;

}

/////// timer interrupts:
mmIO_timer_int::mmIO_timer_int(generic_robot *robot) : mmIO_prop(robot) {}

mem_word mmIO_timer_int::read() {

     return bot_admin.CYCLE;

}

void mmIO_timer_int::write(mem_word val) {

          value = val;

}

/*mem_word mmIO_timer_int::interrupt_read() {

     return value;

}*/

/////// interrupt ack address:
int_ack_addr::int_ack_addr(generic_robot *robot, int regcontext) : 
                                                             mmIO_prop(robot) {

     reg_context = regcontext;
     int_mask = 0x0;

}

mem_word int_ack_addr::read() {
     
     return value;

}

void int_ack_addr::write(mem_word val) {

     //printf("inside int_ack_addr write.\n");
     value = val;
     reg_image_t &reg_image = reg_images[reg_context];
     Cause(reg_image) &= ~int_mask;
     
}

void int_ack_addr::set_mask(unsigned int mask) {

     int_mask = mask;

}
