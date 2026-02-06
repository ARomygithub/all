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

struct TreeAnd {
    typedef int T;
    static constexpr T unit = (1<<30)-1;
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
    long long countSubarrays(vector<int>& nums, int k) {
        int n = sz(nums);
        TreeAnd st(n);
        rep(i,0,n) {
            st.update(i,nums[i]);
        }
        ll ret = 0;
        rep(i,0,n) {
            int l=i,r=n-1;
            int li = -1;
            while(l<=r) {
                int mid = (l+r)/2;
                int qry = st.query(i,mid+1);
                if(qry==k) {
                    li = mid;
                    r = mid-1;
                } else if((qry&k)==k) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            if(li==-1) continue;
            l = i, r = n-1;
            int ri = -1;
            while(l<=r) {
                int mid = (l+r)/2;
                int qry = st.query(i,mid+1);
                if(qry==k) {
                    ri = mid;
                    l = mid+1;
                } else if((qry&k)==k) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }            
            if(ri==-1) continue;
            ret += ri-li+1;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}