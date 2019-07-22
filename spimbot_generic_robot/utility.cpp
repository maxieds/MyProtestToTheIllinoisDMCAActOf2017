/* utility.cpp : various utils
 * Author: Maxie D. Schmidt    */

#include "utility.h"

// string related:
vector<string> split_string(string line, char delimeter) {

     vector<string> r_val;
     int cur_pos = 0;//, next_pos = 0;
     string temp_val = "";//, first_pos = "";
     
     while(line.length() != 0) {
          cur_pos = line.find_first_of(delimeter, 0);
          if(cur_pos == -1) {
               r_val.push_back(line);
               return r_val;
          }
          else {
               if(cur_pos != 0)
                    r_val.push_back(line.substr(0, cur_pos));
               else
                    r_val.push_back(line.substr(0, 1));
                              
               if(line.length() == cur_pos + 1)
                    return r_val;
               
               line = line.substr(cur_pos + 1, line.length() - cur_pos - 1);
          }

     }

     return r_val;

}

string trim_whitespace(string input) {

     vector<string> whitespace_chars;
     whitespace_chars.push_back("\n");
     whitespace_chars.push_back(" ");
     whitespace_chars.push_back("\t");

     for(int i = 0; i < whitespace_chars.size(); i++) {

          //bool loop_done = false;
          string cur_char = whitespace_chars[i];
          int cur_pos = 0;
          
          while(cur_pos != -1) {

               cur_pos = input.find_first_of(cur_char, 0);
               if(cur_pos != -1)
                    input = input.replace(cur_pos, 1, "");

          }

     }

     return input;
     
}

// error handling:
bot_error_t bot_error(int error_code, string msg, int line_num) {

     bot_error_t e;
     e.error_code = error_code;
     e.msg = msg;
     e.line = line_num;

     return e;

}

void print_error_msg(bot_error_t e, string error_type) {

     printf("Reached error %s:\n", error_type.c_str());
     printf("     %s\n", e.msg.c_str());
     printf("     line: %d\n\n", e.line);

}

// display props:
/*unsigned string_to_color(string color) {

     if(color == "navy")
          return NAVY_COLOR;
     else if(color == "lime")
          return LIME_COLOR;
     else if(color == "yellow")
          return YELLOW_COLOR;
     else if(color == "red")
          return RED_COLOR;
     else if(color == "lightblue")
          return LIGHTBLUE_COLOR;
     else if(color == "orange")
          return ORANGE_COLOR;
     else if(color == "darkgreen")
          return DARKGREEN_COLOR;
     else if(color == "pink")
          return PINK_COLOR;
     else if(color == "black")
          return BLACK_COLOR;
     else if(color == "white")
          return WHITE_COLOR;
     else if(color == "tan")
          return TAN_COLOR;
     else if(color == "grey")
          return GREY_COLOR;
     else if(color == "purple")
          return PURPLE_COLOR;
     else if(color == "lightpurple")
          return LIGHTPURPLE_COLOR;
     //else if(color == "transparent")
     //     return TRANSPARENT;
     else {
          
          //convert string to the unsigned
          return ((unsigned) atoi(color.c_str()));
     
     }

}*/

void setup_xcolor(string color, XColor &xcolor) {

     if(color == "blue") {

          xcolor.red = 0;
          xcolor.green = 0;
          xcolor.blue = 65535;

     }
     else if(color == "navy") {

          xcolor.red = 0;
          xcolor.green = 0;
          xcolor.blue = 26214;

     }
     else if(color == "lime") {

          xcolor.red = 13107;
          xcolor.green = 65535;
          xcolor.blue = 0;

     }
     else if(color == "yellow") {

          xcolor.red = 65535;
          xcolor.green = 65535;
          xcolor.blue = 0;

     }
     else if(color == "red") {

          xcolor.red = 65535;
          xcolor.green = 0;
          xcolor.blue = 0;

     }
     else if(color == "lightblue") {

          xcolor.red = 0;
          xcolor.green = 39321;
          xcolor.blue = 65535;

     }
     else if(color == "orange") {

          xcolor.red = 65535;
          xcolor.green = 39321;
          xcolor.blue = 0;

     }    
     else if(color == "darkgreen") {

          xcolor.red = 0;
          xcolor.green = 39321;
          xcolor.blue = 13107;

     }
     else if(color == "pink") {

          xcolor.red = 65535;
          xcolor.green = 39321;
          xcolor.blue = 52428;

     }
     else if(color == "lightpink") {

          xcolor.red = 59367;
          xcolor.green = 50886;
          xcolor.blue = 59367;

     }
     else if(color == "black") {

          xcolor.red = 0;
          xcolor.green = 0;
          xcolor.blue = 0;

     }
     else if(color == "white") {

          xcolor.red = 65535;
          xcolor.green = 65535;
          xcolor.blue = 65535;

     }
     else if(color == "tan") {

          xcolor.red = 52428;
          xcolor.green = 39321;
          xcolor.blue = 0;

     }
     else if(color == "grey") {

          xcolor.red = 39321;
          xcolor.green = 39321;
          xcolor.blue = 39321;

     }
     else if(color == "purple") {

          xcolor.red = 26214;
          xcolor.green = 0;
          xcolor.blue = 39321;

     }
     else if(color == "lightpurple") {

          xcolor.red = 39321;
          xcolor.green = 13107;
          xcolor.blue = 65535;

     }
     else {

          xcolor.red = xcolor.green = xcolor.blue = 0;

     }

     xcolor.flags = DoRed | DoGreen | DoBlue;

}
 
// mmappedIO:
mem_addr get_mmappedIO_address(int context, mmIO_prop *ptr) {

     mem_addr address = mem_images[context].CUR_MMIO_ADDR;
     mem_images[context].CUR_MMIO_ADDR += 4;
     
     addr_list_node node;
     node.address = address;
     node.location = ptr;
     mem_images[context].mmapped_address_lookup.push_back(node);

     return address;

}
     
