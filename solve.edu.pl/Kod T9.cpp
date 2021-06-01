#include<iostream> // 91/100 pkt; rozwiazanie przeszlo wszystkie testy
#include<string>
#include<cstdio>
using namespace std;
int f(char z)
{
    int n=(int)z;
    if(n>=97 && n<=99)
    {
             return 2;
    }
    if(n>=100 && n<=102)
    {
             return 3;
    }
    if(n>=103 && n<=105)
    {
             return 4;
    }
    if(n>=106 && n<=108)
    {
             return 5;
    }
    if(n>=109 && n<=111)
    {
             return 6;
    }
    if(n>=112 && n<=115)
    {
             return 7;
    }
    if(n>=116 && n<=118)
    {
             return 8;
    }
    if(n>=119 && n<=122)
    {
             return 9;
    }
}
int main()
{
    int n,i;
    string s;
    cin>>s;
    n=s.size();
    for(i=0; i<n; i++)
    {
             printf("%d", f(s[i]));
    }
    printf("\n");
    //system("pause");
    return 0;
}
