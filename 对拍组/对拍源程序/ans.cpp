#include <bits/stdc++.h>
using namespace std;
int d[128],l;
string s;
stack <int> st;
int main()
{
	cin >>s; l=s.size();
	d['/']=4; d['*']=3; d['-']=2; d['+']=1;
	for (int i=0;i<l;i++)
	{
		if (s[i]=='/' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='(')
			st.push(i);
		if (s[i]==')')
		{
			int k;
			for (k=5;s[st.top()]!='(';st.pop())
				k=min(k,d[s[st.top()]]);
			int head=-1,tail=-1;
			if (i+1<l && s[i+1]!=')')
				tail=d[s[i+1]];
			if (st.top()-1>=0 && s[st.top()]!=')')
				head=d[s[st.top()-1]];
			if (k>=tail && k>=head)
				s[i]=s[st.top()]=0;
			if (k==1 && tail==2 && head<=1 || k==3 && tail==4 && head<=3)
				s[i]=s[st.top()]=0;
			st.pop();
		}
	}
	for (int i=0;i<l;i++)
		if (s[i]!=0)
			cout <<s[i];
	return 0;
}

