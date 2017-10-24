#include<bits/stdc++.h>
using namespace std;

int ctr=0;

void merge(int *a,int l,int m,int r){
	
		int i,j,k,n1,n2;
	n1 = m-l+1 ;
	n2 = r-m ;
	
	int left[n1] , right[n2] ;
	
	for(i=0;i<n1;++i)
		left[i] = a[l+i] ;
	for(j=0;j<n2;++j)
		right[j] = a[m+1+j] ;
	  
	i=j=0;	k=l;
	
	while(i<n1 && j<n2){
		
		if(left[i]<=right[j])
			a[k++]=left[i++];
		else 
		{
			a[k++]=right[j++];
			ctr+=(m-l+1)-i;				// iver. ctr
		}
		
	}
	while(i<n1)
	a[k++] = left[i++] ;
	
	while(j<n2)
	a[k++] = right[j++] ;
}

void merge_sort(int a[],int l,int r){
	
	if(r>l){
		
		int m=(l+r)/2 ;
		merge_sort(a,l,m) ;
		merge_sort(a,m+1,r) ;
		merge(a,l,m,r) ;
		
	}
	
}

int main()
{
	int a[]={1000,688,90,78} ;
	int n=*(&a+1)-a ;
	
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	
	cout<<"\n"<<ctr<<"\n";

	return 0;
}
