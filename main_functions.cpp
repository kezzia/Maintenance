#include "main_functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

//"**" means new info
std::vector<string> FindSpecialNodes(string line, int i) {
	string defective_module, searching_transaction;

	int count = 0;
	int j = i;
	int saved;
	bool end_node = false;

	while (count < 3) {
		if ((line[j + 4] != ' ') && (line[j + 4] != ';')) {
			defective_module += line[j + 4];
			saved = j + 4;
		}
		j++;
		count++;
	}
	std::vector<string> v = MakeVector(defective_module);
	
	count = 0;
	int k = saved;

	while (count < 3) {
		if ((line[k + 2] != ' ') && (line[k + 2] != ';')) {
			searching_transaction += line[k + 2];
		}
		k++;
		count++;
	}

	AddToVector(searching_transaction, v);

	cout << "searching_transaction: " << searching_transaction << endl;
	cout << "defective_module: " << defective_module << endl;
	return v;
}

std::vector<string> MakeVector(string new_child) {
  std::vector<string> v;
  v.push_back(new_child);
  return v;
}

void AddToVector(string new_child, std::vector<string> &v) {
	v.push_back(new_child);
}

void PrintVector(const std::vector<string>& v) {
	cout << "{";
	for (int i=0; i<v.size();i++) {
	    cout << v[i] << ",";
	}
	cout << "}" << endl;
}

void PrintMap(std::map<string, vector<string>> &myMap) {
	for(auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
	    std::cout << it->first << ":"; 
	    PrintVector(it->second);
	}
}

std::vector<string> PopulateMap(ifstream &in_file, std::map<string, vector<string>> &temp_map) {
	std::vector<string> v;
	string line;
	string new_string = "";
	string parent_string = "";
	string child_string = "";

	bool child = true;
	bool pair = false;
	std::map<string,string>::iterator it;

	if (in_file) {
		while (getline(in_file, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Unable to open file :(\n";
	}

	for (int i = 0; i < line.length(); i++) {
		//checks to see if we are about to read the defective node and the head of the tree
		if (line[i] == '*') {
			v = FindSpecialNodes(line, i);

			//cout << "defective_module: " << defective_module << endl;
			//cout << "searching_transaction: " << searching_transaction << endl;
			break;
		}

		//separates nodes from the list and decides whether it is a parent or child node
		if ((line[i] != ' ') && (line[i] != ';') && (new_string.length() < 3)) {
			new_string += line[i];
		}
		else if (new_string != "") {
			child = !(child); //parent and child nodes alternate in this list

			if (!child) {
				parent_string = new_string;
				//cout << "parent " << parent_string << endl;
				pair = false;
			}
			else {
				child_string = new_string;
				//cout << "child " << child_string << endl;
				pair = true;
			}
			
			if ( (temp_map.find(parent_string) == temp_map.end()) && (pair) ) { //if parent is not in the map
				std::vector<string> x = MakeVector(child_string);
				temp_map[parent_string] = x;
				//PrintVector(temp_map[parent_string]);
			}
			else if ( (temp_map.find(parent_string) != temp_map.end()) && (pair) ){
				//cout << "The node " << parent_string << " already exists\n";
				AddToVector(child_string, temp_map[parent_string]);
			}

			new_string = "";
		}
	}

return v;
}

//given the map containing the nodes, it prints the transactions
void FindTransactions(std::map<string, vector<string>> m) {
	cout << "FINDING TRANSACTIONS\n";
	//for each key
	//if that key is not also a value, print it

	for(auto i = m.cbegin(); i != m.cend(); ++i) {
		bool is_transaction = true;
		for(auto it = m.cbegin(); it != m.cend(); ++it) {
			//cout << "Finding " << i->first << " in ";
			//PrintVector(it->second);

		    if ( std::find(it->second.begin(), it->second.end(), i->first) != it->second.end() ) {
	   			is_transaction = false;
	   		}
		}
		if (is_transaction) {
			cout << i->first << " is a transaction\n";
		}
	}
}

//given the map containing the nodes, it prints the unique nodes
void FindUniqueNodes(std::map<string, vector<string>> m) {
	cout << "PRINTING UNIQUE NODES\n";
	//for each key and value
	//when we encounter a value we check it against an array of unique values
	//if the that value is not in the array, add it
	//print the array

	//this vector stores unique nodes
	std::vector<string> v;
	bool is_unique = true;
	int unique_count = 0;

	for(auto i = m.cbegin(); i != m.cend(); ++i) {
		//cout << "Adding new unique module: " << i->first << endl;
		AddToVector(i->first, v);
	}

	cout << "Current unique nodes: ";
	PrintVector(v);

	for(auto i = m.cbegin(); i != m.cend(); ++i) {
		for(auto j = m.cbegin(); j != m.cend(); ++j) {
			for (int k = 0; k < (i->second.size()); k++) {
				if (std::find(j->second.begin(), j->second.end(), i->second[k]) != j->second.end()) {
					cout << "looking for: " << i->second[k] << " in: ";
					PrintVector(j->second);
					cout << "and it was found!" << endl;
					if (std::find(v.begin(), v.end(), "abc") != v.end()) {
						AddToVector(i->second[k], v);
					}
				}
			}
		}
	}
	cout << "Current unique nodes: ";
	PrintVector(v);
}

//given the map containing the nodes, it prints an explosion of the map's nodes
void Explode(std::map<string, vector<string>> temp_map) {
	cout << "EXPLODING TRANSACTIONS\n";
}

//given the map containing the nodes and the defective node, it prints the path from the defective node to the transaction 
void ReturnToSender(std::map<string, vector<string>> &temp_map) {
	cout << "CHARTING BACK TO TRANSACTION\n";
}


