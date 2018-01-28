#include "main.h"
#include "clawarmextern.h"
#include "LCDfunctions.h"
#include "autofunctions.h"
#include "autoruns.h"
//#include "autoruns.h"

void autonomous() {

  TaskHandle armcontrol_auto = taskCreate(armcontrol, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle clawcontrol_auto = taskCreate(clawcontrol, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
//TaskHandle auto_lcd = taskCreate(autolcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

delay(250);

switch (myauto) {

  case -1:
    programmingskills();
  break;
  case 1:
    centerfence_R();
  break;
  case 2:
    centerfence_L();
  break;
  case 3:
    cubedirect_R();
  break;
  case 4:
    cubedirect_L();
  break;
  case 5:
    nearauto_R();
  break;
  case 6:
    nearauto_L();
  break;
  case 7:
    hangauto_R();
  break;
  case 8:
    hangauto_L();
  break;
  case 9:
  break;
  default:

  break;
  }
}
