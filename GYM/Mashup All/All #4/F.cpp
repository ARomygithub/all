#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

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

const int mxn=2e5;
int n,q;
string s;

void solve() {
    cin >>n >>q;
    cin >>s;
    map<char,int> mp = {{'R',0},{'P',1},{'S',2}};
    vector<oset<int>> vs(3);
    rep(i,0,n) {
        vs[mp[s[i]]].insert(i);
    }
    auto loser = [&](char c) -> int {
        int cc = mp[c];
        return (cc+1)%3;
    };
    auto getLose = [&]() -> int {
        int l = 0, r= n-1;
        rep(i,0,3) {
            max_self(l, sz(vs[i])?(*vs[i].begin()):n);
            min_self(r, sz(vs[i])?(*(--vs[i].end())):-1);
        }
        if(l==n) {
            set<int> st;
            rep(i,0,3) {
                if(sz(vs[i])) {
                    st.insert(i);
                }
            }
            if(sz(st)==2) {
                auto it = st.begin();
                int i = *it; it++;
                int j = *it;
                if(((j-i+3)%3)==1) {
                    return sz(vs[i]);
                } else {
                    return sz(vs[j]);
                }
            } else {
                return 0;
            }
        } else {
            char c1 = s[l];
            char c2 = s[r];
            int ret = 0;
            int lc1 = loser(c1), lc2 = loser(c2);
            ret += vs[lc1].order_of_key(l) - vs[lc1].order_of_key((*vs[(lc1+1)%3].begin()));
            // cout <<ret <<endl;
            ret += vs[lc2].order_of_key(*(--vs[(lc2+1)%3].end())) - vs[lc2].order_of_key(r);
            // cout <<ret <<endl;
            return ret;
        }
    };
    cout <<n-getLose() <<"\n";
    while(q--) {
        int i; char c; cin >>i >>c; i--;
        int prv = mp[s[i]];
        int cur = mp[c];
        vs[prv].erase(i);
        vs[cur].insert(i);
        s[i] = c;
        // cout <<s <<"\n";
        cout <<n-getLose() <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}