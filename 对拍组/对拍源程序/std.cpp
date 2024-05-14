#include<bits/stdc++.h>
using namespace std;

#define N 1005
#define int long long

char a[N];
int level[200];

inline bool isop(char c){return level[c];}
inline bool isdigit(char c){return c>='a'&&c<='z';}

int find(int l,int r)
{
	int ret=0;
	int flag=0;
	for(int i=l;i<=r;++i)
	{
		if(a[i]=='(')
			++flag;
		else if(a[i]==')')
			--flag;
		else if(flag)
			continue;
		else if(isop(a[i])&&level[a[i]]<=level[a[ret]])
			ret=i;
	}
	return ret;
}

void f(int l,int r)
{
	int mid=find(l,r);
	if(mid)
		f(l,mid-1),putchar(a[mid]),f(mid+1,r);
	else if(isdigit(a[l]))
		putchar(a[l]);
	else if(r-l==2&&isdigit(a[l+1]))
		putchar(a[l+1]);
	else
	{
		int mid=find(l+1,r-1);
		int lt=l-1,rt=r+1;
		for(;lt>=1&&rt<=strlen(a+1)&&!isop(a[lt])&&!isop(a[rt]);++lt,++rt);
		if(lt>=1&&isop(a[lt])&&(a[lt]=='/'||(a[lt]=='*'||a[lt]=='-')&&(a[mid]=='+'||a[mid]=='-'))||rt<=strlen(a+1)&&isop(a[rt])&&(a[rt]=='*'||a[rt]=='/')&&(a[mid]=='+'||a[mid]=='-'))
			putchar('('),f(l+1,r-1),putchar(')');
		else f(l+1,r-1);
	}
}

signed main()
{
	scanf("%s",a+1);
	a[0]='\0';
	level['+']=level['-']=1;
	level['*']=level['/']=2;
	level['\0']=INT_MAX;
	f(1,strlen(a+1));
	return 0;
}
/*
(((a+b)))   AC
a+b


(((a+b)+c)*d/(e-f))+e         AC
(a+b+c)*d/(e-f)+e


(a+b)*c   AC
(a+b)*c


(((a+b))+c)*d+(e-f)        AC
(a+b+c)*d+e-f


((a+b)*c)     AC
(a+b)*c


(a)*(b)*(c)     AC
a*b*c


(a)+(b)*(c)+(d)     AC
a+b*c+d


a+b+(a-(b/c))      AC
a+b+a-b/c


(a*b)+((d*e)/((e)*(f)))         AC
a*b+d*e/(e*f)


((a+b))+((a+b))/((a+b))     AC
*/ 
