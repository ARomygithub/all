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

const int mxn=3e5;
int n,k;
int a[mxn];

void solve() {
    cin >>n >>k;
    rep(i,0,n) {
        cin >>a[i]; a[i]--;
    }
    int ans = k-1;
    set<int> s;
    int ri = 0;
    auto add = [&](int x) -> bool {
        if(s.count(a[x])) return 0;
        if(sz(s)) {
            auto it = *s.begin();
            auto it2 = *(--s.end());
            if(abs(a[x]-it)>=k) return 0;
            if(abs(a[x]-it2)>=k) return 0;
        }
        s.insert(a[x]);
        return 1;
    };
    auto erase = [&](int x) -> void {
        s.erase(a[x]);
    };
    rep(li,0,n) {
        while(ri-li<k && add(ri%n)) {
            ri++;
        }
        min_self(ans, k-(ri-li));
        erase(li%n);
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}