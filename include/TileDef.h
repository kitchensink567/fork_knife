#ifndef TILEDEF_H
#define TILDEF_H
#define MAP_HEIGHT 50
#define MAP_WIDTH 60
#include <cstdbool>

class Tile {
  public:
    Tile();
    Tile(int terr, bool capt);
    void setTerrain(int terr);
    void setCaptured(bool capt);
    int getTerrain();
    int getDifficulty();
    int getMaxBloon();
    int getTrack();
    bool getCaptured();
    bool getCamoAssault();
    bool getRegrowAssault();
    bool getFortifiedAssault();
    bool getTatteredAssault();
  private:
    int terrain; // grass 0, forest 1, heavyforest 2, desert 3, jungle 4
    bool captured;

    struct capturedTile {
      int building;
      int action; // nothing happening 0, building 1, upgrading 2
      int timeLeft;
    };

    struct uncapturedTile {
      uncapturedTile();
      uncapturedTile(int dif, int maxBl, int trck, bool camAsslt, bool rgrwAsslt, bool fortAsslt, bool tattrdAsslt);
      int difficulty;
      int maxBloon;
      int track;
      bool camoAssault;
      bool regrowAssault;
      bool fortifiedAssault;
      bool tatteredAssault;
    };
    capturedTile cap;
    uncapturedTile uncap;
};


#endif