#include<bits/stdc++.h>
using namespace std;

struct node{
    int page;
    node *next,*prev;
};

struct Queue{
    int ctr;
    int tot_frames;
    node *front,*rear;
};

Queue *create_que(int k){
    Queue *q=new Queue;
    q->front=q->rear=NULL;
    q->ctr=0;
    q->tot_frames=k;
    return q;
}

bool isempty(Queue *q){
    if(q->front && q->rear)
        return 0;
    return 1;
}

node *Enque(Queue *q,int key){
    
    node *temp=new node;
    temp->page=key;
    temp->next=temp->prev=NULL;
    q->ctr++;
    if(!q->front)
        q->front=q->rear=temp;
    else{
        q->rear->next=temp;
        temp->prev=q->rear;
    }
    q->rear=temp;
    return temp ;
    
}

void Deque(Queue *q, unordered_map<int,node * > &mp){

    if(isempty(q)){
        cout<<"Queue is empty...\n";
        return ;
    }
    
    q->ctr--;
    node *temp=q->front;
    q->front = q->front->next ;
    if(q->front->next)
        q->front->next->prev=NULL;
    else
        q->rear=NULL;
    delete(temp);


}

void update(Queue *q,unordered_map<int,node * > &mp,int page){

    if(q->rear==mp[page])
        return ;

    if(q->front==mp[page]){
        Deque(q,mp);
        Enque(q,page);
        return ;
    }
    node *temp=mp[page];
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    q->rear->next = temp;
    temp->prev = q->rear;
    q->rear=temp;

}

void LRU_cache(Queue *q,unordered_map<int,node * > &mp,int page){

    if(mp.find(page)==mp.end() && q->ctr<q->tot_frames ){

        mp[page] = Enque(q,page);

    }
    else if(mp.find(page)==mp.end() && q->ctr>=q->tot_frames){
    	mp.erase(q->front->page);
        Deque(q,mp);
        mp[page]=Enque(q,page);
    }
    else
        update(q,mp,page);

}

int main(){
    
    Queue *q=create_que(4);
    unordered_map<int,node * > mp ;
    int page_od[12]={1,2,3,5,4,2,3,2,5,6,1};
    
    for(int i=0;i<11;i++){

        cout<<"Page Request... "<<page_od[i]<<" ---->   ";

        LRU_cache(q,mp,page_od[i]) ;
		cout<<q->front->page<<"  "<<q->rear->page<<"\n\n";
		
    }
    

    return 0;
}
