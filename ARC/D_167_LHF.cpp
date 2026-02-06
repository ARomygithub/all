#include<cstdio>
#include<set>
using namespace std;
const int N=2e5+10;
set<int> t;
int a[N],w[N],p[N],n,T,vis[N];
void add(int x)
{
	if(vis[x]) return;
	vis[x]=1,t.erase(x);
	add(p[x]);
}
void work(int x,int y)
{
	swap(a[x],a[y]),add(y);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		t.clear();
		for(int i=1;i<=n;i++) t.insert(i),vis[i]=0;
		for(int i=1;i<=n;i++) scanf("%d",&p[i]),a[i]=p[i],w[p[i]]=i;
		add(1);
		for(int i=1;i<=n;i++)
		{
			if(t.empty()) break;
			int mx=*t.begin();
			if(mx<a[i]||!vis[i+1]) work(i,w[mx]);
		}
		for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	}
}