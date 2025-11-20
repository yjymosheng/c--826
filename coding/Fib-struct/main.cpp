#include <iostream>
#include "fib.h"

int main() {
    // 构造一个 Fib 对象，生成 Fibonacci 数列直到 >= 10
    Fib fibSeq(10);

    std::cout << "Initial Fibonacci >= 10: " << fibSeq.get() << std::endl;

    // 输出接下来的 5 个 Fibonacci 数
    std::cout << "Next 5 Fibonacci numbers: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << fibSeq.next() << " ";
    }
    std::cout << std::endl;

    // 回退 3 个 Fibonacci 数
    std::cout << "Previous 3 Fibonacci numbers: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << fibSeq.prev() << " ";
    }
    std::cout << std::endl;

    return 0;
}
