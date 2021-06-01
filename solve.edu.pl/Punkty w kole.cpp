#include<iostream> // 100 pkt
using namespace std;
int main()
{
    long long wyn,R,i,ind;
    cin>>R;
    ind=R-1; wyn=(4*R)+1;
    for(i=1; i<=R; i++)
    {
             while((ind*ind)>(R+i)*(R-i))
             {
                                   ind--;
             }
             wyn+=(4*ind);
    }
    cout<<wyn<<endl;
    //system("pause");
    return 0;
}
