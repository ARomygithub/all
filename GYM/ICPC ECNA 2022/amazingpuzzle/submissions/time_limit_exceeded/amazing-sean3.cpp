#include <iostream>
#include <vector>
#include <deque>

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
  string history;
  bool operator==(const state& s){  // everything but bumps and moves
    return bot1r==s.bot1r &&
      bot1c == s.bot1c &&
      bot2r == s.bot2r &&
      bot2c == s.bot2c;
     
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

int Direction_Number(char dir){
  if(dir == 'N')
    return 0;
  if(dir == 'E')
    return 1;
  if(dir == 'S')
    return 2;
  if(dir == 'W')
    return 3;
}

bool Can_Move_North(int r, int c, const vector<edge>& walls, int rows, int cols){
  if(r >= rows) // already at max
    return false;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'H' && walls[i].r == r && walls[i].c == c)
      return false;
  }
  return true;
}

bool Can_Move_South(int r, int c, const vector<edge>& walls, int rows, int cols, int exit_col){
  if(r <= 0)
    cout << "What?" << endl;
  
  if(r == 1 && c == exit_col)
    return true;
  if(r<= 1 && c != exit_col)
    return false;

  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'H' && walls[i].r == r-1 && walls[i].c == c)
      return false;
  }
  return true;
}

bool Can_Move_East(int r, int c, const vector<edge>& walls, int rows, int cols){
  if(c >= cols)
    return false;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'V' && walls[i].r == r && walls[i].c == c)
      return false;
  }
  return true;
}

bool Can_Move_West(int r, int c, const vector<edge>& walls, int rows, int cols){
  if(c <= 1)
    return false;
  for(int i = 0; i < walls.size(); i++){
    if(walls[i].dir == 'V' && walls[i].r == r && walls[i].c == c-1)
      return false;
  }
  return true;
}

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

int Find_Exit(int r, int c, const vector<edge>& walls, int exit_col, int rows, int cols){
  // This is more straight BFS
  vector<one_robot_state> q;
  one_robot_state start;
  start.r = r;
  start.c = c;
  start.moves = 0;
  q.push_back(start);
  vector<vector<bool> > seen(rows+1);
  for(int i = 0; i < seen.size(); i++)
    seen[i].resize(cols+1, false);
  
  while(q.size() > 0){
    one_robot_state cur = q[0];
    // cout << "--Finding exit: moves: " << cur.moves << "(" << cur.r << "," << cur.c << ")" << endl;
    if(cur.r == 0)
      return cur.moves;
    
    
      q.erase(q.begin());
      if(!seen[cur.r][cur.c]){
	seen[cur.r][cur.c] = true;
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
  }
    // if we get here we couldn't reach the exit
  cout << "Error: No path to exit from (" << start.r << "," << start.c << ")" << endl;
}

bool Find(state key, const vector<state>& v){
  for(int i = 0; i < v.size(); i++)
    if(key == v[i])
      return true;
  return false;
}


	
// updates my_state with a move for bot1 in "bot1dir" and for bot2 in "bot2dir"
// returns true if succesful, false otherwise
bool Move(state& my_state, int bot1dir, int bot2dir, vector<vector<vector<vector<bool> > > >& seen, const vector<edge>& walls, int rows, int cols, int exit_col){
  int oldr1 = my_state.bot1r;
  int oldr2 = my_state.bot2r;
  int oldc1 = my_state.bot1c;
  int oldc2 = my_state.bot2c;
  string hist = my_state.history;
  my_state.moves++;
  
  if(bot1dir == 0){
    my_state.history = hist + "N";
    if(Can_Move_North(my_state.bot1r, my_state.bot1c, walls, rows, cols)){
      my_state.bot1r++;
    }
    else
      my_state.bumps++;
  }
  if(bot2dir == 0){
    if(Can_Move_North(my_state.bot2r, my_state.bot2c, walls, rows, cols))
      my_state.bot2r++;
    else
      my_state.bumps++;
  }
  if(bot1dir == 1){
    my_state.history = hist + "E";
    if(Can_Move_East(my_state.bot1r, my_state.bot1c, walls, rows, cols))
      my_state.bot1c++;
    else
      my_state.bumps++;
  }
  if(bot2dir == 1){
    if(Can_Move_East(my_state.bot2r, my_state.bot2c, walls, rows, cols))
      my_state.bot2c++;
    else
      my_state.bumps++;
  }
  if(bot1dir == 2){
    my_state.history = hist + "S";
    if(Can_Move_South(my_state.bot1r, my_state.bot1c, walls, rows, cols, exit_col))
      my_state.bot1r--;
    else
      my_state.bumps++;
  }
  if(bot2dir == 2){

    if(Can_Move_South(my_state.bot2r, my_state.bot2c, walls, rows, cols, exit_col))
      my_state.bot2r--;
    else
      my_state.bumps++;
  }
  if(bot1dir == 3){
    my_state.history = hist + "W";
    if(Can_Move_West(my_state.bot1r, my_state.bot1c, walls, rows, cols))
      my_state.bot1c--;
    else
      my_state.bumps++;
  }
  if(bot2dir == 3){
    if(Can_Move_West(my_state.bot2r, my_state.bot2c, walls, rows, cols))
      my_state.bot2c--;
    else
      my_state.bumps++;
  }

  // now to see if this is legal
  if(my_state.bot1r == my_state.bot2r && my_state.bot1c == my_state.bot2c)
    return false; // collision
  if(my_state.bot1r == oldr2 && my_state.bot1c == oldc2 &&
     my_state.bot2r == oldr1 && my_state.bot2c == oldc1)
    return false; // collision

  if(seen[my_state.bot1r][my_state.bot1c][my_state.bot2r][my_state.bot2c])
    return false; // repeat state
  // otherwise, this looks good
  seen[my_state.bot1r][my_state.bot1c][my_state.bot2r][my_state.bot2c] = true;
  return true;
}



int main(){
  int c,r,e;
  cin >> c >> r >> e;

  state start_state;
  cin >> start_state.bot1c >> start_state.bot1r >> start_state.bot1dir
      >> start_state.bot2c >> start_state.bot2r >> start_state.bot2dir;
  start_state.bumps = 0;
  start_state.moves = 0;

  int offset; //number of clockwise turns bot2's facing is from bot1
  offset = Direction_Number(start_state.bot2dir)-Direction_Number(start_state.bot1dir);
  if(offset < 0)
    offset = offset + 4;
  
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
  
  deque<state> my_queue;
  vector<vector<vector<vector<bool> > > >  seen(r+1);
  for(int i = 0; i < seen.size(); i++){
    seen[i].resize(c+1);
    for(int j = 0; j < seen[i].size(); j++){
      seen[i][j].resize(r+1);
      for(int k = 0; k < seen[i][j].size(); k++)
	seen[i][j][k].resize(r+1);
    }
  }
  

  my_queue.push_back(start_state);
  seen[start_state.bot1r][start_state.bot1c][start_state.bot2r][start_state.bot2c] = true;

  bool bot1_out = false;
  bool bot2_out = false;
  int best_moves = r*c*4;
  int best_bumps = r*c*4;
  bool queue_is_useful = true;

  while(my_queue.size() > 0){
   
    state cur = my_queue.front();
    my_queue.pop_front();

    //   cout << "Considering bot1:("<<cur.bot1c << "," << cur.bot1r << ")" << cur.bot1dir << ", bot2:(" << cur.bot2c << "," << cur.bot2r << ")" << cur.bot2dir << endl;
    //    cout << "moves: " << cur.moves << " size: " << my_queue.size() << " best: " << best_moves << "(" << cur.bot1r << "," << cur.bot1c << ")  (" << cur.bot2r << "," << cur.bot2c << endl;
    
   
   
    for(int i = 0; i <= 3; i++){
      state next_state = cur;
      // true if next state is legal and unseen
      if(Move(next_state, i, (i+offset)%4, seen, walls, r, c, e)){
	
	if(next_state.bot1r == 0){  // bot 1 has left the maze
	  int cur_moves = next_state.moves;
	  int cur_bumps = next_state.bumps;
	  int remaining_moves = Find_Exit(next_state.bot2r, next_state.bot2c, walls, e, r, c);
	  cur_moves += remaining_moves;
	  if(cur_moves < best_moves || (cur_moves == best_moves && cur_bumps < best_bumps)){
	    
	    best_moves = cur_moves;
	    best_bumps = cur_bumps;
	    //   cout << "New best found: " << best_moves << "," << best_bumps << " " << next_state.history << endl;
	  }
	}
	else if(next_state.bot2r == 0){ // bot 2 has left the maze
	  int cur_moves = next_state.moves;
	  int cur_bumps = next_state.bumps;
	  int remaining_moves = Find_Exit(next_state.bot1r, next_state.bot1c, walls, e, r, c);
	  cur_moves += remaining_moves;
	  if(cur_moves < best_moves || (cur_moves == best_moves && cur_bumps < best_bumps)){
	    
	    best_moves = cur_moves;
	    best_bumps = cur_bumps;
	    //   cout << "New best found: " << best_moves << "," << best_bumps << " " << next_state.history << endl;
	  }
	}
	else
	  my_queue.push_back(next_state);
      }
    }
  }

  cout << best_moves << " " << best_bumps << endl;
  return 0;
}

      
      
