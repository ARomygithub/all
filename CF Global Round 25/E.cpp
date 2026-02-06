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
int n,t;
string s;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

void solve() {
    cin >>s;
    n = sz(s);
    auto p = manacher(s);
    auto ch_palin= [&](int l, int r) -> bool {
        int mid = (l+r)/2;
        bool odd = (r-l+1)%2;
        if(p[odd][mid+(!odd)] >= mid-l+1-odd) {
            return 1;
        } else {
            return 0;
        }
    };
    // cout <<ch_palin(0,n-1) <<"\n";
    if(!ch_palin(0,n-1)) {
        cout <<"YES\n";
        cout <<"1\n";
        cout <<s <<"\n";
    } else {
        rep(idx,0,(n/2)+1) {
            if(!ch_palin(0,idx) && !ch_palin(idx+1,n-1)) {
                string s1 = s.substr(0,idx+1);
                string s2 = s.substr(idx+1,n-idx-1);
                cout <<"YES\n";
                cout <<"2\n";
                cout <<s1 <<" " <<s2 <<"\n";
                return;
            }
        }
        cout <<"NO\n";
    }
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