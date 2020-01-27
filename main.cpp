#include <TileDef.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;
int stringToData(string &shit) {
  int ret;
  stringstream convert;
  convert << shit;
  convert >> ret;
  return ret;
}

bool stringToDataBool(string &shit) {
  bool ret;
  stringstream convert;
  convert << shit;
  convert >> ret;
  return ret;
}

void initMap(Tile ***map) {
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      map[i][j] = new Tile(rand() % 5, false);
    }
  }
}

void writeData(Tile ***map) {
  fstream myFile;
  myFile.open("TileInfo.txt", ios::out);
  if (myFile.is_open()) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
      for (int j = 0; j < MAP_WIDTH; j++) {
        myFile << "(" << map[i][j]->getCaptured() << "," << map[i][j]->getTerrain() << ") ";
      }
      myFile << endl;
    }
  }
}

bool readData(Tile ****map) {
  fstream myFile;
  myFile.open("TileInfo.txt", ios::in);
  if (myFile.fail()) {
    cerr << "Unable to open file!" << endl;
    return false;
  }
  else {
    if (myFile.is_open()) {
      *map = new Tile**[MAP_HEIGHT];
      for (int i = 0; i < MAP_HEIGHT; i++) {
        (*map)[i] = new Tile*[MAP_WIDTH];
        for (int j = 0; j < MAP_WIDTH; j++) {
          (*map)[i][j] = new Tile;
        }
      }
      string line;
      int row = 0;
      int col = 0;
      while (getline(myFile, line)) {
        int numBegin = 0;
        col = 0;
        for (unsigned int i = 0; i < line.length(); i++) {
          if (isdigit(line[i])) {
            numBegin = i;
          }
          if (line[i] == ',') {
            string data = line.substr(numBegin, i);
            bool cap = stringToDataBool(data);
            (*map)[row][col]->setCaptured(cap);
            numBegin = i+1;
          }
          if (line[i] == ')') {
            string data = line.substr(numBegin, i);
            int terr = stringToData(data);
            (*map)[row][col]->setTerrain(terr);
            col++;
          }
        }
        row++;
      }
    }
    myFile.close();
  }
  return true;
}

int main(int argc, char *argv[]) {
  Tile ***map = NULL;
  string action;
  int x, y;
  srand(time(NULL));
  if (!readData(&map)) {
    map = new Tile**[MAP_HEIGHT];
    for (int i  = 0; i < MAP_HEIGHT; i++) {
      map[i] = new Tile*[MAP_WIDTH];
    }
    initMap(map);
    writeData(map);
    for (int i = 0; i < MAP_HEIGHT; i++) {
      for (int j = 0; j < MAP_WIDTH; j++) {
        delete map[i][j];
      }
      delete []map[i];
    }
  }
  else {
    for (int i = 0; i < MAP_HEIGHT; i++) {
      for (int j = 0; j < MAP_WIDTH; j++) {
        cout << "(" << map[i][j]->getCaptured() << "," << map[i][j]->getTerrain() <<") ";
        delete map[i][j];
      }
      delete []map[i];
      cout << endl;
    }
  }
  while (action != "quit") {
    cin >> x >> y;
    map[x][y].capture();
  }
  delete []map;
  return EXIT_SUCCESS;
}
