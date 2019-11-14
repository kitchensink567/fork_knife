using namespace std;

const int MAP_HEIGHT = 50;

const int MAP_WIDTH = 60;

class Tile {
	int terrain; // grass 0, forest 1, heavyforest 2, desert 3, jungle 4
	
	struct capturedTile {
		int building;
		int action; // nothing happening 0, building 1, upgrading 2
		int timeLeft;
	}
	
	struct uncapturedTile {
		int difficulty;
		int maxBloon;
		int track;
		bool camoAssault;
		bool regrowAssault;
		bool fortifiedAssault;
		bool tatteredAsssault;
	}

public: 
	int getTerrain() {
		return terrain;
	}
	int getDifficulty() {
		return uncapturedTile.difficulty;
	}
	int getMaxBloon() {
		return uncapturedTile.maxBloon;
	}
	int getTrack() {
		return uncapturedTile.track;
	}
} map[MAP_HEIGHT][MAP_WIDTH];
