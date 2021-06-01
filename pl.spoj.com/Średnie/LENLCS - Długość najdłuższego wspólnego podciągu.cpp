#include<iostream> // AC
#include<new>
using namespace std;
int lcs(char *A, int n, char *B, int m) // longest common subsequence
{
    int **W = new int *[n+1],i,j,wyn,temp;
    for(i=0; i<n+1; i++)
    {
             W[i] = new int [m+1];
    }
    for(i=0; i<n+1; i++)
    {
             W[i][0]=0;
    }
    for(i=1; i<m+1; i++)
    {
             W[0][i]=0;
    }
    for(i=1; i<=n; i++)
    {
             for(j=1; j<=m; j++)
             {
                      if(A[i-1]==B[j-1])
                      {
                                    W[i][j]=W[i-1][j-1]+1;
                      }
                      else
                      {
                          W[i][j] = max(W[i-1][j],W[i][j-1]);
                      }       
             }
    }
    wyn=W[n][m];
    for(i=0; i<n+1; i++)
    {
             delete [] W[i];
    }
    delete [] W;
    return wyn;
}
void input(char *A, int n)
{
     int i;
     for(i=0; i<n; i++)
     {
              cin>>A[i];
     }
}
int main()
{
    int t,i,n,m;
    cin>>t;
    for(i=0; i<t; i++)
    {
             cin>>n;
             char *A = new char [n];
             input(A,n);
             cin>>m;
             char *B = new char [m]; 
             input(B,m);
             cout<<lcs(A,n,B,m)<<endl;
             delete [] A;
             delete [] B;
    }
    //system("pause");
    return 0;
}
