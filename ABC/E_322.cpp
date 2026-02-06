#include <bits/stdc++.h>
using namespace std;

// #define fi first
// #define se second
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//     enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge {c b, e;};
// sim > rge<c> range(c i, c j) {return rge<c>{i,j};}
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug{
//     ~debug() {cerr << endl;}
//     eni(!=) cerr << boolalpha << i; ris; }
//     eni(==) ris << range(begin(i), end(i)); }
//     sim, class b dor(pair <b, c> d) {
//         ris <<"(" <<d.fi <<", " <<d.se <<")";
//     }
//     sim dor(rge<c> d) {
//         *this << "[";
//         for(auto it=d.b;it!=d.e;++it) {
//             *this <<", " + 2*(it==d.b) <<*it;
//         }
//         ris << "]";
//     }
// };
// #define imie(...) "[" <<#__VA_ARGS__ ": " << (__VA_ARGS__) <<"]"

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

const int mxn=1e2,mxa=5;
int n,k,p;
int a[mxn][mxa],c[mxn];

string getString6(int j) {
    string res="";
    while(j) {
        res +=(char)('0'+(j%6));
        j /=6;
    }
    while(sz(res)<k) {
        res +='0';
    }
    reverse(res.begin(),res.end());
    return res;
}

void solve() {
    cin >>n >>k >>p;
    for(int i=0;i<n;i++) {
        cin >>c[i];
        for(int j=0;j<k;j++) {
            cin >>a[i][j];
        }
    }
    int nall = 1;
    for(int i=0;i<k;i++) {
        nall *=6;
    }
    vector<ll> dp(nall,1e18);
    dp[0] = 0;
    for(int i=0;i<n;i++) {
        vector<ll> dp_new(nall,1e18);
        for(int j=0;j<nall;j++) {
            min_self(dp_new[j],dp[j]);
            string js = getString6(j);
            // if(dp[j]<1e18) {
            //     debug() <<"Js sebelum " <<imie(js);
            // }
            for(int l=0;l<k;l++) {
                js[l] = min('5',(char)(js[l]+a[i][l]));
            }
            // cout <<js <<"\n";
            // cout <<flush;
            int temp = stoi(js, nullptr, 6);
            // cout <<temp <<"\n";
            // cout <<flush;
            min_self(dp_new[temp],dp[j]+c[i]);
            // if(dp_new[temp]<1e18) {
            //     debug() <<imie(js) <<imie(dp_new[temp]);
            // }
        }
        dp.swap(dp_new);
    }
    int idx = 0,kali=1;
    for(int i=0;i<k;i++) {
        idx +=kali*p;
        kali *=6;
    }
    ll ans=1e18;
    for(int i=0;i<nall;i++) {
        string js=getString6(i);
        bool flag=1;
        for(int j=0;j<k&&flag;j++) {
            flag &= js[j]>=((char)('0'+p));
        }
        if(flag) {
            min_self(ans,dp[i]);
        }
    }
    if(ans==1e18) {
        cout <<"-1\n";
    } else {
        cout <<ans <<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}