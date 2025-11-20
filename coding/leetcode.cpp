#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 返回 A - B 的字符串，要求 A >= B
string high_precision_subtract(string A, string B) {
    // 反转字符串，方便从低位开始处理
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string res;
    int borrow = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        int ai = A[i] - '0';
        int bi = (i < B.size()) ? B[i] - '0' : 0;
        int diff = ai - bi - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff + '0');
    }

    // 去掉前导零
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string A, B;
    cin >> A >> B;

    // 判断大小
    bool negative = false;
    if (A.size() < B.size() || (A.size() == B.size() && A < B)) {
        swap(A, B);
        negative = true;
    }

    string result = high_precision_subtract(A, B);
    if (negative) cout << "-";
    cout << result << endl;

    return 0;
}
