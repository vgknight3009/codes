#include<bits/stdc++.h>
#define pii pair<int,int>			
#define mp make_pair
#define pb push_back
#define mx 1001
					
using namespace std;


int main()
{

	string str,temp,ans;
	getline(cin,str);
	int l=str.length();
	
	for(int i=0;i<l;i++){
		temp="";
		while(str[i]!=' ' && i<l){
			temp+=str[i];
			i++;
		}
		ans = temp + ans;
		if(i<l)
			ans = str[i] + ans;
		
	}
	cout<<ans;

		
	return 0;
}
