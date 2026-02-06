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

const int mxn=1e5;
int n;

void solve() {
    cin >>n;
    int m=1;
    while((1<<m)<n) {
        m++;
    }
    vector<vector<int>> v(m);
    int id=1;
    map<string,int> mp;
    rep(i,0,(1<<m)) {
        string s = "";
        rep(j,0,m) {
            if((i>>j)&1) {
                v[j].push_back(id);
                s +='1';
            } else {
                s +='0';
            }
        }
        mp[s] = id;
        id++;
        if(id>n) break;
    }
    cout <<m <<"\n" <<flush;
    rep(i,0,m) {
        cout <<sz(v[i]) <<" ";
        rep(j,0,sz(v[i])) {
            cout <<v[i][j] <<" \n"[j==sz(v[i])-1];
        }
    }
    cout <<flush;
    string sin; cin >>sin;
    cout <<mp[sin] <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}