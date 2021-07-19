#include<cstdio>
//#include<iostream>

using namespace std;

typedef long long LL;

int main()
{
    LL n;
    
    scanf("%lld", &n);
    
    if( n == 0 )
    {
        printf("1\n");
        
        //system("pause");
        return 0;
    }
    
    switch( n % 4 )
    {
            case 0:
                 printf("6\n");
                 break;
                 
            case 1:
                 printf("2\n");
                 break;                                                             
                 
            case 2:
                 printf("4\n");
                 break;        
                 
            case 3:
                 printf("8\n");
                 break;                
    }
    
    //system("pause");
    return 0;
}
