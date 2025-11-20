#ifndef FIB_H
#define FIB_H


class Fib {
private:
    int f , g ;
public:
    Fib(int n );
    int get ();
    int next();
    int prev();
};

#endif