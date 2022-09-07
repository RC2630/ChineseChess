#include <iostream>
#include "general/ansi_codes.h"
#include "general/parseArguments.h"
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
	// TODO
}

void Command::saveMatch() const {
	// TODO
}

void Command::load(Board& board) const {
	// TODO
}

void Command::undo(Board& board) const {
	// TODO
}

void Command::eaten(const Board& board) const {
	// TODO
}

void Command::replay() const {
	// TODO
}

void Command::exit() const {
	// TODO
}

void Command::restart(Board& board) const {
	// TODO
}

void Command::skip(Board& board) const {
	// TODO
}