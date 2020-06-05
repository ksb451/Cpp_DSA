#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>

class vector{
private:
    int *arr;
    int count;
    int limit;
    void resize();

public:
    //constructor
    vector();//default constructor
    explicit vector(const int size);//to initialize an vector of size size;
    //vector(const int *arr1);//to initialize an vector to an array;
    vector(const vector &);//copy constructor

    //destructor
    ~vector();

    vector& operator=(const vector&);//overloaded assignment operator for deep copying
    //member methods
    int size(){return count;}
    int capacity(){return limit;}
    bool is_empty(){
        if(count==0)
            return true;
        else 
            return false;
        }
    int at(int x){return arr[x];}
    bool push(int n);
    bool insert(int index, int n);
    bool prepend(int n);
    bool pop();
    bool remove_at(int index);
    bool remove(int item);
    int find(int item);
};

#endif