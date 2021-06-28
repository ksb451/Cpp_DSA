#include<iostream>
using namespace std;
  
class base {
public:
    // int a;
    virtual void fun(){
        cout<<"base"<<endl;
    } 
};
  
class b1: public virtual base {
public:
    // void fun(){
    //     cout<<"b1"<<endl;
    // } 
    
 };
  
class b2: public virtual base { 
public:
    // void fun(){
    //     cout<<"b2"<<endl;
    // } 

    };
  
class derived: public b1, public b2 {
public:
   // virtual void fun(){
   //  cout<<"derived"<<endl;
   // }
};
  
int main(void)
{ 
  b1 b11;
  b11.fun();
  b2 b22;
  b22.fun();
  derived d;
  d.fun();
  return 0;
}