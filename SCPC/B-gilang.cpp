#include <bits/stdc++.h>
 
using namespace std;
 
#define ff                  first
#define ss                  second
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define lb                  lower_bound
#define ub                  upper_bound
#define setbits(x)          __builtin_popcountll(x)
#define trailing_zeros(x)   __builtin_ctzll(x)
#define leading_zeros(x)    __builtin_clzll(x)
#define sz(v)               (int)v.size()
#define ps(y)               cout << fixed << setprecision(y)
#define ms(arr, v)          memset(arr, v, sizeof(arr))
#define all(v)              v.begin(), v.end()
#define rall(v)             v.rbegin(), v.rend()
#define trav(x, v)          for(auto &x: v)
#define w(t)                int t; cin >> t; while(t--)
#define rep(i, a, b)        for(int i = a; i <= b; i++)
#define rrep(i, a, b)       for(int i = a; i >= b; i--)
#define rep0(i, n)          rep(i, 0, n - 1)
#define rrep0(i, n)         rrep(i, n - 1, 0)
#define rep1(i, n)          rep(i, 1, n)
#define rrep1(i, n)         rrep(i, n, 1)
#define inp(arr, n)         rep0(i, n) cin >> arr[i];

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef map<ll, ll> mii;
typedef map<char, ll> mci;
typedef priority_queue<ll> pq_mx;
typedef priority_queue<ll, vi, greater<>> pq_mn;

ll lengthNum(ull x){
    ll ret = 0;
    while(x>0){
        x /= 10;
        ret++;
    }
    return ret;
}

string convertToBinary(ull x, ll length){
    string ret = "";
    ll tempIndex = length-1;
    ull index = 0;
    ull power2 = pow(10,tempIndex);
    while(tempIndex>=0){
        ull temp = x/power2;
        ull res = temp%10;
        if(res<4){
            if(index==0) return "0";
            else{
                int prevIndex = index - 1;
                while(ret[prevIndex]=='0'){
                    prevIndex--;
                }
                ret[prevIndex] = '0';
                for(ull i = prevIndex + 1; i<=index; i++) ret[i] = '1';
                for(ull i = index+1; i<=length; i++) ret += '1';
                return ret;
            }
        }else{
            if(res < 7) ret += '0';
            else ret += '1';
        }
        tempIndex--;
        power2 /= 10;
        index++;
    }
    return ret;
}


void solve(){
    int t; cin >> t;
    while(t--){
        ull x; cin >> x;
        ll lengthNumV = lengthNum(x);
        ull a = pow(2,lengthNumV) - 2;
        string bin_string = convertToBinary(x,lengthNumV);
        cout << a + stoi(bin_string, 0, 2)+1 << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    solve();
 
    return 0;
}