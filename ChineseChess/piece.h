#ifndef PIECE_DOT_H
#define PIECE_DOT_H

#include "general/stringUtility.h"
#include "position.h"

// forward declaration for Board (definition in "board.h" and "board.cpp")
struct Board;

// represents a side in chinese chess
enum struct Side {
	RED,
	GREEN // black does not display well on console, so green is used instead
};

// represents a chinese chess piece
struct Piece {

	Position pos;
	string name;
	wchar_t chineseNameRed;
	wchar_t chineseNameGreen;
	Side side;

	virtual bool canMoveTo(Position newPos, const Board& board) const = 0;
	virtual bool canEat(const Piece& enemy, const Board& board) const = 0;

	Piece(Position pos, Side side, const string& name, wchar_t cNameRed, wchar_t cNameGreen);

	void moveTo(Position newPos, const Board& board);
	void eat(Piece& enemy, const Board& board);
	wchar_t getChineseName() const;
	void printChineseName() const;

};

struct Car : public Piece {
	Car(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

struct Horse : public Piece {
	Horse(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

struct Elephant : public Piece {
	Elephant(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

struct Guard : public Piece {
	Guard(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

struct General : public Piece {
	General(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

struct Cannon : public Piece {
	Cannon(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

struct Footman : public Piece {
	Footman(Position pos, Side side);
	bool canMoveTo(Position newPos, const Board& board) const override;
	bool canEat(const Piece& enemy, const Board& board) const override;
};

#endif