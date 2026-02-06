#include <bits/stdc++.h>
using namespace std;
 
 
// Define Template          Python++
// Math
 
// Data Structure and Algorithm
#define all(vec)            (vec).begin(),(vec).end()
#define arrsize(arr)        sizeof(arr)/sizeof(int)
#define sortarr(arr)        sort(arr,arr+arrsize(arr));
#define sortvec(vec)        sort(all(vec));
#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
// Input Output Manage
#define fastIO              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define input(var)          int var;cin>>var;
#define input2(a,b)         int a,b;cin>>a>>b;
#define print(var)          cout<<(var)<<endl;
// Macro
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define int long long
int QUERY;
// Constant
const int MOD = 1e9+7;
const long long INF = 1e18;
const int maxn = 3e4;
 
 
int n,sqrt_n;
struct tquery{
    int idx, L,R;
};
 
bool cmptq(tquery a, tquery b){
    if((a.L)/sqrt_n == (b.L)/sqrt_n) return a.R < b.R;
    else return (a.L)/sqrt_n < (b.L)/sqrt_n;
}
 
int arr[maxn];
 
void solve(){
    cin >> n;
    range(i,0,n) cin >> arr[i];
    // sqrt_n = sqrt(n)+ 1;
    sqrt_n = 305;
 
 
    vector<tquery> vq;
    input(q)
    range(i,0,q){
        input2(l,r)
        tquery temp;
        temp.idx = i;
        temp.L =l-1; // 0-indexing
        temp.R = r-1; // 0-indexing
        vq.pb(temp);
    }
 
    sort(vq.begin(),vq.end(),cmptq);
 
    int i_l = 0;
    int i_r = 0;
 
    vector<int> vp(q);
    mii mapp;
    mapp[arr[0]]++;
 
    range(i,0,q){
        // process the sorted query
 
        // assuming i_l < L
        // there are 2 cases
        //  - we haven't traverse through all i between [i_l,L]
        //  - we have traverse through all i between [i_l,L]. if that is the case, then we have to delete all element from the map
 
        while(i_l > vq[i].L){
            i_l--;
            mapp[arr[i_l]]++;
        }
 
        while(i_r < vq[i].R){
            i_r++;
            mapp[arr[i_r]]++;
        }
 
        while(i_l < vq[i].L){
            if(--mapp[arr[i_l]] == 0){
                mapp.erase(arr[i_l]);
            }
            i_l++;
        }
 
        // assuming i_L > L
        // there are 1 cases
        // - we haven't added all element between [i_l,L]
 
 
        // assuming i_r < R
        // there are only 1 cases
        // - we haven't traverse through all elements between [i_R,R]
 
 
 
        // assuming i_r > R
        // there are only 1 cases
        // - we want to delete all of the elements between [R,i_r]
 
        while(i_r > vq[i].R){
            if(--mapp[arr[i_r]] == 0){
                mapp.erase(arr[i_r]);
            }
            i_r--;
        }
 
        vp[vq[i].idx] = mapp.size();
    }
 
    // sort(vp.begin(),vp.end());
    range(i,0,q){
        print(vp[i])
    }
 
}
 
 
int32_t main(){
    fastIO
 
 
     solve();
 
 
    return 0;
}
 