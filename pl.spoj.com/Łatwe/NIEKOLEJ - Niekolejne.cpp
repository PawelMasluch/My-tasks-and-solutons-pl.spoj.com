#include<cstdio> // AC
//#include<iostream>

using namespace std;

int main()
{
    int n, i, num1, num2;
    
    scanf("%d", &n);
    
    if( n == 1  ||  n == 2 )
    {
        printf("NIE\n");
    }
    else
    {
        num1 = n / 2;
        num2 = n;
        
        for(i=1; i<=n+1; ++i)
        {
             if( i % 2 == 1 )
             {
                 printf("%d ", num1);
                 --num1;
             }
             else
             {
                 printf("%d ", num2);
                 --num2;
             }
        }
        printf("\n");
    }
    
    //system("pause");
    return 0;
}
