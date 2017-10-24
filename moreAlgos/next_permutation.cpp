#include<bits/stdc++.h>
using namespace std ;

bool next_per(string &str,int l){
	
	int k=l-1;
	if(l<2)
		return 1;
	int j,i;
	while(true){
		
		j=k;
		--k;
		if(str[j]>str[k]){
			
			i=l-1;
			while(str[k]>str[i]){				// or we can use binary search here but TC will remain -->  O( n ) 
				i--;
			}
			
			swap(str[i],str[k]);
			reverse(str.begin()+k+1,str.end()) ;
			return true;
			
		}
		else if(k==0)
			return false;
		
	}
	
	
}

int main(){
	
	string str;
	
	while(cin>>str){
		int l=str.length();
	
	if(next_per(str,l))
		cout<<str<<"\n";
	else
		cout<<str<<"\n";
	}
	
	return 0;
}
