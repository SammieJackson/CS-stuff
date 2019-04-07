#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

using namespace std;

vector<int> primes;

long binpow(int a, int n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    if (n%2 == 0) {int b = binpow(a, n/2); return b*b;}
    else
    {
        int b = binpow(a, (n-1)/2);
        return (b*b*a);
    }
}

void find_primes(long& bound)
{
    primes.clear();
    primes.resize(0);
    ///primes.reserve(int(log(bound)));
    vector<bool> isprm;
    int s = sqrt(bound);
    isprm.assign(s+1, true);
    isprm[0] = isprm[1] = false;
    for (int i = 2; i <= s; ++i)
    {
        if (isprm[i]) {
            for (int j = 2*i; j < s+1; j+=i)
            {
                isprm[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int count_weird(long& l, long& r)
{
    int cntr = 0;
    find_primes(r);
    int s = primes.size();
    ///for (int i = 0; i < s; ++i){cout << primes[i] << " ";} cout << endl;
    for (int i = 0; i < s; ++i)
    {
        int max_pow = 0, min_pow = 0, temp = 1;
        bool flag = false;
        while (temp < r)
        {
            temp *= primes[i];
            if (!flag && temp >= l) {flag = true; min_pow = max_pow;}
            max_pow++;
        }
        int j = 0;
        long t = 0;
        while (j < s && primes[j] < min_pow) {++j;}
        while (j < s && primes[j] <= max_pow)
        {
            t = binpow(primes[i],primes[j]);
            if (t >= l && t <= r)
            {
                ///cout << t << " = " << primes[i] << " ^ " << primes[j] << endl;
                cntr++;
            }
            ++j;
        }
    }
    return cntr;
}

int main()
{
    cout << "\n Enter left and right bounds: " << endl;
    long l, r;
    cin >> l >> r;
    cout << "\n Weird numbers found: " << count_weird(l,r) << endl;

    system("pause");
    return 0;
}
