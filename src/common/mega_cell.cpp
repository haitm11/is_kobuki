#include "../../include/common/common.hpp"

int MegaCell::getX() {
  return x;
}

int MegaCell::getY() {
  return y;
}

int MegaCell::getCellSize() {
  return cellSize;
}

bool MegaCell::hasObstacle() {
  return obstacle;
}

int MegaCell::getStatus() {
  return status;
}

void MegaCell::setX(int x) {
  this->x = x;
}

void MegaCell::setY(int y) {
  this->y = y;
}

void MegaCell::setCellSize(int cellSize) {
  this->cellSize = cellSize;
}

void MegaCell::setObstacle(bool obstacle) {
  this->obstacle = obstacle;
}

void MegaCell::setStatus(int status) {
  this->status = status;
}

// Tra ve cell trong megaCell theo position
Cell* MegaCell::getCell(int position) {
  int x, y;
  if (position == TOP_LEFT) {
    x = getX();
    y = getY();
  }

  if (position == TOP_RIGHT) {
    x = getX() + getCellSize();
    y = getY();
  }

  if (position == BOTTOM_LEFT) {
    x = getX();
    y = getY() - getCellSize();
  }

  if (position == BOTTOM_RIGHT) {
    x = getX() + getCellSize();
    y = getY() - getCellSize();
  }

  return Common::findCell(x, y);
}

// Tra ve vi tri position cua cell
int MegaCell::getCellPosition(Cell *cell) {
  if ((getX() == cell->getX()) && (getY() == cell->getY()))
    return TOP_LEFT;

  if ((getX() == cell->getX()) && (getY() - cell->getY() == cell->getCellSize()))
    return BOTTOM_LEFT;

  if ((cell->getX() - getX() == cell->getCellSize()) && (getY() == cell->getY()))
    return TOP_RIGHT;

  if ((cell->getX() - getX() == cell->getCellSize()) && (getY() - cell->getY() == cell->getCellSize()))
    return BOTTOM_RIGHT;

  return -1;
}

// Tra ve vi tri tuong doi cua megaCell so voi this
int MegaCell::getMegaCellPosition(MegaCell *megaCell) {
  if ((megaCell->getX() == getX()) && (megaCell->getY() - getY() == getCellSize()*2))
    return UP;

  if ((getX() - megaCell->getX() == getCellSize()*2 ) && (megaCell->getY() == getY()))
    return LEFT;

  if ((megaCell->getX() == getX()) && (getY() - megaCell->getY() == getCellSize()*2))
    return DOWN;

  if ((megaCell->getX() - getX() == getCellSize()*2) && (megaCell->getY() == getY()))
    return RIGHT;

  return -1;
}

bool MegaCell::isScaned() {
  Cell* cellTopLeft = getCell(TOP_LEFT);
  Cell* cellTopRight = getCell(TOP_RIGHT);
  Cell* cellBottomLeft = getCell(BOTTOM_LEFT);
  Cell* cellBottomRight = getCell(BOTTOM_RIGHT);
  bool scaned = true;
  if (cellTopLeft->getStatus() == WAITING || cellTopRight->getStatus() == WAITING
   || cellBottomLeft->getStatus() == WAITING || cellBottomRight->getStatus() == WAITING)
    scaned = false;
  return scaned;
}

// Lay megaCell xung quanh, theo chieu nguoc chieu kim dong ho.
MegaCell* MegaCell::getNeighbor(int position) {
  int x, y;
  if (position == UP) {
    x = getX();
    y = getY() + getCellSize() * 2;
  }

  if (position == LEFT) {
    x = getX() - getCellSize() * 2;
    y = getY();
  }

  if (position == RIGHT) {
    x = getX() + getCellSize() * 2;
    y = getY();
  }

  if (position == DOWN) {
    x = getX();
    y = getY() - getCellSize() * 2;
  }

  return Common::findMegaCell(x, y);
}

bool MegaCell::operator==(const MegaCell &other) {
  return (x == other.x) && (y == other.y);
}

bool MegaCell::operator!=(const MegaCell &other) {
  return (x != other.x) || (y != other.y);
}

bool MegaCell::isNULL() {
  return this->cellSize == 0;
}
