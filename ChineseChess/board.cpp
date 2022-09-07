#include "general/ansi_codes.h"
#include "board.h"

Board::Board() {

	// the red side goes first
	nextTurn = Side::RED;

	// allocate enough space for the board's 32 pieces
	pieces.reserve(NUM_PIECES);

	// add red non-footman pieces
	pieces.push_back(make_unique<Car>(Position(1, 1), Side::RED));
	pieces.push_back(make_unique<Horse>(Position(2, 1), Side::RED));
	pieces.push_back(make_unique<Elephant>(Position(3, 1), Side::RED));
	pieces.push_back(make_unique<Guard>(Position(4, 1), Side::RED));
	pieces.push_back(make_unique<General>(Position(5, 1), Side::RED));
	pieces.push_back(make_unique<Guard>(Position(6, 1), Side::RED));
	pieces.push_back(make_unique<Elephant>(Position(7, 1), Side::RED));
	pieces.push_back(make_unique<Horse>(Position(8, 1), Side::RED));
	pieces.push_back(make_unique<Car>(Position(9, 1), Side::RED));
	pieces.push_back(make_unique<Cannon>(Position(2, 3), Side::RED));
	pieces.push_back(make_unique<Cannon>(Position(8, 3), Side::RED));

	// add green non-footman pieces
	pieces.push_back(make_unique<Car>(Position(1, 10), Side::GREEN));
	pieces.push_back(make_unique<Horse>(Position(2, 10), Side::GREEN));
	pieces.push_back(make_unique<Elephant>(Position(3, 10), Side::GREEN));
	pieces.push_back(make_unique<Guard>(Position(4, 10), Side::GREEN));
	pieces.push_back(make_unique<General>(Position(5, 10), Side::GREEN));
	pieces.push_back(make_unique<Guard>(Position(6, 10), Side::GREEN));
	pieces.push_back(make_unique<Elephant>(Position(7, 10), Side::GREEN));
	pieces.push_back(make_unique<Horse>(Position(8, 10), Side::GREEN));
	pieces.push_back(make_unique<Car>(Position(9, 10), Side::GREEN));
	pieces.push_back(make_unique<Cannon>(Position(2, 8), Side::GREEN));
	pieces.push_back(make_unique<Cannon>(Position(8, 8), Side::GREEN));

	// add red and green footmen
	for (int i = 1; i <= Position::NUM_COLS; i += 2) {
		pieces.push_back(make_unique<Footman>(Position(i, 4), Side::RED));
		pieces.push_back(make_unique<Footman>(Position(i, 7), Side::GREEN));
	}

}

// returns -1 to signify empty pos
int Board::getIndexOfPieceAtPos(Position pos) const {
	for (int i = 0; i < pieces.size(); i++) {
		if (pieces.at(i)->pos == pos) {
			return i;
		}
	}
	return -1;
}

void Board::displayRiver() {

	// top line divider
	for (int x = 0; x <= CELL_WIDTH * Position::NUM_COLS; x++) {
		cout << "-";
	}
	cout << "\n    ";

	// buffer line
	cout << "|";
	for (int x = 1; x < CELL_WIDTH * Position::NUM_COLS; x++) {
		cout << " ";
	}
	cout << "|\n    ";

	// water line
	cout << "| " << ANSI_BLUE;
	for (int x = 2; x <= CELL_WIDTH * Position::NUM_COLS - 2; x++) {
		cout << "~";
	}
	cout << ANSI_NORMAL << " |\n    ";

}

void Board::display() const {

	// initial newline
	cout << "\n    ";

	// column numbers
	cout << strUtil::spaces((CELL_WIDTH + 1) / 2) << ANSI_YELLOW;
	for (int x = 1; x < Position::NUM_COLS; x++) {
		cout << x << strUtil::spaces(CELL_WIDTH - 1);
	}
	cout << Position::NUM_COLS << ANSI_NORMAL << "\n\n    ";

	// displaying the board row by row, from the top to the bottom
	for (int y = Position::NUM_ROWS; y >= 1; y--) {

		// river
		if (y == Position::NUM_ROWS / 2) {
			displayRiver();
		}
		
		// top line divider
		for (int x = 0; x <= CELL_WIDTH * Position::NUM_COLS; x++) {
			cout << "-";
		}
		cout << "\n    ";

		// buffer line
		for (int x = 0; x < Position::NUM_COLS; x++) {
			cout << "|" << strUtil::spaces(CELL_WIDTH - 1);
		}
		cout << "|\n";

		// piece line
		cout << ((y == 10) ? " " : "  ") << ANSI_YELLOW << y << ANSI_NORMAL << " ";
		for (int x = 1; x <= Position::NUM_COLS; x++) {
			cout << "|" << strUtil::spaces((CELL_WIDTH - 3) / 2);
			int pieceIndex = getIndexOfPieceAtPos(Position(x, y));
			if (pieceIndex == -1) {
				cout << "  ";
			} else {
				pieces.at(pieceIndex)->printChineseName();
			}
			cout << strUtil::spaces((CELL_WIDTH - 3) / 2);
		}
		cout << "|" << ((y == 10) ? " " : "  ") << ANSI_YELLOW << y << ANSI_NORMAL << "\n    ";

		// buffer line (again)
		for (int x = 0; x < Position::NUM_COLS; x++) {
			cout << "|" << strUtil::spaces(CELL_WIDTH - 1);
		}
		cout << "|\n    ";

	}

	// final bottom line
	for (int x = 0; x <= CELL_WIDTH * Position::NUM_COLS; x++) {
		cout << "-";
	}
	cout << "\n\n    ";

	// column numbers (again)
	cout << strUtil::spaces((CELL_WIDTH + 1) / 2) << ANSI_YELLOW;
	for (int x = 1; x < Position::NUM_COLS; x++) {
		cout << x << strUtil::spaces(CELL_WIDTH - 1);
	}
	cout << Position::NUM_COLS << ANSI_NORMAL << "\n";

}

void Board::move(Instruction inst) {
	// TODO
}