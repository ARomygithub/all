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

const int mxn=1e6;
int n;
string x;

void solve() {
    cin >>n;
    cin >>x;
    int sx = 0;
    set<int> s;
    rep(i,0,sz(x)) {
        if(sz(x)-i <=20) {
        // if(n-i <=19) {
            sx += (x[i]-'0')<<(sz(x)-1-i);
        } else if(x[i]=='1') {
            s.insert(sz(x)-i-1);
            // s.insert(n-i);
        }
    }
    if(sx>0) {
        sx--;
    } else {
        int awl = *s.begin();
        s.erase(awl);
        per(j,awl-1,19) {
            s.insert(j);
        }
        sx = (1<<20)-1;
    }
    string ans = "1";
    per(i,n-1,0) {
        if(sz(s)==0 && sx==0) {
            break;
        }
        if(i<20) {
            if(sx>=(1<<i)) {
                ans += '1';
                sx -= (1<<i);
            } else {
                ans += '0';
                sx--;
            }
        } else {
            if(s.count(i)) {
                ans += '1';
                s.erase(i);
            } else {
                ans += '0';
                if(sx>0) {
                    sx--;
                } else {
                    int awl = *s.begin();
                    s.erase(awl);
                    per(j,awl-1,19) {
                        s.insert(j);
                    }
                    sx = (1<<20)-1;
                }
            }
        } 
    }
    // if(sz(x)<=62) {
    //     ll tes1 = 0;
    //     ll tes2 = 0;
    //     rep(i,0,sz(x)) {
    //         tes1 += (1ll*(x[i]-'0'))<<(sz(x)-i-1);
    //     }
    //     tes2 = 1;
    //     rep(i,1,sz(ans)) {
    //         if(ans[i]=='0') {
    //             tes2++;
    //         } else {
    //             tes2 += 1ll<<(1ll*(n-i));
    //         }
    //     }
    //     assert(tes1==tes2);
    // }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}