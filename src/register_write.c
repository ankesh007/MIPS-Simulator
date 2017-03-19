#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "global_vars.h"
#include "main_functions.h"
#include "utils.h"

void* register_read(void* data)
{
  printf("Inside Register Write");
  while (1)
  {
    if (pipeline[3].instr.type != NO_OP)
    {
      // Reading stage
      if (pipeline[3].instr.Itype == LDR_BYTE ||
          pipeline[3].instr.Itype == LDR_WORD)
      {
        register_file[pipeline[3].instr.rt] = pipeline[3].rt_val;
      }
      else if (pipeline[3].instr.Ctype == DP)
      {
        register_file[pipeline[3].instr.rd] = pipeline[3].alu_result;
      }
    }
    else
    {
      // do nothing
    }
    sleep(1);
  }
}