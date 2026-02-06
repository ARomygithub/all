#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int MAXN = 200001;
int last_row[MAXN], last_col[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // memset(last_row, MAXN+1, sizeof(last_row));
    // memset(last_col, MAXN+1, sizeof(last_col));
    for(int i=1; i<MAXN; i++){
        last_row[i] = MAXN+1;
        last_col[i] = MAXN+1;
    }
    last_row[0] = 0;
    last_col[0] = 0;
    int n,m,k;
    // cout << last_row[1] << '\n';
    cin >> n >> m >> k;
    while(k--){
        int x,y;
        cin >> x >> y;
        last_row[n-x] = min(m-y, last_row[n-x]);
        last_col[m-y] = min(n-x, last_col[m-y]);
    }
    // cout << last_row[0] << last_row[1] << last_row[2] << '\n';
    int max_row = 1;
    int max_col = 1;
    while(max_row < n && max_col < m){
        if(last_row[max_row] < max_col || last_col[max_col] < max_row){
            // WIN at max_row,max_col
            bool add_row = false, add_col = false;
                // cout << last_row[max_row] << " " << max_row << " " ;
            if(last_row[max_row] <= max_col){
                add_row = true;
            }
                // cout << last_col[max_col] << " " << max_col;
            if(last_col[max_col] <= max_row){
                add_col = true;
            }
            if(add_row) max_row++;
            if(add_col) max_col++;
        }else{
            //LOSE at max_row,max_col
            last_row[max_row] = max_col;
            last_col[max_col] = max_row;
            max_row++;
            max_col++;
        }
        // cout << last_row[max_row] << " " << last_col[max_col] << '\n';
    }
    if(max_row < n || max_col < m) cout << "Chaneka\n";
    else{
        if(last_row[max_row-1] < max_col-1 || last_col[max_col-1] < max_row-1) {
            cout << "Chaneka\n";
            // cout << max_row << " " << last_row[max_row] << " " << max_col << " " << last_col[max_col] << '\n';
        }
        else cout << "Bhinneka\n";
    }
}