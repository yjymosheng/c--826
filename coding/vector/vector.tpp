//
// Created by mosheng on 25-6-12.
//

#include "vector.h"

template<typename T>
Rank Vector<T>::insert(Rank r, T const &e) {
    expand();

    // 移动
    for (int i = _size; i > r; i--) {
        _elem[i] = _elem[i - 1];
    }

    // insert
    _elem[r] = e;_size++;

    return r;

}

template<typename T>
void Vector<T>::expand() {
    if (_size+1 > _capacity) {
        T * tmp = new T[_capacity*2];
        _capacity *= 2;

        //迁移
        for (int i = 0; i < _size; i++) {
            tmp[i] = _elem[i];
        }
        delete[] _elem;
        _elem = tmp;
    }
}

template<typename T>
void Vector<T>::put(Rank i, const T &e) {
    _elem[i] = e;
}

template<typename T>
T Vector<T>::remove(Rank r) {

}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo==hi )return 0 ;
    while (hi < _size) {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;shrink();

    return hi-lo;
}

