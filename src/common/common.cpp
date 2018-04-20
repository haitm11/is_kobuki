#include "../../include/common/common.hpp"

Cell **Common::cells;
MegaCell **Common::megaCells;
int Common::rowCells = 0;
int Common::colCells = 0;

Cell *Common::findCell(int x, int y) {
	for (int i = 0; i < Common::rowCells; i++) {
		for (int j = 0; j < Common::colCells; j++)
			if (Common::cells[i][j].getX() == x && y == Common::cells[i][j].getY())
				return &Common::cells[i][j];
	}
	Cell cell = Cell();
	return &cell;
}

MegaCell *Common::findMegaCell(int x, int y) {
	for (int i = 0; i < Common::rowCells / 2; i++) {
		for (int j = 0; j < Common::colCells / 2; j++)
			if (Common::megaCells[i][j].getX() == x && y == Common::megaCells[i][j].getY())
				return &Common::megaCells[i][j];
	}
	MegaCell megaCell = MegaCell();
	return &megaCell;
}

MegaCell* Common::findMegaCellByCell(Cell *cell) {
	for (int i = 0; i < Common::rowCells / 2; i++) {
		for (int j = 0; j < Common::colCells / 2; j++)
			if (Common::megaCells[i][j].getCellPosition(cell) != -1)   // sai vi cell khong tro den common
				return &Common::megaCells[i][j];
	}
	MegaCell megaCell = MegaCell();
	return &megaCell;
}

int* Common::findIndexCell(Cell *cell) {
	int* index = (int*)malloc(2 * sizeof(int));
	for (int i = 0; i < Common::rowCells; i++) {
		for (int j = 0; j < Common::colCells; j++)
			if (Common::cells[i][j].getX() == cell->getX() && Common::cells[i][j].getY() == cell->getY()) {
				index[0] = i;
				index[1] = j;
				return index;
			}
	}

	index[0] = -1;
	index[1] = -1;
	return index;
}

int* Common::findIndexMegaCell(MegaCell *megaCell) {
	int* index = (int*)malloc(2 * sizeof(int));
	for (int i = 0; i < Common::rowCells/2; i++) {
		for (int j = 0; j < Common::colCells/2; j++)
			if (Common::megaCells[i][j].getX() == megaCell->getX() && Common::megaCells[i][j].getY() == megaCell->getY()) {
				index[0] = i;
				index[1] = j;
				return index;
			}
	}

	index[0] = -1;
	index[1] = -1;
	return index;
}
