#include<cstdio> // AC
using namespace std;
int main()
{
    int t,i,x1,x2,x3,y1,y2,y3;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
         scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
         if((x1*y2)+(x3*y1)+(x2*y3)==(x2*y1)+(x1*y3)+(x3*y2))
         {
             printf("TAK\n");
         }
         else
         {
             printf("NIE\n");
         }
    }
    return 0;
}

