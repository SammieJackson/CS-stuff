#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const long long p0 = 21169;
const long long q0 = 3967;
const long long e0 = 257;


long long binpowM(long long a, long long n, long long m) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpowM(a, n - 1, m) * a) % m;
    else {
        long long b = binpowM(a, n / 2, m) % m;
        return (b * b) % m;
    }
}

long long gcd(long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

long long reverse(long long fi, long long e) //we find such d: d*e0=1 mod fi
{
    long long y, d;
    gcd(e, fi, d, y);
    d = (d % fi + fi) % fi;

    return d;
}

void encode(vector<long long>& v, long long e, long long n)
{
    for (long long i = 0, l = v.size(); i < l; ++i)
    {
        v[i] = binpowM(v[i], e, n);
    }
}

void decode(vector<long long>& v, long long d, long long n)
{
    for (long long i = 0, l = v.size(); i < l; ++i)
    {
        v[i] = binpowM(v[i], d, n);
    }
}

void read(vector<long long>& v)
{
    string c;
    getline(cin, c);
    for (int i = 0, l = c.length(); i < l; ++i)
    {
        v.push_back(c[i]);
    }
}

void output(vector<long long>& v)
{
    char c;
    for (int i = 0, l = v.size(); i < l; ++i)
    {
        c = v[i];
        cout << c;
        //cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    string s;
    long long n = p0*q0, fi_n, e = e0;
    fi_n = (p0 - 1)*(q0 - 1);

    //only client knows about secret key - d and p, q, fi_n
    //n and e is public
    long long d = reverse(fi_n, e);
    /*long long t;
    t = (d*e)%fi_n;
    cout << t << endl;
    cin >> t;
    long long temp;
    temp = binpowM(t, e, n);
    t = temp;
    cout << t << endl;
    temp = binpowM(t, d, n);
    t = temp;
    cout << t;*/
    vector<long long> v;
    read(v);
    encode(v, e, n);
    output(v);
    decode(v, d, n);
    output(v);
    return 0;
}
