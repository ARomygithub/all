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

const int mxn=1e3;
int n,m,t;
string s[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,n) {
        cin >>s[i];
    }
    if(n==2 && (m%2)==0) {
        if(s[0][1] != s[1][0]) {
            cout <<"NO\n";
            return;
        }
    } 
    pii x = {-1,-1};
    rep(i,0,n) {
        rep(j,i+1,n) {
            if(s[i][j]==s[j][i]) {
                x = {i,j};
                break;
            }
        }
    }
    cout <<"YES\n";
    if(x.fi!=-1) {
        auto [u,v] = x;
        rep(i,0,m+1) {
            if(i%2) {
                cout <<u+1 <<" \n"[i==m];
            } else {
                cout <<v+1 <<" \n"[i==m];
            }
        }
        return;
    }
    if(m%2) {
        rep(i,0,m+1) {
            if(i%2) {
                cout <<2 <<" \n"[i==m];
            } else {
                cout <<1 <<" \n"[i==m];
            }
        }
    } else {
        rep(i,0,n) {
            int ua = -1, ub = -1;
            rep(j,0,n) {
                if(j==i) continue;
                if(s[i][j]=='a') {
                    ua = j;
                } else {
                    ub = j;
                }
            }
            if(ua!=-1 && ub!=-1) {
                int mid = m/2;
                if(mid%2) {
                    rep(j,0,mid+1) {
                        if(j%2) {
                            cout <<i+1 <<" ";
                        } else {
                            cout <<ub+1 <<" ";
                        }
                    }
                } else {
                    rep(j,0,mid+1) {
                        if(j%2) {
                            cout <<ub+1 <<" ";
                        } else {
                            cout <<i+1 <<" ";
                        }                        
                    }
                }
                rep(j,0,mid) {
                    if(j%2) {
                        cout <<i+1 <<" \n"[j==mid-1];
                    } else {
                        cout <<ua+1 <<" \n"[j==mid-1];
                    }
                }
                return;
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