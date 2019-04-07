#ifndef MY_ALGO_H_INCLUDED
#define MY_ALGO_H_INCLUDED

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

///___________________________________________


int main_uset(){
    unordered_set<long long> hashtable;
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
    if (file.good()){
        std::string str;
        //long pos=0, all=0;
        while (getline(file, str)){
            std::istringstream ss(str);
            long long tmp;
            ss>>tmp;
            //all++;
            //if (tmp > 0) pos++;
            //if (tmp >= -10000 && tmp <= 10000) cout << "\n " << tmp;
            hashtable.insert(tmp);
            //if (counter < 5) print_arr(arry);
        }
        //if (pos/all > 0.5) cout << "\n + \n";
    } else {std::cout<<"\n FILE ERROR! \n"; return 0;}
    file.close();

    ///long long q = 88675191155;
    int counter = 0;
    unordered_set<long long> :: iterator itr;
    for (int i = -10000; i<=10000; ++i) {
        ///if (hashtable.find(i - q) != hashtable.end()) {counter++; cout<<"\n "<<i<<" | "<<q;}
        ///else {
         bool flag = true;
         itr = hashtable.begin();
         while (flag && itr != hashtable.end()) {
             if ((*itr) > 0){
             long long t = i - (*itr);
             if (hashtable.find(t) != hashtable.end()) {counter++; flag=false; cout<<"\n "<<i<<" | "<<(*itr);}
            }
            itr++;
         }
        ///}
    }


    cout<<"\n\n !!! "<<counter<<" !!! \n\n";

    return 0;
}

int main_set(){
    set<long long> hashtable;
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
    if (file.good()){
        std::string str;
        while (getline(file, str)){
            std::istringstream ss(str);
            long long tmp;
            ss>>tmp;
            hashtable.insert(tmp);
            //if (counter < 5) print_arr(arry);
        }
    } else {std::cout<<"\n FILE ERROR! \n"; return 0;}
    file.close();

    int counter = 0;
    set<long long> :: iterator itr;
    int bound = 0;
    for (int i = -10000; i<=10000; ++i) {
        bool flag = 1;
        bound = (i/2);
        if (i % 2 == 0) bound--;
        itr = hashtable.begin();
        while (flag && (*itr) <= bound && itr != hashtable.end()) {
            long long t = i - (*itr);
            if (hashtable.find(t) != hashtable.end()) {counter++; flag=false; cout<<"\n "<<i<<" | "<<(*itr);}
            itr++;
        }
    }


    cout<<"\n\n !!! "<<counter<<" !!! \n\n";

    return 0;
}

///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int main2()
{
    unordered_set<int> hashtable;

        hashtable.insert(1);
        hashtable.insert(2);
        hashtable.insert(4);
        hashtable.insert(4);

        unordered_set<int> :: iterator itr0;
        itr0 = hashtable.begin();
        cout<<"\n\n"<<(*itr0);

        //cout<<"\n\n"<<hashtable.find(4)<<"\n\n";
        for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++){
            cout<<"  "<<(*itr)<<"\n\n";
        }

    return 0;
}

int main01(){
    unordered_set<int>* hashtable = new unordered_set<int>;
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
    if (file.good()){
        std::string str;
        while (getline(file, str)){
            std::istringstream ss(str);
            int tmp;
            ss>>tmp;
            hashtable->insert(tmp);
            //if (counter < 5) print_arr(arry);
        }
    } else {std::cout<<"\n FILE ERROR! \n"; return 0;}
    file.close();

    int counter = 0;
    for (int  i = -10000; i<=10000; ++i){
        bool flag=true;
        unordered_set<int> :: iterator itr;
        for (itr = hashtable->begin(); itr != hashtable->end() && flag == true; itr++) {
            if (i%2 == 0) {if ((*itr) != int(i/2)  &&  hashtable->find(i-(*itr)) != hashtable->end()) {counter++; flag=false; cout<<" +1 - "<<(*itr)<<" / "<<i<<" \n";}
            } else if (hashtable->find(i-(*itr)) != hashtable->end()) {counter++; flag=false; cout<<" +1 - "<<(*itr)<<" / "<<i<<"\n";}
            //cout << (*itr).first << ": " << (*itr).second << endl;
        }
    }
    cout<<"\n\n"<<counter<<"\n\n";

    return 0;
}

int main00(){
    unordered_map<int, int>* hashtable = new unordered_map<int, int>;
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
    if (file.good()){
        std::string str;
        while (getline(file, str)){
            std::istringstream ss(str);
            int tmp;
            ss>>tmp;
            hashtable->emplace(tmp, tmp);
            //if (counter < 5) print_arr(arry);
        }
    } else {std::cout<<"\n FILE ERROR! \n"; return 0;}
    file.close();

    int counter = 0;
    for (int  i = -10000; i<=10000; ++i){
        bool flag=true;
        for (auto itr = hashtable->begin(); itr != hashtable->end() && flag == true; itr++) {
            if (i%2 == 0) if ((*itr).first != int(i/2)  &&  (*hashtable)[i-(*itr).second] != 0) {counter++; flag=false; cout<<" +1 - "<<(*itr).first<<" / "<<i<<" \n";}
            else if ((*itr).first != int(i/2)  &&  (*hashtable)[i-(*itr).second] != 0) {counter++; flag=false; cout<<" +1 - "<<(*itr).first<<" / "<<i<<"\n";}
            //cout << (*itr).first << ": " << (*itr).second << endl;
        }
    }
    cout<<"\n\n"<<counter<<"\n\n";

    return 0;
}

int main0()
{
    unordered_map<int, int> hashtable;

        hashtable.emplace(1, 1);
        hashtable.emplace(2, 2);
        hashtable.emplace(2, 4);
        hashtable.emplace(4, 2);

        cout<<"\n\n"<<hashtable[4]<<"\n\n";
        for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++){
            cout<<(*itr).first<<" - "<<(*itr).second<<"\n\n";
        }

    return 0;
}

int main1(){
    unordered_map<int, int> hashtable;
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
    if (file.good()){
        std::string str;
        while (getline(file, str)){
            std::istringstream ss(str);
            int tmp;
            ss>>tmp;
            hashtable.emplace(tmp, tmp);
            //if (counter < 5) print_arr(arry);
        }
    } else {std::cout<<"\n FILE ERROR! \n"; return 0;}
    file.close();

    int counter = 0;
    for (int  i = -10000; i<=10000; ++i){
        bool flag=true;
        for (auto itr = hashtable.begin(); itr != hashtable.end() && flag == true; itr++) {
            if (i%2 == 0) if ((*itr).first != int(i/2)  &&  hashtable[i-(*itr).second] != 0) {counter++; flag=false;}
            else if ((*itr).first != int(i/2)  &&  hashtable[i-(*itr).second] != 0) {counter++; flag=false;}
            //cout << (*itr).first << ": " << (*itr).second << endl;
        }
    }
    cout<<"\n\n"<<counter<<"\n\n";

    return 0;
}

int main03(){
    unordered_set<int>* hashtable = new unordered_set<int>;
    std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
    if (file.good()){
        std::string str;
        while (getline(file, str)){
            std::istringstream ss(str);
            int tmp;
            ss>>tmp;
            hashtable->insert(tmp);
            //if (counter < 5) print_arr(arry);
        }
    } else {std::cout<<"\n FILE ERROR! \n"; return 0;}
    file.close();

    int counter = 0;
    /*
    for (int  i = -10000; i<=10000; ++i){
        bool flag=true;
        unordered_set<int> :: iterator itr;
        for (itr = hashtable->begin(); itr != hashtable->end() && flag == true; itr++) {
            if (i%2 == 0) {
                    if ((*itr) != int(i/2)  &&  hashtable->find(i-(*itr)) != hashtable->end()) {
                        counter++; flag=false; cout<<" +1 - "<<(*itr)<<" / "<<i<<" \n";
                    }
            } else
            if (hashtable->find(i-(*itr)) != hashtable->end()) {counter++; flag=false; cout<<" +1 - "<<(*itr)<<" / "<<i<<"\n";}
            //cout << (*itr).first << ": " << (*itr).second << endl;
        }
    } */

    for (int i = -10000; i<=10000; ++i) {
        bool flag = 1;
        unordered_set<int> :: iterator itr = hashtable->begin();
        while (itr != hashtable->end() && flag) {
            if (i%2 == 0) {
                    if ((*itr) != int(i/2)  &&  hashtable->find(i-(*itr)) != hashtable->end()) {
                        counter++; flag=false; cout<<" +1 - "<<(*itr)<<" / "<<i<<" \n";
                    }
            } else
            if (hashtable->find(i-(*itr)) != hashtable->end()) {counter++; flag=false; cout<<" +1 - "<<(*itr)<<" / "<<i<<"\n";}
            itr++;
        }
    }


    cout<<"\n\n"<<counter<<"\n\n";

    return 0;
}

#endif // MY_ALGO_H_INCLUDED
