#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


int main(int argc, char *argv[])
{

  if (argc<3) {
    fprintf(stderr, "Usage: mv file1 file, or mv file file ... dir\n");
    exit(1);
  }
  exit(0);
}
