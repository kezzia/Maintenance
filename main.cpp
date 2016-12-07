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
	std::vector<string> exploded_nodes;
	std::vector<string> special_nodes = PopulateMap(in_file, my_map);
	PrintMap(my_map);
	std::vector<string> transactions = FindTransactions(my_map);
	cout << "SPECIAL NODES:" << endl;
	PrintVector(special_nodes);
	string defective_node = special_nodes[0];
	string transaction = special_nodes[1];
	cout << "TRANSACTIONS: " << endl;
	PrintVector(transactions);
	FindUniqueNodes(my_map);
	Explode(my_map, transaction, 0, exploded_nodes);
	ReturnToSender(my_map, defective_node, "");

	return 0;
}