/* mmappedIO.h : read and write memory mapped props (base class)
 * Author: Maxie D. Schmidt (created 4/17/2006)                  */

#ifndef _MMAPPEDIO_H_
#define _MMAPPEDIO_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "SPIMbot.h"
#include "types.h"
#include "externs.h"
#include "reg.h"

/////// memory mapped props documentation (indices of mmIO_properties):
#define MMIO_PROP_VELOCITY         0
#define MMIO_PROP_ORIENT_VAL       1
#define MMIO_PROP_ORIENT_CTRL      2
#define MMIO_PROP_ROBOT_X          3
#define MMIO_PROP_ROBOT_Y          4
#define MMIO_PROP_TIMER_INT        5
#define MMIO_PROP_ROBOT_GRID_X     6
#define MMIO_PROP_ROBOT_GRID_Y     7
#define MMIO_PROP_REQUEST_X        8
#define MMIO_PROP_REQUEST_Y        9

// pacman ghostbot:
#define MMIO_PROP_PACMAN_GRID_X    10
#define MMIO_PROP_PACMAN_GRID_Y    11

class mmIO_prop {

     public:
          mmIO_prop(generic_robot *robot);
          
          virtual mem_word read();
          virtual void write(mem_word val); // keep within range
          mem_addr get_address();
          void set_address(mem_addr addr);
          
     //protected:
          mem_addr address;
          mem_word value;
          generic_robot *self;

};

// build off the base class:
class mmIO_velocity : public mmIO_prop {

     public:
          mmIO_velocity(generic_robot *robot);
          
          mem_word read();
          void write(mem_word val);

};

class mmIO_orient_val : public mmIO_prop {

     public:
          mmIO_orient_val(generic_robot *robot);
          
          mem_word read();
          void write(mem_word val);

};

class mmIO_orient_ctrl : public mmIO_prop {

     public:
          mmIO_orient_ctrl(generic_robot *robot);
          
          mem_word read();
          void write(mem_word val);

};

class mmIO_robot_x : public mmIO_prop {

     public:
          mmIO_robot_x(generic_robot *robot);
          
          mem_word read();
          void write(mem_word val);

};

class mmIO_robot_y : public mmIO_prop {

     public:
          mmIO_robot_y(generic_robot *robot);
          
          mem_word read();
          void write(mem_word val);

};

class mmIO_robot_grid_x : public mmIO_prop {

     public:
          mmIO_robot_grid_x(generic_robot *robot);

          mem_word read();
          void write(mem_word val);

};

class mmIO_robot_grid_y : public mmIO_prop {

     public:
          mmIO_robot_grid_y(generic_robot *robot);

          mem_word read();
          void write(mem_word val);

};

class mmIO_pacman_grid_x : public mmIO_prop {

     public:
          mmIO_pacman_grid_x(generic_robot *robot, generic_robot *pacman_ref);

          mem_word read();
          void write(mem_word val);

     protected:

          generic_robot *pacman;

};

class mmIO_pacman_grid_y : public mmIO_prop {

     public:
          mmIO_pacman_grid_y(generic_robot *robot, generic_robot *pacman_ref);

          mem_word read();
          void write(mem_word val);

     protected:

          generic_robot *pacman;

};

class mmIO_request_x : public mmIO_prop {

     public:
          mmIO_request_x(generic_robot *robot);

          mem_word read();
          void write(mem_word val);

};

class mmIO_request_y : public mmIO_prop {

     public:
          mmIO_request_y(generic_robot *robot);

          mem_word read();
          void write(mem_word val);

};

// this one is used to tell whether a timer interrupt is ready: the peripheral
// function checks to see if it matches the current timer to see if it should
// issue interrupt.
class mmIO_timer_int : public mmIO_prop {

     public:
          mmIO_timer_int(generic_robot *robot);

          mem_word read();
          void write(mem_word val);

          // read() returns bot_admin.CYCLE; write() writes the cycle
          // time of the next timer interrupt; to read this value
          // to determine if there is an interrupt use the following
          // function.
          //mem_word interrupt_read();

};

// this is to get the end of interrupt correct for peripherals:
class int_ack_addr : public mmIO_prop {

     public:
          int_ack_addr(generic_robot *robot, int reg_context);

          mem_word read();
          void write(mem_word val);
          void set_mask(unsigned int mask);

     protected:
          int reg_context;
          unsigned int int_mask;

};

#endif
