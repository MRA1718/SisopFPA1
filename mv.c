#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc, char *argv[]){
	char buf[1000];
  if (argc < 3){
    printf(2, "Usage: mv file1 file2 ..... dest or mv oldname newname\n");
    exit();
  }
  if ((link(argv[1], argv[2]) < 0) || (unlink(argv[1]) < 0))
    printf(2, "mv %s to %s failed\n", argv[1], argv[2]);

  exit();
}
