#include "fcntl.h"
#include "types.h"
#include "stat.h"
#include "fs.h"

// Move something to a new location
void do_move(char *from, char *to)
{
  // Unlink whatever is there
  unlink(to);

  // Link old to new
  if (link(from, to)!=0) {
    printf(2, "Unable to link %s to %s\n", from, to);
    exit();
  }

  // Now try to unlink the old one
  if (unlink(from)!=0) {
    printf(2, "Unable to unlink %s\n", from);
    exit();
  }
}
char* Strcat(char* s1, const char* s2)
{
  char* b = s1;

  while (*s1) ++s1;
  while (*s2) *s1++ = *s2++;
  *s1 = 0;

  return b;
}


int main(int argc, char *argv[])
{
  struct stat sb;
  char fulldest[200];

  if (argc<3) {
    printf(2, "Usage: mv file1 file, or mv file file ... dir\n");
    exit();
  }

  // See if the last argument is a directory
  if ((stat(argv[argc-1], &sb)==0) && sb.type == T_DIR) {

    // Yes, link each argument into that directory
    for (int i= 1; i < argc-1; i++) {

      // Append the from file's name to the directory name
      strcpy(fulldest, argv[argc-1]);
      Strcat(fulldest, "/");
      Strcat(fulldest, argv[i]);
      do_move(argv[i], fulldest);
    }
  } else {
    // We should only have two files
    if (argc != 3) {
      printf(2, "Usage: mv file1 file, or mv file file ... dir\n");
      exit();
    }
    do_move(argv[1], argv[2]);
  }
  exit();
}
