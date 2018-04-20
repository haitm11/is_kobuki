#include "../../include/common/common.hpp"

int Cell::getX() {
  return x;
}

int Cell::getY() {
  return y;
}

int Cell::getCellSize() {
  return cellSize;
}

bool Cell::hasObstacle() {
  return obstacle;
}

int Cell::getStatus() {
  return status;
}

void Cell::setX(int x) {
  this->x = x;
}

void Cell::setY(int y) {
  this->y = y;
}

void Cell::setCellSize(int cellSize) {
  this->cellSize = cellSize;
}

void Cell::setObstacle(bool obstacle) {
  this->obstacle = obstacle;
}

void Cell::setStatus(int status) {
  this->status = status;
}

// Tra ve cell ben canh theo vi tri position
Cell* Cell::getNeighbor(int position) {
  int x, y;

  if (position == UP) {
    x = getX();
    y = getY() + getCellSize();
  }

  if (position == LEFT) {
    x = getX() - getCellSize();
    y = getY();
  }

  if (position == RIGHT) {
    x = getX() + getCellSize();
    y = getY();
  }

  if (position == DOWN) {
    x = getX();
    y = getY() - getCellSize();
  }

  return Common::findCell(x, y);
}

bool Cell::operator==(const Cell &other) {
  return (x == other.x) && (y == other.y);
}

bool Cell::operator!=(const Cell &other) {
  return (x != other.x) || (y != other.y);
}

bool Cell::isNULL() {
  return this->cellSize == 0;
}
