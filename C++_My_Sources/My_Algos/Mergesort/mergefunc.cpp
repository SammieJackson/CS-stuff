#include "mergefunc.h"
#include <iostream>
#include <math.h>

using namespace std;

void vvod(int a[], int maxsize, int& sizea){
cout<<"Enter elements of an array, use space to divide them: "<<endl;
for (int i=0; i<maxsize; i++){
cin>>a[i];
sizea++;
if (cin.eof()) {a[i]=-1; sizea--; return;} else
if (cin.fail()) {cout<<"Wrong input!"<<endl; a[i]=-1; sizea--; return;}
}
return;
}

void vyvod(int a[], int sizea){
cout<<"Your array: ";
for (int i=0; i<sizea; i++){cout<<a[i]<<" ";}
return;
}

void sorta(int a[maxsize], int sizea){
    if (sizea==1) return; else{
 double k=int(sizea/2);
 const int sizeL=k;
 const int sizeR=sizea-sizeL;
 int L[sizeL];
 int R[sizeR];
   for (int i=0; i<sizeL; i++){
    L[i]=a[i];
   }
  for (int j=0; j<sizeR; j++){
    R[j]=a[j+sizeL];
   }
  sorta(L, sizeL);
  sorta(R, sizeR);
  mergea(L, sizeL, R, sizeR, a, sizea);
 }
}

void mergea(int L[maxsize], int sizeL, int R[maxsize], int sizeR, int a[maxsize], int sizea){
 int i=0, l=0, r=0;
while (i<sizea){
 if (l==sizeL){a[i]=R[r]; r++;} else
  if (r==sizeR){a[i]=L[l]; l++;} else
   if (L[l]>R[r]){a[i]=R[r]; r++;}
    else {a[i]=L[l]; l++;}
 i++;
}
}
