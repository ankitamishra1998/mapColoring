#ifndef MAP_H
#define MAP_H
#include "node.h"
#include <memory>
#include <vector>
#include <map>
#include <utility>

class Map {
	std::map<std::string, std::vector<std::string>> inputDict;
	std::map<std::string, std::shared_ptr<Node>> map;
	std::vector<std::shared_ptr<Node>> nodeVec;
	std::vector<int> allColors;
	int colorCounter;
	public:
	Map(std::map<std::string, std::vector<std::string>> inputDict);
	~Map();
	void createMap();
	void colorMap();
	int findAptColor(Node &n);
	std::map<std::string, int> getNodeColorInfo();
};

#endif
