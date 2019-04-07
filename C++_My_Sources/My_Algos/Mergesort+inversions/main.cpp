#include <iostream>
#include "mergefunc.h"

using namespace std;

int main()
{
 double* a = new double[maxsize];
 double sizea=0;
 vvod(a, maxsize, sizea);
 //vyvod(a, sizea);
 long double countr=0;
 sort_n_count(a, sizea, countr);
 cout<<endl<<" Sorted array: ";
 //vyvod(a, sizea);
 cout<<fixed<<"\n Number of inversions = "<<countr;
 return 0;
}
