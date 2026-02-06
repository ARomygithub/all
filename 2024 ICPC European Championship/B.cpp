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

const int mxn=5e3;
int n,t;
int a[mxn],b[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    rep(i,0,n) {
        cin >>b[i];
    }
    int l=0, r= 1e9;
    int ans = -1;
    while(l<=r) {
        int mid = (l+r)/2;
        cout <<mid <<endl;
        bool ok = 1;
        multiset<int> ma,mb;
        bool dbg = mid>18 && mid<=30;
        rep(i,0,n) {
            ma.insert(a[i]);
        }
        rep(i,0,n) {
            mb.insert(b[i]);
        }
        for(auto ai: ma) {
            auto it = mb.lower_bound(ai+mid);
            if(it == mb.end()) {
                it = mb.lower_bound(ai-mid);
                if(it==mb.end()) it--;
                while(it!=mb.begin() && abs(ai-(*it))<mid) {
                    // cout <<"while" <<endl;
                    it--;
                }
                // cout <<"en while" <<endl;
                if(it==mb.begin() && abs(ai-(*it))<mid) {
                    cout <<"end" <<endl;
                    ok = 0;
                    break;
                } else {
                    // cout <<"bef erase" <<endl;
                    if(dbg) {
                        cout <<ai <<" " <<(*it) <<endl;
                    }
                    mb.erase(it);
                    // cout <<"af erase" <<endl;
                }
            } else {
                cout <<ai <<" " <<(*it) <<endl;
                mb.erase(it);
            }
        }
        if(ok) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout <<ans <<"\n";
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