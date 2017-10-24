#include<bits/stdc++.h>
#define mod 1000000007
#define max 10010
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ll long long 
using namespace std;

vector<pii> g;
int n,e;
int par[max];
int rank[max]={0} ;

void make_set()
{
    for(int i=1;i<=n;i++)
    par[i]=i;
}

int find_set(int x)
{
    if(x==par[x])
    return x;
    else
    return find_set(par[x]) ;
    
}

void union_set(int x,int y)
{
    if(rank[x]>rank[y])
    par[y]=x;
    else
    {
        par[x]=y;
        if(rank[x]==rank[y])
        ++rank[y] ;
        
    }
}

bool cycle()
{
    for(int i=0;i<e;i++)
    {
        int x=g[i].first;
        int y=g[i].second;
        //cout<<x<<" "<<y<<endl;
        if(find_set(x)==find_set(y))
        return 1;
        else
        union_set(x,y);
        
    }
    return 0;
}

int main()
{
    cin>>n>>e;
   // g=vector<pii> (n+1);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g.pb(mp(u,v)) ;
        
    }
    
    make_set();
    if(cycle())
    cout<<"Cycle\n";
    else
    cout<<"NOT\n";
    
    
    return 0;
}
