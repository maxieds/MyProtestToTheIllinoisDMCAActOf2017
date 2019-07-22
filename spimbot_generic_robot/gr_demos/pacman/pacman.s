# pacman.s : generic_robot demo program; controls the pacbot
# Author: Maxie D. Schmidt (May 2006)

.data

.text

# It would be nicer if it had a couple of instructions to get the 
# addresses, but that is on the TODO list. These addresses can be predicted
# based on the ordering of the peripherals and the robot's position
# in the gamefile.
#
# velocity: 0xffff0000
# orientation value: 0xffff0004
# orientation ctrl: 0xffff0008
# bonk ack: 0xffff0028
# timer ack: 0xffff002c
# arrow up ack: 0xffff0030
# arrow down ack: 0xffff0034
# arrow left ack: 0xffff0038
# arrow right ack: 0xffff003c
# grid align ack: 0xffff0040

# //pacman pseudo code:
#
# set velocity 
# set orientation = 0 degrees
#
# int last_keypress = 0; // 0 = no keypress, 1 = up, 2 = down, 3 = left, 
#                        // 4 = right
# int cur_direction = 4; // 1 = up, 2 = down, 3 = left, 4 = right
#
# while(!(all pebbles eaten) && !(contact with ghostbot)) {
#     
#     if(keypress) last_keypress = #;
#
#     if(last_keypress == 0) continue;
#
#     // positions changing directions from vert->vert or horiz->horiz:
#     if((last_keypress == 1) && (cur_direction == 2)) {
#          last_keypress = 0;
#          cur_direction = 1;
#          move up;
#     }
#     else if((last_keypress == 1) && (cur_direction == 1))
#          last_keypress = 0; // keep moving in cur direction
#     else if((last_keypress == 2) && (cur_direction == 1)) {
#          last_keypress = 0;
#          cur_direction = 2;
#          move down;
#     }
#     else if((last_keypress == 2) && (cur_direction == 2))
#          last_keypress = 0; // keep moving
#     else if((last_keypress == 3) && (cur_direction == 4)) {
#          last_keypress = 0;
#          cur_direction = 3;
#          move left;
#     }
#     else if((last_keypress == 3) && (cur_direction == 3))
#          last_keypress = 0; // keep moving in cur direction
#     else if((last_keypress == 4) && (cur_direction == 3)) {
#          last_keypress = 0;
#          cur_direction = 4;
#          move right;
#     }
#     else if((last_keypress == 4) && (cur_direction == 4))
#          last_keypress = 0; // keep moving
#
#
#     // need to use grid align when changing from vert->horiz or horiz->vert
#     if((grid align) && (last_keypress != 0)) {
#      
#          if(last_keypress == 1) move up set and cur_direction;
#          else if(last_keypress == 2) move down and set cur_direction;
#          else if(last_keypress == 3) move left and set cur_direction;
#          else move right and set cur_direction;
#
#     }
#
# }

main:
     # bonk, arrow keypresses, and grid align interrupts:
     li $t4, 0x7b01
     mtc0 $t4, $12

     # claiming variables: 
     #        (*) $t0 = last_keypress
     #        (*) $t1 = cur_direction
     #        (*) $t2 = robot velocity
     #        (*) $t3 = recovering from bonk
     
     # initialize vars:
     li $t0, 0
     li $t1, 4
     li $t2, 3
     li $t3, 0
     
     # set intial orientation and velocity:
     li $t4, 0 
     sw $t4, 0xffff0004($zero)
     li $t4, 1
     sw $t4, 0xffff0008($zero)
     sw $t2, 0xffff0000($zero)

loop: 
     j loop

.ktext 0x80000080
interrupt_handler:
     .set noat
     move $k1, $at
     .set at

     mfc0 $k0, $13
     srl $a0, $k0, 2
     and $a0, $a0, 0xf
     bne $a0, 0, non_intrpt

interrupt_dispatch:

     mfc0 $k0, $13
     beq $k0, $zero, done

     and $a0, $k0, 0x1000
     bne $a0, 0, bonk_interrupt
     
     and $a0, $k0, 0x2000
     bne $a0, 0, arrow_up_interrupt

     and $a0, $k0, 0x4000
     bne $a0, 0, arrow_down_interrupt

     and $a0, $k0, 0x100
     bne $a0, 0, arrow_left_interrupt

     and $a0, $k0, 0x200
     bne $a0, 0, arrow_right_interrupt
     
     and $a0, $k0, 0x800
     bne $a0, 0, grid_align_interrupt
     
     j done

bonk_interrupt:
    #recovering from bonk:
    li $t3, 1
    
    # acknowledge the interrupt:
    sw $a1, 0xffff0028($zero)

    j interrupt_dispatch

arrow_up_interrupt:
     # check to see if can move immediately:
     li $t0, 1
     sub $t4, $t1, 2
     beq $t4, 0, aup_cond_true
     sub $t4, $t1, 1
     beq $t4, 0, aup_cond_true
     j aup_handled_interrupt

     aup_cond_true:
          # move upwards:
          li $t4, 90
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
          
          # set cur_direction and clear last_keypress:
          li $t1, 1
          li $t0, 0
     
          # reset the velocity (in case of bonk):
          sw $t2, 0xffff0000($zero)
     
     aup_handled_interrupt:
          # ack:
          sw $a1, 0xffff0030($zero)

          # if((last_keypress != 0) && (bonk)) 
          #      go to grid align;
          beq $t0, 0, aup_done
          bne $t3, 1, aup_done
          j grid_align_interrupt
     
     aup_done:
          j interrupt_dispatch

arrow_down_interrupt:
     # check to see if can move immediately:
     li $t0, 2 
     sub $t4, $t1, 2
     beq $t4, 0, adown_cond_true
     sub $t4, $t1, 1
     beq $t4, 0, adown_cond_true
     j adown_handled_interrupt

     adown_cond_true:
          # move downwards:
          li $t4, 270
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
          
          # set cur_direction and clear last_keypress:
          li $t1, 2
          li $t0, 0
     
          # reset the velocity (in case of bonk):
          sw $t2, 0xffff0000($zero)
     
     adown_handled_interrupt:
          # ack:
          sw $a1, 0xffff0034($zero)

          # if((last_keypress != 0) && (bonk)) 
          #      go to grid align;
          beq $t0, 0, aup_done
          bne $t3, 1, aup_done
          j grid_align_interrupt

     adown_done:
          j interrupt_dispatch

arrow_left_interrupt:
     # check to see if can move immediately:
     li $t0, 3
     sub $t4, $t1, 3
     beq $t4, 0, aleft_cond_true
     sub $t4, $t1, 4
     beq $t4, 0, aleft_cond_true
     j aleft_handled_interrupt

     aleft_cond_true:
          # move left:
          li $t4, 180
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
          
          # set cur_direction and clear last_keypress:
          li $t1, 3
          li $t0, 0
     
          # reset the velocity (in case of bonk):
          sw $t2, 0xffff0000($zero)
     
     aleft_handled_interrupt:
          # ack:
          sw $a1, 0xffff0038($zero)

          # if((last_keypress != 0) && (bonk)) 
          #      go to grid align;
          beq $t0, 0, aup_done
          bne $t3, 1, aup_done
          j grid_align_interrupt
     
     aleft_done:
          j interrupt_dispatch

arrow_right_interrupt:
     # check to see if can move immediately:
     li $t0, 4
     sub $t4, $t1, 3
     beq $t4, 0, aright_cond_true
     sub $t4, $t1, 4
     beq $t4, 0, aright_cond_true
     j aright_handled_interrupt

     aright_cond_true:
          # move right:
          li $t4, 0
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
          
          # set cur_direction and clear last_keypress:
          li $t1, 4
          li $t0, 0
     
          # reset the velocity (in case of bonk):
          sw $t2, 0xffff0000($zero)
     
     aright_handled_interrupt:
          # ack:
          sw $a1, 0xffff003c($zero)

          # if((last_keypress != 0) && (bonk)) 
          #      go to grid align;
          beq $t0, 0, aup_done
          bne $t3, 1, aup_done
          j grid_align_interrupt

     aright_done:
          j interrupt_dispatch

grid_align_interrupt:
     beq $t0, 0, ga_handled_interrupt
     sub $t4, $t0, 4
     beq $t4, 0, ga_right
     sub $t4, $t0, 3
     beq $t4, 0, ga_left
     sub $t4, $t0, 2
     beq $t4, 0, ga_down
     
     ga_up:
          # set cur_direction:
          li $t1, 1
    
          # change orientation (move upwards):
          li $t4, 90
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
      
          j ga_handled_interrupt

     ga_down:
          li $t1, 2
      
          li $t4, 270
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
     
          j ga_handled_interrupt
          
     ga_left:
          li $t1, 3
   
          li $t4, 180
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
    
          j ga_handled_interrupt
     
     ga_right:
          li $t1, 4
         
          li $t4, 0
          sw $t4, 0xffff0004($zero)
          li $t4, 1
          sw $t4, 0xffff0008($zero)
    
     ga_handled_interrupt:
          # reset the velocity if needed:
          sw $t2, 0xffff0000($zero)
          
          # keystroke handled:
          li $t0, 0
          
          # see if need to ack:
          beq $t3, 1, ga_done 
          
          # ack:
          sw $a1, 0xffff0040($zero)

     ga_done:
          # reset bonk:
          li $t3, 0

          j interrupt_dispatch

non_intrpt:
     j done

done:
     mfc0 $k0, $14
     .set noat
     move $at, $k1
     .set at
     rfe
     jr $k0
