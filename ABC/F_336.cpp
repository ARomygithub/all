#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=8;
int n,m;

vector<vector<int>> op(vector<vector<int>>& b, int tp) {
    int x = tp&1;
    int y = (tp>>1)&1;
    vector<vector<int>> ans(sz(b), vector<int>(sz(b[0])));
    // cout <<"op 0\n" <<flush;
    rep(i,0,n) {
        rep(j,0,m) {
            if(i>=x && i<x+n-1 && j>=y && j<y+m-1) {
                // cout <<i <<" " <<j <<" " <<n-1-(i-x)+x <<" " <<m-1-(j-y)+y <<"\n" <<flush;
                ans[i][j] = b[n-2-(i-x)+x][m-2-(j-y)+y];
            } else {
                ans[i][j] = b[i][j];
            }
        }
    }
    // cout <<"op 1\n" <<flush;
    return ans;
}

bool same(vector<vector<int>>& a,const vector<vector<int>>& b) {
    rep(i,0,sz(a)) {
        rep(j,0,sz(a[0])) {
            if(a[i][j]!=b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> fromTo(const vector<vector<int>>& a, vector<vector<int>>& b) {
    vector ret(sz(a), vector<int>(sz(a[0])));
    map<int,int> mpa;
    rep(i,0,sz(a)) {
        rep(j,0,sz(a[0])) {
            mpa[a[i][j]] = i*m+j;
        }
    }
    rep(i,0,sz(a)) {
        rep(j,0,sz(a[0])) {
            int temp = mpa[b[i][j]];
            ret[i][j] = temp;
        }
    }
    return ret;
}

void deb(vector<vector<int>>& b) {
    rep(i,0,sz(b)) {
        rep(j,0,sz(b[0])) {
            cout <<b[i][j] <<" \n"[j==sz(b[0])-1];
        }
    }
    cout <<flush;
}

void solve() {
    cin >>n >>m;
    vector s(n, vector(m,0));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >>s[i][j]; s[i][j]--;
        }
    }
    map<vector<vector<int>>, int> mp;
    vector a(n, vector(m,0));
    rep(i,0,n) {
        rep(j,0,m) {
            a[i][j] = i*m+j;
        }
    }
    mp[a] = 0;
    queue<vector<vector<int>>> q;
    q.push(a);
    rep(i,0,10) {
        // cout <<i+1 <<"\n" <<flush;
        queue<vector<vector<int>>> q2;
        while(sz(q)) {
            auto b = q.front(); q.pop();
            rep(j,0,4) { 
                auto bi = op(b,j);
                if(!mp.count(bi)) {
                    mp[bi] = i+1;
                    // deb(bi);
                    q2.push(bi);
                }
            }
        }
        q.swap(q2);
    }
    int ans=100;
    for(auto [v,d]: mp) {
        if(same(s,v)) {
            min_self(ans, d);
        } else {
            auto v2 = fromTo(v,s);
            if(mp.count(v2)) {
                min_self(ans, d+mp[v2]);
            }
        }
    }
    if(ans==100) {
        cout <<"-1\n";        
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}