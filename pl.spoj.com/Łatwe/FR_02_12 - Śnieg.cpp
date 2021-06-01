#include<cstdio> // AC
//#include<iostream>

using namespace std;

typedef unsigned long long ulong;

ulong NWD(ulong a, ulong b)
{
      ulong temp;
      
      while(b)
      {
              temp = a % b;
              a = b;
              b = temp;
      }
      
      return a;
}

ulong NWW(ulong a, ulong b)
{
       return ( a / NWD(a,b) ) * b;
}

ulong NWW3(ulong a, ulong b, ulong c)
{
       return NWW( NWW(a,b), c );
} 

int main()
{
    ulong a, b, c, s, pom;
    
    scanf("%llu%llu%llu%llu", &a, &b, &c, &s);
    
    s *= 100;
    
    pom = NWW3(a,b,c);
    
    printf("%llu\n", s/pom);
    
    //system("pause");
    return 0;
}

