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
typedef pair<int,ull> ph;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans(sz(wordsQuery),-1);
        vector<pcon> con;
        rep(i,0,sz(wordsContainer)) {
            HashInterval hs(wordsContainer[i]);
            rep(j,0,sz(wordsContainer[i])) {
                pcon cur;
                cur.fi = {j-sz(wordsContainer[i]),sz(wordsContainer[i])};
                ull hsi = hs.hashInterval(j,sz(wordsContainer[i])).get();
                cur.se = {i,hsi};
                con.push_back(cur);
            }
        }
        sort(con.begin(),con.end());
        map<ph,set<int>> mp;
        rep(i,0,sz(wordsQuery)) {
            HashInterval hs(wordsQuery[i]);
            rep(j,0,sz(wordsQuery[i])) {
                ph cur;
                ull hsi = hs.hashInterval(j,sz(wordsQuery[i])).get();
                cur = {sz(wordsQuery[i])-j,hsi};
                mp[cur].insert(i);
            }
        }
        rep(i,0,sz(con)) {
            auto [sufasli, idhash] = con[i];
            auto [lsuf, len] =sufasli;
            auto [id,hs] = idhash;
            lsuf *=-1;
            // cout <<lsuf <<" " <<len <<" " <<id <<endl;
            ph cur = {lsuf,hs};
            if(mp.count(cur)) {
                for(auto iq: mp[cur]) {
                    if(ans[iq]==-1) {
                        ans[iq] = id;
                    }
                }
                mp.erase(cur);
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