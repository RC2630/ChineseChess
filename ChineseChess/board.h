#ifndef BOARD_DOT_H
#define BOARD_DOT_H

#include <memory>
#include "general/vectorUtility.h"
#include "piece.h"
#include "instruction.h"

// forward declaration for Instruction (definition in "instruction.h" and "instruction.cpp")
struct Instruction;

// represents a chinese chess board
struct Board {

	static const int NUM_PIECES = 32;
	static const int CELL_WIDTH = 11; // must be an odd number

	static void displayRiver();
	
	Side nextTurn;
	vector<unique_ptr<Piece>> pieces;

	Board();
	int getIndexOfPieceAtPos(Position pos) const; // returns -1 to signify empty pos
	void display() const;
	void move(Instruction inst);
	bool isGeneralAlive(Side side) const;

};

#endif