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

const int mxn=2e3;
int n,l,r;
int sg[mxn+1];

pii getMove() {
    int x,y;
    cin >>x >>y;
    return {x,y};
}

void doMove(int x, int y) {
    cout <<x <<" " <<y <<"\n";
    cout <<flush;
}

void solve() {
    cin >>n >>l >>r;
    if(l==r) {
        rep(i,l,n+1) {
            set<int> s;
            rep(j,0,i-l+1) {
                s.insert(sg[j]^sg[i-l-j]);
            }
            int mex = 0;
            for(auto si: s) {
                if(si==mex) {
                    mex++;
                } else {
                    break;
                }
            }
            sg[i] = mex;
        }
        set<pii> st;
        st.insert({1,n});
        int sgg = sg[n];
        auto simulate = [&](pii res) -> void {
            auto it = st.upper_bound({res.fi, (int)(1e9)}); it--;
            auto [le, ri] = *it;
            sgg ^= sg[ri-le+1];
            st.erase(it);
            if(res.fi>le) {
                sgg ^=sg[res.fi-le];
                st.insert({le,res.fi-1});
            }
            if(res.fi+res.se-1< ri) {
                sgg ^= sg[ri-(res.fi+res.se-1)];
                st.insert({res.fi+res.se, ri});
            }
        };
        auto findMove = [&]() -> pii {
            for(auto [le,ri]: st) {
                rep(i,le,ri-l+2) {
                    int sggn = sgg^sg[ri-le+1];
                    int sl = i-le, sr = ri-(i+l-1);
                    sggn = sggn^sg[sl]^sg[sr];
                    // cout <<i <<" " <<sl <<" " <<sr <<endl;
                    if(sggn==0) {
                        sgg = sggn;
                        st.erase({le,ri});
                        if(i>le) {
                            st.insert({le,i-1});
                        }
                        if(ri> (i+l-1)) {
                            st.insert({i+l, ri});
                        }
                        return {i, l};
                    }
                }
            }
            return {-1,-1};
        };
        if(sg[n]) {
            cout <<"First\n"; cout<<flush;
            while(true) {
                auto mv = findMove();
                doMove(mv.fi, mv.se);
                auto res = getMove();
                pii zero = {0,0}, minOne = {-1,-1};
                if(res==zero || res==minOne) {
                    return;
                } else {
                    simulate(res);
                }
            }
        } else {
            cout <<"Second\n"; cout <<flush;
            while(true) {
                auto res = getMove();
                pii zero = {0,0}, minOne = {-1,-1};
                if(res==zero || res==minOne) {
                    return;
                } else {
                    simulate(res);
                }
                auto mv = findMove();
                doMove(mv.fi, mv.se);
            }
        }
    } else {
        int ct = ((l%2)==(n%2)? l: l+1);
        int sisa = (n-ct)/2;
        cout <<"First\n"; cout <<flush;
        doMove(sisa+1, ct);
        while(true) {
            auto res = getMove();
            pii zero = {0,0}, minOne = {-1,-1};
            if(res==zero || res==minOne) {
                return;
            }
            pii mv = res;
            if(mv.fi <=sisa) {
                mv.fi += sisa+ct;
            } else {
                mv.fi -= sisa+ct;
            }
            doMove(mv.fi, mv.se);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}