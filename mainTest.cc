#include "map.h"
#include "node.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <typeinfo>
using namespace std;

int main(){
	vector<string> neighbors;
//	vector<string> neighbors1;
//	vector<string> neighbors2;
	neighbors.push_back("B");
	neighbors.push_back("C");
//	neighbors1.push_back("A");
//	neighbors1.push_back("D");
//	neighbors1.push_back("E");
//	neighbors2.push_back("B");
//	neighbors2.push_back("F");
	auto n = make_shared<Node>("A", neighbors);
//	auto n1 = make_shared<Node>("B", neighbors1);
//	auto n2 = make_shared<Node>("C", neighbors2);
	cout << n->getRestrictedColors().size() << endl;
	n->addRestrictedColor(1);
	n->addRestrictedColor(2);
	n->addRestrictedColor(1);

	map<string, shared_ptr<Node>> map;
//	map["A"] = n;
//	map["B"] = n1;
//	map["C"] = n2;
	cout << n->getRestrictedColors().size() << endl;

	for(auto &x: n->getRestrictedColors()){
		cout << "color: " << x << endl;
	}
	
	vector<int> rc = n->getRestrictedColors();

	int count1 = count(rc.begin(), rc.end(), 1);
	int count2 = count(rc.begin(), rc.end(), 2);
	int count3 = count(rc.begin(), rc.end(), 3);	
	cout << "num ones: " << count1 << endl;
	cout << "num twos: " << count2 << endl;
	cout << "num threes: " << count3 << endl;

}

/*
int main () {
  // counting elements in container:

  //{10,20,30,30,20,10,10,20}; 
  std::vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);
  myvector.push_back(30);
  myvector.push_back(20);
  myvector.push_back(10);
  myvector.push_back(10);
  myvector.push_back(20);
  int mycount = std::count (myvector.begin(), myvector.end(), 20);
  std::cout << "20 appears " << mycount  << " times.\n";

  return 0;
}
*/
