# ghostbot_maze1.s : part of the pacman demo for generic_robot; controls the
#                    ghostbot(s) chasing after pacman (pacbot);
# Author: Maxie D. Schmidt (May 2006)

# TODO: need to
# handle bonks between the ghostbots (on ghostbot bonk in the cpp source give
# priority to some ghostbots for moving (based on names of the ghostbots:
# Pinky, Blinky, etc.));

# The grid is stored as a single array. "0" indicates an open spot to
# travel and "1" indicates an object that does not share space. To access 
# the element at row r (0 <= r < grid height) and column c (0 <= c < grid
# width) use: array[r*(grid width) + c].
#
# grid height: 22, grid width = 19

.data
GRID: .word 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 1 1 0 1 1 1 0 1 0 1 1 1 0 1 1 0 1 1 0 1 1 0 1 1 1 0 1 0 1 1 1 0 1 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 1 0 1 0 1 1 1 1 1 0 1 0 1 1 0 1 1 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 1 1 1 1 1 0 1 1 1 0 1 0 1 1 1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 0 0 1 0 1 1 1 1 1 1 1 1 0 1 0 1 1 1 1 1 0 1 0 1 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 1 1 1 1 1 0 1 0 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 0 0 1 0 1 1 1 1 1 1 1 1 0 1 0 1 1 1 1 1 0 1 0 1 1 1 1 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 0 1 1 0 1 1 1 0 1 0 1 1 1 0 1 1 0 1 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 1 0 1 0 1 0 1 1 1 1 1 0 1 0 1 0 0 1 1 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 1 1 0 1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

save0: .word 0
save_s0: .word 0
save_s3: .word 0

bonk_text: .asciiz "bonk interrupt\n"

## debugging:
begin_count_steps_x: .asciiz "begin count_steps_x\n"
end_count_steps_x: .asciiz "end count_steps_x\n"
begin_count_steps_y: .asciiz "begin count_steps_y\n"
end_count_steps_y: .asciiz "end count_steps_y\n"
begin_grid_align: .asciiz "begin grid_align\n"
end_grid_align: .asciiz "end grid_align\n"
begin_main: .asciiz "begin main\n"
end_main: .asciiz "end main\n"
looping: .asciiz "looping\n"
other_exception_text: .asciiz "non-interrupt exception\n"

.text

# addresses: these can be calculated by looking at the ordering of the
#            mmappedIO addresses and peripherals within each robot.
#
# pacman grid x: 0xffff0028
# pacman grid y: 0xffff002c
# ghostbot grid x: 0xffff0018
# ghostbot grid y: 0xffff001c

# pseudocode for on_grid_align(), count_steps_x(), and count_steps_y()
# can be found at: gr_demos/pacman/ghostbot.pseudocode

main:
     ## debugging:
     #la $a0, begin_main
     #li $v0, 4
     #syscall
     ## end debugging
       
     # interrupts: bonk and grid align:
     li $t4, 0x1801
     mtc0 $t4, $12

     # claiming vars:
     # $t0 = velocity
     # $t1 = px 
     # $s1 = py
     # $t2 = gx
     # $s2 = gy
     # $t3 = grid_check_x
     # $t4 = grid_check_y
     # $t5 = last_move_dir / backtracking dir (when backtracking)
     # $t6 = x_move
     # $t7 = y_move
     # $t8 = backtracking
     # $t9 = num_back_tracking_steps
     #
     # initialize:
     li $t0, 3 # speed is the same as pacman's
     li $t5, 0
     li $t8, 0

     # start the robot moving:
     sw $t0, 0xffff0000($zero)

     ## debugging:
     #la $a0, end_main
     #li $v0, 4
     #syscall
     ## end debugging

loop:
     ### debugging:
     #la $a0, looping
     #li $v0, 4
     #syscall
     ## end debugging

     j loop

.ktext 0x80000080
interrupt_handler:
     .set noat
     move $k1, $at
     .set at

     mfc0 $k0, $13
     srl $a0, $k0, 2
     and $a0, $a0, 0xf
     bne $a0, 0, non_interrupt

interrupt_dispatch:

     mfc0 $k0, $13
     beq $k0, $zero, done

     and $a0, $k0, 0x1000
     bne $a0, 0, bonk_interrupt
     
     and $a0, $k0, 0x800
     bne $a0, 0, grid_align_interrupt
     
     j done

###############################################################################
## functions:

# grid(row, col) : $a0 = row, $a1 = col; 
# returns the grid element at row/col:
grid:
     sw $s0, save_s0
     sw $s3, save_s3
     
     mul $s0, $a0, 76
     mul $a1, $a1, 4
     add $s0, $s0, $a1
     la $s3, GRID
     add $s3, $s3, $s0
     lw $v0, 0($s3)

     lw $s0, save_s0
     lw $s3, save_s3

     jr $ra

# count_steps_x: counts the number of steps needed for backtracking 
#                in the direction specified by $a0. If $a0 = 0,
#                move left. If $a0 = 1, move right. If there is
#                no backtracking path, returns count = -1.
#
# code uses $s0 (count) and $s3 (x_pos). 

count_steps_x:
          
     sw $s0, save_s0
     sw $s3, save_s3
     
     li $s0, 0
     move $s3, $t2
     
     #sub $sp, $sp, 4
     #sw $ra, 0($sp)
     sw $ra, save0
     
     while_top:
           # if(a0 == 0)
           bne $a0, 0, while_else
               
               # if(grid(gy, x_pos - 1) == 1)
               move $a0, $s2
               sub $a1, $s3, 1
               jal grid
               bne $v0, 1, while_if_else
                    li $s0, -1
                    j while_break
                    
               while_if_else:
                    addi $s0, $s0, 1
                    sub $s3, $s3, 1
                    j check_eo_path

          while_else:

               # if(grid(gy, x_pos + 1) == 1)
               move $a0, $s2
               addi $a1, $s3, 1
               jal grid
               bne $v0, 1, while_else_else
                    li $s0, -1
                    j while_break

               while_else_else:
                    addi $s0, $s0, 1
                    addi $s3, $s3, 1
                    j check_eo_path

          check_eo_path:
          # if((y_move == 0) && (grid(gy - 1, x_pos) == 0)) break;
          bne $t7, 0, check_path_ei
          sub $a0, $s2, 1
          move $a1, $s3 #592
          jal grid
          bne $v0, 0, while_top
          
               j while_break

          # else if((y_move == 1) && (grid(gy + 1, x_pos) == 0)) break;
          check_path_ei:
          bne $t7, 1, while_top
          addi $a0, $s2, 1
          move $a1, $s3
          jal grid
          bne $v0, 0, while_top

               j while_break
     
     while_break:
          #lw $ra, 0($sp)
          #addi $sp, $sp, 4
          lw $ra, save0
          
          move $v0, $s0

     lw $s0, save_s0
     lw $s3, save_s3

     jr $ra

# count_steps_y: counts the number of steps needed for backtracking 
#                in the direction specified by $a0. If $a0 = 0,
#                move up. If $a0 = 1, move down. If there is
#                no backtracking path, returns count = -1.
# code uses $s0 (count) and $s3 (y_pos). 

count_steps_y:
    
     sw $s0, save_s0
     sw $s3, save_s3
     
     li $s0, 0
     move $s3, $s2
     
     #sub $sp, $sp, 4
     #sw $ra, 0($sp)
     sw $ra, save0
     
     csy_while_top:
           # if(a0 == 0)
           bne $a0, 0, csy_while_else
               
               # if(grid(y_pos - 1, gx) == 1)
               sub $a0, $s3, 1
               move $a1, $t2
               jal grid
               bne $v0, 1, csy_while_if_else
                    li $s0, -1
                    j csy_while_break
                    
               csy_while_if_else:
                    addi $s0, $s0, 1
                    sub $s3, $s3, 1
                    j csy_check_eo_path

          csy_while_else:

               # if(grid(y_pos + 1, gx) == 1)
               addi $a0, $s3, 1
               move $a1, $t2
               jal grid
               bne $v0, 1, csy_while_else_else
                    li $s0, -1
                    j csy_while_break

               csy_while_else_else:
                    addi $s0, $s0, 1
                    addi $s3, $s3, 1
                    j csy_check_eo_path

          csy_check_eo_path:
          # if((x_move == 0) && (grid(y_pos, gx - 1) == 0)) break;
          bne $t6, 0, csy_check_path_ei
          move $a0, $s3
          sub $a1, $t2, 1
          jal grid
          bne $v0, 0, csy_while_top
          
               j csy_while_break

          # else if((x_move == 1) && (grid(y_pos, gx + 1) == 0)) break;
          csy_check_path_ei:
          bne $t6, 1, csy_while_top
          move $a0, $s3
          addi $a1, $t2, 1
          jal grid
          bne $v0, 0, csy_while_top

               j csy_while_break
     
     csy_while_break:
          #lw $ra, 0($sp)
          #addi $sp, $sp, 4
          lw $ra, save0
          
          move $v0, $s0
     
     lw $s0, save_s0
     lw $s3, save_s3
          
     jr $ra

move_up:
     sw $s0, save_s0
     
     li $s0, 90
     sw $s0, 0xffff0004($zero)
     li $s0, 1
     sw $s0, 0xffff0008($zero)
     sw $t0, 0xffff0000($zero)
     
     lw $s0, save_s0
     jr $ra
     
move_down:
     sw $s0, save_s0
     
     li $s0, 270 
     sw $s0, 0xffff0004($zero)
     li $s0, 1
     sw $s0, 0xffff0008($zero)
     sw $t0, 0xffff0000($zero)
     
     lw $s0, save_s0
     jr $ra

move_left:
     sw $s0, save_s0
     
     li $s0, 180
     sw $s0, 0xffff0004($zero)
     li $s0, 1
     sw $s0, 0xffff0008($zero)
     sw $t0, 0xffff0000($zero)

     lw $s0, save_s0
     jr $ra

move_right:
     sw $s0, save_s0
      
     li $s0, 0
     sw $s0, 0xffff0004($zero)
     li $s0, 1
     sw $s0, 0xffff0008($zero)
     sw $t0, 0xffff0000($zero)

     lw $s0, save_s0
     jr $ra

## end functions
###############################################################################

bonk_interrupt:
     # shouldn't have bonk interrupts since the ghostbot code checks for
     # walls / (objects that do not share space) before moving (TODO: except
     # robots).
     la $a0, bonk_text
     li $v0, 4
     syscall
     
     # ack:
     sw $a1, 0xffff0020($zero)
     
     j interrupt_dispatch

grid_align_interrupt:
     ## debugging:
     #la $a0, begin_grid_align
     #li $v0, 4
     #syscall
     ## end debugging
     
     # this is where most of the work calculating new moves for the
     # ghostbot is done (begin bulk of pseudocode):
     
     # set velocity = 0:
     li $s0, 0
     sw $s0, 0xffff0000($zero)

     # ack:
     sw $a1, 0xffff0030($zero) # ack

     bne $t8, 0, else_backtracking
     if_not_backtracking:
                    
          # if(px > gx) x_move = 1;
          # else if(px < gx) x_move = 0;
          # else x_move = 2;
               lw $t1, 0xffff0028($zero)
               lw $t2, 0xffff0018($zero)
               ble $t1, $t2, ei_pxgx
               li $t6, 1
               j start_pygy
          ei_pxgx:
               beq $t1, $t2, e_pxgx
               li $t6, 0
               j start_pygy
          e_pxgx:
               li $t6, 2
          
          # if(py > gy) y_move = 1;
          # else if(py < gy) y_move = 0;
          # else y_move = 2;
          start_pygy:
               lw $s1, 0xffff002c($zero)
               lw $s2, 0xffff001c($zero)
               ble $s1, $s2, ei_pygy
               li $t7, 1
               j start_check_bonks
          ei_pygy:
               beq $s1, $s2, e_pygy
               li $t7, 0
               j start_check_bonks
          e_pygy:
               li $t7, 2
          
          start_check_bonks:
               #sub $sp, $sp, 4
               #sw $ra, 0($sp)
               sw $ra, save0

          # if(x_move == 1) grid_check_x = grid(gy, gx + 1);
          # else grid_check_x = grid(gy, gx - 1);
               bne $t6, 1, e_check_bonks_x
               move $a0, $s2
               move $a1, $t2
               addi $a1, $a1, 1
               jal grid
               move $t3, $v0
               j if_check_bonks_y
          e_check_bonks_x:
               move $a0, $s2
               move $a1, $t2
               addi $a1, $a1, -1
               jal grid
               move $t3, $v0
          
          # if(y_move == 1) grid_check_y = grid(gy + 1, gx);
          # else grid_check_y = grid(gy - 1, gx);
          if_check_bonks_y:
               bne $t7, 1, e_check_bonks_y
               move $a0, $s2
               addi $a0, $a0, 1
               move $a1, $t2
               jal grid
               move $t4, $v0
               j cleanup_grid_calls
          e_check_bonks_y:
               move $a0, $s2
               addi $a0, $a0, -1
               move $a1, $t2
               jal grid
               move $t4, $v0

          cleanup_grid_calls:
               #lw $ra, 0($sp)
               #addi $sp, $sp, 4
               lw $ra, save0
               
          ## start the main move conditionals:
          # if((x_move == 2) && (y_move == 2)) continue moving;
          bne $t6, 2, if_move_conds
          bne $t7, 2, if_move_conds
               sw $t0, 0xffff0000($zero)
               j grid_align_done
          
          # (else) if((x_move == 2) && (grid_check_y == 1)) 
               if_move_conds:
               bne $t6, 2, ei0_move_conds
               bne $t4, 1, ei0_move_conds
                    li $t8, 1

                    #sub $sp, $sp, 4
                    #sw $ra, 0($sp)
                    sw $ra, save0

                    # check left direction:
                    li $a0, 0
                    jal count_steps_x
                    move $s4, $v0

                    # check right direction:
                    li $a0, 1
                    jal count_steps_x
                    move $s5, $v0

                    # figure out what path to take:
                    # if((count_left == -1) || (count_right <= count_left))
                    beq $s4, -1, if_move_conds_if
                    ble $s5, $s4, if_move_conds_if
                    j if_move_conds_else
                    
                    if_move_conds_if:
                         sub $s5, $s5, 1
                         move $t9, $s5
                         li $t5, 4
                         jal move_right
                         j if_move_conds_cleanup
                    
                    # else { //if((count_right == -1) || (count_right > count_left))
                    if_move_conds_else:
                         sub $s4, $s4, 1
                         move $t9, $s4
                         li $t5, 3
                         jal move_left
                    
               if_move_conds_cleanup:
                    #lw $ra, 0($sp)
                    #addi $sp, $sp, 4
                    lw $ra, save0
                    
               j grid_align_done

          #else if((y_move == 2) && (grid_check_x == 1))
          ei0_move_conds:
               bne $t7, 2, ei1_move_conds
               bne $t3, 1, ei1_move_conds
                    li $t8, 1

                    #sub $sp, $sp, 4
                    #sw $ra, 0($sp)
                    sw $ra, save0

                    # check the up direction:
                    li $a0, 0
                    jal count_steps_y
                    move $s4, $v0

                    # check the down direction:
                    li $a0, 1
                    jal count_steps_y
                    move $s5, $v0
                    
                    # figure out (shortest) backtracking path:
                    # if((count_down == -1) || (count_up <= count_down)) 
                    beq $s5, -1, ei0_move_conds_if
                    ble $s4, $s5, ei0_move_conds_if
                    j ei0_move_conds_else
                    
                    ei0_move_conds_if:
                         sub $s4, $s4, 1
                         move $t9, $s4
                         li $t5, 1
                         jal move_up
                         j ei0_move_conds_cleanup

                    # else { // if((count_up == -1) || (count_up > count_down))
                    ei0_move_conds_else:
                         sub $s5, $s5, 1
                         move $t9, $s5
                         li $t5, 2
                         jal move_down
               
               ei0_move_conds_cleanup:
                    #lw $ra, 0($sp)
                    #addi $sp, $sp, 4
                    lw $ra, save0

               j grid_align_done

          # else if((grid_check_x == 1) && (grid_check_y == 1))
          ei1_move_conds:
               bne $t3, 1, ei2_move_conds
               bne $t4, 1, ei2_move_conds
                    li $t8, 1

                    #sub $sp, $sp, 4
                    #sw $ra, 0($sp)
                    sw $ra, save0

                    # if(x_move == 0) // move to the right
                    bne $t6, 0, ei1_move_conds_x_move_else
                         li $a0, 1
                         jal count_steps_x
                         move $s4, $v0
                         j ei1_move_conds_y_move_if
                    
                    # else // move to the left
                    ei1_move_conds_x_move_else:
                         li $a0, 0
                         jal count_steps_x
                         move $s4, $v0

                    # if(y_move == 0) // move down
                    ei1_move_conds_y_move_if:
                    bne $t7, 0, ei1_move_conds_y_move_else
                         li $a0, 1
                         jal count_steps_y
                         move $s5, $v0
                         j ei1_move_conds_pick_path

                    # else // move up
                    ei1_move_conds_y_move_else:
                         li $a0, 0
                         jal count_steps_y
                         move $s5, $v0

                    ei1_move_conds_pick_path:
                    # if(count_x == -1) || (count_y <= count_x))
                    beq $s4, -1, ei1mc_if
                    ble $s5, $s4, ei1mc_if
                    j ei1mc_else

                    ei1mc_if:
                         sub $s5, $s5, 1
                         move $t9, $s5

                         #if(y_move == 0)
                         bne $t7, 0, ei1mc_if_else
                              li $t5, 2
                              jal move_down
                              j ei1_move_conds_cleanup
                         
                         # else
                         ei1mc_if_else:
                              li $t5, 1
                              jal move_up
                              j ei1_move_conds_cleanup
                    
                    ei1mc_else:
                         sub $s4, $s4, 1
                         move $t9, $s4

                         # if(x_move == 0)
                         bne $t6, 0, ei1mc_else_else
                              li $t5, 4
                              jal move_right
                              j ei1_move_conds_cleanup

                         # else
                         ei1mc_else_else:
                              li $t5, 3
                              jal move_left
                              
               ei1_move_conds_cleanup:
                    #lw $ra, 0($sp)
                    #addi $sp, $sp, 4
                    lw $ra, save0

               j grid_align_done

          # else if((x_move == 2) || (grid_check_x == 1))
          ei2_move_conds:
               beq $t6, 2, move_conds_move_in_y_dir
               beq $t3, 1, move_conds_move_in_y_dir
               j ei3_move_conds

               move_conds_move_in_y_dir:
                    #sub $sp, $sp, 4
                    #sw $ra, 0($sp)
                    sw $ra, save0
                    
                    # if(y_move == 0)
                    bne $t7, 0, e_mcmi_y_dir
                         # move up:
                         jal move_up
                         j mcmi_y_dir_cleanup
                    e_mcmi_y_dir:
                         # move down:
                         jal move_down

                    mcmi_y_dir_cleanup:
                         li $t5, 1
                         #lw $ra, 0($sp)
                         #addi $sp, $sp, 4
                         lw $ra, save0

               j grid_align_done

          # else if((y_move == 2) || (grid_check_y == 1))
          ei3_move_conds:
               beq $t7, 2, move_conds_move_in_x_dir
               beq $t4, 1, move_conds_move_in_x_dir
               j e_move_conds

               move_conds_move_in_x_dir:
                    #sub $sp, $sp, 4
                    #sw $ra, 0($sp)
                    sw $ra, save0
                    
                    # if(x_move == 0)
                    bne $t6, 0, e_mcmi_x_dir
                         # move left:
                         jal move_left
                         j mcmi_x_dir_cleanup
                    e_mcmi_x_dir:
                         # move right:
                         jal move_right
                    mcmi_x_dir_cleanup:
                         li $t5, 0
                         #lw $ra, 0($sp)
                         #addi $sp, $sp, 4
                         lw $ra, save0

               j grid_align_done

          # else
          e_move_conds:
               #sub $sp, $sp, 4
               #sw $ra, 0($sp)
               sw $ra, save0
               
               bne $t5, 1, e_e_move_conds
                    li $t5, 0
                    bne $t6, 0, e_move_conds_else_move_right
                         jal move_left
                         j e_move_conds_cleanup
                    e_move_conds_else_move_right:
                         jal move_right
                         j e_move_conds_cleanup
               e_e_move_conds:
                    li $t5, 1
                    bne $t7, 0, e_move_conds_else_move_down
                         jal move_up;
                         j e_move_conds_cleanup
                    e_move_conds_else_move_down:
                         jal move_down
                         j e_move_conds_cleanup

               e_move_conds_cleanup:
                    #lw $ra, 0($sp)
                    #addi $sp, $sp, 4
                    lw $ra, save0

               j grid_align_done

     else_backtracking:
          #sub $sp, $sp, 4
          #sw $ra, 0($sp)
          sw $ra, save0
          
          bne $t9, 0, backtracking_with_steps
               li $t8, 0
               #li $t5, 0
               beq $t5, 1, else_backtracking_no_steps_if
               beq $t5, 2, else_backtracking_no_steps_if
               j else_backtracking_no_steps_else
               else_backtracking_no_steps_if:
                    bne $t6, 0, ebnsi_else
                         jal move_left
                         j else_backtracking_cleanup
                    ebnsi_else:
                         jal move_right
                         j else_backtracking_cleanup
               else_backtracking_no_steps_else:
                    bne $t7, 0, ebnse_else
                         jal move_up
                         j else_backtracking_cleanup
                    ebnse_else:
                         jal move_down
                         j else_backtracking_cleanup
          backtracking_with_steps:
               sub $t9, $t9, 1
               bne $t5, 1, bsw_ei0
                    jal move_up
                    j else_backtracking_cleanup
               bsw_ei0:
               bne $t5, 2, bsw_ei1
                    jal move_down
                    j else_backtracking_cleanup
               bsw_ei1:
               bne $t5, 3, bsw_else
                    jal move_left
                    j else_backtracking_cleanup
               bsw_else:
                    jal move_right
     
          else_backtracking_cleanup:
               #lw $ra, 0($sp)
               #addi $sp, $sp, 4
               lw $ra, save0

               j grid_align_done
          
     grid_align_done:

     ## debugging:
     #la $a0, end_grid_align
     #li $v0, 4
     #syscall
     ## end debugging
          
          j interrupt_dispatch

non_interrupt:
     la $a0, other_exception_text
     li $v0, 4
     syscall
     
     j done

done:
     mfc0 $k0, $14
     .set noat
     move $at, $k1
     .set at
     rfe
     jr $k0
