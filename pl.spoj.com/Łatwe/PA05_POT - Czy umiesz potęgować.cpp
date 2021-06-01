#include<iostream> // AC
using namespace std;
int main()
{
    int d,a,b;
    cin>>d;
    for(int i=0; i<d;i++)
    {
            cin>>a>>b;
            if(b%4==0)
            {
                      cout<<((a%10)*(a%10)*(a%10)*(a%10))%10<<endl;
            }
            else
            {
                if(b%4==1)
            {
                      cout<<(a%10)%10<<endl;
            }
            else
            {
                if(b%4==2)
            {
                      cout<<((a%10)*(a%10))%10<<endl;
            }
            else
            {
                if(b%4==3)
            {
                      cout<<((a%10)*(a%10)*(a%10))%10<<endl;
            }
            }
            }
            }
    }
    getchar();
    //system("pause");
    return 0;
}
                

