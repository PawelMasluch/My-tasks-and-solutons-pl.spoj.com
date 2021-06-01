#include<iostream> // AC
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int t, i, l, ile = 1, r, j;
    cin >> t;
    
    string s;
    
    for(l=1; l<=t; l++)
    {
         cin >> s;
         
         s = s + "#";
         
         r = s.size();
         
         for(i=1; i<=r-1; i++)
         {
                  if(s[i] == s[i-1])
                  {
                      ile++;
                  }
                  else
                  {
                      if(ile >= 3)
                      {
                          cout << s[i-1] << ile;
                      }
                      else
                      {
                          for(j=1; j<=ile; j++)
                          {
                                   cout << s[i-1];
                          }
                      }
                      
                      ile = 1;
                  }
         }
         
         cout << endl;
    }
    
    return 0;
}
