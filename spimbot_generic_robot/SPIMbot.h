/* SPIMbot.h : give some definitions if not compiling with the SPIM files.
 * Author: Maxie D. Schmidt (created 4/17/2006)                            */

#ifndef _SPIMBOT_H_
#define _SPIMBOT_H_

#define __STDC_LIMIT_MACROS
#ifdef __DARWIN__
#include <stdint.h>
#define SPIMBOT_MAXINT_32  INT32_MAX
#else
#include <values.h>
#define SPIMBOT_MAXINT_32 MAXINT
#endif

#define DEBUGGING
#define MAX_NUM_ROBOTS    10

typedef unsigned int uint32;
typedef uint32 mem_addr;
typedef int mem_word;
typedef int reg_word;

#define SPIMBOT_IO_BOT ((mem_addr) 0xffff0000)
#define SPIMBOT_IO_TOP ((mem_addr) 0xffffffff)

//#define MM_IO_BOT ((mem_addr) 0xffff0000)
//#define MM_IO_TOP ((mem_addr) 0xffffffff)
    
// other constants:
const int GRID_SCALING = 14;
const double PI_DELTA = .001;
const double VELOCITY_SCALING_FACTOR = .0004;
//const double VELOCITY_SCALING_FACTOR = .00001; // works; too slow


#endif
