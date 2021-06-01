#include<iostream> // AC

using namespace std;

/*void iloczyn_hadamarda()
{
    int i,j,w1,k1,w2,k2;
	cin>>w1>>k1;
	int A[w1][k1];
    for(i=0; i<w1; i++)
    {
              for(j=0; j<k1; j++)
		      {
                       cin>>A[i][j];
              }
    }
    cin>>w2>>k2;
	int B[w2][k2];
    for(i=0; i<w2; i++)
    {
              for(j=0; j<k2; j++)
		      {
                       cin>>B[i][j];
              }
    }
	if(k1!=k2 || w1!=w2)
	{
		cout<<"\nNiewykonalne\n";
	}
	else
	{
		int C[w1][k1];	
		for(i=0; i<w1; i++)
		{
			for(j=0; j<k1; j++)
			{
				C[i][j]=A[i][j]*B[i][j];
			}
		}
		cout<<endl;
		for(i=0; i<w1; i++)
        {
              for(j=0; j<k1; j++)
		      {
                       cout<<C[i][j]<<" ";
              }
              cout<<endl;
        }
	}
}

void mnozenie_macierzy() // wykonujemy mno¿enie A*B
{
	int i,j,w1,k1,w2,k2;
	cin>>w1>>k1;
	int A[w1][k1];
    for(i=0; i<w1; i++)
    {
              for(j=0; j<k1; j++)
		      {
                       cin>>A[i][j];
              }
    }
    cin>>w2>>k2;
	int B[w2][k2];
    for(i=0; i<w2; i++)
    {
              for(j=0; j<k2; j++)
		      {
                       cin>>B[i][j];
              }
    }
	if(k1!=w2)
	{
		cout<<"\nNiewykonalne\n";
	}
	else
	{
		int C[w1][k2],S=0,l;	
		for(i=0; i<w1; i++)
		{
			for(j=0; j<k2; j++)
			{
				for(l=0; l<k1; l++)
				{
					S+=A[i][l]*B[l][j];
				}
				C[i][j]=S;
				S=0;
			}
		}
		cout<<endl;
		for(i=0; i<w1; i++)
        {
              for(j=0; j<k2; j++)
		      {
                       cout<<C[i][j]<<" ";
              }
              cout<<endl;
        }
	}
}

void dodawanie_macierzy()
{
    int i,j,w1,k1,w2,k2;
	cin>>w1>>k1;
	int A[w1][k1];
    for(i=0; i<w1; i++)
    {
              for(j=0; j<k1; j++)
		      {
                       cin>>A[i][j];
              }
    }
    cin>>w2>>k2;
	int B[w2][k2];
    for(i=0; i<w2; i++)
    {
              for(j=0; j<k2; j++)
		      {
                       cin>>B[i][j];
              }
    }
	if(k1!=k2 || w1!=w2)
	{
		cout<<"\nNiewykonalne\n";
	}
	else
	{
		int C[w1][k1];	
		for(i=0; i<w1; i++)
		{
			for(j=0; j<k1; j++)
			{
				C[i][j]=A[i][j]+B[i][j];
			}
		}
		cout<<endl;
		for(i=0; i<w1; i++)
        {
              for(j=0; j<k1; j++)
		      {
                       cout<<C[i][j]<<" ";
              }
              cout<<endl;
        }
	}
}*/

void transpozycja()
{
     int i,j,w1,k1;
	 cin>>w1>>k1;
	 int A[w1][k1];
     for(i=0; i<w1; i++)
	 {
              for(j=0; j<k1; j++)
		      {
                       cin>>A[i][j];
              }
     }
     int B[k1][w1];
     for(i=0; i<k1; i++)
	 {
              for(j=0; j<w1; j++)
              {
                       B[i][j]=A[j][i];
              }
     }
     cout<<endl;
     for(i=0; i<k1; i++)
	 {
              for(j=0; j<w1; j++)
		      {
                       cout<<B[i][j]<<" ";
              }
              cout<<endl;
     }
}

int main()
{
    //dodawanie_macierzy();
    //iloczyn_hadamarda();
    //mnozenie_macierzy();
    transpozycja();
	//system("pause");
	return 0;
}
