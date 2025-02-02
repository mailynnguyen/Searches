import heapq
import copy

class Node:
    def __init__(self, cost, board):
        self.cost = cost
        self.board = board

    def boardToTuple(self): # converts the board prop to a tuple
        return tuple(tuple(row) for row in self.board)

    def __lt__(self, other): # function to be able to compare two nodes, to push into heap
        return self.cost < other.cost

def main():
    goal_board = [[1,2,3], [4,5,6], [7,8,0]]

    depth0 = [[1,2,3], [4,5,6], [7,8,0]]
    depth2 = [[1,2,3], [4,5,6], [0,7,8]]
    depth4 = [[1,2,3], [5,0,6], [4,7,8]]
    depth8 = [[1,3,6], [5,0,2], [4,7,8]]
    depth12 = [[1,3,6], [5,0,7], [4,8,2]]
    depth16 = [[1,6,7], [5,0,3], [4,8,2]]
    depth20 = [[7,1,2], [4,8,5], [6,3,0]]
    depth24 = [[0,7,2], [4,6,1], [3,5,8]]

    val = int(input("Enter which board (1-8) or nothing to enter your own board: "))

    if val == 1:
        board_input = depth0
        print("solution should be at depth 0.")
        print("---------------------------")
    elif val == 2:
        board_input = depth2
        print("solution should be at depth 2.")
        print("---------------------------")
    elif val == 3:
        board_input = depth4
        print("solution should be at depth 4.")
        print("---------------------------")
    elif val == 4:
        board_input = depth8
        print("solution should be at depth 8.")
        print("---------------------------")
    elif val == 5:
        board_input = depth12
        print("solution should be at depth 12.")
        print("---------------------------")
    elif val == 6:
        board_input = depth16
        print("solution should be at depth 16.")
        print("---------------------------")
    elif val == 7:
        board_input = depth20
        print("solution should be at depth 20.")
        print("---------------------------")
    elif val == 8:
        board_input = depth24
        print("solution should be at depth 24.")
        print("---------------------------")
    else:
        board_input = []
        digits_used = []
        print("Enter digits 0-9: ")
        for i in range(3):
            row = []
            for j in range(3):
                x = int(input())
                while (x in digits_used):
                    x = int(input("Digit already used, enter another: "))
                row.append(x)
                digits_used.x
            input.append(row)  
            
    uniform_cost_search(board_input, goal_board)



def uniform_cost_search(board, goal_state):

    queue = []
    curr = Node(0, board)
    heapq.heappush(queue, curr)

    visited = { curr.boardToTuple() : 0 }


    while(True):
        # check if queue is empty
        if len(queue) == 0:
            print("no possible solution")
            return
        
        # else, pop top node from queue (node with lowest cost)
        curr = heapq.heappop(queue)

        # if top node (curr state) equals goal state
        if curr.board == goal_state:
            print("solution found: depth ", curr.cost)
            return

        # else, expand the curr node
        expand_node(curr, queue, visited)



def expand_node(curr_node, queue, visited):
    
    curr_board = curr_node.board

    for i in range(3):
        for j in range(3):
            if curr_board[i][j] == 0: # found the zero in board
                
                directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

                for d in directions:
                    if 0 <= i + d[0] <= 2 and 0 <= j + d[1] <= 2:
                        # swap
                        child_board = copy.deepcopy(curr_board)
                        
                        temp = child_board[i + d[0]][j + d[1]]
                        child_board[i + d[0]][j + d[1]] = curr_board[i][j]
                        child_board[i][j] = temp

                        
                        # make node of new board
                        child_node = Node(curr_node.cost + 1, child_board)
                        child_board_tuple = child_node.boardToTuple()

                        # check if node, with new board, exists in queue already
                        if child_board_tuple not in visited:
                            visited[child_board_tuple] = curr_node.cost + 1 # add to repeated states
                            heapq.heappush(queue, child_node) # add to the queue


main()
