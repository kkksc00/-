#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

#define N 400005

int n;
vector<pair<int,int> > map[N];
int depth[N];
int fa[N][20],gcd[N][20];

void init(int u,int father,int gcdd)
{
	depth[u]=depth[father]+1;
	fa[u][0]=father;
	gcd[u][0]=gcdd;
	for(int j=1;j<20;++j)
		fa[u][j]=fa[fa[u][j-1]][j-1],
		gcd[u][j]=__gcd(gcd[u][j-1],gcd[fa[u][j-1]][j-1]);
	for(pair<int,int> edge:map[u])
	{
		int v=edge.first,w=edge.second;
		if(v!=father)
			init(v,u,w);
	}
}

void updata(int &ret,bool &flag,int upd){if(flag)ret=upd,flag=1;ret=__gcd(ret,upd);}
int path_gcd(int x,int y)
{
	if(depth[x]<depth[y])
		swap(x,y);
	int ret=0;
	bool flag=0;
	for(int i=0,j=depth[x]-depth[y];(1<<i)<=j;++i)
		if((1<<i)&j)
		{
			updata(ret,flag,gcd[x][i]);
			x=fa[x][i];
		}
	if(x==y)
		return ret;
	for(int i=19;i>=0;--i)
		if(fa[x][i]!=fa[y][i])
		{
			updata(ret,flag,__gcd(gcd[x][i],gcd[y][i]));
			x=fa[x][i];
			y=fa[y][i];
		}
	updata(ret,flag,__gcd(gcd[x][0],gcd[x][0]));
	return ret;
}

signed main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		map[u].push_back(make_pair(v,w));
		map[v].push_back(make_pair(u,w));
	}
	init(1,0,0);
	
	return 0;
}