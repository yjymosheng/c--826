#include <cstdio>
#include <iostream>

#include "vector.h"

void show(Vector<int> &a) {
    for (auto a1: a) {
        printf("%d ", a1);
    }
    printf("\n");
}

int main() {
    Vector<int> a = Vector<int>();

    std::cout << "初始状态:" << std::endl;
    show(a);

    a.insert(0, 9);
    show(a);

    a.insert(0, 4);
    show(a);

    a.insert(1, 5);
    show(a);

    a.put(1, 2);
    show(a);

    printf("%d\n", a.get(2));

    a.insert(3, 6);
    show(a);

    a.insert(1, 7);
    show(a);

    printf("%d\n", a.remove(2));
    show(a);
    //
    // a.insert(1, 3);
    // show(a);
    //
    // a.insert(3, 4);
    // show(a);
    //
    // printf("%d\n", a.size());
    //
    // printf("%d\n", a.disordered());
    //
    // printf("%d\n", a.find(9));
    //
    // printf("%d\n", a.find(5));
    //
    // a.sort();
    // show(a);
    //
    // printf("%d\n", a.disordered());
    //
    // printf("%d\n", a.search(1));
    //
    // printf("%d\n", a.search(4));
    //
    // printf("%d\n", a.search(8));
    //
    // printf("%d\n", a.search(9));
    //
    // printf("%d\n", a.search(10));
    //
    // a.uniquify();
    // show(a);
    //
    // printf("%d\n", a.search(9));

    return 0;
}
