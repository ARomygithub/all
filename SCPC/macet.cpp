#include<bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define ar array

const int mxn=1e3;
int t,x,y,n;
int j,uc,sc, u[5], s[5];
int p[mxn];
vector<ar<ll,2>> adj1[mxn]; 
vector<ar<ll,2>> adj2[mxn];
ll d[mxn];
ll d1[5][mxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    ifstream ff;
    ff.open("macet_0_2.in");
    
    ff >>t;
    while(t--) {
        ff >>x >>y >>n;
        ff >>j >>uc >>sc;
        for(int i=0;i<uc;i++) {ff>>u[i]; u[i]--;}
        for(int i=0;i<sc;i++) {ff>>s[i]; s[i]--;}
        for(int i=0;i<j;i++) {
            ll a,b,c,e; ff >>a >>b >>c >>e; a--, b--;
            if(a!=b) {
                if(e>=x) {
                    adj1[a].push_back({c,b});
                    adj1[b].push_back({c,a});
                }
                if(e>=y) {
                    adj2[a].push_back({c,b});
                    adj2[b].push_back({c,a});
                }
            }
        }
        bool ok1=false;
        ll ans1 = 1e9;
        for(int i=0;i<sc;i++) {
            priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
            pq.push({0,s[i]});
            memset(d1[i],0x3f,sizeof(d1[i]));
            d1[i][s[i]]=0;
            while(pq.size()) {
                ar<ll,2> a = pq.top(); pq.pop();
                if(a[0]>d1[i][a[1]]) continue;
                for(auto b : adj1[a[1]]) {
                    if(d1[i][b[1]]>a[0]+b[0]) {
                        d1[i][b[1]]=a[0]+b[0];
                        pq.push({d[b[1]],b[1]});
                    }
                }
            }
            for(int j=0;j<uc;j++) {
                ans1 = min(ans1,d1[i][u[j]]);
            }
        }
        if(ans1<1e9) ok1=true;
        bool ok2=false; ll ans2=1e9;
        for(int i=0;i<sc;i++) {
            priority_queue<ar<ll,2>,vector<ar<ll,2>>,greater<ar<ll,2>>> pq;
            pq.push({0,s[i]});
            memset(d,0x3f,sizeof(d));
            d[s[i]]=0;
            while(pq.size()) {
                ar<ll,2> a = pq.top(); pq.pop();
                if(a[0]>d[a[1]]) continue;
                for(auto b : adj2[a[1]]) {
                    if(d[b[1]]>a[0]+b[0]) {
                        d[b[1]]=a[0]+b[0];
                        p[b[1]]=a[1];
                        pq.push({d[b[1]],b[1]});
                    }
                }
            }
            for(int j=0;j<uc;j++) {
                if(!ok1) {
                    if(d[u[j]]<(ll)1e9) {
                        set<int> udah;
                        int c=u[j];
                        while(c^s[i]) {
                            udah.insert(c);
                            c =p[c];
                        }
                        udah.insert(s[i]);
                        ll ans11=(ll)1e9;
                        for(int k=0;k<sc;k++) {
                            for(int l=0;l<n;l++) {
                                if(udah.find(l)==udah.end()) {
                                    ans11 = min(ans11,d1[k][l]);
                                }
                            }  
                        }
                        if(ans11<1e9) ok2=true;
                        ans2 = min(ans2,d[u[j]]+ans11);                      
                    }
                } else {
                    ans2= min(ans2,d[u[j]]);
                }
            }
        }
        if(ans2<1e9) ok2=true;
        if(ok1 && ok2) {
            cout <<"2 " <<(ans1+ans2) <<"\n";
        } else if(ok1) {
            cout <<"1 " <<ans1 <<"\n";
        } else if(ok2) {
            cout <<"1 " <<ans2 <<"\n";
        } else {
            cout <<"-1\n";
        }       

        for(int i=0;i<mxn;i++) adj1[i].clear();
        for(int i=0;i<mxn;i++) adj2[i].clear();
    }
    ff.close();
}