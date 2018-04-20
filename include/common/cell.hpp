#ifndef CELL_H
#define CELL_H

#include "position.hpp"
#include "status.hpp"

// Tren ban do toa do [0,0] nam o goc duoi ben trai (BOTTOM_LEFT)
class Cell {
private:
  //  column, row top_left position of Cell
  int x, y;

  // size of a Cell
  int cellSize;

  // Co vat can hay k?
  bool obstacle;

  // Da quet hay chua
  int status;

public:
  Cell() {
    x = 0;
    y = 0;
    cellSize = 0;
    obstacle = true;
    status = WAITING;
  }

  Cell(int x, int y, int cellSize, bool obstacle) {
    this->x = x;
    this->y = y;
    this->cellSize = cellSize;
    this->obstacle = obstacle;

    status = WAITING;
  }

  int getX();
  int getY();
  int getCellSize();
  bool hasObstacle();
  int getStatus();

  void setX(int x);
  void setY(int y);
  void setCellSize(int cellSize);
  void setObstacle(bool obstacle);
  void setStatus(int status);

  // Tra ve cell ben canh theo vi tri position
  Cell* getNeighbor(int position);

  // Kiem tra cell null
  bool isNULL();

  // So sanh cell == other
  bool operator==(const Cell &other);

  // So sanh cell != other
  bool operator!=(const Cell &other);
};

#endif /* CELL_H */
