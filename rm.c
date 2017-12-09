#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2) //mengecek parameter, jika terpenuhi
  {
    printf(2, "Usage: rm files...\n");
    exit();
  }

  for(i = 1; i < argc; i++) //looping untuk unlink
  {
    if(unlink(argv[i]) < 0) //menghapus file dengan unlink(menghaous pointer)
	{
      printf(2, "rm: %s failed to delete\n", argv[i]); // jika nilai argv negatif maka akan muncul pesan failed
      break;
    }
  }

  exit(); // jika kondisi diatas tidak ada yg terpenuhi maka cd di eksekusi dan program exit
}
