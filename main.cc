#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd;
  Grid g;
  int moves = 0;
  int x, y, n;

  while (true) {
    try { cin >> cmd; }
    catch (ios::failure &) {
      if (cin.eof()) break;
      cin.clear();
      cin.ignore();
    }
    if (cmd == "new") {
      try { cin >> n; }
      catch (ios::failure &) {
        if (cin.eof()) break;
        cin.clear();
        cin.ignore();
      }
      g.init(n);
    }
    else if (cmd == "init") {
      while (cin >> x >> y) {
        if (x == -1 && y == -1) break;
        g.turnOn(x,y);
      }
      cout << g;
    }
    else if ( cmd == "neighbours" ) {
      g.printCells();
    }
    else if (cmd == "game") {
      try { cin >> moves; }
      catch (ios::failure &) {
        if (cin.eof()) break;
        cin.clear();
        cin.ignore();
      }
      if (moves == 1) {
        cout << moves << " move left" << endl;
      } else {
        cout << moves << " moves left" << endl;
      }
      while (moves > 0) {
        try { cin >> cmd; }
        catch (ios::failure &) {
          if (cin.eof()) break;
          cin.clear();
          cin.ignore();
        }
        if (cmd == "init") {
          while (cin >> x >> y) {
            if (x == -1 && y == -1) break;
            g.turnOn(x,y);
          }
        } else if (cmd == "switch") {
          try { cin >> x >> y; }
          catch (ios::failure &) {
            if (cin.eof()) break;
            cin.clear();
            cin.ignore();
          }
          g.toggle(x, y);
          moves--;
          cout << g;
          if (moves == 1) {
            cout << moves << " move left" << endl;
          } else {
            cout << moves << " moves left" << endl;
          }
          if (g.isWon()) {
            cout << "Won" << endl;
            return 0;
          } else if (moves == 0 && !g.isWon()) {
            cout << "Lost" << endl;
            return 0;
          }
        }
        else if ( cmd == "neighbours" ) {
          g.printCells();
        }
      }
    }
  }
}
