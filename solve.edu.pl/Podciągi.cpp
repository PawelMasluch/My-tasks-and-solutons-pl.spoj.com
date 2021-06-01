#include<iostream> // 100 pkt
#include<string>

using namespace std;

bool f(string &a, string &b) // czy a jest podciągiem b (niekoniecznie spójnym)
{
     int i = 0, j = 0, ra = a.size(), rb = b.size();
     
     while( j <= rb - 1 )
     {
            if( b[j] == a[i] )
            {
                ++i;
            }
            
            if( i == ra )
            {
                return true;
            }
            
            ++j;
     }
     
     return false;
}

void g(string &a, string &b)
{
     if( f(a,b) == true )
     {
         cout << "TAK\n";
     }
     else
     {
         cout << "NIE\n";
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int Q;
    
    cin >> Q;
    
    string a, b;
    
    while( Q > 0 )
    {
           cin >> a >> b;
           
           g(a,b);  
           
           --Q; 
    }
    
    return 0;
}
