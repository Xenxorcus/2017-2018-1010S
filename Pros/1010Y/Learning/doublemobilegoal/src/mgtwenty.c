#include "main.h"
#include "mgtwenty.h"

void mgtwentySet(int power)
{
  motorSet(MG20, -power);
}
