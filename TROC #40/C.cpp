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
int a[mxn],b[mxn];

void solve() {
    cin >>n >>x >>y;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    vector<pii> v;
    int ans = 0;
    bool ok = 0;
    rep(i,0,n) {
        if(a[i]>=x && b[i]>=y) {
            ans++;
        } else {
            v.push_back({a[i],b[i]});
        }
    }
    sort(all(v));
    int r = sz(v)-1;
    multiset<int> sb;
    rep(l,0,sz(v)) {
        while(l>r) {
            sb.erase(sb.find(v[r+1].se));
            r++;
        }
        while(r>l && v[l].fi +v[r].fi>=x) {
            sb.insert(v[r].se);
            r--;
        }
        int sbi = 0;
        if(sz(sb)) {
            sbi = *(--sb.end());
            if(v[l].se+sbi>=y) {
                ok = 1;
                break;
            }
        }
    }
    ans += ok;
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}