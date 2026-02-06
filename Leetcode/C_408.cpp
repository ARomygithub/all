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

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> v;
        int tmp = 0;
        rep(i,0,sz(s)) {
            if(s[i]=='0') {
                v.push_back(tmp);
                tmp = 0;
            } else {
                tmp++;
            }
        }
        v.push_back(tmp);
        rep(i,0,sz(v)) {
            ans += v[i]*(v[i]+1)/2;
        }
        rep(len,1,201) {
            if(len*len + len > sz(s)) break;
            int sm = v[0];
            int l=0;
            rep(r,1,sz(v)) {
                if(r-l <=len) {
                    sm += v[r];
                } else {
                    sm += v[r]-v[l];
                    l++;
                }
                if(r-l == len) {
                    // cout <<l <<" " <<r <<endl;
                    // cout <<v[l] <<" " <<v[r] <<endl;
                    int sisa = max(0, len*len - sm + v[l]+v[r]);
                    // cout <<sisa <<endl;
                    if(sisa==0) {
                        ans += (v[l]+1)*(v[r]+1);
                    } else {
                        if(v[l]>=sisa) {
                            ans += (v[l]-sisa+1)*(v[r]+1);
                            // cout <<"add " <<(v[l]-sisa+1)*(v[r]+1) <<endl;
                        }
                        int ats = min(v[l],sisa-1);
                        int bw = max(0, sisa-v[r]);
                        if(bw<=ats) {
                            int ats2 = v[r]-(sisa-ats)+1;
                            int bw2 = v[r]-(sisa-bw)+1;
                            ans += 1ll*(ats2-bw2+1)*(ats2+bw2)/2;
                            // cout <<"add " <<1ll*(ats2-bw2+1)*(ats2+bw2)/2 <<endl;
                        }
                    }
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
    cout <<sol.numberOfSubstrings("101101");
}