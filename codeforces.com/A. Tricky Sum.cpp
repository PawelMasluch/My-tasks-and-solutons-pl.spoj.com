#include<iostream> // AC
 
 
using namespace std;
 
 
typedef long long LL;
 
 
LL f(LL n)
{
    LL wyn = 0, tmp = 1;
    
    while( tmp <= n )
    {
        tmp <<= 1;
        
        ++wyn;
    }
    
    return wyn;
}
 
 
int main()
{
    LL q, n, wyn, x;
    
    cin >> q;
    
    while( q )
    {
        cin >> n;
        
        x = f( n );
        
        wyn = ( ( n * ( n + 1 ) ) >> 1 ) - ( ( ( 1 << x ) - 1 ) << 1 );
        
        cout << wyn << endl;
        
        --q;
    }
    
    return 0;
}
