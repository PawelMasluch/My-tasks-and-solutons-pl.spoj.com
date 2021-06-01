#include<cstdio> // 100 pkt
using namespace std;
bool f(int *t, int n)
{
     int i;
     for(i=0; i<n-1; i++)
     {
              if(t[i]>t[i+1])
              {
                             return false;
              }
     }
     return true;
}
int main()
{
    int n,i,j,temp;
    scanf("%d", &n);
    int t[n];
    for(i=0; i<n; i++)
    {
             scanf("%d", &t[i]);
    }
    while(f(t,n)==false)
    {
                        for(i=0; i<n-1; i++)
                        {
                                if(t[i]>t[i+1])
                                {
                                               printf("%d %d\n", t[i], t[i+1]);
                                               temp=t[i+1];
                                               t[i+1]=t[i];
                                               t[i]=temp;
                                }
                        } 
    }
    for(i=0; i<n; i++)
    {
             printf("%d ", t[i]);
    }
    //system("pause");
    return 0;
}
