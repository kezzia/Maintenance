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
	std::vector<string> transactions = FindTransactions(my_map);
	cout << "SPECIAL NODES:" << endl;
	PrintVector(x);
	cout << "TRANSACTIONS: " << endl;
	PrintVector(transactions);
	FindUniqueNodes(my_map);
	Explode(my_map, transactions);

	return 0;
}