#include <vector>

#ifndef BOARD
#define BOARD

class Board {
    private:
        int cost;
        std::vector<std::vector<int>> board;
    public:
        // get board
        Board() { cost = 0; }
        Board(std::vector<std::vector<int>> board) {
            this->board = board;
            cost = 0;
        }
        Board(std::vector<std::vector<int>> board, int cost) {
            this->board = board;
            this->cost = cost;
        }

        // getters
        std::vector<std::vector<int>> getBoard() {
            return this->board;
        }
        int getCost() {
            return this->cost;
        }

        // setters
        void setBoard(std::vector<std::vector<int>> newBoard) {
            this->board = newBoard;
        }
        void setCost(int newCost) {
            this->cost = newCost;
        }

};

#endif