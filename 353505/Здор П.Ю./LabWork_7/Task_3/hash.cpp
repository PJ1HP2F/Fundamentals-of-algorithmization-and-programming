#include "hash.h"

Hash::Hash(int aaa) {
    capacity=aaa;
    table1.resize(aaa);
    table2.resize(aaa);
}

int Hash::fib(int n){

        int fib[n + 2];
        fib[0] = 1;
        fib[1] = 2;
        for (int i = 2; i <= n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n];

}

int Hash::hashFunction(int key) {
    return key % capacity;
}

void Hash::insert(int key, int data) {
    int index = hashFunction(key);



    table1.find(index)->val = key;
    table2.find(index)->val = data;
}

void Hash::del(int key) {
    int index = hashFunction(key);
    while (table1.find(index)->val != key && table1.find(index)->val != 0)
    {
        index = (index + 1) % capacity;
    }
    if ( table1.find(index)->val == key)
    {
        QPair <int,int> tmp;
        tmp.first=0;
        tmp.second=0;

        table1.find(index)->val = 0;
        table2.find(index)->val = 0;
    }
}


j_stack Hash::hash_table_display1() {
    return table1;
}
j_stack Hash::hash_table_display2() {
    return table2;
}


int Hash::find(int key) {
    int index = hashFunction(key);
    while (table1.find(index)->val != key && table1.find(index)->val != 0) {
        index = (index + 1) % capacity;

    }
    if (table1.find(index)->val == key) {
        return table2.find(index)->val;
    }
    return -1;
}
int Hash::re_hash(int ind)
{
    return (ind+1)%capacity;
}
void Hash::delete_ch()
{
    for(int i=0;i<capacity;++i)
    {
        if (i%2==0)
        {
            del(table1.find(i)->val);
        }
    }
}
