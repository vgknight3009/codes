#include <bits/stdc++.h>
#define mx 26

using namespace std;

bool cmp(int a,int b){
	return a<b;
}

int main(){
	
	int a[8] = {7,3,2,3,9,1,0,-3};
	sort(a,a+8,cmp);
	for(int i=0;i<8;i++)
		cout<<a[i]<<"  ";
	
	return 0;
}
