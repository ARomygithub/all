#include<bits/stdc++.h>
using namespace std;

#define int long long

const int P=998244353;

int X,A,B;

signed main()
{
    cin>>X>>A>>B;
    B--;
    int ans=0;
    for(int a=1;a*(a+1)*(a+2)*(a+3)<=X;a++)
        for(int b=a+1;a*b*(b+1)*(b+2)<=X;b++)
        {
            int n=X/(a*b);
            int lc=b+1,rc;
            int L=0,R=sqrtl(n)+10;
            while(R-L>1)
            {
                int mid=(L+R)>>1;
                if(mid*(mid+1)<=n)
                    L=mid;
                else
                    R=mid;
            }
            rc=L;
            if(lc>rc)
                continue;
            if(a+b>=A&&a+b<=B)
                ans=(ans+(rc-lc+1)*4)%P;
            //L<=a+c<=R
            {
                int lp=max(A-a,lc);
                int rp=min(B-a,rc);
                if(lp<=rp)
                    ans=(ans+(rp-lp+1)*4)%P;
            }
            //L<=b+c<=R
            {
                int lp=max(A-b,lc);
                int rp=min(B-b,rc);
                if(lp<=rp)
                    ans=(ans+(rp-lp+1)*4)%P;
            }
            //L<=a+d<=R
            {
                int ld=A-a,rd=B-a;
                // ld <= n/c <= rd
                int L=1,R=n+2;
                while(R-L>1)
                {
                    int mid=(L+R)>>1;
                    if(n/mid>=ld)
                        L=mid;
                    else
                        R=mid;
                }
                int rp=L;
                L=0,R=n+1;
                while(R-L>1)
                {
                    int mid=(L+R)>>1;
                    if(n/mid<=rd)
                        R=mid;
                    else
                        L=mid;
                }
                int lp=R;
                lp=max(lp,lc);
                rp=min(rp,rc);
                if(lp<=rp)
                    ans=(ans+(rp-lp+1)*4)%P;
            }
            //L<=b+d<=R
            {
                int ld=A-b,rd=B-b;
                // ld <= n/c <= rd
                int L=1,R=n+2;
                while(R-L>1)
                {
                    int mid=(L+R)>>1;
                    if(n/mid>=ld)
                        L=mid;
                    else
                        R=mid;
                }
                int rp=L;
                L=0,R=n+1;
                while(R-L>1)
                {
                    int mid=(L+R)>>1;
                    if(n/mid<=rd)
                        R=mid;
                    else
                        L=mid;
                }
                int lp=R;
                lp=max(lp,lc);
                rp=min(rp,rc);
                if(lp<=rp)
                    ans=(ans+(rp-lp+1)*4)%P;
            }
            //L<=c+d<=R
            {
                
                int L=1,R=rc+1;
                while(R-L>1)
                {
                    int mid=(L+R)>>1;
                    if(mid+n/mid>=A)
                        L=mid;
                    else
                        R=mid;
                }
                int rp=L;
                if(rp+n/rp<A)
                    rp--;
                L=0,R=rc;
                while(R-L>1)
                {
                    int mid=(L+R)>>1;
                    if(mid+n/mid<=B)
                        R=mid;
                    else
                        L=mid;
                }
                int lp=R;
                if(lp+n/lp>B)
                    lp++;
                // cout <<lp <<" " <<rp <<" " <<lc <<" " <<rc <<"\n";
                lp=max(lp,lc);
                rp=min(rp,rc);
                if(lp<=rp)
                    ans=(ans+(rp-lp+1)*4)%P;
            }
        }
    cout<<ans<<endl;
}