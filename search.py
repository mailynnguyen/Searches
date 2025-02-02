import heapq
import copy

class Node:
    def __init__(self, board, cost, heuristic):
        self.board = board

        self.heuristic = heuristic
        self.cost = cost
        self.value = cost + heuristic

    def boardToTuple(self): # converts the board prop to a tuple
        return tuple(tuple(row) for row in self.board)

    def __lt__(self, other): # function to be able to compare two nodes, to push into heap
        return self.value < other.value

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

    while True:
        val = int(input("Enter which board (1-8) or nothing to enter your own board: "))

        if val == 1:
            board_input = depth0
            print("---------------------------")
            print("solution should be at depth 0.")
            print()
        elif val == 2:
            board_input = depth2
            print("---------------------------")
            print("solution should be at depth 2.")
            print()
        elif val == 3:
            board_input = depth4
            print("---------------------------")
            print("solution should be at depth 4.")
            print()
        elif val == 4:
            board_input = depth8
            print("---------------------------")
            print("solution should be at depth 8.")
            print()
        elif val == 5:
            board_input = depth12
            print("---------------------------")
            print("solution should be at depth 12.")
            print()
        elif val == 6:
            board_input = depth16
            print("---------------------------")
            print("solution should be at depth 16.")
            print()
        elif val == 7:
            board_input = depth20
            print("---------------------------")
            print("solution should be at depth 20.")
            print()
        elif val == 8:
            board_input = depth24
            print("---------------------------")
            print("solution should be at depth 24.")
            print()
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
                    digits_used.append(x)
                board_input.append(row)  
                
        # 1 = uniform cost search
        # 2 = a* misplaced tile
        # 3 = a* manhattan distance
        print("Search Types:")
        print("(1) Uniform Cost Search")
        print("(2) A* Misplaced Tile")
        print("(3) A* Manhattan Distance")
        print("-------------------")
        search_type = int(input("Enter (1-3): "))

        general_search(board_input, goal_board, search_type)




# GENERAL SEARCH ALGO
def general_search(board, goal_state, search_type):

    # print initial board for user to see
    print("Initial Board State:")
    for row in board:
        print(row)
    print()
        
    queue = []
    curr = Node(board, 0, 0)
    heapq.heappush(queue, curr)

    visited = { curr.boardToTuple() : 0 } # keep track of repeating states


    while(True):
        # check if queue is empty
        if len(queue) == 0:
            print("no possible solution")
            return
        
        # else, pop top node from queue (node with lowest cost)
        curr = heapq.heappop(queue)

        # if top node (curr state) equals goal state
        if curr.board == goal_state:
            print("Goal Board State:") # print goal board state for user to see
            for row in goal_state: 
                print(row)
            print()

            print("solution found: depth ", curr.cost)
            print("---------------------------")
            return

        # else, expand the curr node
        expand_node(curr, queue, visited, search_type)



def expand_node(curr_node, queue, visited, search_type):
    
    curr_board = curr_node.board

    # loop through to find the empty space (zero)
    for i in range(3):
        for j in range(3):
            if curr_board[i][j] == 0: # found the zero in board
                
                directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]

                # find all possible child boards
                for d in directions:
                    if 0 <= i + d[0] <= 2 and 0 <= j + d[1] <= 2: # if movement is possible
                        # swap
                        child_board = copy.deepcopy(curr_board)
                        
                        temp = child_board[i + d[0]][j + d[1]]
                        child_board[i + d[0]][j + d[1]] = curr_board[i][j]
                        child_board[i][j] = temp

                        # find heuristic value of child board based on search type
                        if search_type == 1: # uniform cost
                            heuristic = 0
                        elif search_type == 2: # a* misplaced tile
                            # find number of misplace tiles
                            expected_val = 1
                            heuristic = 0
                            for row in child_board:
                                for val in row:
                                    if val != expected_val: # incorrect tile
                                        heuristic += 1
                                    if expected_val == 8: # cause last tile should be value 0
                                        expected_val = 0
                                    else:
                                        expected_val += 1
                        else: # a* manhattan distance
                            heuristic = 0
                            expected_val = 1
                            for k in range(3):
                                for l in range(3):   
                                    # if incorrect tile and not the bottom-corner tile
                                    if (k != 2 or l != 2) and child_board[k][l] != expected_val: 
                                        found_correct_tile = False
                                        k1 = k
                                        l1 = l
                                        
                                        # loop through board to find correct tile
                                        while not found_correct_tile:
                                            l1 += 1 # add 1 to index in row
                                            if l1 == 3: # if overbounded in the row, jump to next row
                                                k1 += 1
                                                l1 = 0
                                            if k1 == 3: # if next row is overbounded, reset to beginning
                                                k1 = 0
                                                l1 = 0
                                            if child_board[k1][l1] == expected_val: # if expected value tile is found
                                                found_correct_tile = True
                                        
                                        # once here, expected tile should have been found
                                        # indexes of tile should be saved as well
                                        y = abs(k - k1)
                                        x = abs(l - l1)
                                        heuristic += x + y
                                        
                                    # update expected value
                                    expected_val += 1
                                            
                        # make node of new board
                        child_node = Node(child_board, curr_node.cost + 1, heuristic)
                        child_board_tuple = child_node.boardToTuple()

                        # check if node, with new board, exists in queue already
                        if child_board_tuple not in visited:
                            visited[child_board_tuple] = child_node.value # add to repeated states
                            heapq.heappush(queue, child_node) # add to the queue

                # print("heap:")
                # print("-------")
                # print("current board:")
                # for row in curr_board:
                #     print(row)
                # print("-------")
                # for item in queue:
                #     print("cost:", item.cost)
                #     print("heuristic:", item.heuristic)
                #     print("value:", item.value)
                #     for row in item.board:
                #         print(row)
                #     print()



main()




