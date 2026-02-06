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

const int mxn=5e5;
int n,c,p,q;
string s;

void solve() {
    cin >>n >>c >>p >>q;
    cin >>s;
    int r = 0;
    int last = -1;
    vector<int> ctw(n,0);
    vector<ll> mn(n,0);
    rep(i,0,n) {
        ctw[i] = (s[i]=='Y') + (i>0?ctw[i-1]:0);
        // cout <<ctw[i] <<"\n";
        ll temp;
        if(s[i]=='Y') {
            temp = p-q;
        } else {
            temp = p;
        }
        mn[i] = min(0ll, temp+(i>last+1?mn[i-1]:0ll));
        if(i-last>=c) {
            ll tot = 1ll*c*p - 1ll*q*(ctw[i]-(i-c>=0?ctw[i-c]:0));
            if(i-c>last) {
                tot += mn[i-c];
            }
            if(tot<=0ll) {
                r++;
                last = i;
            }
            // cout <<r <<" " <<i <<" " <<tot <<"\n";
        }
    }
    cout <<r <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}