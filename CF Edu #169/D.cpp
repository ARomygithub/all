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
#define all(x) (x).begin(), (x).end()

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,q,t;
int st[mxn];

void solve() {
    cin >>n >>q;
    vector<vi> id(16);
    map<char,int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;
    rep(i,0,n) {
        string s; cin >>s;
        int sti = 0;
        for(char c: s) {
            sti += 1<<mp[c];
        }
        st[i] = sti;
        id[sti].push_back(i);
    }
    while(q--) {
        int x,y; cin >>x >>y; x--,y--;
        if(x==y) {
            cout <<"0\n";
        } else if((st[x]&st[y])) {
            cout <<abs(x-y) <<"\n";
        } else {
            bool ok = 0;
            int ans = 1e9;
            if(x>y) swap(x,y);
            rep(sti,0,16) {
                if(!sz(id[sti])) continue;
                if(__builtin_popcount(sti)==2) {
                    if((sti&st[x]) && (sti&st[y])) {
                        auto it = upper_bound(id[sti].begin(),id[sti].end(),x);
                        if(it!=id[sti].end()) {
                            if((*it)<y) {
                                ok = 1;
                                ans = 0;
                            } else {
                                ok = 1;
                                min_self(ans, ((*it)-y)*2);
                            }
                        }
                        it = lower_bound(id[sti].begin(),id[sti].end(), x);
                        if(it!=id[sti].begin()) {
                            it--;
                            ok = 1;
                            min_self(ans, (x-(*it))*2);
                        }
                    }
                }
            }
            if(ok) {
                cout <<abs(y-x)+ans <<"\n";
            } else {
                cout <<"-1\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    while(t--) {
        solve();
    }
}