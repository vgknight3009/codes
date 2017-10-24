#include <bits/stdc++.h>
#define mx 26

using namespace std;

struct node{
    
    node *child[mx];
    bool leaf;
};


node* getnode(){
    
    node *root=new node;
    root->leaf=false;
    for(int i=0;i<mx;i++)
        root->child[i]=NULL ; 
    return root;
}

void insert(node *root,string key){
    
    int l = key.length();
    node *pcrawl=root;
    
    for(int i=0;i<l;i++){
        
        int idx = key[i]-'a';
        if(!pcrawl->child[idx])
            pcrawl->child[idx]=getnode() ;
        
        pcrawl=pcrawl->child[idx];
        
    }
    pcrawl->leaf=1;
}

bool search(node *root,string str){
    
    int l=str.length();
    node *pcrawl=root;
    for(int i=0;i<l;i++){
        
        int idx=str[i]-'a';
        if(!pcrawl->child[idx])
            return 0;
        
        pcrawl=pcrawl->child[idx];
        
    }
    return (pcrawl!=NULL && pcrawl->leaf);
    
} 

bool isempty(node *root){
	
	for(int i=0;i<26;i++)
	{
		if(root->child[i])
			return 0;
	}
	return 1;
}

bool delete_str(node *root,string s,int level,int n){
	
	if(root){
		
		if(level==n){
		
			if(root->leaf){
			
				root->leaf=0;
				if(isempty(root))
					return 1;
				return 0;
			}
			
		}	
		
		else{
			
			int idx=s[level]-'a';
			if(delete_str(root->child[idx],s,level+1,n))
			{
				delete(root->child[idx]) ;
				
				if(root->leaf==0)
					return (isempty(root)) ;
			}
			
		}

	}
	
	return false ;
}

int main() {
	
	string keys[7] = {"the","sells", "sea", "shore", "the", "by", "sheer"};
	
	node *root = getnode();
	
	
	for(int i=0;i<7;i++)
	    insert(root,keys[i]);
	    
	cout<<search(root,"t")<<"\n";
	cout<<search(root,"sheer")<<"\n";
	cout<<search(root,"by")<<"\n";
	
	delete_str(root,"the",0,3);

	cout<<search(root,"the")<<"\n";
	
	return 0;
}
