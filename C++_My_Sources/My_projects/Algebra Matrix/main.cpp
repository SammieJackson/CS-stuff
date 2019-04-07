#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{

/*
    Rational miarr[1][12]; miarr[0][0]=0;
    Matrix m(0,0,miarr);
    cout<<endl<<string(m);
    Rational arr1[3]{5,-3,2}, arr2[3]{15,-9,6}, arr3[3]{10,-6,4};
    Vector v1(3,arr1), v2(3,arr2), v3(3,arr3);
  //  cout<<"\n\n"<<string(v1)<<"\n\n"<<string(v2)<<"\n\n"<<string(v3);
    m.add_vector_row(v1);
    cout<<"\n\n"<<string(m);
    m.add_vector_row(v2);
    cout<<"\n\n"<<string(m);
    m.add_vector_row(v3);
    cout<<"\n\n"<<string(m);

    Matrix m1(0,0,miarr);
    m1.add_vector_col(v1);
    cout<<"\n\n"<<string(m1);
    m1.add_vector_col(v2);
    cout<<"\n\n"<<string(m1);
    m1.add_vector_col(v3);
    cout<<"\n\n"<<string(m1);
    */


    /*
    Rational arr[2][12]{{0,1},{0,0}};
    Matrix m1(2,2,arr), m2=m1*m1;
    cout<<"\n"<<string(m1)<<"\n\n"<<string(m2)<<endl;

    Rational arr[3][12]{{5,-3,2},{15,-9,6},{10,-6,4}};
    Matrix m1(3,3,arr), m2=m1*m1;
    cout<<"\n"<<string(m1)<<"\n\n"<<string(m2)<<endl;


    Rational arr[4][12]{{0,2,1,6},{0,0,1,2},{0,0,0,3},{0,0,0,0}};
    Matrix m0(4,4,arr), m=m0;
    for (int i=1; i<5; i++) {cout<<"\n\n"<<string(m); m=m*m0;}
*/

/*
    Rational arr[4][12]{{1,1,1,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    Vector ar[12]; int hor=4, ver=4;
    Matrix m(4,4,arr);
    m.find_base(ar);
    for (int i=0; i<4; i++){cout<<endl<<endl<<string(ar[i]);}

*/
/*
    Rational a=0, b, c=1, d(5,7), e(2,0), x, y, z, i, j, k, l, m, n;
    cout<<string(a)<<endl<<
    string(b)<<endl<<
    string(c)<<endl<<
    string(d)<<endl<<
    string(e)<<endl;
    x=a/b; cout<<endl<<string(x);
    y=b/a; cout<<endl<<string(y);
    z=b/c; cout<<endl<<string(z);
    i=c/d; cout<<endl<<string(i);
    j=c/e; cout<<endl<<string(j);
    k=a+e; cout<<endl<<string(k);
    l=e/c; cout<<endl<<string(l);

    */

/*
    Rational arr[4][12]{{1,1,1,0},{1,1,0,0},{0,0,1,0},{0,0,0,0}};
    Matrix m(4,4,arr); int i=m.get_rang(); cout<<endl<<i;// m.add_rows(1,0,1); cout<<endl<<string(m)<<endl;
 //   m.randomize(); cout<<endl<<string(m)<<endl;
    Vector ar[12];
    m.find_base(ar);
    for (int i=0; i<4; i++){cout<<endl<<endl<<string(ar[i]);}
*/


/*
   Rational arr[4][12]{{1,0,0,0},{0,1,0,0},{0,0,2,0},{0,0,0,11}};
   Matrix my(4,4,arr); cout<<string(my)<<endl<<my.get_rang(); my.randomize(); cout<<endl<<string(my)<<endl<<my.get_rang()<<"\n--------------------------------------------------------------\n";
   Vector ar[12];
   my.find_base(ar);
   for (int i=0; i<4; i++){cout<<endl<<endl<<string(ar[i]);}
   my.normalize(); cout<<string(my);
*/

   /*
   Rational arr2[4][12]{{1,2,3,4},{5,6,7,8},{9,8,7,6},{5,4,3,2}};
   Matrix my2(4,4,arr2); cout<<endl<<endl<<string(my2);
   Matrix my3=my2*my; cout<<endl<<endl<<string(my3);
   Matrix my4=my*my2; cout<<endl<<endl<<string(my4);
   Rational arr0[4]{1,0,2,3};
   Vector v0(4,arr0);
   Vector v01=my*v0; //v02=v0*my;
   cout<<endl<<endl<<string(v01)<<endl;//<<string(v02)<<endl;
   */



  /* Rational arr1[2][20]{{2,1},{0,1}};
   Matrix m1(2,2,arr1);
   cout<<endl<<string(m1)<<string(m1.get_det())<<endl<<string(m1.minor(1,1));
   Matrix m2(m1);
   cout<<endl<<string(m2); */



   int a1=1, a2=3;
    const int s=12;
    Rational myarr[s][s];
    for (int i=0; i<s; i++){
        for (int j=0; j<s; j++){
            if (i == j) {
                if (i<9) myarr[i][j]=a1; else myarr[i][j]=a2;
            } else{
            if (i == (j+1) && (i != 4) && (i != 6) && (i != 8) && (i != 9) && (i != 11)) myarr[i][j]=1; else myarr[i][j]=0;}
        }
    }
    Matrix m(s,s,myarr);
    cout<<string(m)<<endl;
  //  m.randomize();
  //  cout<<string(m)<<endl;
  //  Vector ar[12];
  //  m.find_base(ar);

  //  int line=0;
    Matrix m1=m-a1;
    int deg1=4, deg2=2;
    Matrix m1_1, m1_2, m1_3, m1_4; m1_1=m1;
    m1_2=m1_1*m1;
    m1_3=m1_2*m1;
    m1_4=m1_3*m1;
  //  cout<<"\n\n"<<string(m1_4);

    Vector h[12], base_ker_m1_4[12], base_ker_m1_3[12];// h[5], ker_m1_4[9], ker_m1_3[8]
    m1_4.find_base(base_ker_m1_4);
    m1_3.find_base(base_ker_m1_3);

   cout<<"\n\n"<<m1.get_rang()<<"\n\n"<<m1_1.get_rang()<<"\n\n"<<m1_2.get_rang()<<"\n\n"<<m1_3.get_rang()<<"\n\n"<<m1_4.get_rang();//string(base_ker_m1_3[3])<<"\n\n"<<string(base_ker_m1_3[4])<<"\n\n"<<string(base_ker_m1_3[5]);


    Rational miarr[1][12]; miarr[0][0]=0;
    Matrix q00(0,0,miarr);
    for (int i=0; i<8; i++){q00.add_vector_row(base_ker_m1_3[i]);}
   // cout<<"\n\n"<<string(q00);
    bool flaj=0;
    int io=0;
    while(!flaj){
        Matrix q10=q00;
        q10.add_vector_row(base_ker_m1_4[io]);
        if (q10.get_rang() == 9) {h[1]=base_ker_m1_4[io]; flaj=1;}
        io++;
    }


    for (int i=2; i<5; i++){h[i]=m1*h[i-1];}
    Vector base_ker_m1_1[12], base_ker_m1_2[12];// o[4], p[7]
    m1_1.find_base(base_ker_m1_1);
    m1_2.find_base(base_ker_m1_2);

 //  cout<<"\n\n"<<string(base_ker_m1_1[4])<<"\n\n";

    cout<<"\n";
    Matrix z00(0,0,miarr);
    for (int i=1;i<5; i++){
    cout<<"\n h"<<i<<": "<<string(h[i]); if (i<4) cout<<"\n-->\n"; z00.add_vector_col(h[i]);
    }

    Vector k[3], l[3], h0, q;
    {
    int i=1;
    Matrix tr(0,0,miarr);
    for (int i=0; i<4; i++){
        tr.add_vector_row(base_ker_m1_1[i]);
    }
  //  cout<<"\n\n"<<string(tr);
    bool flag=0;
    while(!flag){
        Matrix tr0=tr;
        tr0.add_vector_row(base_ker_m1_2[i]);
        if (tr0.get_rang() == 5) {k[1]=base_ker_m1_2[i]; flag=1;}
        i++;
    }
    flag=0;
    while(!flag){
        Matrix tr0=tr;
        tr0.add_vector_row(base_ker_m1_2[i]);
        if (tr0.get_rang() == 5) {l[1]=base_ker_m1_2[i]; flag=1;}
        i++;
    }
    flag=0;
    while(!flag){
        Matrix tr0=tr;
        tr0.add_vector_row(base_ker_m1_2[i]);
        if (tr0.get_rang() == 5) {h0=base_ker_m1_2[i]; flag=1;}
        i++;
    }
    }


    Matrix tr00(0,0,miarr);
    tr00.add_vector_row(h[3]);
    tr00.add_vector_row(k[1]);
    tr00.add_vector_row(h0);
    if (tr00.get_rang() == 3) {l[1]=h0;} else{
    Matrix tr000(0,0,miarr);
    tr000.add_vector_row(h[3]);
    tr000.add_vector_row(l[1]);
    tr000.add_vector_row(h0);
    if (tr000.get_rang() == 3) {k[1]=h0;}
    }


    k[2]=m1*k[1];
    l[2]=m1*l[1];
    Matrix tr01(0,0,miarr);
    tr01.add_vector_row(h[4]);
    tr01.add_vector_row(k[2]);
    tr01.add_vector_row(l[2]);
    bool flag=0;
    int j=0;
    while (!flag){
        Matrix tr02=tr01;
        tr02.add_vector_row(base_ker_m1_1[j]);
        if (tr02.get_rang() == 4) {q=base_ker_m1_1[j];flag=1;}
        j++;
    }

    cout<<"\n";
    for (int i=1; i<3; i++){
    cout<<"\n k"<<i<<": "<<string(k[i]); if (i<2) cout<<"\n-->\n"; z00.add_vector_col(k[i]);
    }
    cout<<"\n";
    for (int i=1; i<3; i++){
    cout<<"\n l"<<i<<": "<<string(l[i]); if (i<2) cout<<"\n-->\n"; z00.add_vector_col(l[i]);
    }
    cout<<"\n\n q:"<<string(q)<<"\n"; z00.add_vector_col(q);


    Matrix  m2=m-a2, m2_1, m2_2; m2_1=m2; m2_2=m2*m2;
    Vector s0[3], r, base_ker_m2_1[12], base_ker_m2_2[12];// ker_m2_1[2], ker_m2_2[3]
    m2_1.find_base(base_ker_m2_1);
    m2_2.find_base(base_ker_m2_2);

    flag=0;
    Matrix tr02(0,0,miarr);
    tr02.add_vector_row(base_ker_m2_1[0]);
    tr02.add_vector_row(base_ker_m2_1[1]);
    int z=0;
    while (!flag){
        Matrix tr03=tr02;
        tr03.add_vector_row(base_ker_m2_2[z]);
        if (tr03.get_rang() == 3) {s0[1]=base_ker_m2_2[z]; flag=1;}
        z++;
    }
    z=0;
    flag=0;
    s0[2]=m2*s0[1];
    Matrix tr03(0,0,miarr);
    tr03.add_vector_row(s0[1]);
    tr03.add_vector_row(s0[2]);
    while (!flag){
        Matrix tr04=tr03;
        tr04.add_vector_row(base_ker_m2_2[z]);
        if (tr04.get_rang()==3) {r=base_ker_m2_2[z]; flag=1;}
        z++;
    }




    for (int i=1; i<3; i++){
    cout<<"\n t"<<i<<": "<<string(s0[i]); if (i<2) cout<<"\n-->\n"; z00.add_vector_col(s0[i]);
    }
    cout<<"\n\n r:"<<string(r)<<"\n"; z00.add_vector_col(r);
    cout<<"\n\n"<<string(z00);



return 0;
}

/*
int lcm(int x,int y);
int main()
{
    int i,j,k,r,c,a[MAX][MAX],b[MAX][MAX],det=1,l,d1,d2;
    cout<<"\nEnter the number of Rows of the Matrix: ";
    cin>>r;
    cout<<"\nEnter the number of Columns of the Matrix: ";
    cin>>c;
    if(r==c)
    {
       cout<<"\nEnter the Elements of the Matrix:\n";
       for(i=0;i<r;i++)
       {
          for(j=0;j<c;j++)
          {
             cin>>a[i][j];
          }
       }
       for(i=0;i<r-1;i++)
       {
           for(j=i+1;j<r;j++)
           {
             l=lcm(a[i][i],a[j][i]);
             if(l!=0&&(a[i][i]!=0&&a[j][i]!=0))
             {
               l=(a[i][i]*a[j][i])/l;
               d1=l/a[i][i];
               d2=l/a[j][i];
               a[j][i]=0;
               for(k=i+1;k<r;k++)
               {
                 a[j][k]=(d2*a[j][k])-(d1*a[i][k]);
               }
             }
           }
        }
        cout<<"\nThe given Matrix after Gauss Elimination is:\n";
        for(i=0;i<r;i++)
        {
          for(j=0;j<c;j++)
          {
             cout<<a[i][j]<<"\t";
          }
          cout<<"\n";
        }
     }
     else
     {
        cout<<"\nThis is not a Square Matrix!!!\n";
     }
     return 0;
}
int lcm(int x,int y)
{
    int t;
    while (y != 0)
    {
      t=y;
      y=x%y;
      x=t;
    }
    return x;
}
*/
