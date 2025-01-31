#include "Node.h"
#include <iostream>

using namespace std;

void expand_node(Node curr, vector<Node> nodes_list) {
    // find the zero
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (curr.getBoard()[i][j] == 0) { // found zero

                int temp;
                vector<vector<int>> curr_board = curr.getBoard();
                vector<vector<int>> new_board;

                // TOP SWAP
                if (i - 1 >= 0) {
                    // create new board 
                    int temp = new_board[i][j];
                    new_board[i][j] = new_board[i-1][j];
                    new_board[i-1][j] = temp;

                    // if not repeated state (already in nodes-list), add
                    bool repeated = false;
                    Node repeated_node;
                    for (int i = 0; i < nodes_list.size(); i++) {
                        if (nodes_list[i].getCost() == curr.getBoard()) {

                        }
                    }
                    if (repeated) {
                        

                    }
                        Node newNode(new_board, curr.getCost() + 1);
                        nodes_list.push_back(newNode);
                } 
            }
        }
    }
    
}

void uniform_cost_search(Node curr, vector<vector<int>> goal) {
    
    vector<Node> nodes_list {curr}; 
    do {
        if (nodes_list.empty()) {
            cout << "no solution: failure";
            return;
        }

        // remove the front node
        vector<Node> new_nodes_list;
        for (int i = 1; i < nodes_list.size(); i++) {
            new_nodes_list.push_back(nodes_list[i]);
        }
        nodes_list = new_nodes_list;

        if (curr.getBoard() == goal) {
            cout << "found solution: " << curr.getCost() << endl;
            return;
        }

        // create all of the curr-node's children


    }

}

int main() {
    vector<vector<int>> goal {{1,2,3}, {4,5,6}, {7,8,0}};

    vector<vector<int>> depth0 {{1,2,3}, {4,5,6}, {7,8,0}};
    vector<vector<int>> depth2 {{1,2,3}, {4,5,6}, {0,7,8}};
    vector<vector<int>> depth4 {{1,2,3}, {5,0,6}, {4,7,8}};
    vector<vector<int>> depth8 {{1,3,6}, {5,0,2}, {4,7,8}};
    vector<vector<int>> depth12 {{1,3,6}, {5,0,7}, {4,8,2}};
    vector<vector<int>> depth16 {{1,6,7}, {5,0,3}, {4,8,2}};
    vector<vector<int>> depth20 {{7,1,2}, {4,8,5}, {6,3,0}};
    vector<vector<int>> depth24 {{0,7,2}, {4,6,1}, {3,5,8}};
    
    Node currNode;
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

    vector<Node> openList {currNode};
    vector<Node> closedList;

    uniform_cost_search(currNode, goal, openList, closedList);
    return 0;
}