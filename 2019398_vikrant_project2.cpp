#include<iostream>
using namespace std;
void comp(int arr1[],int nbit);
void display(int arr3[],int ier[],int bitier);
void req(int arr4[],int ier[],int &temp,int bitier);
void add(int arr2[],int temp2[], int num);
int main()
{
    int bitant,bitier,cbitier,ant[10],ier[10],rant[10],ac[10]={ 0 };
    cout<<"Enter number of multipicand bit = \t";
    cin>>bitant;

    cout<<"\nEnter multiplicand(give space after each bit) = \t";
    for(int i =0;i<bitant;i++)
       {
         cin>>ant[i];
       }

    cout<<"\n\nEnter number of multiplier bit ";
    cin>>bitier;

    cout<<"\nEnter multiplier(give space after each bit) = \t";
    for(int j=0;j<bitier;j++)
        {
            cin>>ier[j];
        }

    for(int k=bitant-1;k>=0;k--)
        {
            rant[k]=ant[k];
        }
    comp(ant,bitant);

    cbitier=bitier;
    int temp1=0;
    int temp2=0;

    for(int i=cbitier;i>0;i--)
    {
        if((temp1+ier[0])==1)
        {
            if(temp2==0)
            {
                add(ac,ant,bitier);
                temp2=1;
            }
            else if(temp2==1)
            {
                add(ac,rant,bitier);
                temp2=0;
            }

            req(ac,ier,temp1,bitier);
        }

        else if(temp1-ier[0]==0)
        {
            req(ac,ier,temp1,bitier);
        }


    }
     cout<<"result = \t";
     display(ac,ier,bitier);

}



void comp(int arr1[],int nbit)
{
    int temp[8]={ NULL };
    temp[0]=1;
    for(int a=0;a<nbit;a++)
    {
         arr1[a] = (arr1[a] + 1) % 2;

    }
    add(arr1,temp,nbit);
}

void add(int arr2[],int temp2[], int num)
{
    int flag=0;
    int t=0;
    while(t<num)
    {
        arr2[t] = arr2[t] + temp2[t] + flag;
      if (arr2[t] > 1)
        {
         arr2[t] = arr2[t] % 2;
         flag = 1;
        }
      else
        {
        flag=0;
        }
      t++;
    }

}

void req(int arr4[],int ier[],int &temp,int bitier)
{
   int flag;
   flag=arr4[0];
   temp=ier[0];
   for(int n=0;n<bitier;n++)
   {
       arr4[n]=arr4[n+1];
       ier[n]=ier[n+1];
   }
   ier[bitier-1]=flag;
}



void display(int arr3[],int ier[],int bitier)
{
    for(int z = bitier-1;z>=0;z--)
        cout<<arr3[z];
    for(int y= bitier-1;y>=0;y--)
        cout<<ier[y];
}
