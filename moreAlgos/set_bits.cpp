#include<iostream>
using namespace std;
 
int main()
{
	int N, x;
	int set_bit =0;
	cin>>N;
 
	for(int i=0;i<32;i++)
	{
		x = 1<<i;
		for(int j=1;j<=N;j++)
		{
			if( j & x)
				set_bit++;
		}
	}
	cout<<set_bit<<endl;
return 0;
}
