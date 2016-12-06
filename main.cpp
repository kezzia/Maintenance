#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "main_functions.h"
using namespace std;

int main() {
	std::map<string, vector<string> > my_map;


	ifstream in_file("inp.txt");
	std::vector<string> x = PopulateMap(in_file, my_map);
	PrintMap(my_map);
	FindTransactions(my_map);
	PrintVector(x);
	FindUniqueNodes(my_map);

	return 0;
}