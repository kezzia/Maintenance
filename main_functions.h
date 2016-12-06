#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


std::vector<string> FindSpecialNodes(string line, int i);

//prints contents of map
void PrintMap(std::map<string, vector <string>> &temp_map);

//populates a map with values from the text file
std::vector<string> PopulateMap(ifstream &in_file, std::map<string, vector<string>> &temp_map);

//makes the children into a vector
std::vector<string> MakeVector(string new_child);

//adds new children to an existing vector
void AddToVector(string new_child, vector<string> &v);

//prints the vectors in the map
void PrintVector(const std::vector<string>& v);

//given the map containing the nodes, it prints the transactions
std::vector<string> FindTransactions(std::map<string, vector<string>> m);

//given the map containing the nodes, it prints the unique nodes
void FindUniqueNodes(std::map<string, vector<string>> m);

//given the map containing the nodes, it prints an explosion of the map's nodes
void Explode(std::map<string, vector<string>> temp_map);

//given the map containing the nodes and the defective node, it prints the path from the defective node to the transaction 
void ReturnToSender(std::map<string, vector<string>> &temp_map);

