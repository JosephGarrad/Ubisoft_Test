#ifndef PATHMAPTILE_H
#define PATHMAPTILE_H
#include <array>
class PathmapTile
{
public:
	PathmapTile(int anX, int anY, bool aIsBlockingFlag);
	~PathmapTile(void);

	//std::array<class Tile*, 8> GetNeighboursDiag(Tile* tile);

	int myX;
	int myY;
	bool myIsBlockingFlag;
	bool myIsVisitedFlag;

};

#endif // PATHMAPTILE_H