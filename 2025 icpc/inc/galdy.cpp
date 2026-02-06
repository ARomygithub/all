#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, kmax;
    cin >> n >> kmax;

    // first if kmax is larger than Q, 
    // then no amount of queries can ever make S contain all possible K
    // so mex always possible 0
    if (kmax > n) 
    {
        while(n--) {int x; cin >> x; cout << 0 << '\n';}
        exit(0);
    }


    // notice that MEX can never exceed (n - 1), or just n
    // so keep track all x NOT in S XOR K.
    set<int> not_in_sK;
    for (int i = 0; i < n + 1; i++) not_in_sK.insert(i);
    int in_s[kmax + 1] = {0};
    int cnt = 0;

    int NNNNN = n;
    while (NNNNN--)
    {
        int x; cin >> x;
        if (x <= kmax)
        {
            if (in_s[x]) cnt--;
            else cnt++;
            in_s[x] = 1 - in_s[x];
        }
        
        if ((kmax ^ x) > n){} // ignore.
        else 
        {
            if (not_in_sK.find(kmax ^ x) == not_in_sK.end())
            {
                not_in_sK.insert(kmax ^ x);
            }
            else
            {
                not_in_sK.erase(kmax ^ x);
            }
        }
        
        if (cnt < kmax + 1)
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << *not_in_sK.begin() << '\n';      
        }

        // for (auto x : not_in_sK) cout << x << ' ';
        // cout << endl;
    }

    return 0;
}