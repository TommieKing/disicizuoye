
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int main(void)
{
	srand(time(NULL));//�������� 
	int i, j, s = 0;
	FILE* fp = NULL;
	for (i = 0; i < 100; i++) //��������� 
	{
		j = rand() % 10000;
		printf("j:%d\n", j);
		fp = fopen("C:\\Users\\king\\Desktop\\data.txt", "a");//��ָ��Ŀ¼�´���.txt�ļ�
		fprintf(fp, "%5d", j); //�������д���ļ�
		fclose(fp);
	}

	return 0;
}
