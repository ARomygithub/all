/*******************************************************
** This program was written by *Sakamoto.             **
** Intended for educational use.                      **
** No rights reserved.                                **
*******************************************************/


/* All library and pragma */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 
/* For PBDS */ 
typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
 
/* For pair */ 
#define mp make_pair
#define fi first
#define se second

/* For Random number generator */ 
//mt19937 rng(time(NULL)); //int
//mt19937_64 rng(time(NULL)); //Long Long
//shuffle(a.begin(),a.end(),rng); //shuffle
//rng(); //random
long long a[100005], b[100005];
vector<pair<long long, long long> > v;

int main(){
	/* Fast IO */
	
	int n;
	long long m;
	cin >> n >> m;
	long long sumb = 0;
	
	long long maxi = -1e18;
	long long nilai = 0;
	
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] %= m;
	}
	
	for(int i=1; i<=n; i++){
		cin >> b[i];
		sumb += b[i];
		nilai += b[i]*a[i];
		v.push_back(mp(a[i], b[i]*m));
	}
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	maxi = max(maxi, nilai);
	long long now = m-1;
	
	for(int i=0; i<n; i++){
		long long dif = now-v[i].fi;
		now = v[i].fi;
		nilai += dif * sumb;
		
		maxi = max(maxi, nilai);
		nilai -= v[i].se;
	}
	
	nilai += now * sumb + sumb;
	
	cout << maxi << endl;
	
}
