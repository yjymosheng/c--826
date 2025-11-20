#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* generate_random_array(size_t size, int max_value);
void test_sort_performance(const char* name, void (*sort_func)(int*, size_t), int* data, size_t size) ;

void bubble_sort(int* arr, size_t n);
void insertion_sort(int* arr, size_t n);
int* merge_sorted_arrays(const int* arr1, size_t size1, const int* arr2, size_t size2);
int* merge_sort(const int* arr, size_t n);
void merge_sort_wrapper(int* arr, size_t size);

int main () {
    srand(time(NULL));  // 初始化随机种子

    size_t size = 100000;          // 数组长度
    int max_value = 500;         // 每个数的最大值（不含）

    int* big_array = generate_random_array(size, max_value);

    // test_sort_performance("Bubble Sort", bubble_sort, big_array, size);
    test_sort_performance("Insertion Sort", insertion_sort, big_array, size);
    test_sort_performance("Merge Sort", merge_sort_wrapper, big_array, size);

    free(big_array);
    return 0;

}



void bubble_sort(int* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void insertion_sort(int* arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


// 用于测试排序性能的函数
void test_sort_performance(const char* name, void (*sort_func)(int*, size_t), int* data, size_t size) {
    // 创建数组副本，避免修改原始数据
    int* copy = (int *)malloc(size * sizeof(int));
    memcpy(copy, data, size * sizeof(int));

    // 开始计时
    clock_t start = clock();
    sort_func(copy, size);  // 调用排序函数
    clock_t end = clock();

    // 计算耗时
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf( " %s took %.6f seconds.\n", name, time_spent);

    free(copy);
}


// 生成一个随机整数数组（含重复），元素值范围为 [0, max_value)
int* generate_random_array(size_t size, int max_value) {
    if (max_value <= 0) max_value = 100;  // 避免除以 0

    int* arr = (int *)malloc(size * sizeof(int));
    if (!arr) {
        perror("malloc failed");
        exit(1);
    }

    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % max_value;
    }

    return arr;
}


// 合并两个有序数组，返回新的有序数组（需要 free）
int* merge_sorted_arrays(const int* arr1, size_t size1, const int* arr2, size_t size2) {

    int outsize = size1 + size2;
    int * merged = (int * ) malloc(outsize* sizeof(int));

    int l  = 0, r = 0,index=0;


    while ( l < size1 && r < size2) {
        merged[index++] =  arr1[l] < arr2[r] ? arr1[l++] : arr2[r++];
    }

    while (l < size1) {
        merged[index++] = arr1[l++];
    }

    while (r < size2) {
        merged[index++] = arr2[r++];
    }
    return merged;

}


// 归并排序主函数
int* merge_sort(const int* arr, size_t n) {

    if (n <= 1) {
        int* single = (int*) malloc(n * sizeof(int));
        if (n == 1) single[0] = arr[0]; // 复制原数组元素
        return single;
    }

    int mid = n / 2;

    int * left  = merge_sort(arr , mid) ;
    int * right = merge_sort(arr+mid, n-mid);
    int* sorted = merge_sorted_arrays(left, mid, right, n - mid);

    free(left);
    free(right);

    return sorted;
}

void merge_sort_wrapper(int* arr, size_t size) {
    int* sorted = merge_sort(arr, size);
    memcpy(arr, sorted, size * sizeof(int)); // 把排好序的结果复制回原数组
    free(sorted);
}