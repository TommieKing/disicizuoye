#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <D:\�����ϰ\InsertSort\qgsort.h>
#define MAX 200000
#define BASE 10
//��������
void insertSort(int* a, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j] > key)) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
//�鲢���򣨺ϲ����飩
void Mergeaay(int* a, int begin, int mid, int end, int* temp)
{
    int i, k;
    
    
    int left_begin = begin;//��߲��ֵ�ͷ��
    int left_end = mid;//��߲��ֵ�ͷβ��
    int right_begin = mid + 1;//�ұ߲��ֵ�ͷ��
    int right_end = end;//�ұ߲��ֵ�ͷβ��

    for (k = 0; left_begin <= left_end && right_begin <= right_end; k++)// �Ƚ�����ָ����ָ���Ԫ��
    {                                                                  
        if (a[left_begin] <= a[right_begin])//��С�����ŵ�temp�У�����ָ���һ����
        {
            temp[k] = a[left_begin++];
        }
        else
        {
            temp[k] = a[right_begin++];
        }
    }

    if (left_begin <= left_end) //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
    {                 
        for (i = left_begin; i <= left_end; i++)
            temp[k++] = a[i];
    }

    if (right_begin <= right_end)//���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
    {
        for (i = right_begin; i <= right_end; i++)
            temp[k++] = a[i];
    }

    for (i = 0; i < end - begin + 1; i++)
        a[begin + i] = temp[i];
   
}

// �鲢����
void MergeSort(int* a, int begin, int end, int* temp)
{
    int mid = 0;
    if (begin < end)
    {
        mid = (begin + end) / 2;          
        MergeSort(a, begin, mid, temp);
        MergeSort(a, mid + 1, end, temp);
        Mergeaay(a, begin, mid, end, temp);
    }
}
//�������򣨵ݹ�棩
void QuickSort_Recursion(int* a, int begin, int end)
{
    if (begin < end)//�ж������Ƿ�ֻ��һ����
    {
        int temp = a[begin]; //������ĵ�һ������Ϊ��׼��
        int i = begin; //�����ҽ��в���ʱ�ġ�ָ�롱��ָʾ��ǰ��λ��
        int j = end; //���ҵ�����в���ʱ�ġ�ָ�롱��ָʾ��ǰ��λ��
       
        while (i < j) //���ظ�����
        {
            while (i<j && a[j] > temp)//�ҵ�С�ڵ��ڻ�׼Ԫ�ص���a[j]
                j--;
            
            a[i] = a[j];//���ұ�С�ڵ��ڻ�׼Ԫ�ص������������Ӧλ��

            while (i < j && a[i] <= temp)//�ҵ����ڵ��ڻ�׼Ԫ�ص���a[i]
                i++;
            
            a[j] = a[i];//����ߴ��ڵ��ڻ�׼Ԫ�ص��������ұ���Ӧλ��
        }
       
        a[i] = temp; //����׼Ԫ��������Ӧλ��
      
        QuickSort_Recursion(a, begin, i - 1);//�Ի�׼Ԫ�ص����������������ƵĿ�������
        
        QuickSort_Recursion(a, i + 1, end);//�Ի�׼Ԫ�ص��ұ�������������ƵĿ�������
    }
}
////�������򣨷ǵݹ�棩
//void QuickSort(int* a, int size)
//{
//
//}
////�������������ţ�
//int Partition(int* a, int begin, int end)
//{
//
//}
//��������
void CountSort(int* a, int size, int max)
{
    int min;
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


    int* count = (int*)calloc(size, sizeof(int));//��������

    int i = 0;
    for (i = 0; i < size; i++)
    {
        count[i] = 0;//��ʼ����������
    }

    for (i = 0; i < size; i++)
    {
        count[a[i] - min] = count[a[i] - min]++;//ͳ��Ԫ�س��ֵĴ���
    }
    for (i = 0; i < (size - 1); i++)
    {
        count[i + 1] = count[i + 1] + count[i];//��count�����ݱ�ʾΪԪ���ڽ������������λ��
    }
    int* result = (int*)calloc(size, sizeof(int));//�������
    int j;
    for (j = 0; j < size; j++)
    {
        result[count[a[j] - min] - 1] = a[j];//��Ԫ����ӵ���������ж�Ӧλ��
        count[a[j] - min]--;//���Ԫ�غ󣬼��������ǵ�λ����ǰ��һ
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = result[i];//������õ����ݸ�ֵ��a
    }
    free(count);
    free(result);//�ͷ��ڴ�
}
//������������
void RadixCountSort(int* a, int size)
{
    int i, m = a[0], exp = 1;
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

    int* b = (int*)calloc(size, sizeof(int));//��������
    int* bucket = (int*)calloc(size, sizeof(int));//��������
    for (i = 1; i < size; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }

    while (m / exp > 0)//�ж�λ���Ƿ�����
    {
        int bucket[BASE] = { 0 };//��ʼ��

        for (i = 0; i < size; i++)
        {
            bucket[(a[i] / exp) % BASE]++;//ͳ��Ԫ�س��ֵĴ���
        }

        for (i = 1; i < BASE; i++)
        {
            bucket[i] += bucket[i - 1];//��bucket�����ݱ�ʾΪԪ���ڽ������������λ��
        }

        for (i = size - 1; i >= 0; i--)
        {
            b[--bucket[(a[i] / exp) % BASE]] = a[i];//����λ������
        }

        for (i = 0; i < size; i++)
        {
            a[i] = b[i];//������õ����鸳ֵ��a
        }

        exp *= BASE;
    }
    free(bucket);
    free(b);

}
//��ɫ����
//void ColorSort(int* a, int size)
//{
//
//}