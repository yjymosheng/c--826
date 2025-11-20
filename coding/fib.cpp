#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int maxnumber;

int m[90] = {1, 1};

//普通方法
int f(int n) { return (n <= 2) ? 1 : f(n - 1) + f(n - 2); }

// 记忆化搜索方法
int a(int n) {
    if (n <= 2) return m[n - 1];

    if (m[n - 1] == 0) {
        m[n - 1] = a(n - 1) + a(n - 2);
    }

    return m[n - 1];
}


typedef struct {
    int a, b, c, d;
} matrix;

matrix multiply(const matrix &m1, const matrix &m2) {
    return {
        m1.a * m2.a + m1.b * m2.c,
        m1.a * m2.b + m1.b * m2.d,
        m1.c * m2.a + m1.d * m2.c,
        m1.c * m2.b + m1.d * m2.d
    };
}

matrix hleper(matrix a, int n) {
    matrix res = matrix{1, 0, 0, 1};
    while (n) {
        if (n & 1) {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        n >>= 1;
    }

    return res;
}


// 矩阵方法 logn
int b(int n) {
    if (n == 0) return 0;
    matrix base = {0, 1, 1, 1};
    matrix res = hleper(base, n - 1);
    return res.d;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, z;

    for (int i = 1; i <= 90; i++) {
        // x = f(i);
        y = a(i);
        z = b(i);
        if (!(y == z)) {
            cout << i << "\n";
            // cout << f(i) << " ";
            cout << a(i) << " ";
            cout << b(i) << "\n";

            for (auto m1: m) {
                cout << m1 << " ";
            }
            cout << "\n";
        };
    }
    return 0;
}
