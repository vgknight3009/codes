#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

#define SIZE(arr) sizeof(arr)/sizeof(arr[0])

void maxProdcut(int arr[], int n) 
{
	int ans = arr[0];
	int mxt = arr[0];
	int mnt = arr[0];

    for(int i=1;i<n;i++){
        
        if(arr[i]==0){
            ans = max(ans,arr[i]);
            mxt=mnt=0;
            continue;
        }
        
        int temp=mxt;
        mxt = max(max(mxt*arr[i],mnt*arr[i]),arr[i] );
        mnt = min(min(temp*arr[i],mnt*arr[i]),arr[i] );
        
        ans = max(mxt,ans);
    }
	 
	 cout<<ans<<"\n";

}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        maxProdcut(a,n) ;
        
    }
    
    return 0;
}


