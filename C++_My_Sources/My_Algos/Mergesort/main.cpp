#include <iostream>
#include "mergefunc.h"

using namespace std;

int main()
{
 int a[maxsize], sizea=0;
 vvod(a, maxsize, sizea);
 vyvod(a, sizea);
 sorta(a, sizea);
 cout<<endl<<" Sorted array: ";
 vyvod(a, sizea);
 return 0;
}
