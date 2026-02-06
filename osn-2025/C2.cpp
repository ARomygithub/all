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

const int mxn=1e5;
int n,t; // 18

pii nxt(pii ij) {
    if(ij.fi%2) {
        ij.se--;
        if(ij.se<0) {
            ij.se++;
            ij.fi++;
        }
    } else {
        ij.se++;
        if(ij.se==n) {
            ij.se--;
            ij.fi++;
        }
    }
    return ij;
}

vector<vi> line2(int l0, int l1) {
    vector ret(2, vi());
    bool tuker = 0;
    if(l0>l1) {
        tuker = 1;
        swap(l0,l1);
    }
    ret[0].resize(l0,0);
    ret[1].resize(l1,0);
    int j = 0;
    if(l0>=1 && l0<=3) {
        rep(id,1,4) {
            if(j<l0) {
                ret[0][j] = id;
                ret[1][j] = id;
                j++;
            } else if(j<l1) {
                if(l1-j>=2) {
                    ret[1][j] = id;
                    ret[1][j] = id;
                    j += 2;
                }
            }
        }
    }
    vector tes(2, vi(3));
    tes[0] = {1,2,2};
    tes[1] = {1,1,2};
    if(l0>=4 && l0<=7) {
        rep(j1,0,3) {
            ret[0][j+j1] = tes[0][j1];
            ret[1][j+j1] = tes[1][j1];
        }
        j += 3;
        rep(id,1,4) {
            if(j<l0) {
                ret[0][j] = id;
                ret[1][j] = id;
                j++;
            }
        }        
    }
    if(l0>=8) {
        rep(id,1,4) {
            if(j<l0) {
                ret[0][j] = id;
                ret[1][j] = id;
                j++;
            }
        }       
        rep(j1,0,3) {
            ret[0][j+j1] = tes[0][j1];
            ret[1][j+j1] = tes[1][j1];
        }
        j += 3;
        ret[0][j] = 3;
        ret[0][j+1] = 3;
        ret[1][j] = 3;
        j++;        
    }
    

    if(tuker) {
        ret[0].swap(ret[1]);
    }
    return ret;
}

void solve() {
    // n = 23;
    // cin >>n;
    n = 9;
    vector a(n, vi(n,0));
    pii ij = {0,0};
    map<pii,pii> mp;
    int ct_; cin >>ct_;
    per(ct,ct_,0) {
        rep(id,1,4) {
            mp[{id,ct}] = ij;
            rep(k,0,ct) {
                auto [i,j] = ij;
                a[i][j] = id;
                ij = nxt(ij);
                if(ij.fi>=n) break;
            }
            if(ij.fi>=n) break;
        }
        if(ij.fi>=n) break;
    }
    cout <<n <<"\n";
    cout <<flush;
    cout <<"QUERY\n";
    rep(i,0,n) {
        rep(j,0,n) {
            cout <<a[i][j] <<" \n"[j==n-1];
        }
    }
    cout <<flush;
    int s,m; cin >>s >>m;
    rep(i,0,n) {
        rep(j,0,n) {
            a[i][j] = 0;
        }
    }
    ij = mp[{s,m}];
    if(s==3 && m==18) {
        int ct = 0;
        rep(i,1,4) {
            rep(j,0,3) {
                a[ij.fi][ij.se+ct] = i;
                ct++;
            }
        }
        rep(i,0,3) {
            rep(j,1,4) {
                a[ij.fi][ij.se+ct] = j;
                ct++;
            }
        }
    } else {
        int dir;
        int i = ij.fi;
        int j;
        vi len(2);
        if(ij.fi%2) {
            dir = -1;
            j = n-1;
            len[0] = j - ij.se + 1;
            len[1] = m - len[0];
        } else {
            dir = 1;
            j = 0;
            len[0] = ij.se+1;
            len[1] = m - len[0];
        }
        auto ans = line2(len[0],len[1]);

    }
    // rep(k,0,m) {
    //     auto [i,j] = ij;
    //     a[i][j] = -1;
    //     ij = nxt(ij);
    // }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}