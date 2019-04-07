#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include "vector.h"

class Matrix{
public:
    Matrix();
    Matrix(const int m, const int n, const Rational myarr[][12]);
    Matrix(const Matrix&);
    void operator=(const Matrix&);
    void create(const Rational myarr[][12]);
    //Matrix& minor(const int& r, const int& c);
    std::string inverse()const;
    void add_rows(const int i, const int j, const Rational k);
    void add_columns(const int i, const int j, const Rational k);
    void find_base(Vector (&ar)[12])const;
    void refresh();
    void normalize();
    void randomize();
   // Rational get_det();
    int get_rang();
    //void swap(int row1, int row2);
    bool add_vector_col(const Vector&);
    bool add_vector_row(const Vector&);
    Matrix& operator /(const Rational& a);
    Matrix& operator -(const Rational& a);
    Matrix& operator *(const Matrix&);
    friend Vector &operator *(const Vector&, const Matrix&);
    friend Vector &operator *(const Matrix&, const Vector&);
    operator std::string()const;
    static const int s=12;
    Rational arr[s][s];
    int rang;
private:
    Rational det;
    int ver, hor;// ver is number of columns, hor - of rows
    Vector rows[s];
    Vector columns[s];
    //Rational minors[s][s];
};

Rational determ(Rational arr[][12], const int n);
int rrang(Rational ar[][12], int, int);

#endif // MATRIX_H_INCLUDED

/*	for (j=0;j<n;j++)
    {
        for (i=n-1;i>j;i--)
        {
            for (r=0;r<n;r++)
            {
                a[i][r]=a[i][r]-((a[i][j]/a[i-1][j])*a[i-1][r]);
            }
        }
    }
    printf("The operated matrix is\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            printf("%f\t",a[i][j]);
        printf("\n");
    }

Rational Matrix::determ(Rational a[20][20], const int& h, const int& v){
int p, q, k, i, j;
Rational det=0, temp[20][20];
  if (h != v) {cout<<"\n Not square matrix!\n";return 0;}
  if (h==1) {
    return a[0][0];
  } else if(h==2) {
    det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    return det;
  } else {
    for(p=0;p<h;p++) {
      q = 0;
      k = 0;
      for(i=1;i<h;i++) {
        for( j=0;j<h;j++) {
          if(j==p) {
            continue;
          }
          temp[q][k] = a[i][j];
          k++;
          if(k==q-1) {
            q++;
            k = 0;
          }
        }
      }
      det=det+a[0][p]*pow(-1,p)*determ(temp,h-1, h-1);
    }
    return det;
  }
}
*/
