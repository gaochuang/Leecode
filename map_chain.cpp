#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pair
{
public:
    int key,
    string val;
    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    };
};

class HashMapChaining
{
private:
    int size; //键值数量
    int capacity; //哈希表容量
    double loadThres; //触发扩容的负载因子阈值
    int extendRatio; //扩容倍数
    vector<vector<Pair*>> buckets; //桶数组
public:
   HashMapChaining();
   ~HashMapChaining();
   
   double loadFactor();
   int hashFunc(int key);
   void extend();
   void put(int key, string val);
   string get(int key);
   void remove(int key);

};

HashMapChaining::HashMapChaining():size(0),capacity(4),loadThres(2.0/3.0),extendRatio(2),buckets.resize(capacity)
{

}

HashMapChaining::~HashMapChaining()
{
    for(auto & bucket : buckets)
    {
        for(Pair *pair : bucket)
        {
            delete pair;
            pair = nullptr;
        }
    }
}

double HashMapChaining::loadFactor()
{
    return double(size)/double(capacity);
}

int HashMapChaining::hashFunc(int key)
{
    return key%capacity;
}

void HashMapChaining:put(int key, string val)
{
    if(loadFactor() > loadThres)
    {
        extend();
    }
   
    int index = hashFunc(key);

    for(Pair* pair : buckets[index])
    {
        if(pair->key == key)
        {
            pair->val = val; 
        }
    }

    buckets[index].push_back(new Pair(key, val));
    size++;

}

void HashMapChaining::extend()
{
    vector<vector<Pair*>> bucketsTmp = buckets;
    capacity *= extendRatio;
    buckets.resize(capacity);
    size = 0;

    for(auto &bucket : bucketsTmp){
        for(Pair* pair : bucket)
        {
            put(pair->key, pair->val);
            delete pair;
            pair = nullptr;
        }
    }
}

string HashMapChaining::get(int key)
{
    int index = hashFunc(key);

    for(Pair* pair : buckets[index])
    {
        if(pair->key == key)
        {
            return pair->val;
        }
    }

    return "";
}

void HashMapChaining::remove(int key)
{
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        // 遍历桶，从中删除键值对
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i]->key == key) {
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin() + i); // 从中删除键值对
                delete tmp;                       // 释放内存
                size--;
                return;
            }
        }
}


int main()
{
    return 0;
}