#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxn=2e5, mxa=1e6;
int n,q;
int x[mxn], ct[mxa+1];
ll ans=0;

void remove(int idx) {
    ct[x[idx]]--;
    ans = ans - 1ll*(2*ct[x[idx]]+1)*x[idx];
}
void add(int idx) {
    ans = ans + 1ll*(2*ct[x[idx]]+1)*x[idx];
    ct[x[idx]]++;
}
int get_answer() {
    return ans;
}

const int block_size=317;

struct Query {
    int l,r, idx;
    bool operator<(Query q) const {
        return make_pair(l/block_size,r) < make_pair(q.l/block_size,q.r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>n >>q;
    for(int i=0;i<n;i++) {
        cin >>x[i];
    }
    vector<Query> que(q);
    for(int i=0;i<q;i++) {
        int a,b,c; cin >>a >>b; a--, b--;
        que[i].l=a, que[i].r=b, que[i].idx=i;
    }
    vector<int> res(q);
    sort(que.begin(),que.end());
    int curl = 0;
    int curr = -1;
    for(Query p : que) {
        while(curl>p.l) {
            curl--;
            add(curl);
        }
        while(curr<p.r) {
            curr++;
            add(curr);
        }
        while(curl<p.l) {
            remove(curl);
            curl++;
        }
        while(curr>p.r) {
            remove(curr);
            curr--;
        }
        res[p.idx] = get_answer();
    }
    for(int i=0;i<q;i++) {
        cout <<res[i] <<"\n";
    }
}
