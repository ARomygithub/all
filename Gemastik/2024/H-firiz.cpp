#include <bits/stdc++.h>

using namespace std;

#define FOR(a, b) for (int i = (int) a; i < (int) b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int MOD  = int( 1e9 )+7;

typedef struct item * pitem;
struct item {
    int prior, value, cnt,id;
    bool rev;
    pitem l, r;
    item(int key) : prior( rand()%MOD ), value( key ), 
                    cnt( 1 ),
                    l( NULL ), r( NULL ) {}
};

pitem root;

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

int idi(pitem it) {
    return it? it->id : -1;
}

void upd_cnt (pitem it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        int temp = idi(it->l) + 1;
        if(it->l) {
            temp += cnt(it->l->r);
        }
        it->id = temp;
    }
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void insert(pitem &t, pitem it, int pos) {
    pitem t1, t2;
    split(t, t1, t2, pos);
    merge(t1, t1, it);
    merge(t, t1, t2);
}

void del( pitem &root, int k ) {
    if( root->value == k ) {
        merge( root, root->l, root->r );
    }
    else if( root->value < k ) {
        del( root->r, k );
    }
    else {
        del( root->l, k );
    }
    upd_cnt( root );
}

void query(pitem t, int x) {
    pitem t1, t2;
    split(t, t1, t2, x);
    merge(t, t2, t1);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cout << t->value << " ";
    output (t->r);
}

void output2 (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    cout << t->id << " ";
    output (t->r);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        merge(root, root, new item(a[i]));
    }
    int sz = n;
    for(int i=0; i<q; i++){
        char t;
        cin >> t;
        if(t == 'G') {
            int x;
            cin >> x;
            query(root, x);
            output(root);
            cout << "\n";
            output2(root);
            cout <<"\n ^ cnt \n";
        } else {
            int x;
            cin >> x;
            insert(root, new item(x), 0);
            output(root);
            cout << "\n";
            sz++;
        }
    }

    output(root);

    return 0;
}