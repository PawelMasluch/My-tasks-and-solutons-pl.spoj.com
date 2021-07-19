#include<cstdio> // 100 pkt
#include<new>

using namespace std;

int main()
{
    int n, i, *t, ile[6] = {0,0,0,0,0,0};
    
    scanf("%d", &n);
    
    t = new int [n];
    
    for(i=0; i<=n-1; i++)
    {
             scanf("%d", &t[i]);
             ile[t[i]-1]++;
    }
    
    for(i=0; i<=5; i++)
    {
         printf("%d ", ile[i]);
    }
    printf("\n");
    
    return 0;
}
