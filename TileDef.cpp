#include <TileDef.h>
using namespace std;

Tile::Tile() {
}

Tile::Tile(int terr, bool capt) {
  terrain = terr;
  captured = capt;
}

Tile::uncapturedTile::uncapturedTile() {
}

Tile::uncapturedTile::uncapturedTile(int dif, int maxBl, int trck, bool camAsslt, bool rgrwAsslt, bool fortAsslt, bool tattrdAsslt) {
  difficulty = dif;
  maxBloon = maxBl;
  track = trck;
  camoAssault = camAsslt;
  regrowAssault = rgrwAsslt;
  fortifiedAssault = fortAsslt;
  tatteredAssault = tattrdAsslt;
}

void Tile::setTerrain(int terr) {
  terrain = terr;
}

void Tile::setCaptured(bool capt) {
  captured = capt;
}

int Tile::getTerrain() {
  return terrain;
}

int Tile::getDifficulty() {
  return uncap.difficulty;
}

int Tile::getMaxBloon() {
  return uncap.maxBloon;
}

int Tile::getTrack() {
  return uncap.track;
}

bool Tile::getCaptured() {
  return captured;
}

bool Tile::getCamoAssault() {
  return uncap.camoAssault;
}

bool Tile::getRegrowAssault() {
  return uncap.regrowAssault;
}

bool Tile::getFortifiedAssault() {
  return uncap.fortifiedAssault;
}

bool Tile::getTatteredAssault() {
  return uncap.tatteredAssault;
}
