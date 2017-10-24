#include<bits/stdc++.h>
#include<time.h>

#define dim 7							

using namespace std;

struct Node{

	int parent;					
	int path_no;
	int ends;

} node ;

void init_grid(Node **grid){
	
	for(int i=0;i<dim;i++){
		for (int j=0;j<dim;j++){

			Node n_node;
			n_node.parent=i*dim+j;					// pointing to itself, since it will be unique
			n_node.path_no=0;
			n_node.ends=0;

			grid[i][j] = n_node;

		}
	}

}

int find_set(Node **grid,int k){

	int i,j;
	i=k/dim;
	j=k%dim;

	if(k==grid[i][j].parent)
		return k;

	return find_set(grid,grid[i][j].parent) ;

}

void union_set(Node **grid,int k1,int k2){				// making k1 parent

	int i2,j2;
	i2 = k2/dim;	j2 = k2%dim;

	grid[i2][j2].parent=k1 ;

}

int validNode(Node **grid){

	int k = rand()%(dim*dim);
	int i,j,ctr=0;
	
	while(ctr<dim*dim){

		k = k%(dim*dim);
		i = k/dim;
		j = k%dim;
		
		if(grid[i][j].path_no==0){

			if(i-1>=0 && !grid[i-1][j].path_no)
				return k;
			if(j+1<dim && !grid[i][j+1].path_no)
				return k;
			if(i+1<dim && !grid[i+1][j].path_no)
				return k;
			if(j-1>=0 && !grid[i][j-1].path_no)
				return k;

		}
		
		k++;
		ctr++;
	}
	
	if(ctr==dim*dim)
		return -1;

}

bool validNeigh(Node **grid,int i1,int j1,int k){

	int i,j,c=0;
	i=k/dim;
	j=k%dim;

	if(i1-1>=0 && find_set(grid,k)==find_set(grid,dim*(i1-1)+j1))
		c++;
	if(i1+1<dim && find_set(grid,k)==find_set(grid,dim*(i1+1)+j1))
		c++;
	if(j1-1>=0 && find_set(grid,k)==find_set(grid,dim*i1+j1-1))
		c++;
	if(j1+1<dim && find_set(grid,k)==find_set(grid,dim*i1+j1+1))
		c++;

	if(c>1)
		return 0;
	return 1;

}

int nextNode(Node **grid,int k){

	int i1,j1,i2,j2,flag=0;

	i1=k/dim;	j1=k%dim;
	int r_neigh = rand()%4 ;

	int c=0;
	while(c<4){

		r_neigh = r_neigh%4 ;
		switch(r_neigh){

			case 0: i2 = i1-1;	j2 = j1;
					if(i2>=0 && grid[i2][j2].path_no==0){
						if(validNeigh(grid,i2,j2,k))
						{
							flag=1;
							break;
						}	
					}

			case 1: i2 = i1;	j2 = j2+1;
					if(j2<dim && grid[i2][j2].path_no==0){
						if(validNeigh(grid,i2,j2,k))
						{
							flag=1;
							break;
						}
					}
			case 2: i2 = i1+1;	j2 = j1;
					if(i2<dim && grid[i2][j2].path_no==0){
						if(validNeigh(grid,i2,j2,k))
						{
							flag=1;
							break;
						}
					}
			case 3: i2 = i1; j2 = j1-1;
					if(j2>=0 && grid[i2][j2].path_no==0){
						if(validNeigh(grid,i2,j2,k))
						{
							flag=1;
							break;
						}
					}
		}

		r_neigh++;
		c++;
		if(flag)
			break;
	}	

	if(!flag)
		return -1;
	return i2*dim+j2 ;

}

int generatePath(Node **grid,int p_no){

	int kp = validNode(grid);
	if(kp==-1)
		return 0;

	int i1,j1,i2,j2,k;
	i1 = kp/dim;		
	j1 = kp%dim;

	grid[i1][j1].path_no = p_no ;
	grid[i1][j1].ends = 1;

	k=kp;

	while(1){
	
		
		k = nextNode(grid,k);

		if(k==-1)
			break;

		i2 = k/dim;
		j2 = k%dim;

		grid[i2][j2].path_no=p_no;
		union_set(grid,kp,i2*dim+j2);
	
	}

	grid[i2][j2].ends = 1;
	return 1;

}

void displayGrid(Node **grid){
	
	cout<<"Puzzle to be solved....\n\n";
	
	for(int i=0;i<dim;i++){
		cout<<" ";
		for(int j=0;j<dim;j++){
			
			cout<<"||";
			if(grid[i][j].path_no==0)
				cout<<" X ";
			else if(grid[i][j].ends)
			{
				if(grid[i][j].path_no<10)
					cout<<" "<<grid[i][j].path_no<<" ";
				else
					cout<<" "<<grid[i][j].path_no;
				
			}	
			else
				cout<<"   ";
			
		}
		cout<<"||\n";
		
	}
	
	cout<<"\nSolution of the puzzle...\n\n";
	
	for(int i=0;i<dim;i++){
		cout<<" ";
		for(int j=0;j<dim;j++){
			
			cout<<"||";
			if(grid[i][j].path_no==0)
				cout<<" X ";
			else if(grid[i][j].path_no<10)
				cout<<" "<<grid[i][j].path_no<<" ";
			else
				cout<<" "<<grid[i][j].path_no;
			
		}
		cout<<"||\n";
		
	}
	
}

int main(){

	srand(time(NULL));

	Node **grid = new Node*[dim];
	for(int i=0;i<dim;i++)
		grid[i] = new Node[dim];

	init_grid(grid);
	int p_no=1;

	while(true){

		if(generatePath(grid,p_no))
			p_no++;
		else
			break;

	}
	
	displayGrid(grid);

	return 0;
}
