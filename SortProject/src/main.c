#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <D:\�����ϰ\InsertSort\qgsort.h>

int main()
{
	int s, n, size, max;
	int* temp;
	int begin, mid, end;
	n = 100;
	int* a;
	int i;
	i = 0;
	a = (int*)malloc((n) * sizeof(int));

	FILE* fp = fopen("C:\\Users\\king\\Desktop\\data.txt", "r");
	if (!fp)
	{
		printf("can't open file\n");
		return -1;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%5d", &a[i]);
		
		i++;
	}

	printf("\n");
	fclose(fp);

	
	while (1)
	{
		printf("******����������ѡ��******\n");
		printf("******1.��������******\n");
		printf("******2.�鲢����******\n");
		printf("******4.�������򣨵ݹ�棩******\n");
		printf("******5.��������******\n");
		printf("******6.������������******\n");

		scanf_s("%d", &s);
		switch (s)
		{
		case 1:

			{	clock_t start_time; }
		
			clock_t start_time = clock(); 
			{
				insertSort(a, n);
			}

			clock_t end_time = clock();
			printf("Running time is: %lfms\n", (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000);
		
			printf("\n");
		
			break;
		case 2:
			
			{	clock_t start_time; }

			clock_t start2_time = clock();
			{
				begin = a[0];
				end = a[n - 1];
				mid = a[(n - 1) / 2];
				temp = (int*)malloc((end - begin + 1) * sizeof(int));//����ռ�
				
				Mergeaay(a, begin, mid, end, temp);
				free(temp);
			}

			clock_t end2_time = clock();
			printf("Running time is: %lfms\n", (double)(end2_time - start2_time) / CLOCKS_PER_SEC * 1000);

			printf("\n");
			break;

		case 4:
			//�������򣨵ݹ�棩

			{	clock_t start_time; }

			clock_t start3_time = clock();
			{
				begin = a[0];
				end = a[n - 1];
				mid = a[(n - 1) / 2];
				temp = (int*)malloc((end - begin + 1) * sizeof(int));//����ռ�

				MergeSort(a, begin, mid, end, temp);
				free(temp);
			}

			clock_t end3_time = clock();
			printf("Running time is: %lfms\n", (double)(end3_time - start3_time) / CLOCKS_PER_SEC * 1000);

			printf("\n");

			break;
		case 5:
			//��������
			{	clock_t start_time; }

			clock_t start4_time = clock();
			{
				int min;
				min = a[0];
				max = a[0];
				size = max - min + 1;
				CountSort(a, size, max);
			
			}

			clock_t end4_time = clock();
			printf("Running time is: %lfms\n", (double)(end4_time - start4_time) / CLOCKS_PER_SEC * 1000);

			printf("\n");
			break;
		case 6:
			//������������
		

			{	clock_t start_time; }

			clock_t start5_time = clock();
			{
				int min, max;
				min = a[0];
				max = a[0];
				size = max - min + 1;//���鳤��
				for (int i = 0; i < size; i++)//�õ����ֵ����Сֵ
				{
					if (a[i] > max)
						max = a[i];
					if (a[i] < min)
						min = a[i];
				}
				RadixCountSort(a, size);

			}

			clock_t end5_time = clock();
			printf("Running time is: %lfms\n", (double)(end5_time - start5_time) / CLOCKS_PER_SEC * 1000);

			printf("\n");


			break;

			system("pause");
			system("cls");
		}
	}

	return 0;
}