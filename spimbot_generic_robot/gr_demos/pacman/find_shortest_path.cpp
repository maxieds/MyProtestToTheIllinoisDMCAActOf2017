#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <vector>
#include <string>
using namespace std;

// types:
typedef vector<int> grid_path_t;

enum status {READY, WAITING, PROCESSED};

typedef struct {

     int x, y;

} xy_point;

typedef vector<xy_point> xy_path_t;

// vars:
const int GRID_HEIGHT = 22;
const int GRID_WIDTH = 19;

// pacman maze1:
char grid[GRID_HEIGHT][GRID_WIDTH] = 
               {{'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}, 
                {'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'x', 'W', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'W', 'x', 'W'},
                {'W', 'x', 'W', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'W', 'x', 'W'},
                {'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'x', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'x', 'W'},
                {'W', 'x', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'W', 'W', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'W', 'W', 'W'},
                {'W', 'W', 'W', 'W', 'x', 'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W', 'x', 'W', 'W', 'W', 'W'},
                {'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W'},
                {'W', 'x', 'x', 'x', 'x', 'x', 'x', 'W', 'W', 'W', 'W', 'W', 'x', 'x', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W'},
                {'W', 'W', 'W', 'W', 'x', 'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W', 'x', 'W', 'W', 'W', 'W'},
                {'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W'},
                {'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'x', 'W', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'x', 'W', 'W', 'x', 'W'},
                {'W', 'x', 'x', 'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W', 'x', 'x', 'W'},
                {'W', 'W', 'x', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'x', 'x', 'W'},
                {'W', 'x', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'W', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'x', 'W', 'W', 'W', 'W', 'W', 'W', 'x', 'W', 'x', 'W', 'W', 'W', 'W', 'W', 'W', 'x', 'W'},
                {'W', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'W'},
                {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}};

// functions:
grid_path_t find_path(int start_y, int start_x, int end_y, int end_x);
void print_path(grid_path_t path);
void print_xy_path(xy_path_t path);
void print_directions(vector<int> directions);
void print_solved_maze(grid_path_t path, char path_char);

// conversions:
// directions: next square from current pos (assumes that start square is the
// current position for the ghostbot):
//             1 = UP
//             2 = DOWN
//             3 = LEFT
//             4 = RIGHT
xy_path_t path_to_xy_path(grid_path_t path);
vector<int> get_directions(xy_path_t path);

// helper functions:
int point_to_grid_square(xy_point point);
xy_point grid_square_to_point(int grid_square);
char index_to_alphabet(int index);
string int_to_string(int i);

int main() {

     /////// print paths and path lengths first in the file:
      
     FILE *fp = fopen("paths.code", "w");
     assert(fp != NULL);
     
     fputs("####### paths and lengths:\n", fp);
     fputs("null_path: .word 0\n", fp);
     
     string path_line;
     for(int i = 0; i < GRID_HEIGHT; i++) { // gy

          for(int j = 0; j < GRID_WIDTH; j++) { // gx

               for(int k = 0; k < GRID_HEIGHT; k++) { // py

                    for(int l = 0; l < GRID_WIDTH; l++) { // px
                         
                         // let first element of the path be the length:
                         path_line = string("path_") + index_to_alphabet(i) + index_to_alphabet(j) +
                                                      index_to_alphabet(k) + index_to_alphabet(l) + ": .word ";
                         
                         // get path:
                         grid_path_t grid_path = find_path(i, j, k, l);
                         xy_path_t xy_path = path_to_xy_path(grid_path);
                         vector<int> dirs = get_directions(xy_path);
                         
                         path_line = path_line + int_to_string(dirs.size()) + ' ';
                         for(int x = 0; x < dirs.size(); x++)
                              path_line = path_line + int_to_string(dirs[x]) + ' ';

                         path_line = path_line + '\n';

                         if(dirs.size() > 0)
                              fputs(path_line.c_str(), fp);

                    }

               }

          }

     }
     
     fputs("####### end paths and lengths\n\n", fp);
     fclose(fp);
     
     /////// end paths
     
     /////// parr_gygx:
     fp = fopen("parr_gygx.code", "w");
     assert(fp != NULL);
     
     fputs("####### pypx arrays:\n", fp);
     string path_addr, pypx_line;
     for(int i = 0; i < GRID_HEIGHT; i++) { // gy

          for(int j = 0; j < GRID_WIDTH; j++) { // gx

               pypx_line = string("pypx_") + index_to_alphabet(i) + index_to_alphabet(j) + ": .word ";
               
               for(int k = 0; k < GRID_HEIGHT; k++) { // py

                    for(int l = 0; l < GRID_WIDTH; l++) { // px
                         
                         // let first element of the path be the length:
                         path_addr = string("path_") + index_to_alphabet(i) + index_to_alphabet(j) +
                                                      index_to_alphabet(k) + index_to_alphabet(l);
                         
                         // get path:
                         grid_path_t grid_path = find_path(i, j, k, l);
                         xy_path_t xy_path = path_to_xy_path(grid_path);
                         vector<int> dirs = get_directions(xy_path);
                         
                         if(dirs.size() == 0)
                              pypx_line = pypx_line + "null_path ";
                         else
                              pypx_line = pypx_line + path_addr + ' ';
                         
                    } // for l

               } // for k
               
               pypx_line = pypx_line + '\n';
               
               // only write the line if there is a path possible starting at
               // gygx:
               if(grid[i][j] == 'x')
                    fputs(pypx_line.c_str(), fp);

               
          } // for j

     } // for i

     fputs("####### end pypx arrays\n\n", fp);
     fclose(fp);
     
     /////// end parr_gygx
     
     /////// gygx array:
     
     fp = fopen("gygx_arr.code", "w");
     assert(fp != NULL);
     
     string pypx, gygx_line = "gygx: .word ";
     for(int i = 0; i < GRID_HEIGHT; i++) {

          for(int j = 0; j < GRID_WIDTH; j++) {

               pypx = string("pypx_") + index_to_alphabet(i) + index_to_alphabet(j) + ' ';
               if(grid[i][j] == 'x')
                    gygx_line = gygx_line + pypx;
               else
                    gygx_line = gygx_line + "0 ";

          }

     }

     gygx_line = gygx_line + '\n';
     fputs(gygx_line.c_str(), fp);

     fclose(fp);
     
     /////// end gygx array
     
     // path length is zero when there is no path:
     /*grid_path_t grid_path = find_path(0, 0, 1, 1);
     printf("0011 len: %d\n", grid_path.size());
     grid_path = find_path(0, 0, 0, 0);
     printf("0000 len: %d\n", grid_path.size());
     grid_path = find_path(1, 1, 0, 1);
     printf("1101 len: %d\n", grid_path.size());*/
     
     /*int start_y = 1, start_x = 1, end_y = 20, end_x = 17;
     
     grid_path_t grid_path = find_path(start_y, start_x, end_y, end_x);
     
     xy_path_t xy_path = path_to_xy_path(grid_path);
     print_xy_path(xy_path);
     vector<int> dirs = get_directions(xy_path);
     print_directions(dirs);
     
     print_solved_maze(grid_path, '*');*/

     return 0;

}

// if no path exists this will return a blank vector:
grid_path_t find_path(int start_y, int start_x, int end_y, int end_x) {

     status cell_status[GRID_HEIGHT][GRID_WIDTH];
     xy_point point, front_point;
     vector<int> node_queue;
     int queue_front_index = -1;
     vector<int> node_origin;
     grid_path_t shortest_path;
   
     // initialize:
     for(int i = 0; i < GRID_HEIGHT; i++) {
          
          for(int j = 0; j < GRID_WIDTH; j++)
               cell_status[i][j] = READY;

     }
     
     if((grid[start_y][start_x] == 'W') || (grid[end_y][end_x] == 'W')) 
          return shortest_path;
     
     // begin with the start node:
     point.y = start_y;
     point.x = start_x;
     cell_status[point.y][point.x] = WAITING;
     node_queue.push_back(point_to_grid_square(point));
     queue_front_index++;
     node_origin.push_back(-1);
     
     while(queue_front_index != node_queue.size()) {

          front_point = grid_square_to_point(node_queue[queue_front_index]);
          
          // UP:
          point.y = front_point.y - 1;
          point.x = front_point.x;
          if((point.y >= 0) && (cell_status[point.y][point.x] == READY) && (grid[point.y][point.x] != 'W')) {
               
               node_queue.push_back(point_to_grid_square(point));
               cell_status[point.y][point.x] = WAITING;
               node_origin.push_back(node_queue[queue_front_index]);

          }
          
          // DOWN:
          point.y = front_point.y + 1;
          point.x = front_point.x;
          if((point.y < GRID_HEIGHT) && (cell_status[point.y][point.x] == READY) && (grid[point.y][point.x] != 'W')) {

               node_queue.push_back(point_to_grid_square(point));
               cell_status[point.y][point.x] = WAITING;
               node_origin.push_back(node_queue[queue_front_index]);

          }

          // LEFT:
          point.y = front_point.y;
          point.x = front_point.x - 1;
          if((point.x >= 0) && (cell_status[point.y][point.x] == READY) && (grid[point.y][point.x] != 'W')) {
               
               node_queue.push_back(point_to_grid_square(point));
               cell_status[point.y][point.x] = WAITING;
               node_origin.push_back(node_queue[queue_front_index]);

          }

          // RIGHT:
          point.y = front_point.y;
          point.x = front_point.x + 1;
          if((point.x < GRID_WIDTH) && (cell_status[point.y][point.x] == READY) && (grid[point.y][point.x] != 'W')) {

               node_queue.push_back(point_to_grid_square(point));
               cell_status[point.y][point.x] = WAITING;
               node_origin.push_back(node_queue[queue_front_index]);

          }

          cell_status[front_point.y][front_point.x] = PROCESSED;
          queue_front_index++;

     }
     
     // debugging:
     /*printf("queue size: %d ; origin_size: %d ;\n", node_queue.size(), node_origin.size());
     printf("(node, origin) : ");
     for(int i = 0; i < node_queue.size(); i++)
          printf("(%d, %d) ", node_queue[i], node_origin[i]);*/
               
     
     // now construct the path:
     xy_point start_point, end_point;
     start_point.y = start_y; start_point.x = start_x;
     end_point.y = end_y; end_point.x = end_x;
     int start_node = point_to_grid_square(start_point), end_node = point_to_grid_square(end_point);
     int cur_node = end_node, cur_index = -1;
     bool continue_path = true;
     
     while(continue_path) {

          //printf("continue path loop\n");
          // find cur_node:
          for(int i = 0; i < node_queue.size(); i++) {

               if(node_queue[i] == cur_node) {

                    cur_index = i;
                    break;

               }

          }

       //printf("cur_node: %d ; cur_index: %d ; node_origin[cur_index]: %d ;\n", cur_node, cur_index, node_origin[cur_index]);
          shortest_path.push_back(cur_node);
          if(node_origin[cur_index] == -1)
               continue_path = false;
          else
               cur_node = node_origin[cur_index];

     }

     // path currently points end -> (...) -> start
     // reverse the path:
     grid_path_t r_path;
     for(int i = (shortest_path.size() - 1); i >= 0; i--)
          r_path.push_back(shortest_path[i]);
     
     return r_path;

}

void print_path(grid_path_t path) {
     
     if(path.size() == 0)
          return;
     
     printf("%d -> ", path[0]);
     for(int i = 1; i < path.size(); i++) {

          if(i == (path.size() - 1))
               printf("%d\n", path[i]);
          else
               printf("%d -> ", path[i]);

     }

}

void print_xy_path(xy_path_t path) {

     if(path.size() == 0)
          return;

     printf("(row, column): \n     ");
     for(int i = 0; i < path.size(); i++) {

          if(i == (path.size() - 1))
               printf("(%d, %d)\n", path[i].y, path[i].x);
          else
               printf("(%d, %d) -> ", path[i].y, path[i].x);

     }

}

void print_directions(vector<int> directions) {

     printf("[START] -> ");
     for(int i = 0; i < directions.size(); i++) {

          if(directions[i] == 1)
               printf("UP ");
          else if(directions[i] == 2)
               printf("DOWN ");
          else if(directions[i] == 3)
               printf("LEFT ");
          else
               printf("RIGHT ");

          if(i == (directions.size() - 1))
               printf("-> [END]\n");
          else
               printf("-> ");

     }

}

// this probably modifies the array, so only call it once:
void print_solved_maze(grid_path_t path, char path_char) {

     xy_point path_point;
     
     for(int i = 0; i < path.size(); i++) {

          path_point = grid_square_to_point(path[i]);
          grid[path_point.y][path_point.x] = path_char;

     }

     // print the grid:
     for(int i = 0; i < GRID_HEIGHT; i++) {

          for(int j = 0; j < GRID_WIDTH; j++) {

               if(grid[i][j] == 'x')
                    printf(" ");
               else
                    printf("%c", grid[i][j]);

          }
          printf("\n");

     }
          
}

// conversions:
xy_path_t path_to_xy_path(grid_path_t path) {

     xy_path_t xy_path;
     for(int i = 0; i < path.size(); i++)
          xy_path.push_back(grid_square_to_point(path[i]));

     return xy_path;

}

vector<int> get_directions(xy_path_t path) {

     vector<int> r_val;
     xy_point ref, next;

     //if(path.size() == 0) {
     //
     //     r_val.push_back(0);
     //     return r_val;
     //
     //}
     
     for(int i = 1; i < path.size(); i++) {

          ref = path[i - 1];
          next = path[i];
          // note that are using dirs to refer to usual dir, 
          // not in the matrix:
          if(next.y == (ref.y - 1))
               r_val.push_back(1); // see note
          else if(next.y == (ref.y + 1))
               r_val.push_back(2);
          else if(next.x == (ref.x - 1))
               r_val.push_back(3); // see note
          else
               r_val.push_back(4);

     }

     return r_val;

}

int point_to_grid_square(xy_point point) {

     return (point.y*GRID_WIDTH + point.x + 1);

}

xy_point grid_square_to_point(int grid_square) {

     xy_point r_val;
     r_val.y = grid_square / GRID_WIDTH;
     r_val.x = (grid_square - 1) % GRID_WIDTH;
     
     return r_val;

}

// indices start at zero:  index 0 => 'a', index 26 => 'A'

char index_to_alphabet(int index) {

     if((index >= 0) && (index <= 25))
          return ((char) (index + 97));
     else if((index >= 26) && (index <= 51))
          return ((char) (index - 26 + 65));

     return '\0';

}

string int_to_string(int i) {

     char int_val[10];
     sprintf(int_val, "%i", i);
     return string(int_val);

}
