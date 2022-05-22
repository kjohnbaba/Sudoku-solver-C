# Sudoku-solver-C

Checks whether a proposed Sudoku solution is correct and checks whether a partially-solved Sudoku puzzle with one unknown square can be solved. sudoku
takes a single argument, which is the path to a file containing a completed or almost-completed
Sudoku puzzle.

1) sudoku will be given a completed Sudoku puzzle, determine whether the solution is correct,
and print either correct or incorrect.
2) sudoku will be given an almost-complete Sudoku puzzle, determine whether the partial
solution can be solved, and print either solvable or unsolvable.

The input file
file1.txt corresponding to the puzzle above would contain something like:

534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179

for correctness checking and for solvability checking contains an almost-completed puzzle with one or two unknown entries like:

435269781
682571493
1978345 2
826195347
374682915
951743628
519 26874
248957136
763418259



