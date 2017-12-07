#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  int i;
  if(argc < 2){
    printf(2, "Touch files ...\n");
    exit();
  }
    for(i = 1; i < argc; i++){
    if(mkfile(argv[i]) < 0){
      printf(2, "touch: %s failed to create\n", argv[i]);
      break;
    }
  }    
}
