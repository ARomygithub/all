#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAX = 2000000;
int last_row[MAX], last_col[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(last_row, MAX+1, sizeof(last_row));
    memset(last_col, MAX+1, sizeof(last_col));
    last_row[0] = 0;
    last_col[0] = 0;
    int n,m,k;
    cin >> n >> m >> k;
    while(k--){
        int x,y;
        cin >> x >> y;
        last_row[n-x] = min(m-y, last_row[n-x]);
        last_row[m-y] = min(n-x, last_col[m-y]);
    }
    int max_row = 1;
    int max_col = 1;
    while(max_row < n-1 && max_col < m-1){
        if(last_row[max_row] < max_col || last_col[max_col] < max_row){
            // WIN at max_row,max_col
            if(last_row[max_row] <= max_col){
                max_row++;
            }
            if(last_col[max_col] <= max_row){
                max_col++;
            }
        }else{
            //LOSE at max_row,max_col
            last_row[max_row] = max_col;
            last_col[max_col] = max_col;
            max_row++;
            max_col++;
        }
    }
    if(max_row < n-1 || max_col < m-1) cout << "Chaneka\n";
    else{
        if(last_row[max_row] < max_col || last_col[max_col] < max_row) cout << "Bhinneka\n";
    }
}