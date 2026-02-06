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

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=2e5;
int n,m;
string s,t;

void solve() {
    cin >>n >>m;
    cin >>s >>t;
    if(m==1) {
        int ct = count(s.begin(),s.end(),t[0]);
        cout <<(ct==n?"Yes":"No") <<"\n";
        return;
    }
    vector<vector<int>> partisi;
    function<void(vector<int>&, int)> doPartisi;
    map<vector<int>, int> mp;
    doPartisi = [&](vector<int>& temp, int sisa) -> void {
        mp[temp] = sz(partisi);
        partisi.push_back(temp);
        rep(i,1,sisa+1) {
            temp.push_back(i);
            doPartisi(temp, sisa-i);
            temp.pop_back();
        }
    };
    vector<int> temp;
    doPartisi(temp, m-1);
    vector<bool> flag(sz(partisi), 0);
    flag[0] = 1;
    rep(i,0,n) {
        vector<bool> new_flag(sz(partisi),0);
        bool gavalid = 1;
        rep(j,0,sz(partisi)) {
            if(!flag[j]) continue;
            vector<int> now = partisi[j];
            // ga diambil or ditumpuk sz(now)+1 pilihan
            auto doSimul = [&](vector<int> v) -> void {
                // if(i==2 && j==1) {
                //     debug() <<imie(v);
                // }
                bool valid = sz(v)>0 && (t[m-v[0]]==s[i]);
                if(!valid) return;
                gavalid = 0;
                vector<int> new_v;
                v[0] -=1;
                rep(k,0,sz(v)) {
                    if(v[k]>0) new_v.push_back(v[k]);
                }
                // if(i==2 && j==1) {
                //     debug() <<imie(new_v);
                //     debug() <<imie(mp[new_v]);
                // }                
                new_flag[mp[new_v]] = 1;
            };
            doSimul(now);
            rep(k,0,sz(now)+1) {
                int len = m;
                vector<int> v;
                rep(k1,0,sz(now)) {
                    if(k1<k) { //atas
                        len -=now[k1];
                        v.push_back(now[k1]);
                    } else {
                        break;
                    }
                }
                v.push_back(len);
                doSimul(v);
            }
        }
        if(gavalid) {
            cout <<"No\n";
            return;
        }
        flag.swap(new_flag);
        // debug() <<imie(flag);
    }
    if(flag[0]) {
        cout <<"Yes\n";
    } else {
        cout <<"No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}