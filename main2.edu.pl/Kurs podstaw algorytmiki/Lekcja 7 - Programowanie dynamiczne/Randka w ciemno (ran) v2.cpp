#include<iostream>
#include<new>
#include<string>
#include<algorithm>

using namespace std;

struct elem
{
       string S;
       int num;
};

bool f(elem a, elem b)
{
     return (a.num < b.num);
}

int main()
{
    int n, s, i, j;
    
    cin >> n >> s;
    
    elem *t = new elem [n];
    
    for(i=0; i<=n-1; i++)
    {
         cin >> t[i].S >> t[i].num;
    }
    
    sort(t,t+n,f);
    
    i = 0;
    j = n-1;
    
    while( i <= n - 1 )
    {
           while( j > i )
           {
                  if(t[i].num + t[j].num > s)
                  {
                              j--;
                  }
                  else
                  {
                      break;
                  }
           }
           
           if(j <= i)
           {
                cout << "NIE\n";
                
                return 0;
           }
           
           if(t[i].num + t[j].num == s)
           {
                       cout << t[i].S << " " << t[j].S << endl;
                       
                       return 0;
           }
           
           i++;
    }
    
    return 0;
}
