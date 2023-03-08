#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
#define val 4

class sentinal{

    public:
       int count;
       sentinal *up;
       node *next;
       
       sentinal():count(0), up(NULL), next(NULL){}
};

class node{
   
   public:
      int item;
      node *next;
      node *prev;
      node *down;
      
      node(int item):item(item), next(NULL), prev(NULL), down(NULL){}
};

class SkipList{

    private:
        sentinal *L;
        node *tail;
        int tossCoin(){
            return rand()%2;
        }
    
    public:
        SkipList();
        void insert(int);
        void del(int);
        bool search(int);
};

SkipList::SkipList(){
   L = new sentinal();
   tail = NULL;
}

void SkipList::insert(int item){
    node *newNode = new node(item);
    if(L->count<=val){
        if(tail==NULL){
           L->next = newNode;
           tail = newNode;
        }
        else{
           tail->next = newNode;
           tail = newNode;
        }
    }
    else{
        if(tossCoin()){
            
    
    
