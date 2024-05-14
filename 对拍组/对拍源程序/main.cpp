#include<bits/stdc++.h>
using namespace std;

signed main()
{
	while(1)
	{
		system("random.exe > in.txt");
		system("ans.exe < in.txt > out1.txt");
		int st=clock();
		system("std.exe < in.txt > out2.txt");
		int ed=clock();
		if(system("fc out1.txt out2.txt"))
		{
			puts("Wrong Answer");
			break;
		}
		if(ed-st>1000)
		{
			puts("Time Limit Exceeded");
			break;
		}
		puts("Accepted");
	}
	puts("====================");
	
	puts("input:");
	freopen("in.txt","r",stdin);
	char c[1005];
	scanf("%s",c);
	puts(c);
	
	freopen("out1.txt","r",stdin);
	puts("\nans.exe output:");
	scanf("%s",c);
	puts(c);
	
	freopen("out2.txt","r",stdin);
	puts("\nstd.exe output:");
	scanf("%s",c);
	puts(c);
	
	puts("====================");
	
	freopen("CON","r",stdin);
	system("pause");
	system("pause");
	system("pause");
	return 0;
}
