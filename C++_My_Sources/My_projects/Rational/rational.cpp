#include "rational.h"

using namespace std;

int GCD(int a, int b){
    if ((a == 0) && (b == 0)) return 1;
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;
    while ((a != 0) && (b != 0)) {
        if (a>b) a=a-b; else
            b=b-a;
    }
    if (a == 0) return b;
    if (b == 0) return a;
}

int LCD(int a, int b){
    return a*b/GCD(a,b);
}
