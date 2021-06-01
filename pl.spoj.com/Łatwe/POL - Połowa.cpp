#include<string> // AC
#include<iostream>
using namespace std;
int main()
{
    string s;
    int t,i,j,rozm;
    cin>>t;
    for(i=0; i<t+1; i++)
    {
        getline(cin,s);
        rozm=s.size();
        for(j=0; 2*j<rozm; j++)
        {
                 cout<<s[j];
        }
        cout<<endl;    
    }
    return 0;
}

