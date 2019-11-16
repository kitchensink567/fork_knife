#include <TileDef.h>
#include <iostream>
using namespace std;

Tile::Tile() {
}

Tile::Tile(int terr, bool capt) {
  terrain = terr;
  captured = capt;
  if (captured) {
    cap = new capturedTile(0, 0, 0);
    uncap = NULL;
  }
  else {
    cap = NULL;
    uncap = new uncapturedTile(0,0,0,false, false, false, false);
  }
}

Tile::uncapturedTile::uncapturedTile() {
}

Tile::capturedTile::capturedTile() {
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

Tile::capturedTile::capturedTile(int bldng, int actn, int time) {
  building = bldng;
  action = actn;
  timeLeft = time;
}

void Tile::setTerrain(int terr) {
  terrain = terr;
}

void Tile::setCaptured(bool capt) {
  captured = capt;
}

void Tile::capture() {
  cap = new capturedTile(0, 0, 0);
  setCaptured(true);
  delete uncap;
}

int Tile::getTerrain() {
  return terrain;
}

int Tile::getDifficulty() {
  return uncap->difficulty;
}

int Tile::getMaxBloon() {
  return uncap->maxBloon;
}

int Tile::getTrack() {
  return uncap->track;
}

bool Tile::getCaptured() {
  return captured;
}

bool Tile::getCamoAssault() {
  return uncap->camoAssault;
}

bool Tile::getRegrowAssault() {
  return uncap->regrowAssault;
}

bool Tile::getFortifiedAssault() {
  return uncap->fortifiedAssault;
}

bool Tile::getTatteredAssault() {
  return uncap->tatteredAssault;
}
