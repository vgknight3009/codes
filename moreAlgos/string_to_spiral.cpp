#include <bits/stdc++.h>
using namespace std;

string convert(string str,int R,int C)
{										// spiral order of a string
	string s;
	int i,l=0,r=C-1,u=0,d=R-1;
	
	while(l<=r && u<=d){
		
		for(i=l;i<=r;i++)
			s+=str[C*u+i];
		u++;
		
		for(i=u;i<=d;i++)
			s+=str[i*C+r];
		r--;
		
		if(u<=d){
			for(i=r;i>=l;i--)
				s+=str[C*d+i];
			d--;
		}
		
		if(l<=r){
			for(i=d;i>=u;i--)
				s+=str[C*i+l];
			l++;
		}
		
	}
//	cout<<s;
	return s;
	
}

string value(string str){
	
	string s;
	int k=0;
	if(str.length()<5)
	    return "";
	for(int i=0;i<5;i++)
		k+=(str[4-i]-'0')*(1<<i) ;
	
	s+='A'+k-1;
	//cout<<s<<" ";
	return s;
}

int main(){
	
	int t,r,c,k=1;
	cin>>t;
	while(k<=t){
		
		cin>>r>>c;
		string str,ans="";
		cin>>str;
		
		str = convert(str,r,c);
		cout<<str<<"\n\n";
		int l=str.length();
		
		for(int i=0;i<l;i+=5)
		{
		    
			string s=str.substr(i,5);
			ans+=value(s);
			
		}
		cout<<k<<" "<<ans<<"\n";
		k++;
	}
	
	
	return 0;
}
