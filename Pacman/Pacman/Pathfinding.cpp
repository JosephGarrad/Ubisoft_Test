#include "Pathfinding.h"

Pathfinding::Pathfinding(PathmapTile* tilemap)
{
	//TileMap = tilemap;
}

//std::vector<PathmapTile*> Pathfinding::calculatePath(PathmapTile* start, PathmapTile* goal)
//{
//	PriorityQueue<PathmapTile*, float> frontier;			// Queue of tiles to check
//
//	came_from[start] = start;
//	cost_so_far[start] = 0;
//
//	frontier.put(start, 0);
//
//	while (!frontier.empty())
//	{
//		// Get a tile with the biggest priority
//		PathmapTile* current = frontier.get();
//
//		// If it's the goal, our path is complete
//		if (current == goal)
//			break;
//
//		// Check all neighbours
//		for (auto next : TileMap->GetNeighbours(current)) {
//			float new_cost = cost_so_far[current] + 1;
//
//			if (next != NULL && (!cost_so_far.count(next) || new_cost < cost_so_far[next]))
//			{
//				// If there's a wall in the tile, set cost of movement to INFINITY
//				// TODO: We shouldn't include those tiles at all!
//				
//
//				cost_so_far[next] = new_cost;
//				float priority = new_cost + Heuristic(next, goal);
//				frontier.put(next, priority);
//				came_from[next] = current;
//			}
//		}
//	}
//
//	vector<PathmapTile*> path;
//	Tile* current = goal;
//
//	path.push_back(current);
//
//	// Add all tiles of the path to a list
//	while (current != start)
//	{
//		current = came_from[current];
//		path.push_back(current);
//	}
//
//	// Reverse the list, so that we start at the beginning
//	reverse(path.begin(), path.end());
//
//	return path;
//}
