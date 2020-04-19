
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int main(void)
{
	srand(time(NULL));//先种种子 
	int i, j, s = 0;
	FILE* fp = NULL;
	for (i = 0; i < 100; i++) //产生随机数 
	{
		j = rand() % 10000;
		printf("j:%d\n", j);
		fp = fopen("C:\\Users\\king\\Desktop\\data.txt", "a");//在指定目录下创建.txt文件
		fprintf(fp, "%5d", j); //把随机数写进文件
		fclose(fp);
	}

	return 0;
}
