#include<iostream> 
using namespace std; 
#define MAX  10 
#define TEMP  0 
#define PERM 1 
#define infinity 9999 
#define NIL -1 
struct edge 
{ 
int u; 
int v;     
}; 
int n; 
int adj[MAX][MAX]; 
int predecessor[MAX]; 
int status[MAX]; 
int length[MAX]; 
void create_graph(); 
void make_tree(int r,struct edge tree[MAX]); 
int min_temp(); 
int main() 
{ 
int wt_tree=0; 
int i,root; 
struct edge tree[MAX]; 
create_graph(); 
cout<<"\nEnter the root vertex : "; 
cin>>root; 
make_tree(root,tree); 
cout<<"\nEdges to be included in spanning tree are :\n"; 
for(i=1;i<=n-1;i++) 
{ 
cout<<tree[i].u<<" "; 
cout<<tree[i].v; 
cout<<"\n"; 
wt_tree += adj[tree[i].u][tree[i].v]; 
} 
cout<<"\nThe weight of spanning tree is :\n"; 
cin>>wt_tree; 
return 0; 
}/*End of main()*/ 
void create_graph() 
{ 
int i,max_edges,origin,destin,wt; 
cout<<"\nEnter the number of vertices :"; 
cin>>n; 
max_edges=n*(n-1)/2;/*Undirected graph*/ 
for(i=1;i<=max_edges;i++)  
{ 
cout<<"\nEnter edge(-1 -1 to quit) "<<i<<" : " ; 
cin>>origin>>destin; 
if((origin==-1)&&(destin==-1))   
break; 
cout<<"\nEnter the weight for this edge :"; 
cin>>wt; 
if(origin>=n||destin>=n||origin<0||destin<0) 
{ 
cout<<"\nInvalid Edge"; 
i--; 
} 
else 
{ 
adj[origin][destin]=wt; 
adj[destin][origin]=wt; 
} 
} 
}/*End of create_graph()*/ 
void make_tree(int r, struct edge tree[MAX]) 
{ 
int current,i; 
int count=0;/*Number of vertices in the tree*/    
for(i=0;i<n;i++)/*Initialize all the vertices*/  
{ 
predecessor[i]=NIL; 
length[i]=infinity; 
status[i]=TEMP;     
} 
length[r]=0;/*Make the length of the root vertex equal to 0*/ 
while(1) 
{ 
/*Search for the temporary vertex with minimum length and make it current vertex*/ 
current=min_temp(); 
if(current==NIL) 
{ 
if(count==n-1)/*No temporary vertex is left*/     
return; 
else /*Temporary vertices left with length infinity*/ 
{ 
cout<<"\nGraph is not connected,No spanning tree is possible"; 
exit(1);    
} 
} 
status[current]=PERM; /*Make the current vertex permanent*/ 
/*Insert the edge (predecessor[current],current) into the tree , except when the current vertex 
is root*/ 
if (current!=r) 
{ 
count++; 
tree[count].u=predecessor[current]; 
tree[count].v=current;     
} 
for(i=0;i<n;i++) 
if (adj[current][i]>0 && status[i]==TEMP) 
if (adj[current][i]<length[i]) 
{ 
predecessor[i]=current; 
length[i]=adj[current][i]; 
} 
} 
}/*End of make_tree()*/ 
/*Returns the temporary vertex with minimum value of length , Returns NIL if no temporary 
vertex left or all temporary vertices left have pathlength infinity*/ 
int min_temp() 
{ 
int i; 
int min=infinity; 
int k=-1; 
for(i=0;i<n;i++) 
{ 
if(status[i]==TEMP && length[i]<min)  
{ 
min=length[i]; 
k=i; 
}    
} 
return k; 
} /*End of min_temp()*/ 
/* OUTPUT:-
Enter the number of vertices :6

Enter edge(-1 -1 to quit) 1 : 0 1

Enter the weight for this edge :6

Enter edge(-1 -1 to quit) 2 : 0 2

Enter the weight for this edge :2

Enter edge(-1 -1 to quit) 3 : 0 3

Enter the weight for this edge :3

Enter edge(-1 -1 to quit) 4 : 0 4

Enter the weight for this edge :10

Enter edge(-1 -1 to quit) 5 : 1 3

Enter the weight for this edge :11

Enter edge(-1 -1 to quit) 6 : 1 5

Enter the weight for this edge :9

Enter edge(-1 -1 to quit) 7 : 2 3

Enter the weight for this edge :14

Enter edge(-1 -1 to quit) 8 : 2 4

Enter the weight for this edge :8

Enter edge(-1 -1 to quit) 9 : 3 4

Enter the weight for this edge :7

Enter edge(-1 -1 to quit) 10 : 3 5

Enter the weight for this edge :5

Enter edge(-1 -1 to quit) 11 : 4 5

Enter the weight for this edge :4

Enter edge(-1 -1 to quit) 12 : -1 -1

Enter the root vertex : 0

Edges to be included in spanning tree are :
0 2
0 3
3 5
5 4
0 1

The weight of spanning tree is :
20
*/