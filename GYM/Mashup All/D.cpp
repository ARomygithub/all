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
int n;

int ask(int i) {
    cout <<"? " <<i <<"\n";
    cout <<flush;
    int ai; cin >>ai;
    return ai;
}

int askb(int i) {
    int a1 = ask(i), a2 = ask(i+(n/2));
    return a1-a2;
}

int sgn(int x) {
    return (x>=0) - (x<=0);
}

void solve() {
    cin >>n;
    int b1 = askb(1);
    if(b1%2) {
        cout <<"! -1\n";
        cout <<flush;
        return;
    }
    if(b1==0) {
        cout <<"! 1\n";
        cout <<flush;
        return;
    }
    int l = 2, r = n/2;
    while(l<=r) {
        int mid = (l+r)/2;
        int bm = askb(mid);
        if(bm==0) {
            cout <<"! " <<mid <<"\n";
            cout <<flush;
            return;
        } else if(sgn(bm)==sgn(b1)) {
            l= mid+1;
        } else {
            r = mid-1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}