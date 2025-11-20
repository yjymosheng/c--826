
#include <stdio.h>
#include <stdlib.h>

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

// 测试
int main() {
    int arr[] = {42, 9, 1, 7, 3, 5, 51, 4, 2, 6, 8, 10};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    int* sorted = merge_sort(arr, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
    return 0;
}