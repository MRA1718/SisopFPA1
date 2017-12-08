
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"

int main(int argc, char *argv[])
{
	int fp;
	if(argc < 2){
	printf(2, "Touch files with 2 arguments.\n");
	}

for(int i=0;i<=argc;i++)
{
	if((fp = open(argv[i], O_CREATE | O_RDWR)) < 0){
		printf(2, "touch: %s failed to create\n", argv[i]);
	}
	close(fp);
}	
	exit();
}
