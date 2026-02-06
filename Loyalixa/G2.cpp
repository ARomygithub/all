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

const int mxn=1e5,mxa=1e9;
int n,t;
vi pri;

const int LIM = 1e9;
bitset<LIM> isprime;
vi eratosthenes() {
    const int S = (int)round(sqrt(LIM)), R = LIM/2;
    vi pr = {1,2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1)+1);
    vector<pii> cp;
    for(int i=3;i<=S;i+=2) if(!sieve[i]) {
        cp.push_back({i,i*i/2});
        for(int j=i*i;j<=S;j+=2*i) sieve[j] = 1;
    }
    for(int L=1; L <=R; L += S) {
        array<bool, S> block{};
        for(auto &[p, idx]: cp)
            for(int i=idx; i< S+L; idx = (i+=p)) block[i-L] = 1;
        rep(i,0, min(S, R-L)) {
            if(!block[i]) pr.push_back((L+i) * 2 + 1);
        }
    }
    for(int i: pr) isprime[i] = 1;
    return pr;
}

void solve() {
    cin >>n;
    int ans = 0;
    while(n>0) {
        auto it = upper_bound(all(pri), n); it--;
        ans++;
        n -= (*it);
    }
    cout <<ans <<"\n";
}

void init() {
    pri = eratosthenes();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}