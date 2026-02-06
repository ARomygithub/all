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

const int mxn=1e5;

int ask(ll a) {
    cout <<"query " <<a <<"\n" <<flush;
    int ret; cin >>ret;
    return ret;
}

void solve() {
    int d0 = ask(0);
    if(d0==0) {
        cout <<"answer 0\n" <<flush;
        return;
    }
    ll n = 0;
    int fd = 17;
    while(fd>=0) {
        ll temp = 9;
        rep(i,0,fd) {
            temp *=10ll;
        }
        int di = ask(temp);
        if(di!=d0+9) {
            break;
        }
        fd--;
    }
    int l=1,r=8;
    int a = 9;
    while(l<=r) {
        int mid = (l+r)/2;
        ll temp = mid;
        rep(i,0,fd) {
            temp *=10ll;
        }
        int di = ask(temp);
        if(di!=d0+mid) {
            a = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    n = 10 - a;
    fd--;
    while(fd>=0) {
        l = 1, r = 9;
        a = 10;
        while(l<=r) {
            int mid = (l+r)/2;
            ll temp = mid;
            rep(i,0,fd) {
                temp *=10ll;
            }
            int di = ask(temp);
            if(di!=d0+mid) {
                a = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        n = n*10 + (10-a);
        fd--;
    }
    cout <<"answer " <<n <<"\n" <<flush;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}