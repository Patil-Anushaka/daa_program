#include<iostream>
#include<stdlib.h> 
using namespace std;

#define MAX 100
#define initial 1
#define visited 2

int n;
int adj[MAX][MAX];
int state[MAX];
int stack[MAX]; 
int top=-1;

void push(int v);
int pop();
void create_graph();
void DF_traversal();
void dfs(int v);
int isEmpty_stack();

int main() 
{
create_graph();
DF_traversal();
return 0;
}

void DF_traversal() 
{
int v;
for(v=0;v<n;v++)
state[v] = initial;
cout<<"\nEnter starting vertex for depth-first search: ";
cin>>v;
dfs(v);
}

void dfs(int v) 
{
int i;
push(v);
while (!isEmpty_stack()) 
{
v = pop();
if(state[v]==initial) 
{
cout << v << " ";
state[v] = visited;
for (i=n-1;i >=0; i--)
{
if(adj[v][i]==1&&state[i]==initial) 
push(i);
}
}
}
}

void create_graph()
{
int i,max_edges,origin,destin ;
cout<<"\nEnter the number of nodes: ";
cin>>n;
max_edges=n *(n-1);
for(i=0; i<n;i++) 
{
for(int j=0; j<n;j++) 
{
adj[i][j]=0;
}
}
for (i=1;i<=max_edges;i++) 
{
cout<<"\nEnter edge (-1 -1 to quit): ";
cin>>origin>>destin;
if(origin==-1 && destin==-1)
break;
if(origin==-1 || destin>=n || origin<0 || destin<0) 
{
cout<<"\nInvalid edge";
i--;
}
else
adj[origin][destin]=1;
}
}

void push(int v)
{
if (top>=(MAX-1)) 
{
cout<<"\nStack is overflow\n";
return;
}
top= top+1;
stack[top]=v;
}

int pop() 
{
int v;
if(top==-1)
{
cout<<"\nStack is underflow";
return -1;
}
else
{
v=stack[top];
top=top-1;
return v;
}
}

int isEmpty_stack() 
{
if (top==-1)
return 1;
else
return 0;
}
/*OUTPUT:-
Enter the number of nodes: 10

Enter edge (-1 -1 to quit): 0 1

Enter edge (-1 -1 to quit): 0 3

Enter edge (-1 -1 to quit): 1 2

Enter edge (-1 -1 to quit): 1 4

Enter edge (-1 -1 to quit): 2 3

Enter edge (-1 -1 to quit): 2 5

Enter edge (-1 -1 to quit): 3 6

Enter edge (-1 -1 to quit): 4 7

Enter edge (-1 -1 to quit): 5 6

Enter edge (-1 -1 to quit): 5 7

Enter edge (-1 -1 to quit): 5 8

Enter edge (-1 -1 to quit): 6 9

Enter edge (-1 -1 to quit): 7 8

Enter edge (-1 -1 to quit): 8 9

Enter edge (-1 -1 to quit): -1 -1

Enter starting vertex for depth-first search: 0
0 1 2 3 6 9 5 7 8 4
*/