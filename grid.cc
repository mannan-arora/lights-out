#include <iostream>
#include "grid.h"

using namespace std;

Grid::Grid() {}

Grid::~Grid() {
  delete td;
}

void Grid::clearGrid() { theGrid.clear(); }

bool Grid::isWon() const { 
  int count = 0;
  for (int r = 0; r < gridSize; r++) {
    for (int c = 0; c < gridSize; c++) {
      if (theGrid[r][c].getState() == false) {
        count++;
      }
    }
  }
  return (count == gridSize*gridSize);
}

void Grid::init(int n) {
  gridSize = n;
  if (!theGrid.empty() == true) {
    clearGrid();
    delete td;
  }
  td = new TextDisplay(gridSize);
  for (int r = 0; r < n; r++) {
    theGrid.push_back(std::vector<Cell>());
    for (int c = 0; c < n; c++) {
      theGrid[r].emplace_back();
      theGrid[r][c].setCoords(r, c);
    }
  }
  if (gridSize >= 1) {
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (r == 0 && c == 0) {
          theGrid[r][c].attach(&theGrid[r][c+1]);
          theGrid[r][c].attach(&theGrid[r+1][c]);
        } else if (r == 0 && c == gridSize-1) {
          theGrid[r][c].attach(&theGrid[r][c-1]);
          theGrid[r][c].attach(&theGrid[r+1][c]);
        } else if (r == gridSize-1 && c == 0) {
          theGrid[r][c].attach(&theGrid[r-1][c]);
          theGrid[r][c].attach(&theGrid[r][c+1]);
        } else if (r == gridSize-1 && c == gridSize-1) {
          theGrid[r][c].attach(&theGrid[r-1][c]);
          theGrid[r][c].attach(&theGrid[r][c-1]);
        } else if (r == 0) {
          theGrid[r][c].attach(&theGrid[r][c-1]);
          theGrid[r][c].attach(&theGrid[r][c+1]);
          theGrid[r][c].attach(&theGrid[r+1][c]);
        } else if (c == 0) {
          theGrid[r][c].attach(&theGrid[r-1][c]);
          theGrid[r][c].attach(&theGrid[r][c+1]);
          theGrid[r][c].attach(&theGrid[r+1][c]);
        } else if (c == gridSize-1) {
          theGrid[r][c].attach(&theGrid[r-1][c]);
          theGrid[r][c].attach(&theGrid[r][c-1]);
          theGrid[r][c].attach(&theGrid[r+1][c]);
        } else if (r == gridSize-1) {
          theGrid[r][c].attach(&theGrid[r-1][c]);
          theGrid[r][c].attach(&theGrid[r][c-1]);
          theGrid[r][c].attach(&theGrid[r][c+1]);
        } else if (r < gridSize && c < gridSize) {
          theGrid[r][c].attach(&theGrid[r-1][c]);
          theGrid[r][c].attach(&theGrid[r][c-1]);
          theGrid[r][c].attach(&theGrid[r][c+1]);
          theGrid[r][c].attach(&theGrid[r+1][c]);
        }
        theGrid[r][c].attach(td);
      }
    }
  }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
  theGrid[r][c].notifyObservers(SubscriptionType::SwitchOnly);
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  theGrid[r][c].notifyObservers(SubscriptionType::All);
}

ostream &operator<<(ostream &out, const Grid &g) {
  out << *g.td;
  return out;
}

void Grid::printCells() const {
  for (int r = 0; r < gridSize; r++) {
    for (int c = 0; c < gridSize; c++) {
      cout << theGrid[r][c].getName() << ": " << theGrid[r][c].getObserverNames() << endl;
    }
  }
}

