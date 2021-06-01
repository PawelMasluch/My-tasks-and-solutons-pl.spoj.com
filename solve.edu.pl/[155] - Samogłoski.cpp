#include<cstdio> // 100 pkt
#include<string>
#include<iostream>
using namespace std;
int f(char z)
{
    if(z=='a' || z=='e' || z=='i' || z=='o' || z=='u' || z=='y')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n,i,w=0;
    string s;
    cin>>s;
    n=s.size();
    for(i=0; i<n; i++)
    {
             w+=f(s[i]);
    }
    cout<<w<<endl;
    //system("pause");
    return 0;
}
