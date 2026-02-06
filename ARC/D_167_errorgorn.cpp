#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
int brr[200005];

set<int> s[200005];
set<int> S;

int P[200005];

int par(int i){
	if (P[i]==i) return i;
	else return P[i]=par(P[i]);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		S.clear();
		rep(x,1,n+1){
			brr[arr[x]]=x;
			s[x].clear();
			P[x]=x;
		}
		
		rep(x,1,n+1) if (par(x)!=par(arr[x])){
			int a=par(x),b=par(arr[x]);
			P[a]=b;
		}
		
		rep(x,1,n+1) s[par(x)].insert(x);
		rep(x,1,n+1) if (P[x]==x) S.insert(*s[x].begin());
		
		rep(x,1,n+1){
			if (sz(S)==1) break;
			
			int p=par(x);
			S.erase(*s[p].begin());
			s[p].erase(arr[x]);
			
			int mn=*S.begin();
			
			if (mn<arr[x] || s[p].empty()){
				int i=x,j=brr[mn];
				int pi=par(i),pj=par(j);
				
				P[pj]=pi;
				S.erase(*s[pj].begin());
				s[pj].erase(mn);
				if (sz(s[pi])<sz(s[pj])) swap(s[pi],s[pj]);
				for (auto it:s[pj]) s[pi].insert(it);
				s[pi].insert(arr[x]);
				S.insert(*s[pi].begin());
				
				swap(arr[i],arr[j]);
				swap(brr[arr[i]],brr[arr[j]]);
			}
			else{
				S.insert(*s[p].begin());
			}
			
			// rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
			// for (auto it:S) cout<<it<<" "; cout<<endl;
			// rep(x,1,n+1) if (P[x]==x){
				// cout<<x<<": "; for (auto it:s[x]) cout<<it<<" "; cout<<endl;
			// }
			// cout<<endl;
		}
		
		rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
	}
}
