#include<bits/stdc++.h>

#define pb push_back
using namespace std;

vector<int> vec;
struct node{
	int val,i,j;

};

class cmp{
	
	public:
		bool operator()(node n1,node n2){
			
			return n1.val>n2.val;
			
		}
	
};

void mergeK(int a[][5],int k){

	priority_queue< node,vector<node>, cmp> pq;
	int m = 5 ;
	for(int i=0;i<k;i++)
	{
		node n;
		n.val=a[i][0];
		n.i=i;
		n.j=0;
		pq.push(n);
	}

	for(int i=0;i<m*k;i++){

		node n=pq.top();
		pq.pop();
		vec.pb(n.val);

		if(n.j!=m-1)
		{
			n.j=++n.j;
			n.val=a[n.i][n.j];
			pq.push(n);
		}

	}

	for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<"  ";

}



int main()
{
    // Change n at the top to change number of elements
    // in an array
    int arr[][5] =  {{2, 6, 12, 34,67},
                     {1, 9, 20, 1000,9888},
                     {23, 34, 90, 110,190}};
    int k = sizeof(arr)/sizeof(arr[0]);
 
    mergeK(arr, k);
 
  //  cout << "Merged array is " << endl;
    
 
    return 0;
}
