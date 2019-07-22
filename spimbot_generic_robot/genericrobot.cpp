/* genericrobot.cpp : code for the robot base class
 * Author: Maxie D. Schmidt                          */

#include "genericrobot.h"

generic_robot::generic_robot(int reg_context) {

     props.bot_name = "generic_robot";
     props.bot_type = "generic_robot";
     props.color = "lightblue";
     props.radius = 5;
     props.orientation = 0.0;
     props.cur_pos.x = props.cur_pos.y = 0.0;
     props.next_pos.x = props.next_pos.y = 0.0;
     props.next_grid_pos.x = props.next_grid_pos.y = 0;

     context = reg_context;
     
     // setup properties:
     mmIO_properties.push_back(new mmIO_velocity(this));
     mmIO_properties.push_back(new mmIO_orient_val(this));
     mmIO_properties.push_back(new mmIO_orient_ctrl(this));
     mmIO_properties.push_back(new mmIO_robot_x(this));
     mmIO_properties.push_back(new mmIO_robot_y(this));
     mmIO_properties.push_back(new mmIO_timer_int(this));
     mmIO_properties.push_back(new mmIO_robot_grid_x(this));
     mmIO_properties.push_back(new mmIO_robot_grid_y(this));
     mmIO_properties.push_back(new mmIO_request_x(this));
     mmIO_properties.push_back(new mmIO_request_y(this));
     
     mmIO_properties[MMIO_PROP_VELOCITY]->set_address(
           get_mmappedIO_address(context, mmIO_properties[MMIO_PROP_VELOCITY]));
     mmIO_properties[MMIO_PROP_VELOCITY]->write(0);
     
     mmIO_properties[MMIO_PROP_ORIENT_VAL]->set_address(
                 get_mmappedIO_address(context, 
                 mmIO_properties[MMIO_PROP_ORIENT_VAL]));
     mmIO_properties[MMIO_PROP_ORIENT_VAL]->write(0);

     mmIO_properties[MMIO_PROP_ORIENT_CTRL]->set_address(
              get_mmappedIO_address(context, 
              mmIO_properties[MMIO_PROP_ORIENT_CTRL]));
     mmIO_properties[MMIO_PROP_ORIENT_CTRL]->write(1);

     mmIO_properties[MMIO_PROP_ROBOT_X]->set_address(
                   get_mmappedIO_address(context, 
                   mmIO_properties[MMIO_PROP_ROBOT_X]));
     mmIO_properties[MMIO_PROP_ROBOT_X]->write(0);

     mmIO_properties[MMIO_PROP_ROBOT_Y]->set_address(
                   get_mmappedIO_address(context, 
                   mmIO_properties[MMIO_PROP_ROBOT_Y]));
     mmIO_properties[MMIO_PROP_ROBOT_Y]->write(0);

     mmIO_properties[MMIO_PROP_TIMER_INT]->set_address(
                  get_mmappedIO_address(context, 
                  mmIO_properties[MMIO_PROP_TIMER_INT]));
     mmIO_properties[MMIO_PROP_TIMER_INT]->write(0);

     mmIO_properties[MMIO_PROP_ROBOT_GRID_X]->set_address(
               get_mmappedIO_address(context, 
               mmIO_properties[MMIO_PROP_ROBOT_GRID_X]));
     mmIO_properties[MMIO_PROP_ROBOT_GRID_X]->write(0);

     mmIO_properties[MMIO_PROP_ROBOT_GRID_Y]->set_address(
               get_mmappedIO_address(context, 
               mmIO_properties[MMIO_PROP_ROBOT_GRID_Y]));
     mmIO_properties[MMIO_PROP_ROBOT_GRID_Y]->write(0);

     mmIO_properties[MMIO_PROP_REQUEST_X]->set_address(
               get_mmappedIO_address(context, 
               mmIO_properties[MMIO_PROP_REQUEST_X]));
     mmIO_properties[MMIO_PROP_REQUEST_X]->write(-1);

     mmIO_properties[MMIO_PROP_REQUEST_Y]->set_address(
               get_mmappedIO_address(context, 
               mmIO_properties[MMIO_PROP_REQUEST_Y]));
     mmIO_properties[MMIO_PROP_REQUEST_Y]->write(-1);

     // peripherals:
     peripherals.push_back(new bonk_periph(context, this));
     peripherals.push_back(new timer_periph(context, this));

     peripherals[PERIPH_BONK]->ack_addr.set_address(get_mmappedIO_address(
                    context, &(peripherals[PERIPH_BONK]->ack_addr)));
     peripherals[PERIPH_TIMER]->ack_addr.set_address(get_mmappedIO_address(
                    context, &(peripherals[PERIPH_TIMER]->ack_addr)));

}

generic_robot::~generic_robot() {

     for(int i = 0; i < peripherals.size(); i++) {

          delete peripherals[i];
          peripherals[i] = NULL;

     }

     for(int j = 0; j < mmIO_properties.size(); j++) {

          delete mmIO_properties[j];
          mmIO_properties[j] = NULL;

     }

}

void generic_robot::maintenence() {

     for(int i = 0; i < robot_contact.size(); i++)
          robot_contact.pop();
     for(int k = 0; k < env_obj_contact.size(); k++)
          env_obj_contact.pop();

}

#ifdef DEBUGGING
void generic_robot::print_info() {
 
     printf("Robot type: %s \n\n", props.bot_type.c_str());
     
     // print addresses:
     printf("mmapped properties addresses:\n");
     for(int i = 0; i < mmIO_properties.size(); i++)
          printf("(# = %d): 0x%08x\n", i, mmIO_properties[i]->get_address());

     printf("\nperipherals ack addresses:\n");

     for(int k = 0; k < peripherals.size(); k++)
          printf("(# = %d) 0x%08x\n", k, peripherals[k]->ack_addr.get_address());

}
#endif

// derived classes:
pacbot::pacbot(int reg_context) : generic_robot(reg_context) {

     num_pebbles_eaten = 0;

     // additional peripherals:
     peripherals.push_back(new key_arrow_up(context, this));
     peripherals.push_back(new key_arrow_down(context, this));
     peripherals.push_back(new key_arrow_left(context, this));
     peripherals.push_back(new key_arrow_right(context, this));
     peripherals.push_back(new grid_align(context, this));
     
     peripherals[PERIPH_PACBOT_ARROW_UP]->ack_addr.set_address(
                 get_mmappedIO_address(context, 
                 &(peripherals[PERIPH_PACBOT_ARROW_UP]->ack_addr)));
     peripherals[PERIPH_PACBOT_ARROW_DOWN]->ack_addr.set_address(
                 get_mmappedIO_address(context, 
                 &(peripherals[PERIPH_PACBOT_ARROW_DOWN]->ack_addr)));
     peripherals[PERIPH_PACBOT_ARROW_LEFT]->ack_addr.set_address(
                 get_mmappedIO_address(context, 
                 &(peripherals[PERIPH_PACBOT_ARROW_LEFT]->ack_addr)));
     peripherals[PERIPH_PACBOT_ARROW_RIGHT]->ack_addr.set_address(
                 get_mmappedIO_address(context, 
                 &(peripherals[PERIPH_PACBOT_ARROW_RIGHT]->ack_addr)));
     peripherals[PERIPH_PACBOT_GRID_ALIGN]->ack_addr.set_address(
                 get_mmappedIO_address(context, 
                 &(peripherals[PERIPH_PACBOT_GRID_ALIGN]->ack_addr)));

}

void pacbot::maintenence() {

     if(num_pebbles_eaten >= 85)
          bot_admin.game_over = true;

     // merge robot collisions:
     vector<int> collisions;
     while(!robot_contact.empty()) {
          
          collisions.push_back(robot_contact.front());
          robot_contact.pop();

     }
     while(!incoming_robot_contact.empty()) {

          int cur_front = incoming_robot_contact.front();
          for(int i = 0; i < collisions.size(); i++) {
               
               if(collisions[i] == incoming_robot_contact.front()) {

                    incoming_robot_contact.pop();
                    break;

               }
          
          }

          if(cur_front == incoming_robot_contact.front()) {
               
               collisions.push_back(incoming_robot_contact.front());
               incoming_robot_contact.pop();

          }

     }
     
     for(int i = 0; i < collisions.size(); i++) {

          if(bot_admin.robot_list[collisions[i]].robot->props.bot_type 
                                                               == "ghostbot") { 
               bot_admin.game_over = true;
               break;

          }

     }
     
     // env_objects:
     for(int i = 0; i < env_obj_contact.size(); i++) {

          env_object *obj = bot_admin.envobj_list[env_obj_contact.front()];
          if((obj != NULL) && (obj->props.type == "pacman_pebble"))
               num_pebbles_eaten++;

          env_obj_contact.pop();

     }

}

ghostbot::ghostbot(int reg_context) : generic_robot(reg_context) {

     pacman = NULL;
     for(int i = 0; i < num_contexts; i++) {

          generic_robot *robot = bot_admin.robot_list[i].robot;
          if((robot != NULL) && (robot->props.bot_type == "pacbot")) {
               
               pacman = robot;
               break;

          }

     }
     
     // add pacman position detection:
     mmIO_properties.push_back(new mmIO_pacman_grid_x(this, pacman));
     mmIO_properties.push_back(new mmIO_pacman_grid_y(this, pacman));

     mmIO_properties[MMIO_PROP_PACMAN_GRID_X]->set_address(
               get_mmappedIO_address(context, 
               mmIO_properties[MMIO_PROP_PACMAN_GRID_X]));
     mmIO_properties[MMIO_PROP_PACMAN_GRID_Y]->set_address(
               get_mmappedIO_address(context, 
               mmIO_properties[MMIO_PROP_PACMAN_GRID_Y]));

     // peripherals: align grid to let the ghostbot travel with 
     // minimal bonks:
     peripherals.push_back(new grid_align(context, this));
     peripherals.push_back(new position(context, this));
     
     peripherals[PERIPH_GHOSTBOT_GRID_ALIGN]->ack_addr.set_address(
               get_mmappedIO_address(context, 
               &(peripherals[PERIPH_GHOSTBOT_GRID_ALIGN]->ack_addr))); 
     
     peripherals[PERIPH_GHOSTBOT_POSITION]->ack_addr.set_address(
               get_mmappedIO_address(context, 
               &(peripherals[PERIPH_GHOSTBOT_POSITION]->ack_addr)));

}

void ghostbot::maintenence() {

     if(pacman == NULL) {

          for(int i = 0; i < num_contexts; i++) {

               generic_robot *robot = bot_admin.robot_list[i].robot;
               if((robot != NULL) && (robot->props.bot_type == "pacbot")) {

                    pacman = robot;
                    //mmIO_properties[MMIO_PROP_PACMAN_GRID_X]->set_pacman(
                    //                                              pacman);
                    //mmIO_properties[MMIO_PROP_PACMAN_GRID_Y]->set_pacman(
                    //                                              pacman);
                    break;

               }

          }

     }

     // collisions: pacbot checks for contact with a ghostbot to 
     // see if need to set game_over; empty the queues;
     while(!robot_contact.empty())
          robot_contact.pop();
     while(!incoming_robot_contact.empty())
          incoming_robot_contact.pop();
     while(!env_obj_contact.empty())
          env_obj_contact.pop();

}

// update this function as new robot types are created:
generic_robot * create_generic_robot(string type, int context) {

     if(type == "generic_robot")
          return new generic_robot(context);
     else if(type == "pacbot")
          return new pacbot(context);
     else if(type == "ghostbot")
          return new ghostbot(context);
     else
          return NULL;

}
