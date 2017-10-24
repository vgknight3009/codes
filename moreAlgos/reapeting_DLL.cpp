#include<bits/stdc++.h>
using namespace std ;

struct node{
	char info;
	node *left;
	node *right;
};

void append(node **start,node **tail,char ch){
	
	node *temp=new node;
	temp->info=ch;
	temp->right=temp->left=NULL;
	
	if((*start)==NULL)
		(*start)=temp;
	else{
		(*tail)->right=temp;
		temp->left=(*tail);
	}
	(*tail)=temp;
	
}

void remove(node **start,node **tail,node *temp){
	
	if(*start==NULL)
		return ;
	if(temp== *start)
		(*start)=(*start)->right ;
	if(temp==*tail)
		(*tail)=(*tail)->left;
	if(temp->left)
		temp->left->right=temp->right;
	if(temp->right)
		temp->right->left=temp->left;
		
	delete(temp);
	
}

void funct(string s,node **start,node **tail){
	
	bool repeat[256]={0};
	node *ptr[256]={NULL};
	
	int l=s.length();
	for(int i=0;i<l;i++){
		
		if(repeat[s[i]]==0 && ptr[s[i]]==NULL){
		
			append(start,tail,s[i]) ;
				ptr[s[i]]=*tail;
			
		}
		else if(repeat[s[i]]==0 && ptr[s[i]]!=NULL)
		{
			repeat[s[i]]=1;
			remove(start,tail,ptr[s[i]]) ;
			
		}
		
		if((*start)){
			cout<<"So far......  ";
			cout<<(*start)->info<<"\n";
		}
		
		
	}
	
}

int main(){
	string str;
	cin>>str;
	
	node *start=NULL,*tail=NULL;
	
	funct(str,&start,&tail);

	
	return 0;
}
