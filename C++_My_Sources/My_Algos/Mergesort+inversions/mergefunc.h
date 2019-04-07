#ifndef MERGEFUNC_H_INCLUDED
#define MERGEFUNC_H_INCLUDED

const int maxsize=100000;
void vvod(double* a, int maxsize, double &sizea);
void vyvod(double* a, double sizea);
void sort_n_count(double* a, double sizea, long double& counter);
void merge_n_count(double* L, double sizeL, double* R, double sizeR, double* a, double sizea, long double& counter);

#endif // MERGEFUNC_H_INCLUDED
