#include "bitmap.h"

template<typename T>
Bitmap<T>::Bitmap(T size) {
    _size = size;
    _n = (size + 7) / 8;
    _elem = new char[_n]();
}

template<typename T>
Bitmap<T>::~Bitmap() {
    delete[] _elem;
}

template<typename T>
void Bitmap<T>::expand(T pos) {
    if (pos > _size) {
        _size *= 2;
        _n = (_size + 7) / 8;
        char *old_elem = _elem;
        _elem = new char[_n]();
        for (int i = 0; i < _n / 2; ++i) {
            _elem[i] = old_elem[i];
        }
        delete old_elem;
    }
}


template<typename T>
void Bitmap<T>::set(T pos) {
    expand(pos);
    int index = pos / 8;
    pos = (pos % 8) + 1;
    _elem[index] |= (1 << (pos - 1));
    printf("%d\n", _elem[index]);
}


template<typename T>
void Bitmap<T>::clear(T pos) {
    expand(pos);
    int index = pos / 8;
    pos = (pos % 8) + 1;
    _elem[index] &= ~(1 << (pos - 1));
}


template<typename T>
bool Bitmap<T>::test(T pos) {
    expand(pos);
    int index = pos / 8;
    pos = (pos % 8) + 1;
    return ((_elem[index] >> (pos - 1)) & 1) == 1;
}


template<typename T>
void Bitmap<T>::print() {
    printf("\n");
    printf("_size : %d\n", _size);
    printf("_n : %d\n", _n);

    printf("_elem\n");

    for (int i = 0; i < _n; ++i) {
        for (int j = 128; j >= 1; j >>= 1) {
            if (_elem[i] & j) {
                printf("0");
            } else printf("_");
        }
        printf("\n");
    }
    printf("\n");
}
