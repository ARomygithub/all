// cases:
// best move involved goign through each other, so do something else.  (possible?)

// multiple good ways to go with different #'s of bumps
// best solution has more bumps than some worse solution
//best solution has 2 robots collide at exit position
// a correct path goes horizontally (vertically) through (r,c) but a wall goes
// vertically (horizontally) though that coordinate
// a board with an inaccessible "box" in it that still has a solution, but you
// have to go around the box
// 2 robots chasing each other around the maze is ok, won't cause collisions
#include <iostream>
#include <vector>
using namespace std;


struct state{
  int bot1r;
  int bot1c;
  char bot1dir;
  int bot2r;
  int bot2c;
  char bot2dir;
  int bumps;
  int moves;
  bool operator==(const state& s){  // everything but bumps and moves
    return bot1r==s.bot1r &&
      bot1c == s.bot1c &&
      bot1dir == s.bot1dir &&
      bot2r == s.bot2r &&
      bot2c == s.bot2c &&
      bot2dir == s.bot2dir;
  }
  
};

struct edge{
  int r;
  int c;

  char dir;
};

struct one_robot_state{
  int r;
  int c;
  int moves;
};

int Find_Smallest(const vector<state>& queue){
  int smallest_pos = 0;
  int smallest_moves = queue[0].moves;
  int smallest_bumps = queue[0].bumps;
  for(int i = 1; i < queue.size(); i++){
    if(queue[i].moves < smallest_moves ||
       (queue[i].moves == smallest_moves && queue[i].bumps < smallest_bumps)){
      smallest_pos = i;
      smallest_moves = queue[i].moves;
      smallest_bumps = queue[i].bumps;
    }
  }
  return smallest_pos;
}

char Turn_Left(char dir){
  if(dir == 'N')
    return 'W';
  if(dir == 'W')
    return 'S';
  if(dir == 'S')
    return 'E';
  if(dir == 'E')
    return 'N';
}

char Turn_Right(char dir){
  if(dir == 'N')
    return 'E';
  if(dir == 'E')
    return 'S';
  if(dir == 'S')
    return 'W';
  if(dir == 'W')
    return 'N';
}

bool Find(state key, const vector<state>& v){
  for(int i = 0; i < v.size(); i++)
    if(key == v[i])
      return true;
  return false;
}

bool Can_Move_North(int r, int c, const vector<edge>& walls, int rows, int cols){
  if(r == rows) // already at max
    return false;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'H' && walls[i].r == r && walls[i].c == c)
      return false;
  }
  return true;
}

bool Can_Move_South(int r, int c, const vector<edge>& walls, int rows, int cols, int exit_col){
  if(r== 1 && c != exit_col)
    return false;
  if(r == 1 && c == exit_col)
    return true;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'H' && walls[i].r == r-1 && walls[i].c == c)
      return false;
  }
  return true;
}

bool Can_Move_East(int r, int c, const vector<edge>& walls, int rows, int cols){
  if(c == cols)
    return false;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'V' && walls[i].r == r && walls[i].c == c)
      return false;
  }
  return true;
}

bool Can_Move_West(int r, int c, const vector<edge>& walls, int rows, int cols){
  if(c == 1)
    return false;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'V' && walls[i].r == r && walls[i].c == c-1)
      return false;
  }
  return true;
}
		   
    
void Move_Forward(state cur, state& dest, vector<edge>& walls, int rows, int cols, int exit_col){
  if(cur.bot1dir == 'N')
    if(Can_Move_North(cur.bot1r, cur.bot1c, walls, rows, cols))
      dest.bot1r++;
    else
      dest.bumps++;
  if(cur.bot2dir == 'N')
    if(Can_Move_North(cur.bot2r, cur.bot2c, walls, rows, cols))
      dest.bot2r++;
    else
      dest.bumps++;
  if(cur.bot1dir == 'S')
    if(Can_Move_South(cur.bot1r, cur.bot1c, walls, rows, cols, exit_col))
      dest.bot1r--;
    else
      dest.bumps++;
  if(cur.bot2dir == 'S')
    if(Can_Move_South(cur.bot2r, cur.bot2c, walls, rows, cols, exit_col))
      dest.bot2r--;
    else
      dest.bumps++;
  if(cur.bot1dir == 'E')
    if(Can_Move_East(cur.bot1r, cur.bot1c, walls, rows, cols))
      dest.bot1c++;
    else
      dest.bumps++;
  if(cur.bot2dir == 'E')
    if(Can_Move_East(cur.bot2r, cur.bot2c, walls, rows, cols))
      dest.bot2c++;
    else
      dest.bumps++;
  if(cur.bot1dir == 'W')
    if(Can_Move_West(cur.bot1r, cur.bot1c, walls, rows, cols))
      dest.bot1c--;
    else
      dest.bumps++;
  if(cur.bot2dir == 'W')
    if(Can_Move_West(cur.bot2r, cur.bot2c, walls, rows, cols))
      dest.bot2c--;
    else
      dest.bumps++;
}
	

int Find_Exit(int r, int c, const vector<edge>& walls, int exit_col, int rows, int cols){
  // This is more straight BFS
  vector<one_robot_state> q;
  one_robot_state start;
  start.r = r;
  start.c = c;
  start.moves = 0;
  q.push_back(start);
  while(q.size() > 0){
    one_robot_state cur = q[0];
    if(cur.r == 0)
      return cur.moves;
    q.erase(q.begin());
    one_robot_state next = cur;
    next.moves = cur.moves+1;
    if(Can_Move_North(cur.r, cur.c, walls, rows, cols)){
      next.r = cur.r+1;
      q.push_back(next);
      next.r = cur.r;
    }
    
    if(Can_Move_South(cur.r, cur.c, walls, rows, cols, exit_col)){
	next.r = cur.r-1;
	q.push_back(next);
	next.r = cur.r;
    }
    if(Can_Move_East(cur.r, cur.c, walls, rows, cols)){
      next.c = cur.c+1;
      q.push_back(next);
      next.c = cur.c;
    }
    if(Can_Move_West(cur.r, cur.c, walls, rows, cols)){
      next.c = cur.c-1;
      q.push_back(next);
      next.c = cur.c;
    }
  }
  // if we get here we couldn't reach the exit
  cout << "Error: No path to exit from (" << start.r << "," << start.c << ")" << endl;
}
     
int main(){
  int c, r, e;
  cin >> c >> r >> e;

  state start_state;
  cin >> start_state.bot1c >> start_state.bot1r >> start_state.bot1dir
      >> start_state.bot2c >> start_state.bot2r >> start_state.bot2dir;
  start_state.bumps = 0;
  start_state.moves = 0;

  vector<edge> walls;
  int h;
  cin >> h;
  for(int i = 0; i < h; i++){
    edge cur;
    cin >> cur.c>> cur.r;
    cur.dir = 'H';
    walls.push_back(cur);
  }
  int v;
  cin >> v;
  for(int i = 0; i < v; i++){
    edge cur;
    cin >> cur.c >> cur.r;
    cur.dir = 'V';
    walls.push_back(cur);
  }
  
  vector<state> queue;
  vector<state> seen;
  queue.push_back(start_state);
  seen.push_back(start_state);

  
  bool bot1_out = false;
  bool bot2_out = false;
  int best_moves = r*c*4;
  int best_bumps = r*c*4;
  bool queue_is_useful = true;
  while(queue.size() > 0){
    // I should keep this queue sorted, we'll see if it matters for now
    int pos = Find_Smallest(queue); // do I even need this?
    state cur = queue[pos];

    //   cout << "Considering bot1:("<<cur.bot1c << "," << cur.bot1r << ")" << cur.bot1dir << ", bot2:(" << cur.bot2c << "," << cur.bot2r << ")" << cur.bot2dir << endl;
    //   cout << cur.moves << endl;
    queue[pos] = queue[queue.size()-1];
    queue.pop_back();
    if(cur.moves <= best_moves){
      

      // turn left
      state left_state = cur;
      left_state.bot1dir = Turn_Left(cur.bot1dir);
      left_state.bot2dir = Turn_Left(cur.bot2dir);
      if(!Find(left_state, seen)){
	seen.push_back(left_state);
	queue.push_back(left_state);
      }

      // turn right
      state right_state = cur;
      right_state.bot1dir = Turn_Right(cur.bot1dir);
      right_state.bot2dir = Turn_Right(cur.bot2dir);
      if(!Find(right_state, seen)){
	seen.push_back(right_state);
	queue.push_back(right_state);
      }

      // move forward- the only way we can bump, add to moves,
      // or exit the maze
      state forward_state = cur;
      forward_state.moves = cur.moves+1;
      // This function checks if we've hit an exit
      Move_Forward(cur, forward_state, walls, r,c,e);
      if((forward_state.bot1r != forward_state.bot2r) ||
	 (forward_state.bot1c != forward_state.bot2c)){ // avoid collisions
	if(forward_state.bot1r == 0){
	  int cur_moves = forward_state.moves;
	  int cur_bumps = forward_state.bumps;
	  int remaining_moves = Find_Exit(forward_state.bot2r, forward_state.bot2c, walls, e, r, c);
	  cur_moves += remaining_moves;
	  if(cur_moves < best_moves || (cur_moves == best_moves && cur_bumps < best_bumps)){
	    best_moves = cur_moves;
	    best_bumps = cur_bumps;
	  }
	}
	
	else if(forward_state.bot2r == 0){
	  int cur_moves = forward_state.moves;
	  int cur_bumps = forward_state.bumps;
	  int remaining_moves = Find_Exit(forward_state.bot1r, forward_state.bot1c, walls, e, r, c);
	  cur_moves += remaining_moves;
	  if(cur_moves < best_moves || (cur_moves == best_moves && cur_bumps < best_bumps)){
	    best_moves = cur_moves;
	    best_bumps = cur_bumps;
	  }
	}
	
	else if(!Find(forward_state, seen)){
	  seen.push_back(forward_state);
	  queue.push_back(forward_state);
	}
      }
    }
  }
  cout << best_moves << " " << best_bumps << endl;
  return 0;
}
