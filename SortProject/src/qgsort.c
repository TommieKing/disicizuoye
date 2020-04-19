#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <D:\编程练习\InsertSort\qgsort.h>
#define MAX 200000
#define BASE 10
//插入排序
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
//归并排序（合并数组）
void Mergeaay(int* a, int begin, int mid, int end, int* temp)
{
    int i, k;
    
    
    int left_begin = begin;//左边部分的头部
    int left_end = mid;//左边部分的头尾部
    int right_begin = mid + 1;//右边部分的头部
    int right_end = end;//右边部分的头尾部

    for (k = 0; left_begin <= left_end && right_begin <= right_end; k++)// 比较两个指针所指向的元素
    {                                                                  
        if (a[left_begin] <= a[right_begin])//将小的数放到temp中，并且指向后一个数
        {
            temp[k] = a[left_begin++];
        }
        else
        {
            temp[k] = a[right_begin++];
        }
    }

    if (left_begin <= left_end) //若第一个序列有剩余，直接复制出来粘到合并序列尾
    {                 
        for (i = left_begin; i <= left_end; i++)
            temp[k++] = a[i];
    }

    if (right_begin <= right_end)//若第二个序列有剩余，直接复制出来粘到合并序列尾
    {
        for (i = right_begin; i <= right_end; i++)
            temp[k++] = a[i];
    }

    for (i = 0; i < end - begin + 1; i++)
        a[begin + i] = temp[i];
   
}

// 归并排序
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
//快速排序（递归版）
void QuickSort_Recursion(int* a, int begin, int end)
{
    if (begin < end)//判断区间是否只有一个数
    {
        int temp = a[begin]; //将区间的第一个数作为基准数
        int i = begin; //从左到右进行查找时的“指针”，指示当前左位置
        int j = end; //从右到左进行查找时的“指针”，指示当前右位置
       
        while (i < j) //不重复遍历
        {
            while (i<j && a[j] > temp)//找到小于等于基准元素的数a[j]
                j--;
            
            a[i] = a[j];//将右边小于等于基准元素的数填入左边相应位置

            while (i < j && a[i] <= temp)//找到大于等于基准元素的数a[i]
                i++;
            
            a[j] = a[i];//将左边大于等于基准元素的数填入右边相应位置
        }
       
        a[i] = temp; //将基准元素填入相应位置
      
        QuickSort_Recursion(a, begin, i - 1);//对基准元素的左边子区间进行相似的快速排序
        
        QuickSort_Recursion(a, i + 1, end);//对基准元素的右边子区间进行相似的快速排序
    }
}
////快速排序（非递归版）
//void QuickSort(int* a, int size)
//{
//
//}
////快速排序（枢轴存放）
//int Partition(int* a, int begin, int end)
//{
//
//}
//计数排序
void CountSort(int* a, int size, int max)
{
    int min;
    min = a[0];
    max = a[0];
    size = max - min + 1;//数组长度
    for (int i = 0; i < size; i++)//得到最大值和最小值
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }


    int* count = (int*)calloc(size, sizeof(int));//计数数组

    int i = 0;
    for (i = 0; i < size; i++)
    {
        count[i] = 0;//初始化计数数组
    }

    for (i = 0; i < size; i++)
    {
        count[a[i] - min] = count[a[i] - min]++;//统计元素出现的次数
    }
    for (i = 0; i < (size - 1); i++)
    {
        count[i + 1] = count[i + 1] + count[i];//将count中数据表示为元素在结果数组中最后的位置
    }
    int* result = (int*)calloc(size, sizeof(int));//结果数组
    int j;
    for (j = 0; j < size; j++)
    {
        result[count[a[j] - min] - 1] = a[j];//将元素添加到结果数组中对应位置
        count[a[j] - min]--;//添加元素后，计数数组标记的位置向前加一
    }
    for (int i = 0; i < size; i++)
    {
        a[i] = result[i];//将排序好的数据赋值到a
    }
    free(count);
    free(result);//释放内存
}
//基数计数排序
void RadixCountSort(int* a, int size)
{
    int i, m = a[0], exp = 1;
    int min, max;
    min = a[0];
    max = a[0];
    size = max - min + 1;//数组长度
    for (int i = 0; i < size; i++)//得到最大值和最小值
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    int* b = (int*)calloc(size, sizeof(int));//计数数组
    int* bucket = (int*)calloc(size, sizeof(int));//计数数组
    for (i = 1; i < size; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }

    while (m / exp > 0)//判断位上是否有数
    {
        int bucket[BASE] = { 0 };//初始化

        for (i = 0; i < size; i++)
        {
            bucket[(a[i] / exp) % BASE]++;//统计元素出现的次数
        }

        for (i = 1; i < BASE; i++)
        {
            bucket[i] += bucket[i - 1];//将bucket中数据表示为元素在结果数组中最后的位置
        }

        for (i = size - 1; i >= 0; i--)
        {
            b[--bucket[(a[i] / exp) % BASE]] = a[i];//按个位数排序
        }

        for (i = 0; i < size; i++)
        {
            a[i] = b[i];//将排序好的数组赋值给a
        }

        exp *= BASE;
    }
    free(bucket);
    free(b);

}
//颜色排序
//void ColorSort(int* a, int size)
//{
//
//}