#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int d[n];
    for(int i=0; i<n; i++){
        cin >> d[i];
    }
    sort(d+1, d+n);
    map<ll, int> idx;
    ll one = 0;
    bool ok = 0;
    for(int i=1; i<= m+1 && !ok; i++){
        one = (one*10+1)%m;
        if(idx[one]){
            for(int j=1; j<n; j++){
                for(int k=1; k<i-idx[one]; k++){
                    cout << d[j];
                }
                for(int k=0; k<idx[one]; k++){
                    cout << 0;
                }
            }
            cout << 0 << "\n";
            ok = 1;
        }
        else{
            idx[one] = i;
        }
    }
    if(!ok){
        cout << -1 << "\n";
    }
    return 0;
}