#include<cstdio>
#include<new>
using namespace std;
int main()
{
    int N,i,Q,B;
    scanf("%d%d", &N, &Q);
    int *T = new int [N],*pom = new int [1000001];
    for(i=0; i<=1000000; i++)
    {
             pom[i]=-1;
    }
    for(i=0; i<N; i++)
    {
             scanf("%d", &T[i]);
    }
    for(i=N-1; i>=0; i--)
    {
               pom[T[i]]=i+1;
    }
    for(i=0; i<Q; i++)
    {
             scanf("%d", &B);
             if(pom[B]>=0)
             {
                          printf("%d\n", pom[B]);
             }
             else
             {
                 printf("NIE\n");
             }
    }
    //system("pause");
    return 0;
}