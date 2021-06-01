#include<cstdio> // AC
#include<cmath>
//#include<iostream>

using namespace std;

double f(double x)
{
      return (x>=0) ? x : -x ;
}

bool czy_trojkat(double a, double b, double c)
{    
     if( a < b + c  &&  a > f(b-c) )
     {
         return true;
     }
     
     return false;
}

double ile_kredy(double a, double b, double c, double ile)
{
                if(czy_trojkat(a,b,c) == false)
                {
                                      return 0. ;
                }
                
                double p = (a+b+c) / 2. ;
                
                return ile * sqrtl(p*(p-a)*(p-b)*(p-c)) / 10. ;
}

int main()
{
    long long t, i, n, j;
    
    double ile, a, b, c, wyn = 0. ;
    
    scanf("%lld", &t);
    
    for(i=1; i<=t; i++)
    {
             scanf("%lld%lf", &n, &ile);
             
             for(j=1; j<=n; j++)
             {
                   scanf("%lf%lf%lf", &a, &b, &c);
                   
                   wyn += ile_kredy(a,b,c,ile);
             }
             
             printf("%.0lf\n", wyn);
             
             wyn = 0. ;
    }   
    
    //system("pause");
    return 0;
}
