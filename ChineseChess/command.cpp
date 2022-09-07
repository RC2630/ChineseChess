#include <iostream>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include "general/ansi_codes.h"
#include "general/parseArguments.h"
#include "general/file.h"
#include "command.h"

Command::Command(const string& com)
: command(com)
{ }

void Command::execute(Board& board) const {
	if (parse::commandIs(command, "/help")) {
		cout << ANSI_CYAN << "\n" << COMMAND_HELP << ANSI_NORMAL;
	} else if (parse::commandIs(command, "/save") && parse::parseArgument(command, 1) == "frame") {
		saveFrame(board);
	} else if (parse::commandIs(command, "/save") && parse::parseArgument(command, 1) == "match") {
		saveMatch();
	} else if (parse::commandIs(command, "/load")) {
		load(board);
	} else if (parse::commandIs(command, "/undo")) {
		undo(board);
	} else if (parse::commandIs(command, "/eaten")) {
		eaten(board);
	} else if (parse::commandIs(command, "/replay")) {
		replay();
	} else if (parse::commandIs(command, "/exit")) {
		exit();
	} else if (parse::commandIs(command, "/restart")) {
		restart(board);
	} else if (parse::commandIs(command, "/skip")) {
		skip(board);
	} else {
		cout << ANSI_MAGENTA << "\nInvalid command. Try again!\n" << ANSI_NORMAL;
	}
}

void Command::saveFrame(const Board& board) const {
	string filename = "saves/" + parse::parseArgument(command, 2);
	board.printFrameToFile(filename, true);
	cout << ANSI_CYAN << "\nFrame has been saved.\n" << ANSI_NORMAL;
}

void Command::saveMatch() const {

	string label = parse::parseArgument(command, 2);

	vector<string> frames;
	file::inputStrVecFrom(frames, COM_CURR_MATCH_FRAMES);
	file::outputVecTo(frames, "saves/" + label + "_frames.txt");

	vector<string> moves;
	file::inputStrVecFrom(moves, COM_CURR_MATCH_MOVES);
	file::outputVecTo(moves, "saves/" + label + "_moves.txt");

	cout << ANSI_BLUE << "\nMatch has been saved (frames in \"saves/" << label
		 << "_frames.txt\" and moves in \"saves/" << label << "_moves.txt\").\n" << ANSI_NORMAL;

}

void Command::load(Board& board) const {
	// TODO
}

void Command::undo(Board& board) const {
	// TODO
}

void Command::eaten(const Board& board) const {

	vector<wchar_t> redEaten;
	vector<wchar_t> greenEaten;

	for (int i = 0; i < board.pieces.size(); i++) {
		if (board.pieces.at(i)->pos.isEaten()) {
			if (board.pieces.at(i)->side == Side::GREEN) {
				greenEaten.push_back(board.pieces.at(i)->chineseNameGreen);
			} else {
				redEaten.push_back(board.pieces.at(i)->chineseNameRed);
			}
		}
	}

	cout << ANSI_CYAN << "\nPieces eaten so far:\n" << ANSI_RED;

	if (redEaten.empty()) {
		cout << "(no red pieces eaten)";
	} else {
		_setmode(_fileno(stdout), _O_U16TEXT);
		for (int i = 0; i < redEaten.size() - 1; i++) {
			wcout << redEaten.at(i) << L' ';
		}
		wcout << redEaten.back();
		_setmode(_fileno(stdout), _O_TEXT);
	}

	cout << "\n" << ANSI_GREEN;

	if (greenEaten.empty()) {
		cout << "(no green pieces eaten)";
	} else {
		_setmode(_fileno(stdout), _O_U16TEXT);
		for (int i = 0; i < greenEaten.size() - 1; i++) {
			wcout << greenEaten.at(i) << L' ';
		}
		wcout << greenEaten.back();
		_setmode(_fileno(stdout), _O_TEXT);
	}

	cout << "\n" << ANSI_NORMAL;

}

void Command::replay() const {
	// TODO
}

void Command::exit() const {
	cout << ANSI_CYAN << "\nThank you for playing Chinese Chess. Have fun!\n" << ANSI_NORMAL;
	file::clearFile(COM_CURR_MATCH_FRAMES);
	file::clearFile(COM_CURR_MATCH_MOVES);
	std::exit(EXIT_SUCCESS);
}

void Command::restart(Board& board) const {
	cout << ANSI_CYAN << "\nStarting a new match ......\n" << ANSI_NORMAL;
	file::clearFile(COM_CURR_MATCH_FRAMES);
	file::clearFile(COM_CURR_MATCH_MOVES);
	board = Board();
	board.printFrameToFile(COM_CURR_MATCH_FRAMES, false);
}

void Command::skip(Board& board) const {
	Side originalSide = board.nextTurn;
	board.nextTurn = ((board.nextTurn == Side::GREEN) ? Side::RED : Side::GREEN);
	cout << ANSI_CYAN << "\nThis turn has been skipped and is given to the other side.\n" << ANSI_NORMAL;
	board.printFrameToFile(COM_CURR_MATCH_FRAMES, false);
	file::outputStrVecAddTo({((originalSide == Side::GREEN) ? "Green" : "Red") + string(" skipped a turn")}, COM_CURR_MATCH_MOVES);
}