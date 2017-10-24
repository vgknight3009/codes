#include<bits/stdc++.h>
using namespace std;
int ct=0;
bool isSafe(char matrix[3][4],int x,int y,bool visited[3][4],string word,int k)
{
	if(x<0||y<0||x>3||y>4||visited[x][y]==1)return false;
	else if(matrix[x][y]==word[k])return true;
	else return false;
}

void dfs(char matrix[3][4],int x,int y, bool visited[3][4],string word,int k)
{
	if(k==word.length()){ct++;}
	visited[x][y]=1;
	int i;
	int dx[8] = {0,0,-1,-1,-1,1,1,1};
	int dy[8] = {-1,1,0,-1,1,0,-1,1};
	for(i=0;i<8;++i)
	{
		if(isSafe(matrix,x+dx[i],y+dy[i],visited,word,k))
		{
			dfs(matrix,x+dx[i],y+dy[i],visited,word,k+1);
		}
	}
	k--;
	visited[x][y]=0;
	return;
}

int main()
{
	string word = "AA";
	int rows = 3;
	int cols = 4;
	char matrix[3][4]={"AAA","AAA","AAA"};
	int i,j;
	bool visited[3][4];
	memset(visited,0,sizeof(visited));
	for(i=0;i<rows;++i)
	{
		for(j=0;j<cols;++j)
		{
			if(matrix[i][j]=='A')
			{
			
				dfs(matrix,i,j,visited,word,1);
			}
		}
	}
	cout<<ct<<endl;
	return 0;
}
