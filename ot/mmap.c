#include "func.h"

int main()
{
	// 打开文件
	int fd = open("english.txt", O_RDWR);
	int len = lseek(fd, 0, SEEK_END);// 通过从头到尾的偏移，计算文件len

	// 文件大小
	// 创建内存映射区
	void *ptr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap");
		return -1;
	}	
	printf("%s", (char *)ptr);
	// 完成后需要释放
	munmap(ptr, len);
 	close(fd);	
	return 0;
}
