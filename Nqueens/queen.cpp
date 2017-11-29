#include <iostream>
#include <vector>

using namespace std;
/****
 * n Queens to be arranged on an n x n chessboard
 * so they do not attack each other
 *
 * Recursion with backtracking
 * for n = 8, backtracking reduces the search space 
 *            from 64 C 8 to a max of 105 depending on staring row index!!
 *
 *******/

class Q {
public:
  Q(int n): board(n, vector<bool>(n, false)),
	    rowNo(n, n + 99), tries(0) {
  }
  
  ~Q() {};
  
  void debug(string desc = "");
  void placeThisQueen(int currRow, int col);
  void removeThisQueen(int currRow, int col);
  bool isSafe(int currRow, int col);
  bool solveNqueens(int startRow = 0, int col = 0);
  
private:
  
  vector<vector<bool>> board;
  vector<int> rowNo; // row idx of queens in each column
  int tries;
};

void Q::debug(string desc) {

  cout << desc << endl;
  for(int row = 0; row < board.size(); ++row) {
    cout << string(rowNo.size() * 4, '-') << endl;
    cout << "| ";
    for(int col = 0; col < board[0].size(); ++col) {
      if(board[row][col] == true)
	cout << "X" << " | ";
      else
	cout << " " << " | ";
    }
    cout << endl;
  }
  cout << string(rowNo.size() * 4, '-') << endl;
  cout << string(rowNo.size() * 4, '_') << endl;

}

bool Q::isSafe(int currRow, int col) {

  for(int colNo = 0; colNo < rowNo.size(); ++colNo) {
    //are the rows same?
    if(rowNo[colNo] == currRow) return false;
    //is it on same diagonal?
    if(abs(col - colNo) == abs(rowNo[colNo] - currRow)) return false;
    // no need to check column, backtracking deals with it.
  }
  return true;
}

void Q::placeThisQueen(int currRow, int col) {
  
  rowNo[col] = currRow;
  board[currRow][col] = true;
  debug("PLACE:[" + to_string(currRow) + "][" + to_string(col) + "]");
}

void Q::removeThisQueen(int currRow, int col) {
  ++tries;
  rowNo[col] = rowNo.size() + 99;
  board[currRow][col] = false;
  debug("REMOVE:[" + to_string(currRow) + "][" + to_string(col) + "]");
}

bool Q::solveNqueens(int startRow, int col) {
  
  if(col == board[0].size()) {
    cout << "Tries: " << tries << endl;
    return true;
  }
  int endRow = board.size();
  for(int currRow = startRow; currRow < endRow; ++currRow) {
    if(isSafe(currRow, col)) {
      placeThisQueen(currRow, col);
      if(solveNqueens(0, col + 1) == true) return true;
      removeThisQueen(currRow, col);
    }
    if(startRow != 0 && currRow == endRow - 1) {
      currRow = 0; endRow = startRow;
    }
  }
  return false; // backtrack -->if no row works for current queen
}

int main() {
  cout << "Enter number of queens: " << endl;
  int n, m;
  cin >> n;
  cout << "Enter first queen's position in column 1 (row no): " << endl;
  cin >> m;
  cout << "SOL: " << endl;
  Q q(n);
  q.solveNqueens(m > n ? n - 1 : m - 1 > 0 ? m - 1 : 0);

}
