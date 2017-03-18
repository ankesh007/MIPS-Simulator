#include <stdio.h>
#include <stdlib.h>
#include "global_vars.h"
#include "parser.h"
#include "utils.h"

int main(int argc, char* argv[])
{
  FILE* code;
  FILE* svg;

  // Input error handling
  if (argc == 3)
  {
    code = fopen(argv[1], "r");
    svg = fopen(argv[2], "w");
  }
  else
  {
    fprintf(stderr, "Usage: %s <instruction_file> <svg_output>\n", argv[0]);
    throw_error("");
  }

  char* a = malloc(sizeof(char) * 10);
  int i = 0;

  while (fscanf(code, "%s", a)!=EOF)
  {
    int num = (int)strtol(a, NULL, 16);
    program[i++] = instruction_parse(num);
    //print_instruction(&program[i - 1]);
  }
  free(a);

  MAX_PC = 4 * (i - 1);

  for (i = 0; i <= MAX_PC; i += 4)
  {
    print_instruction(&program[i / 4]);
  }

  fclose(code);
  fclose(svg);
  return 0;
}