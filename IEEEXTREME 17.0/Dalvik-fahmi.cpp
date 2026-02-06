#include <bits/stdc++.h>

using namespace std;

vector<long long> v(20);

void solve() {
    v.clear();
    long long a,b,c;
    cin >> a >> b >> c;
    v[6] = 1LL;
    v[9] = a+b;
    for(int j=1; j<=c; j++){
        v[13] = ((j*a)-1)%b+1;
        if(v[13]*2 > b) v[13] -= b;
        // cout << "13: " << v[13] << '\n';
        v[13] = abs(v[13]);
        v[17] = v[13]*v[6] - v[9]*j;
        // cout << "17: " << v[17] << '\n';
        if(v[17]<0){
            v[6] = j;
            v[9] = v[13];
        }
    }
    cout << v[6] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}