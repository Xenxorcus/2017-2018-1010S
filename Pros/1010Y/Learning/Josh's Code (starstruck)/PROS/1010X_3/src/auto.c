#include "main.h"
#include "autoruns.h"
//#include "armpidterms.h"
//#include "clawpidterms.h"

void autonomous() {

//TaskHandle taskdisable_functions = taskCreate(disable_functions, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
TaskHandle armtaskpid_auto = taskCreate(auto_armcontrol, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
TaskHandle clawtaskpid_auto = taskCreate(auto_clawcontrol, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

  lcdClear(uart1);
  lcdPrint(uart1, 1, "Auto %d Running", myauto);

clawtarget = analogRead(potclaw);
armtarget_L = analogRead(potarmL);
armtarget_R = analogRead(potarmR);

switch (myauto) {
  case -4:
  delay(250);
    turnexact(CLOCKWISE, 90, 40, 50, 0.5, 0.5, 15, 20000);
  break;

  case -3:
    drivestraight(NORTH, 100,40, 50, 0.2, 0.15, 15, 20000);
  break;

  case -2:
    drivestraight(NORTH, 800,40, 50, 0.2, 0.15, 15, 20000);
  break;
  case -1:
    lift_basic(2000, 3000);
  break;

  case 0:
    auto0_programming();
  break;
  case 1:
      auto1_centerfence_R();
  break;
  case 2:
      auto2_centerfence_L();
  break;
  case 3:
      auto3_close_R();
  break;
  case 4:
      auto4_close_L();
  break;
  case 5:
    auto5_wall_R();
  break;
  case 6:
    auto6_wall_L();
  break;
  case 7:
    auto7_hang_R();
  break;
  case 8:
    auto8_hang_L();
  break;



  default:
  break;
  }
  taskDelete(armtaskpid_auto);
  taskDelete(clawtaskpid_auto);
  //taskDelete(taskdisable_functions);
}
