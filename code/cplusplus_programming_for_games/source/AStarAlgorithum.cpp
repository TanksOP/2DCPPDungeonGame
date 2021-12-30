#include "AStarAlgorithum.h"

inline bool operator<(const Node& lhs, const Node& rhs)
{
	return lhs.fCost < rhs.fCost;
}

bool isValid(const int MAP_DATA[20][20], int x, int y)
{
	if (x < 0 || x > 20) {
		return false;
	}
	if (y < 0 || y > 20) {
		return false;
	}
	if (MAP_DATA[y][x] == 1) {
		return false;
	}
	return true;
}

bool isDestination(int x, int y, Node destination)
{
	if (x == destination.x && y == destination.y) {
		return true;
	}
	return false;
}

float calculateH(int x, int y, Node destination)
{
	int xDist = max(x, destination.x) - min(x, destination.y);
	int yDist = max(y, destination.y) - min(y, destination.y);
	return xDist + yDist;
}

vector<Node> makePath(array<array<Node, 20>, 20> map, Node dest)
{
	try {
		int x = dest.x;
		int y = dest.y;
		stack<Node> path;
		vector<Node> usablePath;

		while (!(map[x][y].parentX == x && map[x][y].parentY == y)
			&& map[x][y].x != -1 && map[x][y].y != -1)
		{
			path.push(map[x][y]);
			int tempX = map[x][y].parentX;
			int tempY = map[x][y].parentY;
			x = tempX;
			y = tempY;

		}
		path.push(map[x][y]);

		while (!path.empty()) {
			Node top = path.top();
			path.pop();
			usablePath.emplace_back(top);
		}
		return usablePath;
	}
	catch (const exception& e) {

	}
}

vector<Node> aStar(const int MAP_DATA[20][20], Node player, Node dest) {
	vector<Node> empty;
	if (!isValid(MAP_DATA, dest.x, dest.y)) {
		return empty;
	}
	if (isDestination(player.x, player.y, dest)) {
		return empty;
	}
	bool closedList[20][20];
	// makes every point on the map have node values
	array<array < Node, 20>, 20> allMap;
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			allMap[x][y].fCost = FLT_MAX;
			allMap[x][y].gCost = FLT_MAX;
			allMap[x][y].hCost = FLT_MAX;
			allMap[x][y].parentX = -1;
			allMap[x][y].parentY = -1;
			allMap[x][y].x = x;
			allMap[x][y].y = y;
			closedList[x][y] = false;
		}
	}

	int x = player.x;
	int y = player.y;
	allMap[x][y].fCost = 0.0f;
	allMap[x][y].gCost = 0.0f;
	allMap[x][y].hCost = 0.0f;
	allMap[x][y].parentX = x;
	allMap[x][y].parentY = y;

	// creates the vector open list and sets the fist value to the player position
	vector<Node> openList;
	openList.emplace_back(allMap[x][y]);
	bool destinationFound = false;

	while (!openList.empty() && openList.size() < 20 * 20) {
		Node node;
		do {
			float temp = FLT_MAX;
			vector<Node>::iterator itNode;
			for (vector<Node>::iterator it = openList.begin();
				it != openList.end(); it = next(it)) {
				Node n = *it;
				if (n.fCost < temp) {
					temp = n.fCost;
					itNode = it;
				}
			}
			node = *itNode;
			openList.erase(itNode);
		} while (isValid(MAP_DATA, node.x, node.y) == false);
		x = node.x;
		y = node.y;
		closedList[x][y] = true;

		for (int newX = -1; newX <= 1; newX++) {
			for (int newY = -1; newY <= 1; newY++) {
				//lock to only 4 way direction
				if (x + newX == x || y + newY == y) {

					double gNew, hNew, fNew;
					if (isValid(MAP_DATA, x + newX, y + newY)) {
						if (isDestination(x + newX, y + newY, dest))
						{
							//Destination found - make path
							allMap[x + newX][y + newY].parentX = x;
							allMap[x + newX][y + newY].parentY = y;
							destinationFound = true;
							return makePath(allMap, dest);
						}
						else if (closedList[x + newX][y + newY] == false)
						{
							gNew = node.gCost + 1.0;
							hNew = calculateH(x + newX, y + newY, dest);
							fNew = gNew + hNew;
							// Check if this path is better than the one already present
							if (allMap[x + newX][y + newY].fCost == FLT_MAX ||
								allMap[x + newX][y + newY].fCost > fNew)
							{
								// Update the details of this neighbour node
								allMap[x + newX][y + newY].fCost = fNew;
								allMap[x + newX][y + newY].gCost = gNew;
								allMap[x + newX][y + newY].hCost = hNew;
								allMap[x + newX][y + newY].parentX = x;
								allMap[x + newX][y + newY].parentY = y;
								openList.emplace_back(allMap[x + newX][y + newY]);
							}
						}
					}
				}
			}
		}
	}

	if (destinationFound == false) {
		std::cout << "empty3" << std::endl;
		return empty;
	}

}
