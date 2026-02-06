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
int ct = 0;
ll bw = 1<<0, ats = 1<<30;
vector<pii> cand[31];

ll ask(int l, int r) {
    ct++;
    cout <<"? " <<l+1 <<" " <<r+1 <<"\n";
    cout <<flush;
    ll ret; cin >>ret;
    if(ret==-1) exit(0);
    return ret;
}

void slv(int l, int r, ll sm) {
    if(l==r) {
        max_self(bw, sm);
        return;
    }
    int li = l, ri = r-1;
    int md = -1;
    ll cur = min(sm-(r-l+1)+1, sm/2);
    if(cur<= bw) return;
    while(li<=ri) {
        if(li==ri) {
            md = li;
            break;
        }
        int mid = (li+ri)/2;
        ll cur = ask(l,mid);
        if(cur==sm/2) {
            md = mid;
            break;
        } else if(cur>sm/2) {
            ri = mid-1;
        } else {
            li = mid+1;
        }
    }
    slv(l,md,sm/2);
    slv(md+1,r,sm/2);
}

void solve() {
    cin >>n;
    ct = 0;
    bw = 1<<0, ats = 1<<30;
    ll sm = ask(0,n-1);
    per(i,30,-1) {
        for(auto [l,r]: cand[i]) {
            
        }
    }
    slv(0,n-1,sm);
    cout <<"! " <<bw <<"\n";
    cout <<flush;
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