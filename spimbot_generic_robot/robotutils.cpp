/* robotutils.cpp : replacement for robot.{c,h} in the original spimbot code
 * Author: Maxie D. Schmidt (created 4/22/2006)                              */

#include "robotutils.h"

Widget mapshell;
Widget mappane;
Widget map = NULL;

robot_admin bot_admin;

int SPIMBOT_TOURNAMENT = 0;
int cycle_limit = 0;
int EXIT_WHEN_DONE = 0;

void world_initialize() {

     bot_admin.CYCLE = 0x00000000;
     bot_admin.keyboard_input.up = bot_admin.keyboard_input.down 
      = bot_admin.keyboard_input.left = bot_admin.keyboard_input.right = false;

     for(int i = 0; i < MAX_NUM_ROBOTS; i++)
          mem_images[i].CUR_MMIO_ADDR = 0xffff0000;
     
     parse_game_file(game_file);

}

void create_map_display(void) {

     String trans = "<Expose>: redraw_map_window()\n\
                     <Key>Up: arrow_key_up()\n\
                     <Key>Down: arrow_key_down()\n\
                     <Key>Left: arrow_key_left()\n\
                     <Key>Right: arrow_key_right()";
     map = XtVaCreateManagedWidget("map", coreWidgetClass, mappane, 
               XtNtranslations, XtParseTranslationTable(trans), XtNwidth,
               (bot_admin.environment->width)*GRID_SCALING, XtNheight, 
               (bot_admin.environment->height)*GRID_SCALING, NULL);
     XtPopup(mapshell, XtGrabNone);

}

void redraw_map_window(Widget w, XEvent *event, String *params, 
                                                        Cardinal *num_params) {

     Display *d = XtDisplay(w);
     Window W = XtWindow(w);
     GC gc = DefaultGCOfScreen(XtScreen(w));
     int screen = DefaultScreen(d); 
     Colormap colormap = DefaultColormap(d, screen);
     XColor color;
     
     // clear the screen:
     XClearWindow(d, W);
     //XClearArea(d, W, 0, 0, bot_admin.environment->width,
     //           bot_admin.environment->height, 0);

     // draw the env. objects:
     env_object *obj;
     for(int i = 0; i < bot_admin.environment->height; i++) {

          for(int j = 0; j < bot_admin.environment->width; j++) {

               if(bot_admin.environment->grid[i][j] == 'x')
                    continue;
          
               obj = bot_admin.envobj_list[bot_admin.environment->grid[i][j]];
               if((obj != NULL) && (obj->props.visible)) {

                    setup_xcolor(obj->props.color, color);
                    XAllocColor(d, colormap, &color);
                    XSetForeground(d, gc, color.pixel);
                    XFillRectangle(d, W, gc, j*GRID_SCALING, i*GRID_SCALING, 
                                   GRID_SCALING, GRID_SCALING);
                    //XDrawPoint(d, W, gc, j, i); // too slow for large grids

               }

          }

     }

     // draw robots:
     generic_robot *robot;
     for(int i = 0; i < bot_admin.robot_list.size(); i++) {

          robot = bot_admin.robot_list[i].robot;
          if(robot != NULL) { // (killed robots are NULL)

               setup_xcolor(robot->props.color, color);
               XAllocColor(d, colormap, &color);
               XSetForeground(d, gc, color.pixel);
               XFillArc(d, W, gc, 
                        robot->mmIO_properties[MMIO_PROP_ROBOT_X]->read(), 
                        robot->mmIO_properties[MMIO_PROP_ROBOT_Y]->read(),
                        2*(robot->props.radius), 2*(robot->props.radius),
                        0, 360 * 64);

          }

     }

     XFlush(d);

} 

void write_spimbot_IO(int context, mem_addr addr, mem_word value) {

     if(addr >= mem_images[context].CUR_MMIO_ADDR) {

          run_error("Write to unused memory-mapped IO address (0x%x)\n", addr);
          return;

     }
     
     int addr_index = (0x0000ffff & addr) / 4;
     mem_images[context].mmapped_address_lookup[addr_index].location
                                                                 ->write(value);
     
}

mem_word read_spimbot_IO(int context, mem_addr addr) {

     if(addr >= mem_images[context].CUR_MMIO_ADDR) {

          run_error("Read from unused memory-mapped IO address (0x%x)\n", addr);
          return 0;

     }
     
     int addr_index = (0x0000ffff & addr) / 4;
     return mem_images[context].mmapped_address_lookup[addr_index].location
                                                                       ->read();

}

void arrow_key_up(Widget w, XEvent *event, String *params, 
                                                         Cardinal *num_params) {

     //printf("UP\n");
     bot_admin.keyboard_input.up = true;
}

void arrow_key_down(Widget w, XEvent *event, String *params, 
                                                         Cardinal *num_params) {

     //printf("DOWN\n");
     bot_admin.keyboard_input.down = true;

}

void arrow_key_left(Widget w, XEvent *event, String *params,
                                                         Cardinal *num_params) {

     //printf("LEFT\n");
     bot_admin.keyboard_input.left = true;

}

void arrow_key_right(Widget w, XEvent *event, String *params, 
                                                         Cardinal *num_params) {

     //printf("RIGHT\n");
     bot_admin.keyboard_input.right = true;

}

void spimbot_map_click() {}

int world_update() {
     
     if(bot_admin.game_over)
          return 1;

     for(int i = 0; i < num_contexts; i++) {
          
          generic_robot *robot = bot_admin.robot_list[i].robot;
          reg_image_t &reg_image = reg_images[i];
          
          // need to do some initializations on startup:
          if(bot_admin.CYCLE == 0x00000000) {

               robot->props.cur_pos.x = (float) robot->
                                    mmIO_properties[MMIO_PROP_ROBOT_X]->read();
               robot->props.cur_pos.y = (float) robot->
                                    mmIO_properties[MMIO_PROP_ROBOT_Y]->read();

          }
          
          // calculate the next grid positions (then check for interrupts
          // before move to the new positions):
          double velocity = VELOCITY_SCALING_FACTOR * (robot->
                                  mmIO_properties[MMIO_PROP_VELOCITY]->read());
          double delta_x = cos(robot->props.orientation) * velocity;
          double delta_y = sin(robot->props.orientation) * velocity * (-1.0);
          
          robot->props.next_pos.x = robot->props.cur_pos.x + delta_x;
          robot->props.next_pos.y = robot->props.cur_pos.y + delta_y;
          robot->props.next_grid_pos.x = 
                                  (int) robot->props.next_pos.x / GRID_SCALING;
          robot->props.next_grid_pos.y = 
                                  (int) robot->props.next_pos.y / GRID_SCALING;

          // check for interrupts:
          unsigned int cause = 0;
          for(int k = 0; k < (robot->peripherals.size()); k++) {

               if((robot->peripherals[k]->interrupt()) && 
                  (INTERRUPTS_ON(reg_image)) && 
                  (Status_Reg(reg_image) & (robot->peripherals[k]->int_mask))) {
                    
                    cause |= (robot->peripherals[k]->int_mask);
                    // robot->peripherals[k]->on_interrupt();
                    //printf("     * cause has been or'ed\n");

               }

          }
          if(cause != 0) {
              RAISE_EXCEPTION(reg_image, INT_EXCPT, Cause(reg_image) |= cause);
          }

          // update the positions:
          robot->props.cur_pos.x = robot->props.next_pos.x;
          robot->props.cur_pos.y = robot->props.next_pos.y;
          robot->mmIO_properties[MMIO_PROP_ROBOT_X]->write((int) 
                                                     (robot->props.cur_pos.x));
          robot->mmIO_properties[MMIO_PROP_ROBOT_Y]->write((int) 
                                                     (robot->props.cur_pos.y));
          robot->mmIO_properties[MMIO_PROP_ROBOT_GRID_X]->write(
                                                 robot->props.next_grid_pos.x);
          robot->mmIO_properties[MMIO_PROP_ROBOT_GRID_Y]->write(
                                                 robot->props.next_grid_pos.y);

          // find timer value for one grid:
          /*if(robot->context == 0) {

               int xpos = robot->mmIO_properties[MMIO_PROP_ROBOT_X]->read();
               int ypos = robot->mmIO_properties[MMIO_PROP_ROBOT_Y]->read();
               if(xpos == 140)
                    printf("x 140 : cycle = %08x\n", bot_admin.CYCLE);
               else if(xpos == 154)
                    printf("x 154 : cycle = %08x\n", bot_admin.CYCLE);
               else if(xpos == 168)
                    printf("x 168 : cycle = %08x\n", bot_admin.CYCLE);
               else if(xpos == 182)
                    printf("x 182 : cycle = %08x\n", bot_admin.CYCLE);
               else if(xpos == 196)
                    printf("x 196 : cycle = %08x\n", bot_admin.CYCLE);


          }*/
          
     }
     
     // after all the robots have been checked for interrupts, etc., 
     // run any maintenece tasks:
     for(int i = 0; i < num_contexts; i++) {
          bot_admin.robot_list[i].robot->maintenence();
     }
     for(int j = 0; j < bot_admin.envobj_list.size(); j++) {
          bot_admin.envobj_list[j]->maintenence();
     }
     
     // other maintenence:
     // from xspim.c (line 1087), get keypresses processed:
     while(XtAppPending(app_context)) {

          XEvent event;
          XtAppNextEvent(app_context, &event);
          XtDispatchEvent(&event);

     }
     if((bot_admin.CYCLE & 0xfff) == 0) { // prev: 0x3ff, 0x1fff
          
          redraw_map_window(map, NULL, NULL, NULL);
          //usleep(4000);

     }
     
     bot_admin.CYCLE++;

     return -1;

}
