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
	static constexpr T unit = INT_MAX;
	T f(T a, T b) { return min(a, b); } // (any associative fn)
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

struct TreeAnd {
	typedef int T;
	static constexpr T unit = (1<<17)-1;
	T f(T a, T b) { return (a&b); } // (any associative fn)
	vector<T> s; int n;
	TreeAnd(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        TreeAnd ta(sz(nums));
        rep(i,0,sz(nums)) {
            ta.update(i, nums[i]);
        }
        Tree st(sz(nums));
        rep(i,0,sz(nums)) {
            if(ta.query(i,sz(nums)) == andValues[sz(andValues)-1]) {
                st.update(i, nums[sz(nums)-1]+(i>0?nums[i-1]:0));
            }
        }
        per(i,sz(andValues)-2,-1) {
            Tree st_new(sz(nums));
            rep(j,0,sz(nums)-sz(andValues)+i+1) {
                // cout <<"tes" <<endl;
                int l = j, r = sz(nums)-sz(andValues)+i;
                int rr = -1;
                while(l<=r) {
                    int mid = (l+r)/2;
                    int x = ta.query(j,mid+1);
                    if((x&andValues[i])==andValues[i]) {
                        rr = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                if(rr==-1) continue;
                l = j, r = sz(nums)-sz(andValues)+i;
                int li = -1;
                while(l<=r) {
                    int mid = (l+r)/2;
                    int x = ta.query(j,mid+1);
                    if((x&andValues[i])==x) {
                        li = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                if(li==-1) continue;
                int qry = st.query(li+1,min(rr+2,sz(nums)));
                if(qry< INT_MAX) {
                    st_new.update(j, qry+(j>0?nums[j-1]:0));
                }
            }
            swap(st,st_new);
        }
        int ans = st.query(0,1);
        if(ans==INT_MAX) {
            ans = -1;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution sol;
    vector<int> nums = {2,3,5,7,7,7,5};
    vector<int> an = {0,7,5};
    cout <<sol.minimumValueSum(nums,an) <<endl;
}