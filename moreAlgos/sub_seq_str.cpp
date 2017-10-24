#include<bits/stdc++.h>
#define mod 1000000007
#define max 100010
#define ll unsigned long long 
#define pb push_back
#define mp make_pair
#define pii pair<int ,int>
using namespace std;


int main(){
	
	string str;
	cin>>str;
	
	int l=str.length();
	
	for(int i=1;i<(1<<l);i++){
		
		int temp=i;
		int j=0;string s;
		while(temp)
		{
			if(temp&1)
				s+=str[j];
			temp>>=1;
			j++;
		}
		cout<<s<<"\n";
	}

	return 0;
}
