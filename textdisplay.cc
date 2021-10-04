#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay(int n) : gridSize{n} {
   for (int r = 0; r < n; r++) {
    theDisplay.push_back(std::vector<char>());
    for (int c = 0; c < n; c++) {
      theDisplay[r].push_back('.');
    }
  }
}

void TextDisplay::notify(Cell &whoNotified) {
  int row = whoNotified.getRow();
  int col = whoNotified.getCol();
  if (theDisplay[row][col] == '.') {
    theDisplay[row][col] = 'X';
  } 
  else if (theDisplay[row][col] == 'X') {
    theDisplay[row][col] = '.';
  }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

std::string TextDisplay::getName() const {
  std::string td = "TD";
  return td;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int r = 0; r < td.gridSize; r++) {
    for (int c = 0; c < td.gridSize; c++) {
      out << td.theDisplay[r][c];
    }
    out << endl;
  }
  return out;
}

