#include<cstdio> // AC
//#include<iostream>

using namespace std;

typedef unsigned long long LLU;

LLU NWD(LLU a, LLU b)
{
          LLU temp;
          
          while(b)
          {
                  temp = a % b;
                  a = b;
                  b = temp;
          }
          
          return a;
}

LLU NWW(LLU a, LLU b)
{
          return ( a / NWD(a,b) ) * b;
}

int main()
{
    LLU l1,m1,l2,m2,lwyn,mwyn,pom,a,b,c,d;
    
    scanf("%llu/%llu %llu/%llu", &l1, &m1, &l2, &m2);
    
    a = l1; // zapamiêtanie oryginalnych u³amków
    b = m1;
    
    c = l2;
    d = m2;
    
    pom = NWD(l1,m1); // skrócenie 1. u³amka
    l1 /= pom;
    m1 /= pom;
    
    pom = NWD(l2,m2); // skrócenie 2. u³amka
    l2 /= pom;
    m2 /= pom;
    
    mwyn = NWW(m1,m2); // obliczenie mianownika wynikowego
    
    lwyn = ( (mwyn / m1) * l1 ) + ( (mwyn / m2) * l2 ); // obliczenie licznika wynikowego
    
    pom = NWD(lwyn,mwyn);
    lwyn /= pom;
    mwyn /= pom;
    
    printf("%llu/%llu + %llu/%llu = %llu/%llu\n", a,b,c,d,lwyn,mwyn);
    
    //system("pause");
    return 0;   
}

