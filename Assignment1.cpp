#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
struct student
{
    char name[15];
    int roll;
    float sgpa;
};
class studata
{
    struct student s[20],temp;
    int i,n;
    string key;
    public:
    void getdata()
    {
        cout<<"Enter number of students ";
        cin>>n;
        for(i=0;i<n;i++)
        {
            cout<<"Enter roll number ";
            cin>>s[i].roll;
            cout<<"Enter name ";
            cin>>s[i].name;
            cout<<"Enter SGPA ";
            cin>>s[i].sgpa;
            cout<<"------------------------------------------------\n";
        }
    }
    void rollwise()
    {
        int i,j;
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                if(s[j].roll>s[j+1].roll)
                {
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
            cout<<"\nPass "<<i<<endl;
            display();
        }
    }
    void display()
    {
        int i;
        cout<<"ROLL NO."<<setw(20)<<"NAME"<<setw(20)<<"SGPA"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<s[i].roll<<setw(27)<<s[i].name<<setw(20)<<s[i].sgpa<<endl;
        }
    }
    void Alphaorder()
    {
        int j;
        for(i=0;i<n;i++)
        {
            temp=s[i];
            key=s[i].name;
            j=i-1;
            while(j>=0 && s[j].name>key)
            {
                s[j+1]=s[j];
                j=j-1;
            }
            s[j+1]=temp;
            cout<<"\nPass "<<i<<endl;
            display();
        }
    }
    int partition(int b,int e)
    {
        float pivot=s[e].sgpa;
        int pi=b;
        for(i=b;i<e;i++)
        {
            if(s[i].sgpa>=pivot)
            {
                temp=s[i];
                s[i]=s[pi];
                s[pi]=temp;
                pi++;
            }
        }
        temp=s[e];
        s[e]=s[pi];
        s[pi]=temp;
        return pi;
    }
    void quick(int b,int e)
    {
        if(b<e)
        {
            int p=partition(b,e);
            quick(b,(p-1));
            quick((p+1),e);
        }
        //ranks();
    }
    void ranks()  
    {
        int i;
        cout<<"RANK"<<setw(20)<<"NAME"<<setw(20)<<"SGPA"<<endl;
        for(i=0;i<10;i++)
        {
            cout<<i+1<<setw(22)<<s[i].name<<setw(20)<<s[i].sgpa<<endl;
        }
    }
    void sgsearch()
    {
        float key;
        int i,flag=0;
        cout<<"Enter SGPA to Search :";
        cin>>key;
        for(i=0;i<n;i++)
        {
            if(key==s[i].sgpa)
            {    
                cout<<"ROLL NO:"<<s[i].roll<<setw(10)<<"NAME:"<<s[i].name<<setw(10)<<"SGPA:"<<s[i].sgpa<<endl;
                flag=1;  
            }
        }
        if(flag==0)
        {
            cout<<"NO Student Found";
        }
    }
   void nmsearch()
    {
        int f=0,l=n-1,ch=0,j,i,p=0;
        float d;
        string x;
        for(i=1;i<n-1;i++)
        {
            for(j=0;j<n-i;j++)
            {
                if(s[j].name>s[j+1].name)
                {
                    temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
        cout<<"Enter Name to search :";
        cin>>x;
        while(f<=l)
        {
            int m=(f+l)/2;
            if(s[m].name==x)
            {
                p=p+1;
                cout<<"ROLL NO:"<<s[m].roll<<setw(10)<<"NAME:"<<s[m].name<<setw(10)<<"SGPA:"<<s[m].sgpa<<endl;
               // d=s[m].roll;
                break;
            }
            else
            {
                if(s[m].name<x)
                {
                    f=m+1;
                    m=(f+l)/2;
                }
                else if(x<s[m].name)
                {
                    l=m-1;
                    m=(f+l)/2;
                }
            }
        }
        for(int k=0;k<n;k++)
        {
            if(s[k].name==key && s[k].roll!=d)
            {
                cout<<"ROLL NO:"<<s[k].roll<<setw(10)<<"NAME:"<<s[k].name<<setw(10)<<"SGPA:"<<s[k].sgpa<<endl;
                p=p+1;
                break;
            }
        }
        if(p==0)
        {
            cout<<"NO Student found !!";
        }
    }
};
int main()
{
    studata divA;
    int o;
    char w;
    divA.getdata();
    do
    {
        cout<<"Enter Option \n1.Roll number List of Students\n2.List of Students in Alphabetical order\n3.Print first 10 Toppers\n4.Search Student by SGPA\n5.Search Student by Name\n----->";
        cin>>o;
        switch(o)
        {
            case 1:
                divA.rollwise();
                break;
            case 2:
                divA.Alphaorder();
                break;
            case 3:
                divA.quick(0,14);
                divA.ranks();
                break;
            case 4:
                divA.sgsearch();
                break;
            case 5:
                divA.nmsearch();
                break;
            default:
                cout<<"Wrong option ";
        }
        cout<<"\nDo you want to continue (Enter Y/y to continue)? ";
        cin>>w;
    }while(w=='Y' || w=='y');
}