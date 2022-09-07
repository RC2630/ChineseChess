#ifndef COMMAND_DOT_H
#define COMMAND_DOT_H

#include <string>
#include "board.h"

using namespace std;

// represents a special command instruction (ones starting with "/")
struct Command {

	string command;

	Command(const string& com);

	void execute(const Board& board) const;

};

#endif