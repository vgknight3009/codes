//Write a code to print all possible combinations(order matters) of characters of string
//in lexicographical order.
//Input: “ABC”
//Output: A, AB, ABC, AC, ACB, B, BA, BAC, BC, BCA, C, CA, CAB, CB, CBA
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
void findCom(vector<char> v,char *s,int pos)
{
 
   for(unsigned int i=0;i<v.size();i++)
   {
   	 s[pos]=v[i];
   	 cout<<s<<endl;
   	 v.erase(v.begin()+i);
   	 findCom(v,s,pos+1);
   	 v.insert(v.begin()+i,s[pos]);
   	 s[pos]=0;
   }
 
   return;
}	
int main() {
	char a[]="nhv";
	char s[100]={0};
	int pos=0;
	int n = strlen(a);
	sort(a,a+n);
	vector<char> v(a,a+n);
	findCom(v,s,0);
	return 0;
}
