#include<iostream>  
#include<fstream>  
#define Row 7  
#define Col 7  
using namespace std;  
  
int m[Row][Col]={  
{2, 2, 2, 2, 2, 2, 2},   
{2, 0, 0, 0, 0, 0, 2},   
{2, 0, 2, 0, 0, 0, 2},   
{2, 0, 0, 2, 0, 2, 2},   
{2, 2, 0, 2, 0, 2, 2},   
{2, 0, 0, 0, 0, 0, 2},   
{2, 2, 2, 2, 2, 2, 2}  
};  
  
int x=1,y=1,xx=5,yy=5;  
int sum=0;  
int XH[4]={1,-1,0,0};  
int YH[4]={0,0,1,-1};  
  
void find(int x,int y);  
void output();  
ofstream fout("estdout_2.pc2");  
  
int main()  
{  
    int i,j;  
    for(i=0;i<Row;i++)  
    {  
        for(j=0;j<Col;j++)  
        {  
            if(m[i][j]==2)  
                cout<<"█";  
            else    
                cout<<"  ";  
        }  
        cout<<endl;  
    }  
    cout<<endl<<endl;  
  
    find(1,1);  
    cout<<"所有走法:"<<sum<<endl;  
    return 0;  
}  
  
void find(int x,int y)  
{     
    int t=m[x][y];  
    m[x][y]=1;  
    if(x==5&&y==5)  
    {  
        sum++;  
        output();  
    }  
    else  
    {  
        int u,v;  
        for(int i=0;i<4;i++)  
        {  
            u=x+XH[i];  
            v=y+YH[i];  
            if(m[u][v]==0)  
                find(u,v);        
        }  
    }  
        m[x][y]=t;  
}  
  
void output()  
{     
      
    int i,j;  
    for(i=0;i<Row;i++)  
    {  
        for(j=0;j<Col;j++)  
        {  
            if(m[i][j]==2)  
            {  
                cout<<"█";  
            }  
            else if(m[i][j]==0)  
            {  
                cout<<"  ";  
            }  
            else  
            {  
                cout<<"◇";  
            }  
        }  
        cout<<endl;  
    }  
    cout<<endl;  
}  