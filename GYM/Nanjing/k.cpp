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

const int mxn=25e3;
int n,m,t;
string sh,sd;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cin >>n >>m;
    cin >>sh;
    cin >>sd;
    map<char,int> mp;
    mp['Q'] = 0;
    mp['B'] = 1;
    mp['W'] = 2;
    mp['G'] = 3;
    rep(k,n,n+m+1) {
        vi ct(4,0);
        int cta = 0;
        for(auto c: sh) {
            ct[mp[c]]++;
            cta++;
        }
        int id = 0;
        auto do0 = [&]() -> void {
            ct[0]--;
            ct[mp[sd[id]]]++;
            id++;
        };
        auto do1 = [&]() -> void {
            ct[1]--;
            ct[mp[sd[id]]]++;
            if(cta<k) {
                cta++;
                ct[mp[sd[id+1]]]++;
            }
            id += 2;
        };
        while(id<sz(sd)) {
            if(ct[0]+ct[1]==0) {
                break;
            }
            if(cta==k && id+1<sz(sd) && sd[id+1]=='W' && ct[1]>0) {
                // B
                ct[1]--;
                ct[mp[sd[id]]]++;
                id += 2;
            } else if(cta==k && id+1<sz(sd) && sd[id+1]=='B' && ct[0]>0) {
                // Q
                do0();
            } else {
                int cur = rng()%2;
                if(cur==0) {
                    if(ct[0]>0) {
                        do0();
                    } else if(ct[1]>0) {
                        do1();
                    }
                } else {
                    if(ct[1]>0) {
                        do1();
                    } else if(ct[0]>0) {
                        do0();
                    }
                }
            }
        }
        if(id>=sz(sd)) {
            cout <<k <<"\n";
            return;
        }
    }
    cout <<"IMPOSSIBLE\n";
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