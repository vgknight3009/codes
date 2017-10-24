#include<bits/stdc++.h>
using namespace std;

int median(int *a,int n){
	if(n&1)
		return a[n/2];
	return (a[n/2-1]+a[n/2])/2;
}

int getmed(int *a,int *b,int n){
	
	if(n<=0)
		return -1;
	if(n==1)
		return (a[0]+b[0])/2;
	if(n==2)
		return (max(a[0],b[0])+min(a[1],b[1]))/2 ;
	
	int m1=median(a,n);
	int m2=median(b,n);
	
	if(m1==m2)
		return m1;
	if(m1<m2)
	{
		if(n&1)
			return getmed(a+n/2,b,n-n/2);
		return getmed(a+n/2-1,b,n-n/2+1);
	}
	else{
		if(n&1)
			return getmed(a,b+n/2,n-n/2);
		return getmed(a,b+n/2-1,n-n/2+1);
	}
	
}

int main(){
	
	int a[]={1, 2, 3, 6};
    int b[] = {4, 6, 8, 10};
	
	int n= *(&a+1)-a;
	
	cout<<getmed(a,b,n);
	
	return 0;
}
