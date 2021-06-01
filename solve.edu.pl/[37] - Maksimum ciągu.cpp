#include<iostream> // 100 pkt
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n,i,w=-1,a;
    cin>>n;
    for(i=0; i<n; i++)
    {
             cin>>a;
             w=max(w,a);
    }
    cout<<w<<endl;
    return 0;
}
