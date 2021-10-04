#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }
void Cell::setOn() { isOn = true; }
void Cell::toggle() { isOn = !isOn; }
void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Cell & whoNotified) {
  toggle();
  notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::notifyObservers(SubscriptionType t) {
  if (t == SubscriptionType::All) {
    for (auto ob : observers) {
     ob->notify(*this);
    }
  } else if (t == SubscriptionType::SwitchOnly) {
    observers.back()->notify(*this);
  }
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}

std::string Cell::getName() const {
  std::string name;
  name += "(" + std::to_string(this->getRow()) + "," + std::to_string(this->getCol()) + ")";
  return name;
}

