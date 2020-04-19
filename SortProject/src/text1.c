#include <stdlib.h>  

#include <stdio.h>  

#include <time.h>  

int main()
{
	int* a;
	int i;
	i = 0;
	a = (int*)malloc((100) * sizeof(int));
	FILE* fp = fopen("C:\\Users\\king\\Desktop\\data.txt", "r");
	if (!fp)
	{
		printf("can't open file\n");
		return -1;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%5d", &a[i]);
		printf("%5d", a[i]);
		i++;
	}
	
	printf("\n");
	fclose(fp);
	return 0;
}