#include<bits/stdc++.h>
using namespace std;

int random(int l,int r)
{
	srand(rand()+time(0));
	return rand()*rand()%(r-l+1)+l;
}

char c[]={'+','-','*','/'};

void f(int k)
{
	int t=random(0,3);
	if(t<=k)
		putchar(random('a','z'));
	else
	{
		int t=random(0,1);
		if(t<=0)
			putchar('('),f(k+1),putchar(c[random(0,3)]),f(k+1),putchar(')');
		else f(k+1),putchar(c[random(0,3)]),f(k+1);
	}
}

signed main()
{
	f(-1);
	return 0;
}
