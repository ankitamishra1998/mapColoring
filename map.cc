#include "map.h"
#include <typeinfo>
using namespace std;

Map::Map(std::map<string, vector<string>> inputDict)
	:inputDict{inputDict}, colorCounter{1}{}

Map::~Map(){} 

//Create nodes and store the pointers to the nodes in the map vector
void Map::createMap(){
	for(auto & i :inputDict){
		auto n = make_shared<Node>(i.first, i.second);
		nodeVec.push_back(n);
		map[i.first] = n;
	}
}

int Map::findAptColor(Node &n){
	int aptNum = 0;
	for(auto &i: allColors){
		vector<int> rc = n.getRestrictedColors();
		if(count(rc.begin(), rc.end(), i) == 0){
			aptNum = i;
			break;
		}
	}
	return aptNum;
}

//note: reduce code repetition
void Map::colorMap(){
	//Iterate through the map vector
	for(auto &it: nodeVec){
		if(it->hasColor() == false){ //gotColor variable is false
			if((it->getRestrictedColors()).size() == 0){ //the restrictedColor array is false
				it->setColor(colorCounter);      //set color to colorCounter
				it->setHasColor(true);           //set gotColor to true
				it->addRestrictedColor(colorCounter);  //add the color to the node's rc
				allColors.push_back(colorCounter);     //add the color to allColors array
				for(auto &x: it->getNeighbors()){          //iterate through the current node's neighbors
					map[x]->addRestrictedColor(colorCounter);
				}
			}
			else{
				if(findAptColor(*it) != 0){ //so there is a color that can be reused. We've found the smallest possible color that can be reused. 
					colorCounter = findAptColor(*it);
					it->setColor(colorCounter);
					it->setHasColor(true);
					it->addRestrictedColor(colorCounter);
					for(auto &x: it->getNeighbors()){
						map[x]->addRestrictedColor(colorCounter);
					}
				}
				else{ //so there is no color in all colors that can be reused
					colorCounter = allColors.back() + 1; //set colorCounter to be 1 greater than the largest color in the allColors array
					it->setColor(colorCounter);
					it->setHasColor(true);
					it->addRestrictedColor(colorCounter);
					allColors.push_back(colorCounter);
					for(auto &x: it->getNeighbors()){
						map[x]->addRestrictedColor(colorCounter);
					}
				}
			}
		}
	}
}

std::map<string, int> Map::getNodeColorInfo(){
	std::map<string, int> nodeColorInfo;
	for(auto & x: nodeVec){
		nodeColorInfo[x->getName()] = x->getColor();
	}
	return nodeColorInfo;
}
