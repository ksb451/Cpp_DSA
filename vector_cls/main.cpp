#include<iostream>
#include"vector.h"
using namespace std;

int main()
{
    vector first;
    //int a[5]={1,2,3,4,5};
    //cout<<"size of a is "<<sizeof(a)<<endl;
    cout<<"size of first is "<<first.size()<<endl;
    cout<<"capacity of first is "<<first.capacity()<<endl;
    cout<<"value at 3rd index is "<<first.at(3)<<endl;
    first.push(6);
    first.push(7);
    first.push(8);
    first.push(9);
    first.push(10);
    cout<<"size of first is "<<first.size()<<endl;
    cout<<"capacity of first is "<<first.capacity()<<endl;
    vector second=first;
    cout<<"size of second is "<<second.size()<<endl;
    if(second.prepend(0))
    cout<<"size of second is "<<second.size()<<endl;
    if(second.pop())
    cout<<"size of second is "<<second.size()<<endl;
    if(second.remove_at(4))
    cout<<"size of second is "<<second.size()<<endl;
    if(second.remove(7))
    cout<<"size of second is "<<second.size()<<endl;
    cout<<"size of second is "<<second.size()<<endl;
    cout<<"capacity of second is "<<second.capacity()<<endl;
    return 0;
}
