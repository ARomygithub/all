#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
typedef pair<int,pii> pipi;

template<typename T>
void min_self(T& A, T B) {
    A = min(A,B);
}
template<typename T>
void max_self(T& A, T B) {
    A = max(A,B);
}

const int mxn=1e5;
int n,m;

void solve() {
    cin >>n >>m;
    vector<pii> ans;
    vector<int> r(n+1,n-m), c(n+1,n-m);
    map<int,set<int>> mpr,mpc;
    set<int> row, col;
    rep(i,1,n+1) {
        row.insert(i);
        col.insert(i);
    }
    rep(i,0,m) {
        int ai,bi; cin >>ai >>bi;
        ans.push_back({ai,bi});
        mpr[ai].insert(bi);
        mpc[bi].insert(ai);
        if(sz(mpr[ai])==m) {
            row.erase(ai);
            for(auto bbi: mpr[ai]) {
                c[bbi]++;
            }
        }
        if(sz(mpc[bi])==m) {
            col.erase(bi);
            for(auto aai: mpc[bi]) {
                r[aai]++;
            }
        }
    }
    set<pipi> st;
    rep(i,1,n+1) {
        if(sz(mpr[i])<m) {
            st.insert({r[i],{i,0}});
        }
        if(sz(mpc[i])<m) {
            st.insert({c[i],{i,1}});
        }
    }
    while(sz(st)) {
        auto [ct, idd] = *st.begin(); st.erase(st.begin());
        auto [id, tp] = idd;
        if(tp==0) {
            set<int> vit;
            auto it = col.begin();
            while(sz(mpr[id])!=m) {
                while(mpr[id].find(*it)!=mpr[id].end()) {
                    it++;
                }
                vit.insert(*it);
                ans.push_back({id,*it});
                st.erase({c[*it],{*it,1}});
                mpr[id].insert(*it);
                mpc[*it].insert(id);
            }
            row.erase(id);
            for(auto bbi: mpr[id]) {
                c[bbi]++;
                if(col.count(bbi) && vit.count(bbi)==0) {
                    st.erase({c[bbi]-1,{bbi,1}});
                    st.insert({c[bbi],{bbi,1}});
                }
            }
            for(auto viti : vit) {
                if(sz(mpc[viti])==m) {
                    col.erase(viti);
                    for(auto aai: mpc[viti]) {
                        r[aai]++;
                        if(row.count(aai)) {
                            st.erase({r[aai]-1,{aai,0}});
                            st.insert({r[aai],{aai,0}});
                        }
                    }
                } else {
                    st.insert({c[viti],{viti,1}});
                }
            }
        } else {
            set<int> vit;
            auto it = row.begin();
            while(sz(mpc[id])!=m) {
                while(mpc[id].find(*it)!=mpc[id].end()) {
                    it++;
                }
                vit.insert(*it);
                ans.push_back({*it,id});
                st.erase({r[*it],{*it,0}});
                mpr[*it].insert(id);
                mpc[id].insert(*it);
            }
            col.erase(id);
            for(auto aai: mpc[id]) {
                r[aai]++;
                if(row.count(aai) && vit.count(aai)==0) {
                    st.erase({r[aai]-1,{aai,0}});
                    st.insert({r[aai],{aai,0}});
                }
            }                
            for(auto viti: vit) {
                if(sz(mpr[viti])==m) {
                    row.erase(viti);
                    for(auto bbi: mpr[*it]) {
                        c[bbi]++;
                        if(col.count(bbi)) {
                            st.erase({c[bbi]-1,{bbi,1}});
                            st.insert({c[bbi],{bbi,1}});
                        }
                    }                
                } else {
                    st.insert({r[viti],{viti,0}});
                }
            }
        }
    }
    cout <<sz(ans) <<"\n";
    rep(i,0,sz(ans)) {
        cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}