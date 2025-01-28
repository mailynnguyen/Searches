#include "Board.h"
#include <iostream>

using namespace std;

void uniform_cost_search(Board board, vector<vector<int>> goal, vector<Board>& openList, vector<Board>& closedList) {
    
    // check if top of open list == goal state
    if (openList.size() == 0) {
        cout << "no solution" << endl;
        return;
    } else if (openList[0].getBoard() == goal) {
        cout << "solution found: " << board.getCost() << endl;

        return;
    }
    else {
        // find child nodes of curr node

        // find where the zero is
        bool foundZero = false;
        for (int i = 0; i < 3 && !foundZero; i++) {
            for (int j = 0; j < 3 && !foundZero; j++) {
                vector<vector<int>> b = board.getBoard();
                cout << "hello: (" << i << ", " << j << ") line 22 --> ";
                cout << b[i][j] << endl;
                if (board.getBoard()[i][j] == 0) {
                    cout << "hello: line 26" << endl;
                    // add curr board to closed-list
                    closedList.push_back(board);
                    // remove board from open-list
                    vector<Board> newOpenList;
                    for (int k = 1; k < openList.size(); k++) {
                        newOpenList.push_back(openList[k]);
                    }
                    openList = newOpenList;

                    // check child nodes
                    int temp;
                    vector<vector<int>> newBoard = board.getBoard();

                    // TOP SWAP
                    if (i - 1 >= 0) {
                        temp = newBoard[i][j];
                        newBoard[i][j] = newBoard[i-1][j];
                        newBoard[i-1][j] = temp;

                        // check if newBoard is alr in closed-list
                        bool inClosed = false;
                        for (int i = 0; i < closedList.size(); i++) {
                            if (closedList[i].getBoard() == newBoard) { 
                                inClosed = true;
                                break;
                            }
                        }

                        if (!inClosed) {
                            // check if in open-list
                            bool inOpen = false;
                            for (int i = 0; i < openList.size(); i++) {
                                if (openList[i].getBoard() == newBoard) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(board.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, board.getCost() + 1);
                                openList.push_back(newBoard);
                            }
                        }

                        // reset newBoard to board
                        newBoard = board.getBoard();
                    }

                    // BOTTOM SWAP
                    if (i + 1 <= 2) { 
                        temp = newBoard[i][j];
                        newBoard[i][j] = newBoard[i+1][j];
                        newBoard[i+1][j] = temp;     

                        // check if newBoard is alr in closed-list
                        bool inClosed = false;
                        for (int i = 0; i < closedList.size(); i++) {
                            if (closedList[i].getBoard() == newBoard) { 
                                inClosed = true;
                                break;
                            }
                        }

                        if (!inClosed) {
                            // check if in open-list
                            bool inOpen = false;
                            for (int i = 0; i < openList.size(); i++) {
                                if (openList[i].getBoard() == newBoard) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(board.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, board.getCost() + 1);
                                openList.push_back(newBoard);
                            }         
                        }

                        // reset board
                        newBoard = board.getBoard();
                    }

                    // LEFT SWAP
                    if (j - 1 >= 0) { 
                        temp = newBoard[i][j];
                        newBoard[i][j] = newBoard[i][j-1];
                        newBoard[i][j-1] = temp;   

                        // check if newBoard is alr in closed-list
                        int inClosed = false;
                        for (int i = 0; i < closedList.size(); i++) {
                            if (closedList[i].getBoard() == newBoard) { 
                                inClosed = true;
                                break;
                            }
                        }

                        if (!inClosed) {
                            // check if in open-list
                            bool inOpen = false;
                            for (int i = 0; i < openList.size(); i++) {
                                if (openList[i].getBoard() == newBoard) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(board.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, board.getCost() + 1);
                                openList.push_back(newBoard);
                            }         
                        }

                        // reset board
                        newBoard = board.getBoard();
                    }

                    // RIGHT SWAP
                    if (j + 1 <= 2) { 
                        temp = newBoard[i][j];
                        newBoard[i][j] = newBoard[i][j+1];
                        newBoard[i][j+1] = temp;   

                        // check if newBoard is alr in closed-list
                        int inClosed = false;
                        for (int i = 0; i < closedList.size(); i++) {
                            if (closedList[i].getBoard() == newBoard) { 
                                inClosed = true;
                                break;
                            }
                        }

                        if (!inClosed) {
                            // check if in open-list
                            bool inOpen = false;
                            for (int i = 0; i < openList.size(); i++) {
                                if (openList[i].getBoard() == newBoard) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(board.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, board.getCost() + 1);
                                openList.push_back(newBoard);
                            }         
                        }

                        // reset board
                        newBoard = board.getBoard();
                    }

                    foundZero = true;
                }

            }
        }

        // sort open-list
        for (int i = 0; i < openList.size() - 1; i++) {
            for (int j = i + 1; j < openList.size(); j++) {
                Board temp;
                if (openList[i].getCost() > openList[j].getCost()) {
                    temp = openList[i];
                    openList[i] = openList[j];
                    openList[j] = temp;
                }
            }
        }

    }
    // recursive search to next move
    uniform_cost_search(openList[0], goal, openList, closedList);
}

int main () {
    vector<vector<int>> goal {{1,2,3},
                              {4,5,6},
                              {7,8,0}};

    // vector<vector<int>> initialBoard {{1,2,3},
    //                                   {4,5,6},
    //                                   {7,8,0}};

    vector<vector<int>> initialBoard {{1,2,3},
                                      {4,5,6},
                                      {0,7,8}};
    
    Board board(initialBoard);

    vector<Board> openList {board}; // create open list and add initial state inside
    vector<Board> closedList;

    uniform_cost_search(board, goal, openList, closedList);
    return 0;
}