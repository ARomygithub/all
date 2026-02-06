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

const int mxn=5e5;
int n;
pii ab[mxn];

void solve() {
    cin >>n;
    multiset<int> sfix;
    rep(i,0,n) {
        cin >>ab[i].fi;
    }
    rep(i,0,n) {
        cin >>ab[i].se;
    }
    rep(i,0,n) {
        if(ab[i].fi>ab[i].se) swap(ab[i].fi,ab[i].se);
    }
    vi ans(n,1e9);
    auto doit = [&]() -> void {
        /*
        fixed sz = 1
        add interval i=1..n-1
        la, ra u/ fixed
        lr,rl = set<pii>
        maintain ans_st = MIN(r_i - l_[i+1]), seperti sisip,erase linkedlist
        */
        int la = *sfix.begin(), ra = la;
        multiset<pii> lr,rl;
        min_self(ans[0], 0);
        multiset<int> ans_st;
        auto del = [&](pii abi) -> void {
            auto it = lr.find(abi);
            auto it2 = it; it2++;
            if(it!=lr.begin() && it2!=lr.end()) {
                auto itp = it; itp--;
                int val = itp->se - it2->fi;
                ans_st.insert(val);
            }
            if(it!=lr.begin()) {
                auto itp = it; itp--;
                int val = itp->se - it->fi;
                ans_st.erase(ans_st.find(val));
            }
            if(it2!=lr.end()) {
                int val = it->se - it2->fi;
                ans_st.erase(ans_st.find(val));
            }
            rl.erase(rl.find({it->se,it->fi}));
            lr.erase(it);
        };
        auto add = [&](pii abi) -> void {
            lr.insert(abi);
            rl.insert({abi.se,abi.fi});
            auto it = lr.find(abi);
            auto it2 = it; it2++;
            if(it!=lr.begin() && it2!=lr.end()) {
                auto itp = it; itp--;
                int val = itp->se - it2->fi;
                ans_st.erase(ans_st.find(val));
            }
            if(it!=lr.begin()) {
                auto itp = it; itp--;
                int val = itp->se - it->fi;
                ans_st.insert(val);
            }
            if(it2!=lr.end()) {
                int val = it->se - it2->fi;
                ans_st.insert(val);
            }

            // del yg ke include
            if(it!=lr.begin()) {
                auto itp = it; itp--;
                if(itp->se >= it->se) {
                    del(*it);
                    return;
                }
            }
            vector<pii> vdel;
            while(it2!=lr.end()) {
                if(it2->se <= it->se) {
                    vdel.push_back(*it2);
                    it2++;
                } else {
                    break;
                }
            }
            for(auto deli : vdel) {
                del(deli);
            }
        };
        rep(i,1,n) {
            if(ab[i].fi>=la) {
                sfix.insert(ab[i].fi);
                max_self(ra, ab[i].fi);
                min_self(la, ab[i].fi);
            } else if(ab[i].se<=ra) {
                sfix.insert(ab[i].se);
                max_self(ra, ab[i].se);
                min_self(la, ab[i].se);
            } else {
                add(ab[i]);
            }
            while(sz(lr)) {
                if((--lr.end())->fi >= la) {
                    auto it = --lr.end();
                    sfix.insert(it->fi);
                    max_self(ra, it->fi);
                    min_self(la, it->fi);
                    del(*it);
                } else if((rl.begin())->fi <=ra) {
                    auto it = rl.begin();
                    sfix.insert(it->fi);
                    max_self(ra, it->fi);
                    min_self(la, it->fi);                    
                    del({it->se,it->fi});
                } else {
                    break;
                }
            }
            if(sz(ans_st)) {
                min_self(ans[i], *ans_st.begin());
            }
            if(sz(lr)) {
                min_self(ans[i], *(--sfix.end()) - lr.begin()->fi);
                min_self(ans[i], (*(--lr.end())).se - *(sfix.begin()));
            } else {
                min_self(ans[i], *(--sfix.end()) - *(sfix.begin()));
            }
        }
    };
    sfix.insert(ab[0].fi);
    doit();
    sfix.clear();
    sfix.insert(ab[0].se);
    doit();
    rep(i,0,n) {
        cout <<ans[i] <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}