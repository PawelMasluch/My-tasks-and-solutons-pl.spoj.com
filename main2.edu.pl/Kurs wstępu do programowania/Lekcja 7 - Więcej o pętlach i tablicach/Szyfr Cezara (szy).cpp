#include<string> // 100 pkt
#include<iostream>

using namespace std;

int main()
{
    int n, i, k, co_robic;
    
    string s;
    
    cin >> co_robic >> k >> s;
    
    n = s.size();
    
    if(co_robic == 2) // jesli deszyfruję
    {
        for(i=0; i<=n-1; i++)
        {
                 if( (int)(s[i]) >= 65  &&  (int)(s[i]) <= 90 )
                 {
                     s[i] = 65 + ( ( (int)(s[i]) - k - 39 ) % 26 );
                 }
                 else
                 {
                     if( (int)(s[i]) >= 97  &&  (int)(s[i]) <= 122 )
                     {
                         s[i] = 97 + ( ( (int)(s[i]) - k - 71 ) % 26 );
                     }
                 }
        }
    }
    else // co_robic == 1 , czyli szyfruję
    {
         for(i=0; i<=n-1; i++)
         {
                  if( (int)(s[i]) >= 65  &&  (int)(s[i]) <= 90 )
                  {
                      s[i] = 65 + ( ( (int)(s[i]) + k - 65 ) % 26 );
                  }
                  else
                  {
                      if( (int)(s[i]) >= 97  &&  (int)(s[i]) <= 122 )
                      {
                          s[i] = 97 + ( ( (int)(s[i]) + k - 97 ) % 26 );
                      }
                  }
         }
    }
    
    cout << s << endl;
    
    //system("pause");
    return 0;
}
