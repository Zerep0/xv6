#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf(2, "usage: kill pid...\n");
    exit(EXIT_SUCCESS);
  }
  for(i=1; i<argc; i++)
    kill(atoi(argv[i]));
  exit(EXIT_SUCCESS);
}
