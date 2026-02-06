#include <bits/stdc++.h>
using namespace std;

#define ar array
#define sz(x) (int) (x).size()
#define pii pair<int,int>
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<double,int> pdi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e18;
const ll mod=2e18;

ll fastexpo(ll a, ll b, ll md=mod) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%md;}
        a = (a*a)%md;
        b >>=1;
    }
    return ret;
}

bool solveForN(ll n) {
    vector<pll> v;
    ll idx = 2;
    while(n>1) {
        if(n%idx == 0) {
            ll ct = 0;
            while(n%idx == 0) {
                ct++;
                n /= idx;
            }
            v.push_back({idx, ct});
        }
        idx++;
        if(idx*idx>n) break;
    }
    ll d = 1;
    for(auto [idx, ct]: v) {
        if(ct%2) {
            d *= fastexpo(idx,(ct-1)/2);
            n *= idx;
        } else {
            d *= fastexpo(idx, ct/2);
        }
    }
    // cout <<d <<"\n";
    // cout <<n <<"\n";
    ll bts = 10000000000;
    if(n<=bts) {
        int mx = 100000;
        for(int ans1 = 0;ans1<=mx;ans1++) {
            if(n < ans1*ans1*4) {
                break;
            }
            for(int ans2 = ans1;ans2<=mx;ans2++) {
                if(n < ans1*ans1 + ans2*ans2*3) {
                    break;
                }
                for(int ans3 = ans2;ans3<=mx;ans3++) {
                    if(n < ans1*ans1 + ans2*ans2 + ans3*ans3*2) {
                        break;
                    }
                    for(int ans4=ans3;ans4<=mx;ans4++) {
                        if(n == (ans1*ans1+ans2*ans2+ans3*ans3+ans4*ans4)) {
                            cout <<d*ans1 <<" " <<d*ans2 <<" " <<d*ans3 <<" " <<d*ans4 <<"\n";
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void solve() {
    ll nn;
    cin >>nn;
    if(solveForN(nn)) {
        return;
    }
    for(int diff=1;diff<10;diff++) {
        if(solveForN(nn+diff)) {
            return;
        }
        if(solveForN(nn-diff)) {
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}