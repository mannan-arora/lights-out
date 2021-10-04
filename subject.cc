#include "subject.h"
#include "cell.h"

using namespace std;


void Subject::attach( Observer *o ) {
  observers.push_back(o);
}

string Subject::getObserverNames() const {
  std::string ObserverNames;
  for (auto ob : observers) {
    if (ob->getName() == "TD") {
      ObserverNames += ob->getName();
      break;
    }
    ObserverNames += ob->getName() + ", ";
  }
  return ObserverNames;
}
