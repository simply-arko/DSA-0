#include <bits/stdc++.h>
using namespace std;

struct node{
	int key, val;
	node *next, *prev;
	node(int key, int val):key(key), val(val), next(NULL), prev(NULL){}
};

class LRUCache{
private:
	node *head, *tail;
	unordered_map <int, node*> map;
	int capacity;
	int size;

	bool isEmpty();
	node* addFirst(int, int);
	int deleteLast();
	void rePosition(node*);

public:
	LRUCache();
	LRUCache(int);
	void put(int, int);
	int get(int);
};

LRUCache::LRUCache():head(NULL), tail(NULL), capacity(50), size(0){}

LRUCache::LRUCache(int capacity):head(NULL), tail(NULL), capacity(capacity), size(0){}

bool LRUCache::isEmpty(){
	return (size==0);
}

node* LRUCache::addFirst(int key, int val){
	node *newNode = new node(key, val);
	if(isEmpty()){
		head = newNode;
		tail = head;
	}else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	++size;
	return head;
}

int LRUCache::deleteLast(){

	int key = tail->key;
	if(size==1){
		delete tail;
		head = tail = NULL;
	}else{
		node *del = tail;
		tail = tail->prev;
		delete del;
	}

	--size;
	return key;
}

void LRUCache::rePosition(node *n){
	if(n==head)
		return;
	else if(n==tail){
		tail = tail->prev;
		n->prev = NULL;
		n->next = head;
		head->prev = n;
		head = n;
	}else{
		n->prev->next = n->next;
		n->next->prev = n->prev;
		n->prev = NULL;
		n->next = head;
		head->prev = n;
		head = n;
	}
}

void LRUCache::put(int key, int val){
	if(map.count(key)){
		map.at(key)->val = val;
		return;
	}
	if(size<capacity){
		map[key] = addFirst(key, val);
	}
	else{
		map.erase(deleteLast());
		map[key] = addFirst(key, val);
	}
}

int LRUCache::get(int key){
	if(map.count(key)){
		rePosition(map.at(key));
		return map.at(key)->val;
	}else
		return -1;
}

int main(int argc, char const *argv[]){

	LRUCache l1(2);
	l1.put(1, 1);
	l1.put(2, 2);
	l1.put(3, 3);
	l1.put(3, 3);
	cout<<l1.get(1)<<endl;
	cout<<l1.get(2)<<endl;

	return EXIT_SUCCESS;
}