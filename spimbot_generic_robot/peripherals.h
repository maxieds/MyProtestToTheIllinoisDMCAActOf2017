/* peripherals.h : robot peripherals and corresp. interrupt data
 * Author: Maxie D. Schmidt (created 4/17/2006)                   */

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

#include <stdio.h>
#include <string.h>

#include <vector>
using namespace std;

#include "SPIMbot.h"
#include "types.h"
#include "externs.h"
#include "utility.h"
#include "envobject.h"
#include "mmappedIO.h"

/////// peripherals documentation (indices of peripherals):
// generic (all bots have these):
#define PERIPH_BONK                0
#define PERIPH_TIMER               1

// pacman (pacbot):
#define PERIPH_PACBOT_ARROW_UP     2
#define PERIPH_PACBOT_ARROW_DOWN   3
#define PERIPH_PACBOT_ARROW_LEFT   4
#define PERIPH_PACBOT_ARROW_RIGHT  5
#define PERIPH_PACBOT_GRID_ALIGN   6

// pacman ghostbot:
#define PERIPH_GHOSTBOT_GRID_ALIGN 2
#define PERIPH_GHOSTBOT_POSITION   3

/////// documentation : interrupt masks:
#define INT_MASK_BONK               ((unsigned int) 0x1000)
#define INT_MASK_TIMER              ((unsigned int) 0x8000)
#define INT_MASK_PACBOT_ARROW_UP    ((unsigned int) 0x2000)
#define INT_MASK_PACBOT_ARROW_DOWN  ((unsigned int) 0x4000)
#define INT_MASK_PACBOT_ARROW_LEFT  ((unsigned int) 0x100)
#define INT_MASK_PACBOT_ARROW_RIGHT ((unsigned int) 0x200)
#define INT_MASK_GENERIC_PERIPH     ((unsigned int) 0x400)
#define INT_MASK_GRID_ALIGN         ((unsigned int) 0x800)
#define INT_MASK_POSITION           ((unsigned int) 0x10000)


class peripheral {

     public:
          peripheral(int reg_context, generic_robot *robot);

          virtual bool interrupt(); // true if need interrupt
          virtual void on_interrupt(); // on bonk need to set vel. = 0, etc.
          
          generic_robot *self;
          int context;
          
          unsigned int int_mask;
          int_ack_addr ack_addr;

};

// derived classes:
class bonk_periph : public peripheral {

     public:
          bonk_periph(int reg_context, generic_robot *robot);
          bool interrupt();
          void on_interrupt();

};

class timer_periph : public peripheral {

     public:
          timer_periph(int context, generic_robot *robot);
          bool interrupt();
          void on_interrupt();

};

class key_arrow_up : public peripheral {

     public:
          key_arrow_up(int context, generic_robot *robot);
          bool interrupt();
          void on_interrupt();
     
};

class key_arrow_down : public peripheral {

     public:
          key_arrow_down(int context, generic_robot *robot);
          bool interrupt();
          void on_interrupt();
     
};

class key_arrow_left : public peripheral {

     public:
          key_arrow_left(int context, generic_robot *robot);
          bool interrupt();
          void on_interrupt();
     
};

class key_arrow_right : public peripheral {

     public:
          key_arrow_right(int context, generic_robot *robot);
          bool interrupt();
          void on_interrupt();
     
};

class grid_align : public peripheral {

     public:
          grid_align(int reg_context, generic_robot *robot);

          bool interrupt();
          void on_interrupt();

     protected:
          xy_point last_grid_align; // pixels
          //xy_point last_grid_align_grid; // grid-wise

};

class position : public peripheral {

     public:
          position(int reg_context, generic_robot *robot);

          bool interrupt();
          void on_interrupt();

};

#endif
