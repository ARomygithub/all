#include <bits/stdc++.h>
using namespace std;
 
long long tri(long long x){
	return (x * (x - 1)) / 2;
}
 
long long sweep(vector<pair<int, pair<int, int>>> &ev){
	long long ret = 0;
	sort(ev.begin(), ev.end());
	int n = ev.size();
	for (int l=0; l<n; ){
		int r = l+1;
		map<int, long long> sez;
		long long sum = 0;
		while (r < n && ev[r].second.first == 1){
			if (ev[r].first > ev[l].first){
				sum++;
				sez[ev[r].second.second]++;
			}
			r++;
		}
		ret += tri(sum);
		for (auto p : sez) ret -= tri(p.second);
		l = r;
	}
	return ret;
}
 
void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, pair<int, int>>> lr, du; // {main axis, {type, secondary axis}} type: 0 line, 1 point
	for (int i=0; i<n; i++){
		// vertical
		int x;
		cin >> x;
		lr.push_back({x, {0, -1}});
	}
	for (int i=0; i<m; i++){
		// horizontal
		int y;
		cin >> y;
		du.push_back({y, {0, -1}});
	}
	for (int i=0; i<k; i++){
		int x, y;
		cin >> x >> y;
		lr.push_back({x, {1, y}});
		du.push_back({y, {1, x}});
	}
	long long ans = 0;
	ans += sweep(lr);
	ans += sweep(du);
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tcs;
	cin >> tcs;
	while (tcs--){
		solve();
	}
    return 0;
}