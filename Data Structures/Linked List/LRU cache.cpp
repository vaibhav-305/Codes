#include <iostream>
#include <list>
#include <map>
#include <iterator>
using namespace std;

class LRUCache{
    int sz;
    list<int> Q;
    map<int,pair<int,list<int>::iterator>> M;

public:

    LRUCache(int n){
        sz=n;
    }
    int get(int key){
        if(M.find(key)!=M.end()){
            /*Q.erase(M[key].second);
            Q.push_front(key);
            M[key].second=Q.begin();*/
            Q.splice(Q.begin(),Q,M[key].second);
            return M[key].first;
        }
        else
            return -1;
    }
    void put(int key,int value){
        if(M.find(key)!=M.end()){
            M[key].first=value;
            /*Q.erase(M[key].second);
            Q.push_front(key);
            M[key].second=Q.begin();*/
            Q.splice(Q.begin(),Q,M[key].second);
        }
        else{
            if(M.size()==sz){
                int last = Q.back();
                Q.pop_back();
                M.erase(last);
            }
            Q.push_front(key);
            M[key]=make_pair(value,Q.begin());
        }
        return ;
    }
};
int main()
{
    LRUCache lru(2);
    lru.put(1, 1); // cache is {1=1}
    lru.put(2, 2); // cache is {1=1, 2=2}
    cout<<lru.get(1)<<" ";    // return 1
    lru.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lru.get(2)<<" ";    // returns -1 (not found)
    lru.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<lru.get(1)<<" ";    // return -1 (not found)
    cout<<lru.get(3)<<" ";    // return 3
    cout<<lru.get(4)<<" ";    // return 4
  return 0;
}
