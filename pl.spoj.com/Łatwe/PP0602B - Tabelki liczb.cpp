#include<iostream> // AC
#include<new>
using namespace std;
void input(int **t, int n, int m)
{
     int i,j;
     for(i=0; i<=n-1; i++)
     {
              for(j=0; j<=m-1; j++)
              {
                       cin>>t[i][j];
              }
     }
}
void solve(int **t, int n, int m)
{
     int **pom = new int *[n]/*[m]*/,i,j;
     for(i=0; i<=n-1; i++)
     {
              pom[i] = new int [m];
     }
     for(i=1; i<=n-2; i++)
     {
              for(j=1; j<=m-2; j++)
              {
                       pom[i][j]=t[i][j];
              }
     }
     for(i=0; i<=n-2; i++) // ok
     {
          pom[i+1][0]=t[i][0];
     } 
     for(i=0; i<=m-2; i++) // ok
     {
          pom[n-1][i+1]=t[n-1][i];
     }
     for(i=n-1; i>=1; i--) // ok
     {
          pom[i-1][m-1]=t[i][m-1];
     } 
     for(i=m-1; i>=1; i--) // ok
     {
          pom[0][i-1]=t[0][i];
     } 
     for(i=0; i<=n-1; i++)
     {
              for(j=0; j<=m-1; j++)
              {
                       cout<<pom[i][j]<<" ";
              }
              cout<<endl;
     }
     for(i=0; i<=n-1; i++)
     {
              delete [] pom[i];
     }
     delete [] pom;
}
int main()
{
    int T,i,n,m,**t,j;
    cin>>T;
    for(i=0; i<T; i++)
    {
             cin>>n>>m;
             t = new int *[n];
             for(j=0; j<=n-1; j++)
             {
                      t[j] = new int [m];
             }
             input(t,n,m);
             cout<<endl;
             solve(t,n,m);
             for(j=0; j<=n-1; j++)
             {
                      delete [] t[j];
             }
             delete [] t;
    }
    //system("pause");
    return 0;
}
