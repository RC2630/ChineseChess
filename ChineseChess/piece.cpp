#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "general/ansi_codes.h"
#include "piece.h"

Piece::Piece(Position pos, Side side, const string& name, wchar_t cNameRed, wchar_t cNameGreen)
: pos(pos), name(name), chineseNameRed(cNameRed), chineseNameGreen(cNameGreen), side(side)
{ }

void Piece::moveTo(Position newPos, const Board& board) {
	if (this->canMoveTo(newPos, board)) {
		cout << ANSI_CYAN << "\n" << this->toString() << " moved to " << newPos.toString() << ".\n" << ANSI_NORMAL;
		this->pos = newPos;
	} else {
		throw invalid_argument("the new position is not valid for " + this->name);
	}
}

void Piece::eat(Piece& enemy, const Board& board) {
	if (this->canEat(enemy, board)) {
		cout << ANSI_CYAN << "\n" << this->toString() << " ate " << enemy.toString() << ".\n" << ANSI_NORMAL;
		this->pos = enemy.pos;
		enemy.pos.setToEaten();
	} else {
		throw invalid_argument(this->name + " cannot eat " + enemy.name + " in this configuration");
	}
}

wchar_t Piece::getChineseName() const {
	return (this->side == Side::RED) ? this->chineseNameRed : this->chineseNameGreen;
}

void Piece::printChineseName() const {

	// displays colour of side
	cout << ((this->side == Side::RED) ? ANSI_RED : ANSI_GREEN);

	// allows for Chinese characters to be displayed
	_setmode(_fileno(stdout), _O_U16TEXT);

	// displays Chinese name of piece
	wcout << this->getChineseName();

	// returns to displaying regular (non-Chinese) text
	_setmode(_fileno(stdout), _O_TEXT);

	// returns colour to default
	cout << ANSI_NORMAL;

}

string Piece::toString() const {
	return ((side == Side::RED) ? "Red" : "Green") + string(" ") + name + " @ " + pos.toString();
}

Car::Car(Position pos, Side side)
: Piece(pos, side, "Car", L'车', L'车')
{ }

bool Car::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool Car::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}

Horse::Horse(Position pos, Side side)
: Piece(pos, side, "Horse", L'马', L'马')
{ }

bool Horse::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool Horse::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}

Elephant::Elephant(Position pos, Side side)
: Piece(pos, side, "Elephant", L'相', L'象')
{ }

bool Elephant::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool Elephant::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}

Guard::Guard(Position pos, Side side)
: Piece(pos, side, "Guard", L'士', L'士')
{ }

bool Guard::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool Guard::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}

General::General(Position pos, Side side)
: Piece(pos, side, "General", L'帅', L'将')
{ }

bool General::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool General::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}

Cannon::Cannon(Position pos, Side side)
: Piece(pos, side, "Cannon", L'炮', L'炮')
{ }

bool Cannon::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool Cannon::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}

Footman::Footman(Position pos, Side side)
: Piece(pos, side, "Footman", L'兵', L'卒')
{ }

bool Footman::canMoveTo(Position newPos, const Board& board) const {
	// TODO
	return true;
}

bool Footman::canEat(const Piece& enemy, const Board& board) const {
	// TODO
	return true;
}