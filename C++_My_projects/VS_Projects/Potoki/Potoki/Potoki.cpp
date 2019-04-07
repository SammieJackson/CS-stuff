// Potoki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std;

bool exitRequested = false;

void threadFunc(int i, int delay_time, char c)
{
	int j = 0;
	while (!exitRequested && j < i) {
		cout << c;
		this_thread::sleep_for(chrono::milliseconds(delay_time));
	}
}

int main()
{
	cout << "\n Starting thread...\n";
	cout << "\n Press 0 to exit\n";

	thread th(threadFunc, 500, 100, '+');
	thread th1(threadFunc, 500, 200, '-');
	int x = -1;
	while (x != 0) {
		cin >> x;
	}
	exitRequested = true;
	th.join();
	th1.join();


	system("pause");
    return 0;
}


/*
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

bool exitRequested = false;

const int maxLen = 10;
int len = 0;
int dataArr[maxLen];

mutex dataProtector;

void inserter(int cnt, int delayMs, char c)
{
int i = 0;
while (!exitRequested && i<cnt) {
dataProtector.lock();
if (len < maxLen) {
dataArr[len] = i;
len++;
}
dataProtector.unlock();
cout << len << c <<"\n";
this_thread::sleep_for(chrono::milliseconds(delayMs));
i++;
}
}

void remover(int cnt, int delayMs, char c)
{
int i = 0;
while (!exitRequested && i<cnt) {
dataProtector.lock();
if (len > 0) {
dataArr[len] = 0;
len--;
}
dataProtector.unlock();
cout << len << c << "\n";
this_thread::sleep_for(chrono::milliseconds(delayMs));
i++;
}
}

void main()
{
cout << "Starting thread...";
thread insertThread(inserter, 50000, 1, '*');
thread removeThread(remover, 250000, 1, '+');
thread removeThread2(remover, 250000, 1, '+');
thread removeThread3(remover, 250000, 1, '+');
//thread th2(threadFuc, 1000, 120, '-');
cout << "Press 0 to exit";
int x = -1;
while (x != 0) {
cin >> x;
}
exitRequested = true;
insertThread.join();
removeThread.join();
removeThread2.join();
removeThread3.join();
//th1.join();
//th2.join();
}

*/
