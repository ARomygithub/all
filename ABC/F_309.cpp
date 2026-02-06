#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i > (b); --i)
#define all(x) (x).begin(), (x).end()
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

const int mxn=2e5;
int n;
vector<vector<int>> box;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
		for (; x < sz(ys); x |= x + 1) ys[x].push_back(y);
	}
	void init() {
		for (vi& v : ys) sort(all(v)), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
		return (int)(lower_bound(all(ys[x]), y) - ys[x].begin()); }
	void update(int x, int y, ll dif) {
		for (; x < sz(ys); x |= x + 1)
			ft[x].update(ind(x, y), dif);
	}
	ll query(int x, int y) {
		ll sum = 0;
		for (; x; x &= x - 1)
			sum += ft[x-1].query(ind(x-1, y));
		return sum;
	}
};

void solve() {
    cin >>n;
    set<int> sy,sz;
    rep(i,0,n) {
        vector<int> temp(3);
        cin >>temp[0] >>temp[1] >>temp[2];
        sort(temp.begin(),temp.end());
        box.push_back(temp);
        sy.insert(temp[1]);
        sz.insert(temp[2]);
    }
    sort(box.begin(),box.end());
    map<int,int> mpy,mpz;
    int id = 0;
    for(int yi : sy) {
        mpy[yi] = id++; 
    }
    FT2 ft2(id);
    id = 0;
    for(int zi : sz) {
        mpz[zi] = id++;
    }
    rep(i,0,n) {
        ft2.fakeUpdate(mpy[box[i][1]],mpz[box[i][2]]);
    }
    ft2.init();
    for(int i=0;i<n;) {
        int j = i;
        while(j+1<n && box[j+1][0]==box[i][0]) {
            j++;
        } 
        rep(k,i,j+1) {
            int idy = mpy[box[k][1]], idz = mpz[box[k][2]];
            int qry = ft2.query(idy,idz);
            if(qry) {
                cout <<"Yes\n";
                return;
            }
        }
        rep(k,i,j+1) {
            int idy = mpy[box[k][1]], idz= mpz[box[k][2]];
            ft2.update(idy, idz, 1ll);
        }
        i = j+1;
    }
    cout <<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}