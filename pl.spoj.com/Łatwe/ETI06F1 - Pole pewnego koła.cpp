#include<iostream> // 4 pkt; nie jestem pewien, czy wszystko zaliczone
#include<cstdio>
using namespace std;
int main()
{
    const double pi=3.141592654;
    double r,d;
    cin>>r>>d;
    printf("%.2lf\n", pi*((r*r)-(d*d/4)));
    return 0;
}

