#pragma once

#include <algorithm> //max and min functions
#include <vector>
#include <array>
#include <stack>
#include <iostream>

using namespace std;

struct Node {
	int x, y; //this is the position of the node
	int parentX, parentY; //the X and Y of the last node in the list
	float gCost; //g cost is the cost of moving to this node based on the current position
	float hCost; //h cost is distance between this node and the goal
	float fCost; //f cost is simply the addition of g and h scores and represents the total cost of the path via the current node
};
//this allows two nodes to be compared using the < operator to compare the fCost
inline bool operator <(const Node& lhs, const Node& rhs);

//in our map data, 0 represents a valid tile, and 1 is an obstacle
bool isValid(const int MAP_DATA[20][20], int x, int y);

//checks a node to see if it is the destination node
bool isDestination(int x, int y, Node destination);

//Simple H calcuation only taking into account 4 directional movement
float calculateH(int x, int y, Node destination);

vector<Node> makePath(array<array<Node, 20>, 20> map, Node dest);

vector<Node> aStar(const int MAP_DATA[20][20], Node player, Node dest);