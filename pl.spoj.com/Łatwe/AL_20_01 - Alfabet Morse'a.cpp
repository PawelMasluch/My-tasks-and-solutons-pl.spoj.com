#include<iostream> // AC
#include<string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    string s;
    
    int r, i, num;
       
    while( getline(cin,s) != false )
    {
           r = s.size();
           
           for(i=0; i<=r-1; ++i)
           {
                    num = (int)(s[i]);
                    
                    if( num == 32 )
                    {
                        cout << "/";
                    }
                    
                    if( num == 65  ||  num == 97 )
                    {
                        cout << ".-/";
                    }
                    
                    if( num == 66  ||  num == 98 )
                    {
                        cout << "-.../";
                    }
                    
                    if( num == 67  ||  num == 99 )
                    {
                        cout << "-.-./";
                    }
                    
                    if( num == 68  ||  num == 100 )
                    {
                        cout << "-../";
                    }
                    
                    if( num == 69  ||  num == 101 )
                    {
                        cout << "./";
                    }
                    
                    if( num == 70  ||  num == 102 )
                    {
                        cout << ".-../";
                    }
                    
                    if( num == 71  ||  num == 103 )
                    {
                        cout << "--./";
                    }
                    
                    if( num == 72  ||  num == 104 )
                    {
                        cout << "..../";
                    }
                    
                    if( num == 73  ||  num == 105 )
                    {
                        cout << "../";
                    }
                    
                    if( num == 74  ||  num == 106 )
                    {
                        cout << ".---/";
                    }
                    
                    if( num == 75  ||  num == 107 )
                    {
                        cout << "-.-/";
                    }
                    
                    if( num == 76  ||  num == 108 )
                    {
                        cout << "..-./";
                    }
                    
                    if( num == 77  ||  num == 109 )
                    {
                        cout << "--/";
                    }
                    
                    if( num == 78  ||  num == 110 )
                    {
                        cout << "-./";
                    }
                    
                    if( num == 79  ||  num == 111 )
                    {
                        cout << "---/";
                    }
                    
                    if( num == 80  ||  num == 112 )
                    {
                        cout << ".--./";
                    }
                    
                    if( num == 81  ||  num == 113 )
                    {
                        cout << "--.-/";
                    }
                    
                    if( num == 82  ||  num == 114 )
                    {
                        cout << ".-./";
                    }
                    
                    if( num == 83  ||  num == 115 )
                    {
                        cout << ".../";
                    }
                    
                    if( num == 84  ||  num == 116 )
                    {
                        cout << "-/";
                    }
                    
                    if( num == 85  ||  num == 117 )
                    {
                        cout << "..-/";
                    }
                    
                    if( num == 86  ||  num == 118 )
                    {
                        cout << "...-/";
                    }
                    
                    if( num == 87  ||  num == 119 )
                    {
                        cout << ".--/";
                    }
                    
                    if( num == 88  ||  num == 120 )
                    {
                        cout << "-..-/";
                    }
                    
                    if( num == 89  ||  num == 121 )
                    {
                        cout << "-.--/";
                    }
                    
                    if( num == 90  ||  num == 122 )
                    {
                        cout << "--../";
                    }
           }
           
           cout << endl;
    }
    
    //system("pause");
    return 0;
}

