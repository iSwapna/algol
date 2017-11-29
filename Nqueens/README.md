Algorithm:
	Recursive method with backtracking for N queens
	
	1. Place k-th queen of N on a safe row in the next available column
	2. Try to find a safe solution by trying all combinations
	   further down for k + 1 -th to N-th queens and columns. 
	3. If all of the k + 1 -th result in a conflict further down,
	   4. Backtrack k-th choice
	   5. increment k-th choice to next safe choice --> step 1.

	6. return safe choice found / not found
	
Results in res.txt
------------------


Run (1):

Place 19 queens on a 19 x 19 chessboard. Start at row 19

Run (2):

Place 5 queens on 5 x 5 chessboard. Start at row 3

Run (3):

Place 6 queens on a 6 x 6 chessboard. Start at row 4. 
All interim states of the board printed out. 
