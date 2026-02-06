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
int n,x,y;
set<int> s;

void solve() {
    cin >>n >>x >>y;
    rep(i,0,n) {
        int ai; cin >>ai;
        s.insert(ai);
    }
    auto it = s.begin();
    while(it!=s.end()) {
        int a1 = *it;
        int a2 = x-a1;
        if(s.count(a2)) {
            if(!(x==y*2 && a1==y)) {
                cout <<a1 <<" " <<a2 <<"\n";
                return;
            }
        }
        it++;
    }
    cout <<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}