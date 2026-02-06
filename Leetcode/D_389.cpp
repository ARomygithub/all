#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
    enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug{
    ~debug() {cerr << endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris << range(begin(i), end(i)); }
    sim, class b dor(pair <b, c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it=d.b;it!=d.e;++it) {
            *this <<", " + 2*(it==d.b) <<*it;
        }
        ris << "]";
    }
};
#define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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
typedef pair<ll,int> pli;

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
    void add(long long& sum, int& ct, int prv, int ai) {
        if(ai<prv || ai>prv+2) {
            sum += ai;
            ct++;
        }
    }
    void erase(long long& sum, int& ct, int prv, int ai) {
        if(ai<prv || ai>prv+2) {
            sum -= ai;
            ct--;
        }
    }
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> one;
        rep(i,0,sz(nums)) {
            if(nums[i]==1) one.push_back(i);
        }
        ll ans = 1e12;
        int k0 = k;
        ll mv0 = 0;
        if(nums[0]==1) {
            k0--;
        }
        int l=0,r=0;
        ll sl=0,sr=0;
        if(k0>0) {
            if(nums[1]==1) {
                k0--;
                mv0++;
            }
            int temp = min(maxChanges, k0);
            mv0 += temp*2;
            k0 -= temp;
            if(k0>0) {
                int idx = 0;
                while(one[idx]<=1) {
                    idx++;
                }
                while(k0>0) {
                    r = idx;
                    mv0 += one[idx];
                    sr += one[idx];
                    k0--;
                    idx++;
                }
            }
        }
        ans = mv0;
        vector<pli> v;
        bool ok2 = 0;
        rep(i,1,sz(nums)) {
            ll mv = 0;
            int ki = k;
            // cout <<nums[i] <<"\n";
            if(nums[i]==1) {
                // cout <<"TES\n";
                ki--;
            }
            if(ki>0 && nums[i-1]==1) {
                ki--;
                mv++;
            }
            if(ki>0 && i+1<sz(nums) && nums[i+1]==1) {
                ki--;
                mv++;
            }
            int temp = min(maxChanges, ki);
            mv += temp*2;
            ki -= temp;
            if(ki>0) {
                ;
            } else {
                min_self(ans, mv);
                ok2 = 1;
                // if(i+1<sz(nums)) {
                //     return ans;
                // }
                // break;
            }
            v.push_back({mv,ki});
        }
        if(ok2) return ans;
        if(sz(v)) {
            l = 0, r = 0;
            sl = 0, sr = 0;
            int ctl=0, ctr=0;
            while(one[r]<=2) {
                r++;
            }
            while(v[0].se>0) {
                v[0].se--;
                sr += one[r];
                r++;
                ctr++;
            }
            r--;
            if(sr>0) {
                // cout <<v[0].fi <<endl;
                min_self(ans, v[0].fi + sr - ctr*1);
            }
            rep(i,1,sz(v)) {
                if(v[i].se==0) continue;
                if(one[r]>=i+2 && nums[i+2]==1) {
                    sr -= i+2;
                    ctr--;
                }
                if(one[l]<=i-1 && nums[i-1]==1) {
                    sl += i-1;
                    ctl++;
                }
                while(r+1<sz(one) && one[r+1]<=i) {
                    r++;
                    add(sl, ctl, i, one[r]);
                }
                if(l<r && one[l]<i) {
                    erase(sl, ctl, i, one[l]);
                    l++;
                }
                // if(i+1==7) {
                //     debug() <<imie(sl) <<imie(ctl) <<imie(l);
                // }
                while(ctl+ctr<v[i].se) {
                    if(l>0 && r+1<sz(one)) {
                        int costl = abs(one[l-1]-(i+1));
                        int costr = abs(one[r+1]-(i+1));
                        if(costr<=costl) {
                            r++;
                            if(one[r]<i) {
                                add(sl, ctl, i, one[r]);
                            } else {
                                add(sr, ctr, i, one[r]);
                            }
                        } else {
                            l--;
                            if(one[l]<i) {
                                add(sl, ctl, i, one[l]);
                            } else {
                                add(sr, ctr, i, one[l]);
                            }
                        }
                    } else if(l>0) {
                        l--;
                        if(one[l]<i) {
                            add(sl, ctl, i, one[l]);
                        } else {
                            add(sr, ctr, i, one[l]);
                        }
                    } else if(r+1<sz(one)) {
                        r++;
                        if(one[r]<i) {
                            add(sl, ctl, i, one[r]);
                        } else {
                            add(sr, ctr, i, one[r]);
                        }
                    }
                }
                ll mv = v[i].fi + sr - 1ll*ctr*(i+1) + 1ll*ctl*(i+1) - sl;
                // if(i==3) {
                //     return mv;
                // }
                // debug() <<imie(i+1) <<imie(mv);
                // debug() <<imie(l) <<imie(r);
                // debug() <<imie(sl) <<imie(sr);
                // debug() <<imie(ctl) <<imie(ctr);
                // debug() <<imie(v[i]);
                min_self(ans, mv); 
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
    vi nums = {0,1,0,0,1,1,0,1,0,1,1};
    int ret = sol.minimumMoves(nums, 8, 4);
    cout <<ret <<"\n";
}