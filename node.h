#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Node {
	std::string name;
	int color;
	bool gotColor;
	std::vector<std::string> neighbors;
	std::vector<std::unique_ptr<Node>> neighborNodes;
	std::vector<int> restrictedColors;
	public:
	Node(std::string name, std::vector<std::string> neighbors);
	~Node();
	void setColor(int col);
	int getColor();
	bool hasColor();
	void setHasColor(bool value);
	std::string getName();
	std::vector<std::string> getNeighbors();
	void addNeighbor(std::string n);
	std::vector<int> getRestrictedColors();
	void addRestrictedColor(int c);	
};

#endif
