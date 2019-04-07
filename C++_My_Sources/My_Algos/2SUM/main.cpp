#include <map>
#include <set>
//#include <hashtable.h>
#include <iostream>
#include "my_algo.h"
//#include "array.h"

using namespace std;

void test_set()
{
    set<int> h;
    h.insert(1);
    h.insert(4);
    h.insert(3);
    h.insert(0);
    h.insert(3);
    for (set<int>::iterator j = h.begin(); j != h.end(); ++j) {cout << " " << (*j);}
    set<int>::iterator i = h.find(2);
    if (i != h.end()) cout << "\n Found 1!";
    i = h.find(1);
    if (i == h.end()) cout << "\n Not found 2! \n";
    set<int>::iterator itr; int bound = 0;
    for (int a = 5; a < 8; ++a)
    {
        bool flag = true;
        bound = (a/2);
        if (a % 2 == 0) bound--;
        itr = h.begin();
        while (flag && (*itr) <= bound && itr != h.end())
        {
            if (h.find(a - (*itr)) != h.end()) {flag = false; cout << "\n Found sum " << a << " | = " << (*itr) << " + " << (a - (*itr)); }
            itr++;
        }
    }
}

void test_uset()
{
    unordered_set<int> h;
    h.insert(2);
    h.insert(1);
    h.insert(3);
    h.insert(0);
    h.insert(1);
    for (unordered_set<int>::iterator j = h.begin(); j != h.end(); ++j) {cout << " " << (*j);}
    unordered_set<int>::iterator i = h.find(2);
    if (i != h.end()) cout << "\n Found 2!";
    i = h.find(4);
    if (i == h.end()) cout << "\n Not found 4!";
}

int main(){

    //main2();

    //main01();
    ///main03();

    ///main_set();
    main_uset();

    ///test_set();
    ///test_uset();

    //main00();
    //main0();
    return 0;
}
