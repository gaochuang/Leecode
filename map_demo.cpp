#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pair{
public:
    int key;
    string val;
    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    }
};

class ArrayHashMap
{
private:
    vector<Pair*> buckets;
    int hashfunc(int key);

public:
    ArrayHashMap();
    ~ArrayHashMap();

    string get(int key);
    void push(int key, string val);
    void remove(int key);
    void print();
};

ArrayHashMap::ArrayHashMap()
{
    buckets = vector<Pair*>(100);
}

ArrayHashMap::~ArrayHashMap()
{
    for(const auto& bucket : buckets)
    {
        delete bucket;
    }

    buckets.clear();
}

int ArrayHashMap::hashfunc(int key)
{
    int index = key % 100;
    return index;
}

string ArrayHashMap::get(int key)
{
    int index = hashfunc(key);
    Pair* pair = buckets[index];
    if(nullptr == pair)
    {
        return "";
    }

    return pair->val;
}

void ArrayHashMap::push(int key, string val)
{
    Pair* pair = new Pair(key, val);

    buckets[hashfunc(key)] = pair;
}

void ArrayHashMap::remove(int key)
{
    int index = hashfunc(key);

    delete buckets[index];
    buckets[index] = nullptr;
}

void ArrayHashMap::print()
{
    for(Pair* pair: buckets)
    {
        if(nullptr != pair)
        {
            cout << "key: "<<pair->key <<" value: "<<pair->val<<endl;
        }
    }
}

int main()
{
   
   ArrayHashMap map;

    map.push(1, "one");
    map.push(2, "two");
    map.push(3, "three");
    map.push(4, "four");

    map.print();
    return 0;
}