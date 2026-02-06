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

const int mxn=1e5;
ll n,xx,y;
int a;
map<ll, double> mp;

double get_ans(ll x) {
    if(x==0) return 0;
    if(mp.count(x)) return mp[x];
    // if(x<a) return 1;
    double a1 = get_ans(x/a) + xx;
    double a2 = (get_ans(x/2) + get_ans(x/3) + get_ans(x/4) + get_ans(x/5) + get_ans(x/6) + y*6)/5.0;
    mp[x] = min(a1,a2);
    return mp[x];
}

void solve() {
    cin >>n >>a >>xx >>y;
    cout <<fixed <<setprecision(8) << get_ans(n) <<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}