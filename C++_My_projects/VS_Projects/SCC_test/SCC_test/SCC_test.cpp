// SCC_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
//#include "geeks.h"
#include "geeks2.h"

using namespace std;

void built_Graph_2(Graph* graph) {
	std::ifstream file("_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);
	if (file.good()) {
		std::string str;
		int src, dest, tmp;
		bool i = 1;
		while (getline(file, str)) {
			istringstream ss(str);
			while (ss >> tmp) {
				if (tmp < 1 || tmp > graph->V) cout << "\n Input error! Number out of range! \n"; else
					if (i == 1) { src = tmp; ++i; }
					else
						if (i == 0) { dest = tmp; ++i; graph->addEdge(src, dest); }
			}
		}
	}
	else cout << "\n FILE ERROR!\n";
}

void built_Graph(Graph* graph) {
	std::ifstream file("_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);
	if (file.good()) {
		std::string str;
		int src, dest;
		while (getline(file, str)) {
			istringstream ss(str);
			ss >> src; ss >> dest;
			if (src < 1 || src > graph->V || dest < 1 || dest > graph->V) cout << "\n Input error! Number out of range! \n"; else
				if (src != dest) graph->addEdge(src, dest);
		}
	}
	else cout << "\n FILE ERROR!\n";
}


int main()
{
	//**
	int V = 875714;
	Graph* graph = new Graph(V);
	built_Graph(graph);
	graph->findSCCs();
	///graph->printSCCs();
	//**/

	return 0;
}

void main1()
{
	std::ifstream file("_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);
	if (file.good()) {
		std::string str;
		int dest, tmp;
		getline(file, str);
		getline(file, str);
		getline(file, str);
		istringstream ss(str);
		ss >> tmp; ss >> dest;
		cout << "\n " << tmp << " -> " << dest << endl;
	}
	else cout << "\n FILE ERROR!\n";
}


/**
#include <stdlib.h>

int main00()
{
	ifstream file("_410e934e6553ac56409b2cb7096a44aa_SCC.txt", ios::in);

	/**
	if (file.good()) cout << "\n OK!\n";
	int n;
	string str;
	getline(file,str);
	getline(file, str);
	getline(file, str);
	istringstream css(str);
	css >> n;
	printf("\n %d \n\n", n);
	css >> n;
	printf("\n %d \n\n", n);
	

	///system("pause");
    return 0;
}

**/

