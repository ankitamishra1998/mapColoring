#include "node.h"
#include <typeinfo>
using namespace std;

Node::Node(string name, vector<string> neighbors)
	:name{name}, gotColor{false}, neighbors{neighbors}{}

Node::~Node(){}

bool Node::hasColor(){
	if(gotColor == true){ return true;}
	else{return false;}
}

void Node::setHasColor(bool value){
	gotColor = value;
}

void Node::setColor(int col){
	color = col;
}

int Node::getColor(){
	return color;
}

string Node::getName(){
	return name;
}

vector<string> Node::getNeighbors(){
	return neighbors;
}

void Node::addNeighbor(string n){
	neighbors.push_back(n);
}

vector<int> Node::getRestrictedColors(){
	return restrictedColors;
}

void Node::addRestrictedColor(int c){
	if(count(restrictedColors.begin(), restrictedColors.end(), c)){}
	else{restrictedColors.push_back(c);}
}
