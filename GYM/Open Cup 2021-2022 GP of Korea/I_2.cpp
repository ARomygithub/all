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
typedef vector<int> vi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e4;
int n;
string s[mxn];
int in[26],out[26];
int p[26],cs[26];

int find(int x) {
    return x==p[x]?x:p[x]=find(p[x]);
}

void join(int x, int y) {
    if((x=find(x))==(y=find(y))) {
        return;
    }
    if(cs[x]>cs[y]) swap(x,y);
    p[x] = y;
    cs[y] += cs[x];
}

void solve() {
    cin >>n;
    iota(p,p+26,0);
    fill(cs,cs+26,1);
    rep(i,0,n) {
        cin >>s[i]; 
        out[s[i][0]-'a']++;
        in[s[i][sz(s[i])-1]-'a']++;
        join(s[i][0]-'a',s[i][sz(s[i])-1]-'a');
    }
    rep(i,0,26) {
        if(out[i]!=in[i]) {
            cout <<"NO\n";
            return;
        }
    }
    bool ok = 1;
    rep(i,0,26) {
        rep(j,0,26) {
            if((out[i]>0 || in[i]>0) && (out[j]>0 || in[j]>0)) {
                ok &= find(i)==find(j);
                // cout <<i <<" " <<j <<'\n';
                // cout <<find(i) <<" " <<find(j) <<"\n";
            }
        }
    }
    if(ok) {
        cout <<"YES\n";
    } else {
        cout <<"NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}