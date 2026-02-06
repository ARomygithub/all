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

const int mxn=3e5;
int n;

void solve() {
    cin >>n;
    set<int> s;
    multiset<int> rox;
    map<int,int> mp;
    int ct0 = 0;
    while(n--) {
        int qt; cin >>qt;
        if(qt==3) {
            if(ct0) {
                cout <<"0\n";
            } else {
                cout <<(*rox.begin()) <<"\n";
            }
        } else {
            int x; cin >>x;
            if(qt==1) {
                if(mp[x]) {
                    ct0 += mp[x]==1;
                    mp[x]++;
                } else {
                    mp[x]++;
                    auto it = s.lower_bound(x);
                    auto it2 = it;
                    if(it2!=s.begin()) {
                        it2--;
                    }
                    if(it!=s.end() && it!=s.begin()) {
                        rox.erase(rox.find((*it)^(*it2)));
                    }
                    if(it!=s.end()) {
                        rox.insert(x^(*it));
                    }
                    if(it!=s.begin()) {
                        rox.insert((*it2)^x);
                    }
                    s.insert(x);
                }
            } else {
                ct0 -= mp[x]==2;
                mp[x]--;
                if(!mp[x]) {
                    auto it = s.lower_bound(x);
                    auto it2 = it, it3=it;
                    it2++;
                    if(it!=s.begin()) {
                        it3--;
                    }
                    if(it2!=s.end() && it!=s.begin()) {
                        rox.insert((*it2)^(*it3));
                    }
                    if(it2!=s.end()) {
                        rox.erase(rox.find((*it2)^x));
                    }
                    if(it!=s.begin()) {
                        rox.erase(rox.find((*it3)^x));
                    }
                    s.erase(x);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}