int zeroes = count(s.begin(),s.end(),'0');
int first = s.find('0');
int last = s.rfind('0');

char v1[5] = {'A','E','I','O','U'};
char konso1[21] = {'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};

const int K=26;

struct Vertex {
    int next[K];
    int leaf=0;
    int p=-1, ans=0;
    char pch;
    int link=-1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(next,next+K,-1);
        fill(go,go+K,-1);
    }
};

Vertex t[mxn];

int add_string(string const& s, int idx) {
    int v=0;
    for(char ch : s) {
        int c = ch - 'a';
        if(t[v].next[c]==-1) {
            t[v].next[c] = ++id;
            t[id] = Vertex(v,ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = idx;
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if(t[v].link == -1) {
        if(v==0 || t[v].p == 0) {
            t[v].link = 0;
        } else {
            t[v].link = go(get_link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if(t[v].go[c] == -1) {
        if(t[v].next[c] != -1) {
            t[v].go[c] = t[v].next[c];
        } else {
            t[v].go[c] = v==0? 0: go(get_link(v),ch);
        }
    }
    return t[v].go[c];
}

===============================================================================
const ll base[2] = {191, 307};
const ll mod[2] = {1000001011,1000009999};
ll pwr[2][mxn];

void PreCal() {
    pwr[0][0]=1, pwr[1][0]=1;
    for(int j=0;j<2;j++) {
        for(int i=1;i<mxn;i++) {
            pwr[j][i] = (pwr[j][i-1]*base[j])%mod[j];
        }
    }
}

struct PolyHash {
    vector<pair<ll,ll>> h;
    PolyHash(string &s) {
        ll x[2]={0,0};
        for(char ch: s) {
            x[0] = (x[0]*base[0]+ch) %mod[0];
            x[1] = (x[1]*base[1]+ch) %mod[1];
            h.emplace_back(x[0],x[1]);
        }
    }
    pair<ll,ll> GetHash(int l, int r) {
        ll x[2] = {h[r].first,h[r].second};
        if(l==0) return {x[0],x[1]};
        x[0] = (x[0] - (h[l-1].first*pwr[0][r-l+1])%mod[0] + mod[0])%mod[0];
        x[1] = (x[1] - (h[l-1].second*pwr[1][r-l+1])%mod[1] + mod[1])%mod[1];
        return {x[0],x[1]};
    }
};