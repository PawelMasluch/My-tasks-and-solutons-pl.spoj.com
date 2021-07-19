#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1, s2;
    
    cin >> s1 >> s2;
    
    int r1 = s1.size(), r2 = s2.size(), **DP, i, j, cost;
    
    DP = new int *[r1 + 1];
    
    for(i=0; i<=r1; i++)
    {
         DP[i] = new int [r2 + 1];
    }
    
    for(j=0; j<=r2; j++)
    {
         DP[0][j] = 0;
    }
    
    for(i=1; i<=r1; i++)
    {
         DP[i][0] = 0;
    }
    
    for(i=1; i<=r1; i++)
    {
         for(j=1; j<=r2; j++)
         {
                  if(s1[i-1] == s2[j-1])
                  {
                           cost = 1;
                  }
                  else
                  {
                      cost = 0;
                  }
                  
                  DP[i][j] = max( max( DP[i-1][j], DP[i][j-1] ), DP[i-1][j-1] + cost);
         }
    }
    
    cout << DP[r1][r2] << endl;
    
    //system("pause");
    return 0;
}
