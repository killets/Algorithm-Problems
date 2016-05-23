// 参考http://stackoverflow.com/questions/13337854/understanding-lru-algorithm
// version 2: dlinklist + hash map
// 这里age可以不要了，因为永远都是最新的在tail，最旧的在head处
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

// version 2: dlinklist + hash map
class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        age = 0;
        head = new DLNode(0,0,0,nullptr,nullptr);
        tail = head;
        map = new unordered_map<int, DLNode*>();
    }

    int get(int key) {
        if(size==0) return -1;
        age++;
        if((*map).find(key)!=(*map).end()){
            
             DLNode * target = (*map)[key];
             if(target==tail){
                 target->age = age;
                return (*map)[key]->val;
             }
             
            DLNode * tmp = target->next;
            target->pre->next = tmp;
            tmp->pre = target->pre;
        
            tail->next = new DLNode(key,(*map)[key]->val, age, tail, nullptr);
            tail = tail->next;
            (*map)[key] = tail;
            delete target;
            return (*map)[key]->val;
        }
        return -1;
    }

    void set(int key, int value) {
        age++;//updateAge();
        if(size==0){
            head->next = new DLNode(key, value, age, head,nullptr);
            size++;
            tail = head->next;
            (*map).insert(make_pair(key, tail));
            return;
        }

        DLNode * tobeDelete = nullptr;
        if((*map).find(key)!=(*map).end()){
            DLNode * target = (*map)[key];
            if(target==tail){
                tail->val = value;
                tail->age = age;
                return;
            }

            tobeDelete = target;

        } else{ // cache miss
            if(size>=cap) {
                    tobeDelete = head->next;
            } else
                size++;
        }

        if(tobeDelete!=nullptr){
            DLNode * tmp = tobeDelete->next;
            tobeDelete->pre->next = tmp;
            if(tmp)  // Runtime Error 1,[set(2,1),get(2),set(3,2),get(2),get(3)]
                tmp->pre = tobeDelete->pre;
            (*map).erase(tobeDelete->key);
            delete tobeDelete;
        }

        tail->next = new DLNode(key,value, age, tail, nullptr);
        tail = tail->next;
        (*map)[key] = tail;
        return;
    }

private:
    struct DLNode{
        int key;
        int val;
        long age;
        DLNode * pre=nullptr;
        DLNode * next=nullptr;
        DLNode(int k, int v, long a, DLNode* p, DLNode* n):key(k),val(v),age(a),pre(p),next(n){
        }
    };

    int size;
    int cap;
    long age; // may overflow
    DLNode * head;
    DLNode * tail;

    unordered_map<int, DLNode*>* map;

    // 有可能超过最大时变为负，然后另外的还为正
    void updateAge(){
        if(age<LONG_MAX){
        age++;
        return;
        } else {
            DLNode * p = tail;
            long minage = 0;
            while(p!=head){
                if(p->age<minage)
                 minage = p->age;
                p = p->pre;
            }
            p = tail;
            while(p!=head){
                p->age-=minage;
            }
        }
    }
};
     

int main()
{
   LRUCache lru(4);
   cout<<lru.get(1)<<endl;
   lru.set(1,18);
   cout<<lru.get(1)<<endl;   
   lru.set(2,28);
   lru.set(3,38);
   lru.set(4,48);
   cout<<lru.get(1)<<endl;
   cout<<lru.get(2)<<endl;
   cout<<lru.get(3)<<endl;
   cout<<lru.get(4)<<endl;
   cout<<lru.get(0)<<endl;
   lru.set(5,58);
   cout<<lru.get(1)<<endl;
   cout<<lru.get(2)<<endl;
   cout<<lru.get(3)<<endl;
   cout<<lru.get(4)<<endl;
   cout<<lru.get(5)<<endl;
   
}
