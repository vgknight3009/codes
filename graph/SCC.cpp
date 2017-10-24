#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;

vector<vector<int> > g;
vector<vector<int> > gt;

bool visit[10000]={0};
stack<int> st;
vector<int> scc;
int n,e;

void DFS1(int s){
    visit[s]=1;
    int v;
    for(vector<int>::iterator itr=g[s].begin();itr!=g[s].end();++itr){
        v=*itr ;
        if(!visit[v])
            DFS1(v);
    }
            
    st.push(s);
}

void DFS2(int s){
    visit[s]=1;
    scc.pb(s);										// print here
    for(vector<int>::iterator itr=gt[s].begin();itr!=gt[s].end();++itr)
            if(!visit[*itr])
                DFS2(*itr);
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    while(n){
        int u,v;
        cin>>e;
        g=vector<vector<int> > (n+1);
        gt=vector<vector<int> > (n+1);
        
        for(int i=1;i<=6000;i++){
            g[i].clear();
            gt[i].clear();
        }
        scc.clear();
        
        for(int i=1;i<=e;i++){
            cin>>u>>v;
                g[u].pb(v);
                gt[v].pb(u);
        }
        memset(visit,0,sizeof visit);
        
        for(int i=1;i<=n;i++)
            if(!visit[i])
                DFS1(i);
                
        memset(visit,0,sizeof visit);
        
        while(!st.empty()){
            if(!visit[st.top()])
                DFS2(st.top());
            st.pop();
        }
          //  sort(scc.begin(),scc.end()) ;
        
        for(vector<int>::iterator itr=scc.begin();itr!=scc.end();++itr)
            cout<<*itr<<" ";
        cout<<endl;
        
        cin>>n;
        
    }
        
       
   
    
    return 0;
}
