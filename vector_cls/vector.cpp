#include<iostream>
#include"vector.h"
using std::cout;
vector::vector()
{
    cout<<"con 1 called\n";
    arr = new int(8);
    count=0;
    limit=8;
}
vector::vector(const int size)
{
    cout<<"con 2 called\n";
    arr=new int(size);
    count=0;
    limit=size;
}
// vector::vector(const int arr1[])
// {
//     cout<<"con 3 called\n";
//     cout<<"size of arr1 "<<sizeof(arr1)<<std::endl;
//     count=sizeof(arr1)/sizeof(int);
//     cout<<"size is"<<count<<std::endl;
//     arr=new int(count*2);
//     for(int i=0;i<count;i++)
//     {
//         arr[i]=arr1[i];
//     }
//     limit=count*2;
// }

vector::vector(const vector & vct)
{
    cout<<"copy con called\n";
    count=vct.count;
    limit=vct.limit;
    arr=new int(limit);
    for(int i=0;i<count;i++)
    {
        arr[i]=vct.arr[i];
    }
}

vector::~vector()
{
    cout<<"destruc called\n";
    delete [] arr;
}

vector& vector::operator=(const vector &vct)
{
    cout<<"assignment called\n";
    if(this== &vct)
    {
        return *this;
    }
    delete [] arr;
    count=vct.count;
    limit=vct.limit;
    arr=new int(limit);
    for(int i=0;i<count;i++)
    {
        arr[i]=vct.arr[i];
    }
    return *this;
}
void vector::resize()
{
    if (count==limit)
    {
        int* temp=new int(limit*2);
        for(int i=0;i<count;i++)
        {
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=temp;
        limit*=2;
    }
    if(count<limit/4)
    {
        int* temp=new int(limit/2);
        for(int i=0;i<count;i++)
        {
            temp[i]=arr[i];            
        }
        delete [] arr;
        arr=temp;
        limit=limit/2;
    }
}

bool vector::push(int n)
{
    arr[count]=n;
    count++;
    resize();
    return true;    
}

//function to add a number at given index i m using 0 indexing
bool vector::insert(int index,int n)
{
    if(index==count)
    {
        arr[count]=n;
        count++;
        resize();
        return true;
    }
    else if(index<count&&index>=0)
    {
        for(int i=count-1;i>=index;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[index]=n;
        count++;
        resize();
        return true;
    }
    else
    {
        return false;
    }
}

bool vector::prepend(int n)
{
    return(insert(0,n));
}

bool vector::pop()
{
    if(is_empty())
    {
        return false;
    }
    count--;
    resize();
    return true;
}

bool vector::remove_at(int index)
{
    if(is_empty())
    {
        return false;
    }
    if(index>=0&&index<count)
    {
        for(int i=index;i<count-1;i++)
        {
            arr[i]=arr[i+1];
        }
        count--;
        resize();
        return true;
    }
}

bool vector::remove(int item)
{
    if(vector::is_empty())
    {
        return false;
    }
    for(int i=0;i<count-1;i++)
    {
        if(arr[i]==item)
        {
            for(int j=i+1;j<count;j++)
            {
                arr[j-1]=arr[j];
            }
            count--;
            i--;
        }
    }
    resize();
    return true;
}

int vector::find(int item)
{
    for(int i=0;i<count;i++)
    {
        if(arr[i]==item)
            return i;
    }
    return -1;
}


