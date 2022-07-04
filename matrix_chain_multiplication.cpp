#include <iostream>
using namespace std;
void min_multiplication(int n,int d[100])
{
    int diagonal,i,j,k,m[n+1][n+1],s[n+1][n+1],min,q;
    for(i=1;i<=n;i++)
    { for(j=1;j<=n;j++)
    { m[i][j]=0;s[i][j]=0;}
    }
    for(diagonal=2;diagonal<=n;diagonal++)
    {
        for(i=1;i<=n-diagonal+1;i++)
        {
            j=i+diagonal-1;
            min=9999;
            for(k=i;k<=j-1;k++)
            {
                q=(m[i][k])+(m[k+1][j])+((d[i-1])*(d[k])*(d[j]));
                if(q<min)
                { min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }
    cout<<"The matrix is "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"The sum matrix is "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<s[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    int n,i,j;
    cout<<"Enter the number of matrices to be multiplied:"<<endl;
    cin>>n;
    int a[n+1][3],d[n+1];
    cout<<"Enter the order of each matrix:"<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=2;j++)
        cin>>a[i][j];
    }
    for(i=0,j=1;i<=n;i++,j++)
    {
        d[i]=a[j][1];
    }
    d[n]=a[n][2];
    min_multiplication(n,d);
    return 0;
}
