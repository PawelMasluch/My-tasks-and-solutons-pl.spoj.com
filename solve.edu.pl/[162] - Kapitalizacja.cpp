#include<iostream> // 100 pkt
#include<string>
using namespace std;
int main()
{
    int i,n;
    string s;
    cin>>s;
    n=s.size();
    for(i=0; i<n; i++)
    {
             cout<<(char)((int)(s[i])-32);
    }
    //system("pause");
    return 0;
}
