#include "general/ansi_codes.h"
#include "general/parseArguments.h"
#include "general/stringUtility.h"
#include "board.h"
#include "command.h"
#include "instruction.h"

int main() {

	Board board;

	while (board.isGeneralAlive(Side::RED) && board.isGeneralAlive(Side::GREEN)) {

		board.display();

		if (board.nextTurn == Side::RED) {
			cout << ANSI_RED << "\nred's turn: ";
		} else {
			cout << ANSI_GREEN << "\ngreen's turn: ";
		}

		string instruction;
		getline(cin >> ws, instruction);
		cout << ANSI_NORMAL;

		if (strUtil::beginsWith(instruction, "/")) {
			Command(instruction).execute(board);
			continue;
		}

		try {
			board.move(Instruction(instruction));
		} catch (const InvalidInstructionException& e) {
			cout << ANSI_MAGENTA << "\nInstruction syntax is incorrect. Try again!\n" << ANSI_NORMAL;
		} catch (const invalid_argument& e) {
			cout << ANSI_MAGENTA << "\nInstruction represents an illegal move. Try again!\n" << ANSI_NORMAL;
		}

	}

	board.display();

	if (board.isGeneralAlive(Side::RED)) {
		cout << ANSI_GREEN << "\nCongratulations! The GREEN side has won this game!\n" << ANSI_NORMAL;
	} else {
		cout << ANSI_RED << "\nCongratulations! The RED side has won this game!\n" << ANSI_NORMAL;
	}

}