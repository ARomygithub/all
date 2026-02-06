const int mxa=1e6;
const ll mod=1e9+7;
ll fct[mxa+1], ifc[mxa+1], iv[mxa+1];

ll fastexpo(ll a, ll b, ll m) {
    ll ret =1;
    while(b) {
        if(b&1) {ret=(ret*a)%m;}
        a = (a*a)%m;
        b >>=1;
    }
    return ret;
}

void init_fac() {
    iv[1]=1;
    for(int i=2;i<=mxa;i++) {
        iv[i] = mod - mod/i*iv[mod%i]%mod;
    }
    fct[0]=1, ifc[0]=1;
    for(int i=1;i<=mxa;i++) {
        fct[i]=fct[i-1]*i%mod;
        ifc[i]=ifc[i-1]*iv[i]%mod;
    }
}

ll C(ll a, ll b) {
    if(a<b || a<0 || b<0) return 0;
    ll ret=fct[a];
    ret = ret*ifc[b] %mod;
    ret = ret*ifc[a-b] %mod;
    return ret;
}
