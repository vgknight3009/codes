// A C++ program to sort an array according to the order defined
// by another array
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int A2[] = {2, 1, 8, 3};					// O(mnlogn)
int search(int a ){
	
	int l=-1;
	for(int i=0;i<4;i++){
		
		if(A2[i]==a)
			return i;
		
	}
	return -1;
		
}

bool cmp(int a,int b){
	
	int p=search(a);
	int r=search(b);
	
	if(p!=-1 && r!=-1)
		return p<=r;
	else if(p!=-1)
		return 1;
	else if(r!=-1)
		return 0;
	else 
		return a<=b;
	
}

int main()
{
	int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
	
	int m = sizeof(A1)/sizeof(A1[0]);
	int n = sizeof(A2)/sizeof(A2[0]);
	cout << "Sorted array is \n";

	sort(A1,A1+m,cmp);
	for(int i=0;i<m;i++)
		cout<<A1[i]<<"  ";

	return 0;
}

