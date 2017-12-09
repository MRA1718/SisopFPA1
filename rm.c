#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2) //mengecek parameter, jika inputan salah
  {
    printf(2, "rm [filename]a\n");
    exit();
  }

  for(i = 1; i < argc; i++) //looping untuk unlink
  {
    if(unlink(argv[i]) < 0) //menghapus file dengan unlink
	{
      printf(2, "rm: %s failed to delete\n", argv[i]); // jika nilai argv negatif maka akan muncul pesan failed
      exit();
    }
  }

  exit();
}
