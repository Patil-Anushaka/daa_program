#include<iostream>
using namespace std;
int main()
{
int a[2][2],b[2][2],c[2][2],i,j;
int m1,m2,m3,m4,m5,m6,m7;
cout<<"\nEnter the four elements of 1st matrix:";
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
cin>>a[i][j];
}
}

cout<<"\nEnter the four elements of 2nd matrix:";
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
cin>>b[i][j];
}
}

cout<<"\nThe 1st matrix is:";
for(i=0;i<2;i++)
{
cout<<"\n";
for(j=0;j<2;j++)
{
cout<<a[i][j]<<"\t";
}
}

cout<<"\nThe 2nd matrix is:";
for(i=0;i<2;i++)
{
cout<<"\n";
for(j=0;j<2;j++)
{
cout<<b[i][j]<<"\t";
}
}
m1=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
m2=(a[1][0]+a[1][1])*b[0][0];
m3=a[0][0]*(b[0][1]-b[1][1]);
m4=a[1][1]*(b[1][0]-b[0][0]);
m5=(a[0][0]+a[0][1])*b[1][1];
m6=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
m7=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
c[0][0]=m1+m4-m5+m7;
c[0][1]=m3+m5;
c[1][0]=m2+m4;
c[1][1]=m1-m2+m3+m6;
cout<<"\nAfter multiplication using Strassen's algorithm";
for(i=0;i<2;i++)
{
cout<<"\n";
for(j=0;j<2;j++)
{
cout<<c[i][j]<<"\t";
}
}
return 0;
}
/*OUTPUT:-
Enter the four elements of 1st matrix:
1
2
3
4

Enter the four elements of 2nd matrix:
5
6
7
8

The 1st matrix is:
1	2	
3	4	
The 2nd matrix is:
5	6	
7	8	
After multiplication using Strassen's algorithm
19	22	
43	50
*/