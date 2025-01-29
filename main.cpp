#include "Board.h"
#include <iostream>
// #include <unordered_set>

using namespace std;

void uniform_cost_search(Board currNode, vector<vector<int>> goal, vector<Board>& openList, vector<Board>& closedList) {
    
    // check if top of open list == goal state
    if (openList.size() == 0) {
        cout << "no solution" << endl;
        return;
    } else if (openList[0].getBoard() == goal) {
        cout << "solution found: " << currNode.getCost() << endl;
        return;
    }
    else {
        // find where the zero is
        bool foundZero = false;
        for (int i = 0; i < 3 && !foundZero; i++) {
            for (int j = 0; j < 3 && !foundZero; j++) {
                if (currNode.getBoard()[i][j] == 0) {
                    // add curr board to closed-list
                    closedList.push_back(currNode);
                    // remove board from open-list
                    vector<Board> newOpenList;
                    for (int k = 1; k < openList.size(); k++) {
                        newOpenList.push_back(openList[k]);
                    }
                    openList = newOpenList;

                    // check child nodes
                    int temp;
                    vector<vector<int>> newBoard = currNode.getBoard();

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
                                if (openList[i].getBoard() == newBoard && currNode.getCost() + 1 < openList[i].getCost()) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(currNode.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newNode(newBoard, currNode.getCost() + 1);
                                openList.push_back(newNode);
                            }
                        }

                        // reset newBoard to board
                        newBoard = currNode.getBoard();
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
                                if (openList[i].getBoard() == newBoard && currNode.getCost() + 1 < openList[i].getCost()) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(currNode.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, currNode.getCost() + 1);
                                openList.push_back(newB);
                            }         
                        }

                        // reset board
                        newBoard = currNode.getBoard();
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
                                if (openList[i].getBoard() == newBoard && currNode.getCost() + 1 < openList[i].getCost()) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(currNode.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, currNode.getCost() + 1);
                                openList.push_back(newB);
                            }         
                        }

                        // reset board
                        newBoard = currNode.getBoard();
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
                                if (openList[i].getBoard() == newBoard && currNode.getCost() + 1 < openList[i].getCost()) {
                                    inOpen = true;
                                    openList[i].setBoard(newBoard);
                                    openList[i].setCost(currNode.getCost() + 1);
                                    break;
                                }
                            }

                            if (!inOpen) {
                                Board newB(newBoard, currNode.getCost() + 1);
                                openList.push_back(newB);
                            }         
                        }

                        // reset board
                        newBoard = currNode.getBoard();
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

        // recursive search to next move
        uniform_cost_search(openList[0], goal, openList, closedList);

    }
    
}

int main () {
    vector<vector<int>> goal {{1,2,3}, {4,5,6}, {7,8,0}};

    vector<vector<int>> depth0 {{1,2,3}, {4,5,6}, {7,8,0}};
    vector<vector<int>> depth2 {{1,2,3}, {4,5,6}, {0,7,8}};
    vector<vector<int>> depth4 {{1,2,3}, {5,0,6}, {4,7,8}};
    vector<vector<int>> depth8 {{1,3,6}, {5,0,2}, {4,7,8}};
    vector<vector<int>> depth12 {{1,3,6}, {5,0,7}, {4,8,2}};
    vector<vector<int>> depth16 {{1,6,7}, {5,0,3}, {4,8,2}};
    vector<vector<int>> depth20 {{7,1,2}, {4,8,5}, {6,3,0}};
    vector<vector<int>> depth24 {{0,7,2}, {4,6,1}, {3,5,8}};
    
    Board currNode;
    int userInput;
    cout << "Enter which board: ";
    cin >> userInput;
    switch (userInput) {
        case 0: currNode.setBoard(depth0); break;
        case 2: currNode.setBoard(depth2); break;
        case 4: currNode.setBoard(depth4); break;
        case 8: currNode.setBoard(depth8); break;
        case 12: currNode.setBoard(depth12); break;
        case 16: currNode.setBoard(depth16); break;
        case 20: currNode.setBoard(depth20); break;
        case 24: currNode.setBoard(depth24); break;
        default: cout << "enter a choice: "; break;
    }

    vector<Board> openList {currNode}; // create open list and add initial state inside
    vector<Board> closedList;

    uniform_cost_search(currNode, goal, openList, closedList);
    return 0;
}