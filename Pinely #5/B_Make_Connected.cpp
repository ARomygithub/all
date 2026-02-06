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

const int mxn=1e2;
int n,t;
string s[mxn];
using piii = pair<pii,int>;

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    int u=n,d=-1,l=n,r=-1;
    rep(i,0,n) {
        rep(j,0,n) {
            if(s[i][j]=='#') {
                max_self(d,i);
                min_self(u,i);
                min_self(l,j);
                max_self(r,j);
            }
        }
    }
    if(d-u+1 <=2 && r-l+1<=2) {
        cout <<"YES\n";
        return;
    }
    bool ok = 1, f1 = 1;
    vector<piii> ls;
    rep(i,0,n) {
        if(i>d) break;
        vi cur;
        rep(j,0,n) {
            if(s[i][j]=='#') {
                cur.push_back(j);
            }
        }
        if(f1) {
            if(sz(cur)) {
                if(sz(cur)==1) {
                    ls.push_back({{cur[0],1},-1});
                    if(cur[0]+1<n) {
                        ls.push_back({{cur[0],2},-1});
                    }
                    if(cur[0]-1>=0) {
                        ls.push_back({{cur[0]-1,2},-1});
                    }
                } else if(sz(cur)==2) {
                    if(cur[1]==cur[0]+1) {
                        ls.push_back({{cur[0],2},-1});
                    } else {
                        ok = 0;
                        break;
                    }
                } else {
                    ok = 0;
                    break;
                }
                f1 = 0;
            }
        } else {
            vector<piii> ls_new;
            rep(j2,0,n) {
                rep(c2,1,3) {
                    if(j2+c2-1>=n) continue;
                    int le = j2, ri = j2+c2-1;
                    bool okc = 1;
                    for(auto& curi: cur) {
                        if(curi<le || curi>ri) {
                            okc = 0;
                            break;
                        }
                    }
                    if(okc) {
                        set<int> st2;
                        for(auto& [j1c1,s1]: ls) {
                            auto [j1,c1] = j1c1;
                            int le1 = j1, ri1 = j1+c1-1;
                            if(c1==2 && j2==j1 && c2==c1) {
                                continue;
                            }
                            if(ri<le1 || le>ri1) {
                                continue;
                            } else {
                                int s0 = -1,s2=-1;
                                if(le1>=le && le1<=ri) {
                                    s0 = 0;
                                }
                                if(ri1>=le && ri1<=ri) {
                                    s0 = ri1-j1;
                                }
                                if(le>=le1 && le<=ri1) {
                                    s2 = 0;
                                }
                                if(ri>=le1 && ri<=ri1) {
                                    s2 = ri-j2;
                                }
                                if(s0!=s1) {
                                    st2.insert(s2);
                                }
                                // break;
                            }
                        }
                        for(auto& s2: st2) {
                            ls_new.push_back({{j2,c2},s2});
                        }
                    }
                }
            }
            ls.swap(ls_new);
            if(sz(ls)==0) {
                ok = 0;
                break;
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
    cin >>t;
    while(t--) {
        solve();
    }
}