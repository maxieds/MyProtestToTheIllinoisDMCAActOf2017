/* gameparser.cpp : code to parse .game files
 * Author: Maxie D. Schmidt (created 4/17/2006)  */

#include "gameparser.h"

bot_env * parse_env_file(const char *env_file) {

     FILE *fp = fopen(env_file, "r");
     if(fp == NULL) {

          bot_error_t e = bot_error(NO_SUCH_FILE, "Unable to open the env file",
                                    0);
          print_error_msg(e, "NO_SUCH_FILE");
          exit(-1);

     }
          
     bot_env *r_val = new bot_env();
     int line_num = 0, num_grid_rows = 0;
     char line[1001]; // this should be the max size of env ...
     vector<string> split_str;
     vector<char> row;
     bool parsing_grid = false, parsing_grid_types = false;
     
     env_parse_chklst chklst;
     chklst.height = chklst.width = chklst.grid = false;

     while(!feof(fp)) {


          if(fgets(line, 1000, fp) == NULL) {

               bot_error_t e = bot_error(UNEXPECTED_EOF, "File error.", 
                                         line_num);
               print_error_msg(e, "UNEXPECTED_EOF");
               exit(-1);

          }
          line_num++;
          
          // check for blank line and comments:
          if(!strcmp(line, "\n"))
               continue;
          else if((strlen(line) >= 2) && (line[0] == '/') && (line[1] == '/')) 
               continue;
          
          split_str = split_string(trim_whitespace(line), '=');
          if(!parsing_grid) {
               
               if(split_str[0] == HEIGHT) {
               
                    r_val->height = (unsigned) atoi(split_str[1].c_str());
                    chklst.height = true;

               }
               else if(split_str[0] == WIDTH) {

                    r_val->width = (unsigned) atoi(split_str[1].c_str());
                    chklst.width = true;

               }
               else if((split_str[0] == START_GRID) && (!chklst.width || 
                        !chklst.height)) {
           
                    bot_error_t e = bot_error(PARSE_OTHER_ERROR, 
                                   "need to specify h/w before grid", line_num);
                    print_error_msg(e, "PARSE_OTHER_ERROR");
                    fclose(fp);
                    exit(-1);

               }
               else if(split_str[0] == START_GRID)
                    parsing_grid = true;

          }
          else { // parsing grid (only run through this once)
          
               if(split_str[0] == END_GRID) {

                    chklst.grid = true;
                    break; // should be out of while, ... (debug me)

               }
               
               // get the grid:
               if(!parsing_grid_types) {
               
                    if(split_str[0].length() < r_val->width) {

                         bot_error_t e = bot_error(PARSE_OTHER_ERROR, 
                                         "Env. grid row is too short.", 
                                         line_num);
                         print_error_msg(e, "PARSE_OTHER_ERROR");
                         fclose(fp);
                         exit(-1);

                    }
                    
                    for(int i = 0; i < r_val->width; i++)
                         row.push_back(split_str[0][i]);
                    r_val->grid.push_back(row);

                    row.clear();
                    num_grid_rows++;
                    if(num_grid_rows == r_val->height)
                         parsing_grid_types = true;
                    
               }
               else { // defining types

                    env_object *obj = create_env_object(split_str[1]);
                    obj->obj_key = split_str[0][0];
                    bot_admin.envobj_list.add_object(obj);

               }
                    
          }

     } // while

     fclose(fp);
     
     // check the checklist:
     if(!chklst.height || !chklst.width || !chklst.grid) {
          
          bot_error_t e = bot_error(PARSE_OTHER_ERROR,
                                    "Need to include more in the file", 
                                    line_num);
          print_error_msg(e, "PARSE_OTHER_ERROR");
          exit(-1);

     }

     return r_val;

}

void parse_game_file(const char *game_file) {

     FILE *fp = fopen(game_file, "r");
     if(fp == NULL) {

          bot_error_t e = bot_error(NO_SUCH_FILE, "Unable to open game file.",
                                    0);
          print_error_msg(e, "NO_SUCH_FILE");
          exit(-1);

     }

     int line_num = 0, num_robots = 0;
     char line[1001];
     vector<string> split_str;
     bool parsing_robot = false;
     generic_robot *cur_robot = NULL;
     
     // checklists
     game_parse_chklst gamelst;
     gamelst.env_file = gamelst.robots = false;
     robot_chklst botlst;
     botlst.type = botlst.bot_name = botlst.asm_file = botlst.start_x
                 = botlst.start_y = false;

     while(fgets(line, 1000, fp) && !feof(fp)) {

          //if(fgets(line, 1000, fp) == NULL) {
          //
          //     bot_error_t e = bot_error(UNEXPECTED_EOF, "File error.", 
          //                               line_num);
          //     print_error_msg(e, "UNEXPECTED_EOF");
          //     fclose(fp);
          //     exit(-1);
          //
          //}
          
          line_num++;
          
          // blank lines and comments:
          if(!strcmp(line, "\n"))
               continue;
          else if((strlen(line) >= 2) && (line[0] == '/') && (line[1] == '/'))
               continue;
          
          // parse the line:
          split_str = split_string(trim_whitespace(line), '=');
          if((split_str[0] == ENV_FILE) && !parsing_robot) {

               gamelst.env_file = true;
               bot_admin.environment = parse_env_file(split_str[1].c_str());

          }
          else if((split_str[0] == BEGIN_ROBOT) && !parsing_robot) {

               parsing_robot = true;

          }
          else if(split_str[0] == BEGIN_ROBOT) {

               bot_error_t e = bot_error(ROBOT_SETUP_ERROR, 
                               "Cannot begin a robot within another robot.",
                               line_num);
               print_error_msg(e, "ROBOT_SETUP_ERROR");
               fclose(fp);
               exit(-1);

          }
          else if((split_str[0] == END_ROBOT) && !parsing_robot) {

               bot_error_t e = bot_error(PARSE_OTHER_ERROR, 
                               "END_ROBOT needs BEGIN_ROBOT.", line_num);
               print_error_msg(e, "PARSE_OTHER_ERROR");
               fclose(fp);
               exit(-1);

          }
          else if(split_str[0] == END_ROBOT) {

               parsing_robot = false;
               num_robots++;
               gamelst.robots = true;
               if(!botlst.type || !botlst.bot_name || !botlst.radius || 
                  !botlst.asm_file || !botlst.start_x || !botlst.start_y) {

                    bot_error_t e = bot_error(PARSE_OTHER_ERROR,
                                    "Need more info on the robot.", line_num);
                    print_error_msg(e, "PARSE_OTHER_ERROR");
                    fclose(fp);
                    exit(-1);

               }
               
               botlst.type = botlst.bot_name = botlst.radius = botlst.asm_file 
                           = botlst.start_x = botlst.start_y = false;
               
                              cur_robot = NULL;

          }
          else if((split_str[0] == TYPE) && parsing_robot) {
               
               robot_context bot;
               bot.reg_context = bot_admin.filenames.size();
               //bot.robot = new generic_robot(bot.reg_context);
               bot.robot = create_generic_robot(split_str[1], bot.reg_context);
               bot_admin.robot_list.push_back(bot);               

               cur_robot = bot_admin.robot_list[bot_admin.filenames.size()]
                                                                         .robot;
               cur_robot->props.bot_type = split_str[1];
               botlst.type = true;

          }
          else if((split_str[0] == BOT_NAME) && parsing_robot) {

               cur_robot->props.bot_name = split_str[1];
               botlst.bot_name = true;

          }
          else if((split_str[0] == COLOR) && parsing_robot) {
               
               cur_robot->props.color = split_str[1];
               //botlst.color = true;

          }
          else if((split_str[0] == RADIUS) && parsing_robot) {
               
               cur_robot->props.radius = atoi(split_str[1].c_str());
               botlst.radius = true;

          }
          else if((split_str[0] == ASM_FILE) && parsing_robot) {
               
               bot_admin.filenames.push_back(split_str[1]);
               botlst.asm_file = true;     
          
          } 
          else if((split_str[0] == START_X) && parsing_robot) {
               
               cur_robot->mmIO_properties[MMIO_PROP_ROBOT_X]->write(
                          atoi(split_str[1].c_str()));
               cur_robot->mmIO_properties[MMIO_PROP_ROBOT_GRID_X]->write((int)
                        (cur_robot->mmIO_properties[MMIO_PROP_ROBOT_X]->read())
                          / GRID_SCALING);
               botlst.start_x = true;

          }
          else if((split_str[0] == START_Y) && parsing_robot) {
               
               cur_robot->mmIO_properties[MMIO_PROP_ROBOT_Y]->write(
                          atoi(split_str[1].c_str()));
               cur_robot->mmIO_properties[MMIO_PROP_ROBOT_GRID_Y]->write((int)
                        (cur_robot->mmIO_properties[MMIO_PROP_ROBOT_Y]->read())
                         / GRID_SCALING);
               botlst.start_y = true;

          }
          
     }

     fclose(fp);
     
     if(parsing_robot) {

          bot_error_t e = bot_error(UNEXPECTED_EOF, "Still parsing robot",
                                    line_num);
          print_error_msg(e, "uNEXPECTED_EOF");
          exit(-1);

     }

     if(!gamelst.env_file || !gamelst.robots) {

          bot_error_t e = bot_error(ROBOT_SETUP_ERROR, 
                          "Need more info in the file.", line_num);
          print_error_msg(e, "ROBOT_SETUP_ERROR");
          exit(-1);

     }

}
