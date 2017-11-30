
/*
 * Generic Backtracking algorithm
 *
 */

bool solve(choice c) {

  if(no more choices) {
    return (conf is goal solution )
  }
  for(each available choices for this iteration) {
    make choice c;
    if(solve(choice c) returns goal solution, return true;
    un-make choice c;   
  }
    return false;
}


