#include<iostream> // 100 pkt
using namespace std;
int main()
{
    long long w=0;
    int n,i,ile0=0;
    char z;
    cin>>n;
    for(i=0; i<n; i++)
    {
             cin>>z;
             if(z=='0')
             {
                       ile0++;
             }
             else
             {
                 w+=ile0;
             }
    }
    cout<<w<<endl;
    //system("pause");
    return 0;
}
