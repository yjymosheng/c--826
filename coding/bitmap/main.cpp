#include <iostream>
#include "bitmap.h"

int main() {
    Bitmap<int> bm(64); // 初始容量 64 位

    std::cout << "== Bitmap 简洁测试开始 ==" << std::endl;

    for (int i = 0; i < 128; ++i) {
        bm.set(i);
        if (bm.test(i)) {
            std::cout << "[Pass] set + test 成功: 位置 " << i << std::endl;
        } else {
            std::cerr << "[Fail] set/test 失败: 位置 " << i << std::endl;
        }

        bm.clear(i);
        if (!bm.test(i)) {
            std::cout << "[Pass] clear + test 成功: 位置 " << i << std::endl;
        } else {
            std::cerr << "[Fail] clear/test 失败: 位置 " << i << std::endl;
        }
    }

    std::cout << "== Bitmap 测试结束 ==" << std::endl;

    bm.print();
    return 0;
}
