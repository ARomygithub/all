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

const int mxn=2e5,mxa=25e5;
int n;
int a[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    vi ct(mxa+1, 0);
    vector vct(mxa+1, vi());
    rep(i,0,n) {
        ct[a[i]]++;
        vct[a[i]].push_back(i);
    }
    set<int> v2;
    rep(i,0,mxa+1) {
        if(ct[i]>1) {
            v2.insert(i);
        }
    }
    if(sz(v2)>1) {
        cout <<"YES\n";
        auto x = *v2.begin();
        auto y = *(++v2.begin());
        vi vx, vy;
        rep(i,0,n) {
            if(a[i]==x) {
                vx.push_back(i);
            }
            if(a[i]==y) {
                vy.push_back(i);
            }
        }
        cout <<vx[0]+1 <<" " <<vy[0]+1 <<" " <<vx[1]+1 <<" " <<vy[1]+1 <<"\n";
        return;
    }
    if(sz(v2) && ct[*v2.begin()]>3) {
        auto x = *v2.begin();
        vi vx;
        rep(i,0,n) {
            if(a[i]==x) {
                vx.push_back(i);
            }
        }
        cout <<"YES\n";
        rep(i,0,4) {
            cout <<vx[i]+1 <<" \n"[i==3];
        }
        return;
    }
    vector fl(mxa*2+1, vector<pii>());
    set<int> s;
    int ct2 = 2;
    rep(i,1,mxa+1) {
        for(int j: vct[i]) {
            if(v2.count(i)) {
                ct2--;
                if(ct2<0) break;
                if(ct2==0) {
                    fl[i+i].push_back({vct[i][0],j});
                    if(sz(fl[i+i])>1) {
                        cout <<"YES\n";
                        auto [d1, d2] = fl[i+i][0];
                        auto [d3, d4] = fl[i+i][1];
                        cout <<d1+1 <<" " <<d2+1 <<" " <<d3+1 <<" " <<d4+1 <<"\n";
                        return;
                    }                    
                    continue;
                }
            }
            for(auto si : s) {
                fl[si+i].push_back({vct[si][0],j});
                if(sz(fl[si+i])>1) {
                    cout <<"YES\n";
                    auto [d1, d2] = fl[si+i][0];
                    auto [d3, d4] = fl[si+i][1];
                    cout <<d1+1 <<" " <<d2+1 <<" " <<d3+1 <<" " <<d4+1 <<"\n";
                    return;
                }
            }
            s.insert(i);
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