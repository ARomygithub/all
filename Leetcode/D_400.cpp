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

struct Tree {
	typedef int T;
	static constexpr T unit = (1<<30)-1;
	T f(T a, T b) { return a & b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        Tree st(sz(nums));
        rep(i,0,sz(nums)) {
            st.update(i, nums[i]);
        }
        int ans = 1e9;
        rep(i,0,sz(nums)) {
            int l = i, r = sz(nums)-1;
            int pos = -1;
            while(l<=r) {
                int mid = (l+r)/2;
                int val = st.query(i, mid+1);
                if(val>k) {
                    pos = mid;
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            if(pos==-1) {
                min_self(ans, abs(k-nums[i]));
            } else {
                int val1 = st.query(i,pos+1);
                min_self(ans, abs(k-val1));
                if(pos+1 < sz(nums)) {
                    int val2 = st.query(i,pos+2);
                    min_self(ans, abs(k-val2));
                }
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> nums = {1};
    cout <<sol.minimumDifference(nums, 10);
}