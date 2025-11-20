#ifndef BITMAP_H
#define BITMAP_H


typedef int Rank;

template<typename T>
class Bitmap {
private:
    char *_elem;
    int _size;
    int _n;

    void expand(T size);

public:

    Bitmap(T size);

    ~Bitmap();

    void set(T pos);

    void clear(T pos);

    bool test(T pos);

    void print() ;// 可选但很方便调试
};


#include "bitmap.tpp"

#endif // BITMAP_H