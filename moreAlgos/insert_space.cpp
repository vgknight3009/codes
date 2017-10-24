#include<bits/stdc++.h>
using namespace std ;

void F(string s,string r,int l,int n){
	
	if(l==n )
	{
		cout<<r<<"\n";
		return ;
	}

	F(s,r+s[l],l+1,n);
	r+=' ';
	F(s,r+s[l],l+1,n) ;
	
}

int main(){
	
	string str;
	cin>>str;
	int n=str.length();
	string p;p+=str[0];
	F(str,p,1,n);
	
	return 0;
}
