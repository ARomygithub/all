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

const int mxn=2e5;
int n;
int a[mxn];

bool chk(int k) {
    vector<pii> cur(1, {1,a[0]});
    // cout <<"K: " <<k <<endl;
    // int mx = 0;
    auto add = [&](pii it) -> void {
        if(sz(cur) && cur[sz(cur)-1].fi==it.fi) {
            cur[sz(cur)-1].se += it.se;
        } else {
            cur.push_back(it);
        }
    };
    rep(i,1,n) {
        if(a[i]>a[i-1]) {
            add({1,a[i]-a[i-1]});
        } else {
            int j = a[i-1];
            while(j>a[i]) {
                pii bck = cur[sz(cur)-1];
                if(j-bck.se >=a[i]) {
                    cur.pop_back();
                    j -= bck.se;
                } else {
                    int temp = j-a[i];
                    cur[sz(cur)-1].se -= temp;
                    j = a[i];
                }
            }
            if(sz(cur)==1 && cur[0].fi==k) {
                return 0;
            }
            pii ls = {1,0};
            while(true) {
                assert(sz(cur)>0);
                pii bck = cur[sz(cur)-1];
                if(bck.fi==k) {
                    ls.se += bck.se;
                    cur.pop_back();
                } else {
                    if(bck.se==1) {
                        cur[sz(cur)-1].fi = cur[sz(cur)-1].fi+1;
                        if(sz(cur)>=2 && cur[sz(cur)-2].fi==cur[sz(cur)-1].fi) {
                            cur[sz(cur)-2].se++;
                            cur.pop_back();
                        }
                    } else {
                        cur[sz(cur)-1].se -= 1;
                        cur.push_back({cur[sz(cur)-1].fi+1, 1});
                    }
                    break;
                }
            }
            if(ls.se>0) {
                add(ls);
            }
        }
        // max_self(mx, sz(cur));
    }
    // cout <<mx <<endl;
    return true;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>a[i];
    }
    int ans = n;
    int l = 1, r=n-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(chk(mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout <<ans <<"\n";
    // cout <<"TES" <<endl;
    // cout <<ans <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}