#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "syscall.h"

int main(int argc, char *argv[]){
	char buf[512];
	int fd, fd1, r, w;
	char *src;
	char *dest;
	if(argc <= 2){
		printf(2, "Usage: cp src dest\n");
		exit();
	}
	src = argv[1];
	dest = argv[2];
	if ((fd = open(src, O_RDONLY)) < 0){
		printf(2, "cp: cannot open source %s\n", src);
		exit();
	}
	if ((fd1 = open(dest, O_CREATE|O_WRONLY)) < 0){
		printf(2, "cp: cannot open destination %s\n", dest);
		exit();
	}
	while ((r = read(fd, buf, sizeof(buf))) > 0){
		w = write(fd1, buf, r);
		if (w != r || w<0) break;
	}
	if (r<0){
		printf(2, "cp: error copying %s to %s\n", src, dest);
	}
	close(fd);
	close(fd1);
	exit();
}
