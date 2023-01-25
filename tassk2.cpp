#include <iostream>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <algorithm>
using namespace std;
int main()
{
    string path = "labirint.txt";
    ifstream labirint;
    labirint.open(path);
    string str;
    char Matr[20][20];
    int i1=0; 
    int j1=0; 
    while(i1<20)
    {
        while(j1<20)
        {
            Matr[i1][j1]='#';
            cout<<Matr[i1][j1];
            ++j1;
        }
        j1=0;
        cout<<endl;
        ++i1;
    }
    i1=0;
    if (!labirint.is_open())
    {
       cout<<"closed"<<endl;
    }
    else    
    {
        cout<<"open"<<endl;
        while(getline(labirint, str))
        {
            for (int j1 = 0; str[j1]; j1++)
                {
                    Matr[i1+1][j1+1]=str[j1];
                    cout<<Matr[i1][j1];           
                }
            cout<<endl;
            ++i1;
            j1=0;
        }
        i1=0;

    }
    labirint.close();
    char s;
    int j2;
    int i2;
    while(i1<20)
    {
        while(j1<20)
        {
            cout<<Matr[i1][j1];
            if (Matr[i1][j1]=='S')
            {
                s=Matr[i1][j1];
                j2=j1;
                i2=i1;
            }
            ++j1;
        }
        j1=0;
        cout<<endl;
        ++i1;
    }
    i1=0;
    cout<<s<<i2<<j2;
    char k=s;
    int i3=19;
    int j3=19;
    while (k!='F')
    {
        if ((Matr[i2+1][j2])!=('#'))
        {
            if(Matr[i2][j2]!='S')
            {
                Matr[i2][j2]='#';
            }
            if(Matr[i3][j3]!='S')
            {
                Matr[i3][j3]='!';
            }
            k=Matr[i2+1][j2];
            cout<<k<<i2+1<<j2;
            i3=i2;
            j3=j2;
            ++i2;
        }
        else if((Matr[i2][j2+1])!=('#'))
        {
            if(Matr[i2][j2]!='S'){
                Matr[i2][j2]='#';
            }
            if(Matr[i3][j3]!='S')
            {

                Matr[i3][j3]='!';
            }
            k=Matr[i2][j2+1];
            cout<<k<<i2<<j2+1;
            i3=i2;
            j3=j2;
            ++j2;
        }
        else if((Matr[i2-1][j2])!=('#'))
        {
            if(Matr[i2][j2]!='S')
            {
                Matr[i2][j2]='#';
            }
            if(Matr[i3][j3]!='S')
            {
                Matr[i3][j3]='!';
            }
            k=Matr[i2-1][j2];
            cout<<k<<i2-1<<j2;
            i3=i2;
            j3=j2;
            --i2;
        }
        else if((Matr[i2][j2-1])!=('#'))
        {
            if(Matr[i2][j2]!='S')
            {
                Matr[i2][j2]='#';
            }
            if(Matr[i3][j3]!='S')
            {
                Matr[i3][j3]='!';
            }
            k=Matr[i2][j2-1];
            cout<<k<<i2<<j2-1;
            i3=i2;
            j3=j2;
            --j2;
            
        }
        else
        {
            Matr[i2][j2]='#';
            Matr[i3][j3]='.';
        }
        
    }
    cout<<endl<<"completed"<<endl;

    while(i1<20)
    {
        while(j1<20)
        {
            cout<<Matr[i1][j1];
            ++j1;
        }
        j1=0;
        cout<<endl;
        ++i1;
    }
    
    return 0;
}