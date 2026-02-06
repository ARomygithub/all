#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
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

const int mxn=5e5, sq=700;
int n,q;
int ar[mxn];

void solve() {
    cin >>n;
    rep(i,0,n) {
        int x; cin >>x;
        ar[i] = x;
    }
    vector<vi> v;
    for(int i=0;i<n;) {
        vi vc;
        rep(j,i,min(i+sq,n)) {
            vc.push_back(ar[j]);
        }
        sort(all(vc));
        v.push_back(vc);
        i = min(i+sq,n);
    }

    cin >>q;
    while(q--) {
        int qt; cin >>qt;
        if(qt==0) {
            int a,b,c; cin >>a >>b >>c; a--,b--;
            int ans = 0;
            while(a<=b && (a%sq)!=0) {
                ans += (ar[a]>=c);
                a++;
            }
            while(a<=b && (a+sq-1<=b)) {
                auto& vc = v[a/sq];
                auto it = lower_bound(all(vc),c);
                ans += sq - (it-vc.begin());
                a += sq;
            }
            while(a<=b) {
                ans += (ar[a]>=c);
                a++;
            }
            cout <<ans <<"\n";
        } else {
            int a,b; cin >>a >>b; a--;
            auto& vc = v[a/sq];
            ar[a] = b;
            int awl = (a/sq)*sq;
            rep(i,awl,min(n,awl+sq)) {
                vc[i-awl] = ar[i];
            }
            sort(all(vc));
        }   
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}