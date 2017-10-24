#include<bits/stdc++.h>
using namespace std;

struct Pair{
	int mn;
	int mx;
};																							// 3n/2 - 2

Pair F(int *a,int l,int h){

	Pair pii;

	if(l==h){
		pii.mn=pii.mx=a[l];
		return pii;
	}
	if(l+1==h){
		pii.mn=min(a[l],a[h]);
		pii.mx=max(a[l],a[h]);
	}
	int mid=(l+h)/2 ;

	Pair x,y;
	x = F(a,l,mid);
	y = F(a,mid+1,h);

	pii.mn = min(x.mn,y.mn) ;
	pii.mx = max(x.mx,y.mx) ;

	return pii;
}

int main()
{
  int arr[] = {1000, -1, 44509, 1, 330, 3000};
  int arr_size = 6;
  struct Pair minmax = F(arr, 0, arr_size-1);
  printf("\nMinimum element is %d", minmax.mn);
  printf("\nMaximum element is %d", minmax.mx);
  getchar();
}
