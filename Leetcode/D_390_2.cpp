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

typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

typedef pair<pii,pair<int,ull>> pcon;
typedef pair<pii,ull> ppcon;
typedef pair<int,ull> ph;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans(sz(wordsQuery),-1);
        vector<HashInterval> hsc, hsq;
        rep(i,0,sz(wordsContainer)) {
            HashInterval hs(wordsContainer[i]);
            hsc.push_back(hs);
        }
        int mxlen = 0;
        rep(i,0,sz(wordsQuery)) {
            HashInterval hs(wordsQuery[i]);
            max_self(mxlen, sz(wordsQuery[i]));
            hsq.push_back(hs);
        }
        set<int> blm;
        rep(i,0,sz(wordsQuery)) {
            blm.insert(i);
        }
        per(len,mxlen,0) {
            set<ppcon> con;
            rep(i,0,sz(wordsContainer)) {
                if(len<=sz(wordsContainer[i])) {
                    ppcon cur;
                    int j = sz(wordsContainer[i])-len;
                    ull hsi = hsc[i].hashInterval(j,sz(wordsContainer[i])).get();
                    con.insert({{sz(wordsContainer[i]),i},hsi});
                }
            }
            map<ull,set<int>> mp;
            for(auto iq: blm) {
                if(len<=sz(wordsQuery[iq])) {
                    int j = sz(wordsQuery[iq])-len;
                    ull hsi = hsq[iq].hashInterval(j,sz(wordsQuery[iq])).get();
                    mp[hsi].insert(iq);
                }
            }
            for(auto [lenid,hsi]: con) {
                if(sz(blm)==0) break;
                int id = lenid.se;
                if(mp.count(hsi)) {
                    for(auto iq: mp[hsi]) {
                        if(ans[iq]==-1) {
                            ans[iq] = id;
                            blm.erase(iq);
                        }
                    }
                    mp.erase(hsi);
                }
            }
        }
        int idxmin= 0, mn=sz(wordsContainer[0]);
        rep(i,1,sz(wordsContainer)) {
            int cur = sz(wordsContainer[i]);
            if(cur<mn) {
                mn = cur;
                idxmin = i;
            }
        }
        rep(i,0,sz(ans)) {
            if(ans[i]==-1) {
                ans[i] = idxmin;
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
    vector<string> wc = {"abcd","bcd","xbcd"};
    vector<string> wq = {"cd","bcd","xyz"};
    sol.stringIndices(wc,wq);
}