#include "stdio.h"

int main(void) {
  int f_input[2],s_input[2];
  for(;;)
  {
    scanf("%d %d %d %d",f_input[0],f_input[1],s_input[0],s_input[1]);
    if(f_input[0] + f_input[1] + s_input[0] + s_input[1] == 0) return 0;
    
  }
  return 0;
}
