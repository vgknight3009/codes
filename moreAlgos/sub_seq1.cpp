#include <bits/stdc++.h>
#define mx 26

using namespace std;


int main(){
	
	string str;
	cin>>str;
	int n=str.length();
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j))
				cout<<str[j];
		}
		cout<<"\n";
	}
	
	
	return 0;
}
