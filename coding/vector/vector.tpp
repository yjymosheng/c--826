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
    _elem[r] = e;
    _size++;

    return r;
}

template<typename T>
void Vector<T>::expand() {
    if (_size + 1 > _capacity) {
        T *tmp = new T[_capacity * 2];
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
    T temp = remove(r, r + 1);
    return temp;
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi)return 0;
    while (hi < _size) {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink();

    return hi - lo;
}


template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1)return;
    if (_size << 2 > _capacity) return;

    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++) {
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}


template<typename T>
int Vector<T>::disordered() const {
    int count = 0;

    for (int i = 1; i < _size; i++) {
        if (_elem[i] < _elem[i - 1]) { count++; }
    }

    return count;
}

template<typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (e != _elem[hi]));
    return hi;
}


template<typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
    srand(time(0));
    int random = rand() % 1;
    switch (random) {
        case 0:
            bubbleSort(lo, hi);
            // case 1:
            //     mergeSort(lo, hi);
    }
}

template<typename T>
Rank Vector<T>::search(T const &e, Rank lo, Rank hi) const {
    while (lo < hi) {
        Rank mid = lo + (hi - lo) / 2;
        if (e < _elem[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo - 1;
}

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
    while (!bubble(lo, hi--));
}

template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
    bool sorted = true;
    while (++lo < hi) {
        if (_elem[lo - 1] > _elem[lo]) {
            sorted = false;
            std::swap(_elem[lo - 1], _elem[lo]);
        }
    }
    return sorted;
}

template<typename T>
int Vector<T>::uniquify() {
    int oldSize = _size;
    int i = 0 , j =  1;
    while (j < oldSize) {
        if (_elem[i] != _elem[j]) {
            i++  ;  _elem[i] = _elem[j];
        }
        j ++ ;
    }
    _size = i+1;

    return oldSize-  _size;
}

template<typename T>
T &Vector<T>::operator[](Rank r) const {
    return _elem[r];
}
