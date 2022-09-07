#include "instruction.h"

InstructionType Instruction::getType(const Board& board, int& indexPiece, int& indexTargetPiece) const {

	indexPiece = board.getIndexOfPieceAtPos(this->from);

	// there is no piece to move
	if (indexPiece == -1) {
		return InstructionType::INVALID;
	}

	// the piece there is of the wrong side (colour)
	if (board.pieces.at(indexPiece)->side != board.nextTurn) {
		return InstructionType::INVALID;
	}

	// at this point, we know that there is a correctly-coloured piece at the "from" position,
	// so we just need to check the "to" position using the polymorphic canSomething() methods now

	indexTargetPiece = board.getIndexOfPieceAtPos(this->to);

	// the piece is trying to move to an empty location
	if (indexTargetPiece == -1) {
		return board.pieces.at(indexPiece)->canMoveTo(this->to, board) ? InstructionType::MOVE : InstructionType::INVALID;
	}
	
	// the piece is trying to move to the location of another friendly piece
	if (board.pieces.at(indexTargetPiece)->side == board.pieces.at(indexPiece)->side) {
		return InstructionType::INVALID;
	}

	// the piece is trying to eat an enemy piece and move to its location
	return board.pieces.at(indexPiece)->canEat(*board.pieces.at(indexTargetPiece), board) ? InstructionType::EAT : InstructionType::INVALID;

}