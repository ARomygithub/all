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
int n,t;
string s[mxn];
const string vs[] = {"GGGgGGG", "gggggGG", "gGGGGGg", "ggGGGGG", "GggGgGG", "GgGGGgG", "GGGGGgG", "ggGggGG", "GGGGGGG", "GgGGGGG"};

bool ok(string& si, int j) {
    bool ret = 1;
    rep(i,0,sz(vs[j])) {
        if(si[i]=='+' || si[i]=='-') continue;
        if(si[i]!=vs[j][i]) {
            ret = 0;
            break;
        }
    }
    return ret;
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>s[i];
    }
    string ans = "";
    rep(i,0,n) {
        int ct = 0;
        int ls = -1;
        rep(j,0,10) {
            if(ok(s[i],j)) {
                ct++;
                ls = j;
            }
        }
        if(ct>1) {
            ans +='*';
        } else {
            ans +=(char)(ls+'0');
        }
    }
    cout <<ans <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin >>t;
    t = 1;
    while(t--) {
        solve();
    }
}