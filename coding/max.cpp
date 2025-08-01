#include <algorithm>
#include <cstdio>

int d[] = {-2,1,-3,4,-1,2,1,-5,4};

int sum(int * p, int lo, int i) {
    int sum = 0;
    for (int k = lo; k <= i; k++) {
        sum += p[k];
    }
    return sum;
}

int maxsum(int A[],int lo, int hi) {
    if ( hi - lo < 2 ) return A[lo]; //递归基
    int mi = (lo + hi) / 2; //在中点切分
    int gsL = A[mi-1], sL = 0, i = mi; //枚举
    while ( lo < i-- ) //所有[i, mi)类区段
        if ( gsL < (sL += A[i]) ) gsL = sL; //更新
    int gsR = A[mi], sR = 0, j = mi-1; //枚举
    while ( ++j < hi ) //所有[mi, j)类区段
        if ( gsR < (sR += A[j]) ) gsR = sR; //更新
    return std::max( gsL + gsR, std::max( maxsum(A, lo, mi), maxsum(A, mi, hi) ) ); //递归
}



int main(){

    int a = maxsum(d,0,sizeof(d)/sizeof(d[0]));
    printf("%d\n", a);

}
