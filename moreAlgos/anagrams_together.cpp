#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
												// nmlogn + mnlogm;
	map<string,vector<string> > mp;
	string str[8]= {"dhd","hdd","act","sky","yks","pot","otp","atc"} ;
	int n=8;
	for(int i=0;i<n;i++){
		
		string s=str[i];
		int l=s.length() ;
		sort(s.begin(),s.end());
		
		mp[s].pb(str[i]);
	}
	for(map<string,vector<string> >::iterator itr=mp.begin();itr!=mp.end();++itr){
		
		vector<string > v = itr->second;
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<"  ";
		cout<<"\n";
		
	}
	
	
	return 0;
}
