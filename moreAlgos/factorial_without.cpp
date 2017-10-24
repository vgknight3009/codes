#include<bits/stdc++.h>
#include <math.h>
 using namespace std;
long double factorial(long double n)
{
    return tgammal(n + 1.0);
}
int main(){
	cout<<factorial(5.0);
	return 0;
}
