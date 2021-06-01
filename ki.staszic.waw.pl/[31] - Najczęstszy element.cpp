#include<iostream> // 100 pkt
#include<algorithm>
using namespace std;
int main()
{
    int n,i,*wsk,wyn,temp=1,max=0;
    cin>>n;
    int t[n];
    wsk=t;
    for(i=0; i<n; i++)
    {
            cin>>*(wsk+i); 
    }
    sort(t,t+n);
    wyn=t[0];
    wsk=t;
    for(i=1; i<n; i++)
    {
             if(*(wsk+i)==*(wsk+i-1))
             {
                                     temp++;
             }
             else
             {
                 if(temp>max)
                 {
                             max=temp;
                             wyn=*(wsk+i-1);
                 }
                 temp=1;
             }
    }
    cout<<wyn<<endl;
    //system("pause");
    return 0;
}
