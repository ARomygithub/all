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
typedef pair<pii,int> piii;

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
piii sc[mxn],ld[mxn];
map<int,int> mps,mpl;

void updAns(vector<pii>& vans, ll mn, set<int>& sl, set<int>& sr) {
    auto it = sl.begin(), jt=sr.begin();
    bool cekSkip=1;
    // cout <<"TES\n";
    // for(int sll : sl) {
    //     cout <<"sl " <<sll <<"\n";
    // }
    // for(int srr: sr) {
    //     cout <<"sr " <<srr <<"\n";
    // }
    // cout <<mn <<"\n";
    while(it!=sl.end() && jt!=sr.end()) {
        if(sc[*jt].fi.se==mn && cekSkip) {
            jt++;
            cekSkip = 0;
            continue;
        }
        if(ld[*it].fi.fi>sc[*jt].fi.fi) {
            jt++;
        } else if(ld[*it].fi.fi+1<sc[*jt].fi.fi) {
            it++;
        } else {
            if(ld[*it].fi.se>=sc[*jt].fi.se) {
                vans.push_back({mpl[*it],mps[*jt]});
                it++; jt++;
            } else {
                auto jt1 = jt; jt1++;
                if(jt1==sr.end()) {
                    it++;
                    continue;
                }
                if(sc[*jt1].fi.se==mn && cekSkip) {
                    it++;
                    continue;
                }
                if(ld[*it].fi.fi+1<sc[*jt1].fi.fi || ld[*it].fi.se<sc[*jt1].fi.se) {
                    it++;
                    continue;
                }
                vans.push_back({mpl[*it],mps[*jt1]});
                it++;
                while(it!=sl.end()) {
                    if(ld[*it].fi.fi<=sc[*jt].fi.fi) {
                        if(ld[*it].fi.se>=sc[*jt].fi.se) {
                            vans.push_back({mpl[*it],mps[*jt]});
                            it++;
                            break;
                        } else {
                            it++;
                        }
                    } else {
                        break;
                    }
                }
                jt = jt1; jt++;
            }
            // cout <<"TEs\n";
        }
    }
}

void solve() {
    cin >>n;
    rep(i,0,n) {
        cin >>sc[i].fi.se >>sc[i].fi.fi;
        sc[i].se = i+1;
    }
    cin >>m;
    rep(i,0,m) {
        cin >>ld[i].fi.se >>ld[i].fi.fi;
        ld[i].se = i+1;
    }
    ll ans=0;
    sort(sc,sc+n);
    sort(ld,ld+m);
    rep(i,0,n) {
        mps[i] = sc[i].se;
    }
    rep(i,0,m) {
        mpl[i] = ld[i].se;
    }
    int l=-1,r=-1;
    ll sum=0, mn=1e18;
    int j=0;
    set<int> sl,sr;
    vector<pii> vans;
    vector<pii> temp;
    rep(i,0,m) {
        while(j<n && ld[i].fi.fi > sc[j].fi.fi) {
            j++;
        }
        if(j==n) break;
        if(ld[i].fi.fi+1>=sc[j].fi.fi && ld[i].fi.se>=sc[j].fi.se) {
            temp.push_back({i,j});
        }
        if(j+1==n) continue;
        if(ld[i].fi.fi+1>=sc[j+1].fi.fi && ld[i].fi.se>=sc[j+1].fi.se) {
            temp.push_back({i,j+1});
        } 
    }
    sort(temp.begin(),temp.end(), [&](pii a, pii b) {
        return make_pair(ld[a.fi].fi.fi,sc[a.se].fi.fi)<make_pair(ld[b.fi].fi.fi,sc[b.se].fi.fi);
    });
    rep(k,0,sz(temp)) {
        auto [i,j] = temp[k];
        if(ld[i].fi.fi<=l || sc[j].fi.fi<=r) {
            if(sc[j].fi.fi>r) {
                sum +=sc[j].fi.se;
                min_self(mn,sc[j].fi.se*1ll);
            }
            max_self(l,ld[i].fi.fi); max_self(r,sc[j].fi.fi);
            sl.insert(i); sr.insert(j);
        } else {
            if(sz(sl)>=sz(sr)) {
                ans +=sum;
                updAns(vans, 1e18, sl, sr);
            } else {
                ans +=sum-mn;
                updAns(vans, mn, sl, sr);                                        
            }
            // cout <<mn <<"\n";
            sl.clear(); sr.clear();
            // cout <<"ij " <<i <<" " <<j <<"\n";
            sl.insert(i); sr.insert(j);
            l = ld[i].fi.fi; r= sc[j].fi.fi;
            sum =sc[j].fi.se; mn = sc[j].fi.se;
        }
    }
    if(sz(sl)>=sz(sr)) {
        ans +=sum;
        updAns(vans, 1e18, sl, sr);
    } else {
        ans +=sum-mn;
        updAns(vans, mn, sl, sr);                                        
    }
    cout <<ans <<"\n";
    cout <<sz(vans) <<"\n";
    for(auto [cus,shoe]: vans) {
        cout <<cus <<" " <<shoe <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}