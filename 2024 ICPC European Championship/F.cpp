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
typedef pair<int,set<int>> pis;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m;

void solve() {
    cin >>n >>m;
    vector<pii> va;
    vector<set<int>> st(n);
    vector<set<int>> mp(m+1);
    rep(i,0,n) {
        int pi; cin >>pi;
        rep(j,0,pi) {
            int ki; cin >>ki;
            st[i].insert(ki);
        }
        if(pi>=2) {
            va.push_back({pi,i});
        }
    }
    rep(i,0,sz(va)) {
        auto& [szi,id] = va[i];
        for(auto bi: st[id]) {
            mp[bi].insert(id);
        }
    }
    sort(va.begin(), va.end());
    rep(i,0,sz(va)) {
        auto& [szi, id] = va[i];
        // cout <<"id " <<id <<endl;
        int bi1 = *st[id].begin();
        int mx = sz(mp[bi1]);
        int mxbi= bi1,mnbi=bi1;
        // cout <<mx <<" ";
        for(auto it = ++st[id].begin(); it!=st[id].end();it++) {
            int bi = *it;
            int szmp = sz(mp[bi]);
            // cout <<szmp <<" ";
            if(szmp != mx) {
                if(szmp>mx) {
                    mnbi = mxbi;
                    mxbi = bi;
                } else {
                    mnbi = bi;
                }
                auto& mpxbi = mp[mxbi];
                auto& mpnbi = mp[mnbi];
                for(auto id2 : mpxbi) {
                    if(!mpnbi.count(id2)) {
                        cout <<"YES\n";
                        cout <<id+1 <<" " <<id2+1 <<"\n";
                        return;
                    }
                }
                assert(false);
            }
        }
        // cout <<"\n";
        for(auto it = st[id].begin(); it!=st[id].end(); it++) {
            mp[*it].erase(id);
        }
    }
    cout <<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}