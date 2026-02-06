#include<bits/stdc++.h>
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
struct debug {
    ~debug() {cerr <<endl;}
    eni(!=) cerr << boolalpha << i; ris; }
    eni(==) ris <<range(begin(i),end(i)); }
    sim, class b dor(pair<b,c> d) {
        ris <<"(" <<d.fi <<", " <<d.se <<")";
    }
    sim dor(rge<c> d) {
        *this << "[";
        for(auto it = d.b;it!=d.e;++it) {
            *this << ", " + 2*(it==d.b) <<*it;
        }
        ris <<"]";
    };
};
#define imie(...) "[" <<#__VA_ARGS__ ": " <<(__VA_ARGS__) <<"]"

#define ll long long
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define sz(x) (int)(x).size()

typedef pair<int,ll> pil;

template<typename T>
void min_self(T& a, T b) {
    a = min(a,b);
}

const int mxn=1e4,mxa=2e6;
const ll mod=1e9+7;
int n,t;
int a[mxn],b[mxn];
vector<pil> ans; 

ll fastexpo(ll a, ll b) {
    ll ret=1;
    while(b) {
        if(b&1) {ret=(ret*a)%mod;}
        a = (a*a)%mod;
        b >>=1;
    }
    return ret;
}

void solve() {
    cin >>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        cin >>a[i];
        v.push_back(a[i]);
    }
    for(int i=0;i<n;i++) {
        cin >>b[i];
        v.push_back(b[i]);
    }
    sort(v.begin(),v.end());
    ll sum1=0,sum2=0;
    for(int i=0;i<n;i++) {
        sum1 +=v[i];
    }
    for(int i=n;i<n*2;i++) {
        sum2 +=v[i];
    }
    int avg1 = (sum1)/n, avg2=(sum2)/n;
    ll tes = -1e9;
    auto it1 = upper_bound(ans.begin(),ans.end(),mp(avg1,tes));
    ll ansi=1e18;
    if(it1==ans.begin()) {
        min_self(ansi,1ll);
    } else {
        it1--;
        min_self(ansi,it1->second);
    }
    auto it2 = upper_bound(ans.begin(),ans.end(),mp(avg2,tes));
    if(it2==ans.begin()) {
        min_self(ansi,1ll);
    } else {
        it2--;
        min_self(ansi,it2->second);
    }
    cout <<ansi <<"\n";
}

int init() {
    vector<bool> isComposit(mxa+1,0);
    vector<int> prime;
    for(int i=2;i<=mxa;i++) {
        if(isComposit[i]) continue;
        prime.push_back(i);
        for(int j=i*2;j<=mxa;j+=i) {
            isComposit[j] = 1;
        }
    }
    int ct=1;
    ll sum=prime[0];
    int idxmin=0,idxmax=0,idxmid=0;
    ll x = 1ll*prime[idxmin]*prime[idxmax]/prime[idxmid];
    x %=mod;
    ll temp2 = (1ll*prime[idxmid]*prime[idxmin] + prime[idxmax]);
    ll y = ((sum)+(idxmax>0?prime[idxmax-1]:0)+prime[idxmax])/temp2;
    y %=mod;
    ll z = (sum+ct)/(prime[idxmax]+prime[idxmid]);
    z %=(mod-1);
    ll temp = x*y%mod;
    temp = fastexpo(temp,z)%mod;
    ans.push_back({prime[0],temp});    
            debug() <<imie(ct) <<imie(sum);
            debug() <<imie(idxmin) <<imie(idxmid) <<imie(idxmax);
            debug() <<imie(x) <<imie(y) <<imie(z);
            debug() <<imie(prime[0]) <<imie(temp);       
    for(int i=1;i<sz(prime);i++) {
        ct++;
        sum = (sum+prime[i]);
        idxmax++;
        idxmid = (idxmax+1)/2;
        x = 1ll*prime[idxmin]*prime[idxmax]/prime[idxmid];
        temp2 = (1ll*prime[idxmid]*prime[idxmin] + prime[idxmax]);
        y = ((sum)+prime[idxmax-1]+prime[idxmax])/temp2;
        z = (sum+ct)/(prime[idxmax]+prime[idxmid]);
        z %=(mod-1);
        // if(x>0 && y>0 && z==0) {
        //     cout <<"Ketemu " <<i <<"\n";
        //     cout <<flush;
        // }
        x %=mod;
        y %=mod;
        temp = x*y%mod;
        temp = fastexpo(temp,z)%mod;
        ans.push_back({prime[i],temp});
        if(i<=10) {
            debug() <<imie(ct) <<imie(sum);
            debug() <<imie(idxmin) <<imie(idxmid) <<imie(idxmax);
            debug() <<imie(x) <<imie(y) <<imie(z);
            debug() <<imie(prime[i]) <<imie(temp);            
        }
    }
    // for(int i=0;i<15;i++) {
    //     cout <<ans[i].fi <<" " <<ans[i].se <<"\n";
    // }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>t;
    init();
    while(t--) {
        solve();
    }
}