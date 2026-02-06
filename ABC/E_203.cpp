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
int n,m;
pii xy[mxn];

void solve() {
    cin >>n >>m;
    rep(i,0,m) {
        cin >>xy[i].fi >>xy[i].se;
    }
    sort(xy, xy+m);
    set<int> cur;
    cur.insert(n);
    for(int i = 0;i<m;) {
        vector<int> v;
        int j = i;
        while(j<m && xy[j].fi==xy[i].fi) {
            v.push_back(xy[j].se);
            j++;
        } 
        vector<int> add,apus;
        for(int bl : v) {
            auto it = cur.lower_bound(bl-1);
            if(it==cur.end()) break;
            set<int>::iterator it2 = it;
            it2++;
            if((*it)== bl-1 || (*it)==bl+1 || ((it2)!=cur.end() && (*it2)==bl+1)) {
                add.push_back(bl);
            } else {
                if((*it)==bl) {
                    apus.push_back(bl);
                }
            }
        }
        for(int ai : apus) {
            cur.erase(ai);
        }
        for(int ai : add) {
            cur.insert(ai);
        }
        i = j;
    }
    cout <<sz(cur) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}