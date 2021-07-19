#include<string> // 100 pkt
#include<iostream>

using namespace std;

int main()
{
    string s;
    
    cin >> s;
    
    int n = s.size(), i;
    
    for(i=0; i<=n-1; i++)
    {
             if(s[i] != s[n-1-i])
             {
                     printf("NIE\n");
                     return 0;
             }
    }
    printf("TAK\n");
    
    return 0;
}
