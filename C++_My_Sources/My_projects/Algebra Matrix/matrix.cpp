#include "matrix.h"
#include <cmath>
#include <iostream>
#include <cstdlib>


using std::string;
using namespace std;

Matrix::Matrix()
{ver=1; hor=1; arr[0][0]=0; refresh();}

void Matrix::create(const Rational myarr[][12]){
    for (int i=0; i<hor; i++){
        Rational row[ver];
        for (int j=0; j<ver; j++){
            arr[i][j] = myarr[i][j];
            row[j] = arr[i][j];
        }
        Vector a(ver, row);
        rows[i] = a;
    }
    for (int j=0; j<ver; j++){
        Rational column[hor];
        for (int i=0; i<hor; i++){
            column[i] = arr[i][j];
        }
        Vector a(hor, column);
        columns[j] = a;
    }
   // if (ver == hor) det=determ(arr, ver);
  //  else det=0;
    //rang=rrang(arr, ver, hor);
    /*for(int i=0; i<hor; i++){
        for(int j=0; j<ver; j++){
            minors[i][j]=(this->minor(i+1,j+1)).determ();
        }
    }
    det=determ();*/
}

void Matrix::operator=(const Matrix& m){
    ver=m.ver;
    hor=m.hor;
    create(m.arr);

}

Matrix::Matrix(const Matrix& m):ver(m.ver),hor(m.hor){
    create(m.arr);
}

Matrix::Matrix(const int m, const int n, const Rational myarr[][12]):ver(n),hor(m)
{
    create(myarr);
}

/*
void Matrix::swap(int row1, int row2)
{
    for (int i = 0; i < ver; i++)
    {
        Rational temp = arr[row1][i];
        arr[row1][i] = arr[row2][i];
        arr[row2][i] = temp;
    }
}

int rrang(Rational ar[][12], int ver, int hor){
    Matrix m(hor, ver, ar);
    int ran = ver;
    for (int row = 0; row < ran; row++)
    {
        // Before we visit current row 'row', we make
        // sure that mat[row][0],....mat[row][row-1]
        // are 0.

        // Diagonal element is not zero
        if (m.arr[row][row]!=0)
        {
           for (int col = 0; col < hor; col++)
           {
               if (col != row)
               {
                 // This makes all entries of current
                 // column as 0 except entry 'mat[row][row]'
                 Rational mult = m.arr[col][row]/m.arr[row][row];
                 for (int i = 0; i < ran; i++)
                   m.arr[col][i] -= mult * m.arr[row][i];
              }
           }
        }

        // Diagonal element is already zero. Two cases
        // arise:
        // 1) If there is a row below it with non-zero
        //    entry, then swap this row with that row
        //    and process that row
        // 2) If all elements in current column below
        //    mat[r][row] are 0, then remvoe this column
        //    by swapping it with last column and
        //    reducing number of columns by 1.
        else
        {
            bool reduce = true;

            // Find the non-zero element in current column
            for (int i = row + 1; i < hor;  i++)
            {
                // Swap the row with non-zero element
                // with this row.
                if (m.arr[i][row]!=0)
                {
                    m.swap(row, i);
                    reduce = false;
                    break ;
                }
            }

            // If we did not find any row with non-zero
            // element in current columnm, then all
            // values in this column are 0.
            if (reduce)
            {
                // Reduce number of columns
                ran--;

                // Copy the last column here
                for (int i = 0; i < hor; i ++)
                    m.arr[i][row] = m.arr[i][ran];
            }

            // Process this row again
            row--;
        }

       // Uncomment these lines to see intermediate results
       // display(mat, R, C);
       // printf("\n");
    }
    return ran;
}
*/

int rrang(Rational ar[][12], int ver, int hor){
    Matrix m(hor, ver, ar);
    int j=0, l=0;
    bool checkv[hor]; for (int i=0; i<hor; i++){checkv[i]=0;}
    while (j<ver){
        int i=0;
        while (checkv[i] || m.arr[i][j]==0) {i++;}
        if (i<hor){
          checkv[i]=1; l++;
          for (int k=0; k<hor; k++) {if (k!=i) m.add_rows(k,i,(-m.arr[k][j]/m.arr[i][j]));}
        }
        j++;
    }
    return l;
}

int Matrix::get_rang(){return rang=rrang(arr, ver, hor);}
/*
Matrix& Matrix::minor(const int& r, const int& c){
    Rational ar[s][s];
    int h=0,v=0;
    for (int i=0; i<hor; i++){
        if (i != (r-1)){
        h=0;
        for (int j=0; j<ver; j++){
            if (j != (c-1)){
                ar[v][h]=arr[i][j];
                h++;
            }
           }
         v++;
        }
    }
    Matrix m(hor-1, ver-1, ar);
    return m;
}
*/

Rational determ(Rational arr[][12], const int n){
    int p, h, k, i, j;
    Rational temp[12][12];
    Rational det=0;
  if(n==1) {
    return arr[0][0];
  } else if(n==2) {
    det=(arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]);
    return det;
  } else {
    for(p=0;p<n;p++) {
      h = 0;
      k = 0;
      for(i=1;i<n;i++) {
        for( j=0;j<n;j++) {
          if(j==p) {
            continue;
          }
          temp[h][k] = arr[i][j];
          k++;
          if(k==n-1) {
            h++;
            k = 0;
          }
        }
      }
      det=det+arr[0][p]*pow(-1,p)*determ(temp,n-1);
    }
    return det;
  }
}


/*
Rational Matrix::get_det(){
    if (ver == hor) det=determ(arr, ver); else det=0;
    return det;
}*/



Matrix& Matrix::operator /(const Rational& a){
    Rational ar[s][s];
    for (int i=0; i<hor; i++){
        for (int j=0; j<ver; j++){
            ar[i][j]=arr[i][j]/a;
        }
    }
    Matrix m(hor,ver,ar);
    return m;
}

Matrix& Matrix::operator -(const Rational& a){
    Rational ar[s][s];
    for (int i=0; i<hor; i++){
        for (int j=0; j<ver; j++){
            if (i==j)
            ar[i][j]=arr[i][j]-a;
            else ar[i][j]=arr[i][j];
        }
    }
    Matrix m(hor,ver,ar);
    return m;
}

Matrix& Matrix::operator *(const Matrix& m){
   Rational ar[s][s]; int a, b;
   if (ver==m.hor){
    for (int i=0; i<hor; i++){
        for (int j=0; j<m.ver; j++){
            ar[i][j]=rows[i]*m.columns[j];
        }
    }
    a=hor;
    b=m.ver;
   }
   else {cout<<"\n No matrix product!\n";
   ar[0][0]=0; a=1; b=1;}
   Matrix m0(a,b,ar);
   return m0;
}

Vector& operator *(const Matrix& m, const Vector& v){
    Rational ar[20]; int a;
    Vector v1=v;
    if (m.ver == v.vsize && m.ver==m.hor) {
        for (int i=0; i<m.ver; i++){ar[i]=v1*m.rows[i];}
        a=v.vsize;
    } else {cout<<"\n Not square matrix or no product!\n"; a=1; ar[0]=0;}
    Vector v0(a, ar);
    return v0;
}

std::string Matrix::inverse()const{
    return "";
}

Matrix::operator std::string()const{
    std::string c="";
    for (int i=0; i<hor; i++){
        c += string(rows[i]) + "\n\n";
    }
    return c;
}

void Matrix::add_rows(const int i, const int j, const Rational k){
    for(int l=0; l<ver; l++){
        arr[i][l] += (k*arr[j][l]);
    }
 //   refresh();
    return;
}

void Matrix::add_columns(const int i, const int j, const Rational k){
    for(int l=0; l<hor; l++){
        arr[l][i] += (k*arr[l][j]);
    }
  //  refresh();
    return;
}

void Matrix::randomize(){
    if (ver==hor)
    for (int i=0; i<hor; i++){
        for (int j=0; j<ver; j++){
            if (arr[i][j] == 0) {int k=1 /*(rand()%...)*/; add_rows(i,j,k); add_columns(j,i,(-k));}
        }
    }
    refresh();
    return;
}

void Matrix::refresh(){
    for (int i=0; i<hor; i++){
        Rational row[ver];
        for (int j=0; j<ver; j++){
            row[j] = arr[i][j];
        }
        Vector a(ver, row);
        rows[i] = a;
    }
    for (int j=0; j<ver; j++){
        Rational column[hor];
        for (int i=0; i<hor; i++){
            column[i] = arr[i][j];
        }
        Vector a(hor, column);
        columns[j] = a;
    }
   // if (ver == hor) det=determ(arr, ver);
   // else det=0;
   // rang=rrang(arr, ver, hor);
}

void Matrix::normalize(){
    for(int i=0;i<hor;i++)
       {
           for(int j=i+1;j<ver;j++)
           {
             if(arr[i][i]!=0 && arr[j][i]!=0) add_rows(j,i,(-arr[j][i]/arr[i][i]));
           }
        }
    refresh();
    return;
}

bool Matrix::add_vector_col(const Vector& v){
    if (ver==0) {ver++; hor=v.vsize; for (int i=0; i<hor; i++){arr[i][ver-1]=v.arr[0][i];}} else
    if (ver == 12 || hor != v.vsize) return 0; else{
    ver++;
    for (int i=0; i<hor; i++){arr[i][ver-1]=v.arr[0][i];} }
    refresh();
    return 1;
}

bool Matrix::add_vector_row(const Vector& v){
    if (hor==0) {hor++; ver=v.vsize; for (int i=0; i<ver; i++){arr[hor-1][i]=v.arr[0][i];}} else
    if (hor == 12 || ver != v.vsize) return 0; else{
    hor++;
    for (int i=0; i<ver; i++){arr[hor-1][i]=v.arr[0][i];}}
    refresh();
    return 1;
}

void Matrix::find_base(Vector (&ar)[12])const{
    Matrix m(*this);
    bool checkv[hor], checkh[ver];
    for (int i=0; i<hor; i++) {checkv[i]=0;}
    for (int i=0; i<ver; i++) {checkh[i]=0;}
    int w=m.get_rang(); //cout<<"\n\n"<<w<<"\n\n";
    int v[m.rang], h[m.rang], freecoor[ver-m.rang], j=0, l=0, t=0;// v[rang], h[rang]
    while (j<ver){
        int i=0;
        while (i<hor) {if (checkv[i] || m.arr[i][j]==0) i++; else break;}
        if (i<hor){
          checkv[i]=1; checkh[j]=1;
          v[l]=i;
          h[l]=j;
          l++;
          for (int k=0; k<hor; k++) {if (k!=i) m.add_rows(k,i,(-m.arr[k][j]/m.arr[i][j]));}
        } else {freecoor[t]=j; t++;}
        j++;
    }
    m.refresh();
 //   cout<<endl<<endl<<string(m)<<endl;
    int o=0;
 //   for (int i=0; i<ver; i++){if (checkh[i]==0) {freecoor[o]=i; o++;}}
    for (int s=0; s<ver-m.rang; s++){
            Rational vectarr[ver];
            vectarr[freecoor[s]]=1;
            for (int q=0; q<ver-m.rang; q++){if (q!=s) vectarr[freecoor[q]]=0;}
            for (int p=0; p<m.rang; p++){// if (m.arr[v[p]][h[p]] == 0) vectarr[h[p]]=0; else
                vectarr[h[p]] = (-1)*(m.arr[v[p]][freecoor[s]]/m.arr[v[p]][h[p]]);}
            Vector a(ver, vectarr);
            ar[s]=a;
    }
    return;
}
