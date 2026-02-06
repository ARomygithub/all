#include <bits/stdc++.h>
using namespace std;
const int N = 200005,B = 1000;
int n,a[N],f[N / 2 / B + 5][N],g[N / 2 / B + 5][N],bid[N];
map<int,int> num;int rev[N];

int getn(int x)
{
    // static int idx = 0;return num[x] ? num[x] : (num[x] = ++idx,rev[idx] = x,idx);
    static int idx = 0;
    if(num[x]) {
        return num[x];
    } else {
        num[x] = ++idx; rev[idx] = x;
        return idx;
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i],bid[i] = (i - 1) / B + 1,a[i] = getn(a[i]);
    for (int i = 1;i <= n;i += B)
    {
        int r = min(i + B - 1,n);
        memcpy(f[bid[i]],f[bid[i] - 1],sizeof(f[bid[i]]));
        memcpy(g[bid[i]],g[bid[i] - 1],sizeof(g[bid[i]]));
        for (int j = i;j <= r;j++)
            ++f[bid[i]][a[j]],++g[bid[i]][f[bid[i]][a[j]]];
    }
    int m;cin >> m;
    while (m--)
    {
        int op,x,y;cin >> op >> x >> y;
        if (op == 1)
        {
            for (int id = bid[y];id <= bid[n];id++)
                --g[id][f[id][a[y]]],--f[id][a[y]];
            a[y] = getn(x);
            for (int id = bid[y];id <= bid[n];id++)
                ++f[id][a[y]],++g[id][f[id][a[y]]];
            continue;
        }
        if (x == 1) {cout << rev[a[y]] << "\n";continue;}
        int id = bid[y] - 1;
        for (int i = id * B + 1;i <= y;i++)
            ++f[id][a[i]],++g[id][f[id][a[i]]];
        cout << (!(x & 1) ? f[id][a[y]] : g[id][f[id][a[y]]]) << "\n";
        for (int i = id * B + 1;i <= y;i++)
            --g[id][f[id][a[i]]],--f[id][a[i]];
    }
    return 0;
}