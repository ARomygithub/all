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

set<string> ask(vi a) {
    cout <<"next ";
    rep(i,0,sz(a)) {
        cout <<a[i] <<" \n"[i==sz(a)-1];
    }
    cout <<flush;
    int k;
    cin >>k;
    set<string> ret;
    rep(i,0,k) {
        string reti;
        cin >>reti;
        ret.insert(reti);
    }
    return ret;
}

void solve() {
    int x = 0, xc = 0;
    while(true) {
        auto reti = ask(vi{9});
        xc++;
        if(reti.count("89")) {
            break;
        }
        reti = ask(vi{8,9});
        x++; xc++;
        if(reti.count("89")) {
            break;
        }
    }
    int c = xc - x;
    int s0 = x, s9 = c;
    while(s0!=s9) {
        if(s0>s9) {
            ask(vi{0,1,2,3,4,5,6,7});
            s0--;
        } else {
            ask(vi{9});
            s9--;
        }
    }
    auto chk = [&](set<string>& ret) -> bool {
        vi v(9);
        iota(all(v),0);
        v[8] = 9;
        for(auto reti : ret) {
            bool ok = 1;
            rep(j,0,sz(v)) {
                if(count(all(reti), (char)('0'+v[j])) == 0) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                return 1;
            }
        }
        return 0;
    };
    while(true) {
        auto reti = ask(vi{0,1,2,3,4,5,6,7,9});
        bool ok = chk(reti);
        if(ok) {
            while(sz(reti)>1) {
                reti = ask(vi{8});
            }
            cout <<"done\n";
            cout <<flush;
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