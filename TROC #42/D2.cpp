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

const int mxn=1e5,mg=65536;
int n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ct = 0;

int ask(int l, int r) {
    cout <<"? " <<l <<" " <<r <<"\n" <<flush;
    int ret; cin >>ret;
    ct++;
    return ret;
}

void solve() {
    cin >>n;
    int l = 1, r = n;
    int al = ask(l,r);
    int tg = -1;
    int le = (1<<18), ri = (1<<18);
    while(l<=r) {
        // if(l==r) {
        //     tg = l;
        //     break;
        // }
        int mid = (l+r)/2;
        int cur = ask(1,mid);
        if(__builtin_ctz(cur) == __builtin_ctz(al)) {
            tg = mid;
            r = mid-1;
        } else {
            l = mid+1;
            le = cur;
        }
    }
    // if(rng()%3) {
    //     if(ct<19 && tg<n) {
    //         ri = ask(tg+1,n);
    //     }
    //     if(ct<19 && 1<tg) {
    //         le = ask(1,tg-1);
    //     }
    // } else {
    //     if(ct<19 && 1<tg) {
    //         le = ask(1,tg-1);
    //     }        
        if(ct<19 && tg<n) {
            ri = ask(tg+1,n);
        }
    // }
    ll ans = 1ll*(1<<__builtin_ctz(al))*(1<<(min(__builtin_ctz(le), __builtin_ctz(ri))));
    cout <<"! " <<ans <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}