#include<bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
};

int direct(node p,node q,node r){

    int val = (q.x-p.x)*(r.y-p.y)-(r.x-p.x)*(q.y-p.y) ;

    if(val==0)  
        return 0;

    return val>0?1:2;
}

bool online(node p,node q,node r){
    if(r.x>=min(p.x,q.x) && r.x<=max(q.x,p.x) && r.y<=max(q.y,p.y) 
        && r.y>=min(p.y,q.y))
            return 1;
    return 0;

}

bool intersect(node p1,node p2,node p3,node p4){

    int d1=direct(p1,p2,p3);
    int d2=direct(p1,p2,p4);
    int d3=direct(p3,p4,p1);
    int d4=direct(p3,p4,p2);

    if(d1!=d2 && d3!=d4)
        return 1;
    if(d1==0 && online(p1,p2,p3))
        return 1;
    if(d2==0 && online(p1,p2,p4))
        return 1;
    if(d3==0 && online(p3,p4,p1))
        return 1;
    if(d4==0 && online(p3,p4,p2))
        return 1;

	return 0;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        node p1,p2,p3,p4;
        cin>>p1.x>>p1.y>>p2.x>>p2.y;
        cin>>p3.x>>p3.y>>p4.x>>p4.y;
        intersect(p1,p2,p3,p4)?cout<<"1\n":cout<<"0\n";


    }

    return 0;
}
