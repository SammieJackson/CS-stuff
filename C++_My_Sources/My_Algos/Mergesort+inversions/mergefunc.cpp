#include "mergefunc.h"
#include <iostream>
#include <math.h>

using namespace std;

void vvod(double* a, int maxsize, double& sizea){
cout<<"Enter array size: "<<endl;
double n;
cin>>n;
cout<<"Enter elements of an array, use space to divide them: "<<endl;
for (int i=0; i<n; i++){
cin>>a[i];
sizea++;
if (cin.eof()) {a[i]=-1; sizea--; return;} else
if (cin.fail()) {cout<<"Wrong input!"<<endl; a[i]=-1; sizea--; return;}
}
return;
}

void vyvod(double* a, double sizea){
cout<<"Your array: ";
for (int i=0; i<sizea; i++){cout<<a[i]<<" ";}
return;
}

void sort_n_count(double* a, double sizea, long double& counter){
    if (sizea==1) return; else{
 int k=int(sizea/2);
 const int sizeL=k;
 const int sizeR=sizea-sizeL;
 double* L = new double[sizeL];
 double* R = new double[sizeR];
   for (int i=0; i<sizeL; i++){
    L[i]=a[i];
   }
  for (int j=0; j<sizeR; j++){
    R[j]=a[j+sizeL];
   }
  sort_n_count(L, sizeL, counter);
  sort_n_count(R, sizeR, counter);
  merge_n_count(L, sizeL, R, sizeR, a, sizea, counter);
 }
}

void merge_n_count(double* L, double sizeL, double* R, double sizeR, double* a, double sizea, long double& counter){
 int i=0, l=0, r=0;
while (i<sizea){
 if (l==sizeL){a[i]=R[r]; r++;} else
  if (r==sizeR){a[i]=L[l]; l++;} else
   if (L[l]>R[r]){a[i]=R[r]; r++; counter = counter + (sizeL-l); }
    else {a[i]=L[l]; l++;}
 i++;
}
}
