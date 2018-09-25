#include "map.h"
#include "node.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[]){
	ifstream filename{"input.txt"};
	string s;
	map<string, vector<string>> inputDict;
	while(getline(filename, s)){
		string key;      
		vector<string> values;
		for(int i = 0; i < s.length(); i++){
			string str;
			stringstream ss;
			ss << s[i];
			ss >> str;
			if(i==0){key = str;}
			else{if(str != " "){values.push_back(str);}}	
		}
		inputDict[key] = values;
	}
	Map *m = new Map(inputDict);
	m->createMap();
	m->colorMap();
	map<string, int> n_c_info = m->getNodeColorInfo();
	for(auto &x: n_c_info){
		cout << "Key: " << x.first << " Values: " << x.second << endl;
	}
	delete m;
}
