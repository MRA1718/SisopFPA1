#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  //mengecek banyaknya paramater yang akan dieksekusi
  if(argc < 2) //terpenuhi jika command cd dipanggi tidak terdapat destinasi path yang dituju
  {
    printf(1,"cd need arguments [path destination]");
    exit();
  }
}
