# Search

### To Run:

1. Clone the repo on your terminal
2. Load VSCode and type ``python search.py`` in your terminal

### Summary

Three algorithms (Uniform Cost Search, A* Misplaced Tiles Search, and A* Manhattan Distance) to find the solution of a 3x3 tile game. Uniform Cost Search will choose the next move based on its "cost" i.e. how much effort did it take to that move into a new position. In this case, since everyone move of a 3x3 tile game uses the same amount of effort, the cost is 1 everyone. So the Uniform Cost Search in this case is simply Breadth First Search.

A* algorithms uses a heuristic (the merit of the board). In my case, I used the heuristic Misplaced Tiles (the merit/value of the board is the number of tiles in their correct position) and Manhattan Distance (the merit/value of the board is based on the sum of the number of moves each tile is away from its correct position.
