#include<cstdio> // AC

using namespace std;

int f(int x)
{
    return (x>0) ? x : -x ;
}

int max(int a, int b)
{
    return (a>b) ? a : b ;
}

int max3(int a, int b, int c)
{
    return max(max(a,b),c);   
}

int main()
{
    int a,b,c,S,pom;
    while(scanf("%d%d%d", &a, &b, &c) != EOF)
    {
                          if(!(a<b+c && a>f(b-c)))
                          {
                                     printf("brak\n");
                          }
                          else
                          {
                              S = (a*a) + (b*b) + (c*c);
                              pom = max3(a,b,c);
                              
                              if(S == 2*pom*pom)
                              {
                                   printf("prostokatny\n");
                              }       
                              else
                              {
                                  if(S > 2*pom*pom)
                                  {
                                       printf("ostrokatny\n");
                                  }
                                  else
                                  {
                                      printf("rozwartokatny\n");
                                  }
                              }
                          }
    }
    
    return 0;
}

