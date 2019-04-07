#include <set>
#include <unordered_set>
#include <iostream>
#include <thread>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <mutex>

using namespace std;

unordered_set<long long> hashtable;
const int step = 5;
int counts[step];
int x = 0;
mutex locker;

void thread_s(int s)
{
	int k = s % step;
	counts[k] = 0;
	if (s % step == 0) k = step;
	int count = 0, start = -10000 + step - k;

	unordered_set<long long> ::iterator itr;
	for (int i = start; i <= 10000; i += step) {
		bool flag = true;
		itr = hashtable.begin();
		while (flag && itr != hashtable.end()) {
			if ((*itr) > 0) {
				long long t = i - (*itr);
				if (hashtable.find(t) != hashtable.end()) { count++; flag = false; locker.lock(); cout << "\n " << i << " | " << (*itr); locker.unlock();}
			}
			itr++;
		}
	}
	counts[k%step] = count;
	x++;
}

int main()
{
	std::ifstream file("_6ec67df2804ff4b58ab21c12edcb21f8_algo1-programming_prob-2sum.txt", std::ios::in);
	if (file.good()) {
		std::string str;
		while (getline(file, str)) {
			std::istringstream ss(str);
			long long tmp;
			ss >> tmp;
			hashtable.insert(tmp);
		}
	}
	else { std::cout << "\n FILE ERROR! \n"; return 0; }
	file.close();

	thread th1(thread_s, 1);
	thread th2(thread_s, 2);
	thread th3(thread_s, 3);
	thread th4(thread_s, 4);
	thread th5(thread_s, 5);

	while(x < 5){}
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	th5.join();

	int counter = 0;
	for (int i = 0; i < step; ++i) { counter += counts[i]; }
	cout << "\n\n !!! " << counter << " !!! \n\n";

	system("pause");
	return 0;
}
