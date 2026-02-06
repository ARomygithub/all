#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while(T--) {
        int n; cin >> n;
        bool circ[21][360] = {}; // circ[r][a] blocks crossing between r-1 and r at angle a
        bool rad[20][360]  = {}; // rad[annulus][angle] blocks crossing radial line 'angle' within that annulus
        for(int i=0;i<n;i++){
            char tp; cin >> tp;
            if(tp=='C'){
                int r,a,b; cin >> r >> a >> b;
                int x=a;
                while(x!=b){
                    circ[r][x]=true;
                    x = (x+1)%360;
                }
            }else{
                int r1,r2,th; cin >> r1 >> r2 >> th;
                for(int r=r1;r<r2;r++) rad[r][th]=true;
            }
        }
        vector<vector<char>> vis(20, vector<char>(360,0));
        queue<pair<int,int>> q;
        for(int a=0;a<360;a++){
            vis[0][a]=1;
            q.emplace(0,a);
        }
        auto push=[&](int r,int a){
            if(!vis[r][a]){ vis[r][a]=1; q.emplace(r,a); }
        };
        while(!q.empty()){
            auto [r,a]=q.front(); q.pop();
            if(r<19 && !circ[r+1][a]) push(r+1,a);
            if(r>0  && !circ[r][a])   push(r-1,a);
            int cw=(a+1)%360;
            if(!rad[r][cw]) push(r,cw);
            int ccw=(a+359)%360;
            if(!rad[r][a]) push(r,ccw);
        }
        bool ok=false;
        for(int a=0;a<360;a++){
            if(vis[19][a] && !circ[20][a]) { ok=true; break; }
        }
        cout << (ok?"YES\n":"NO\n");
    }
    return 0;
}