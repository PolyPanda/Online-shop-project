
#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include "List.h"

using namespace std;

template <class hashdata>
class HashTable {
public:
    /**constructors*/
    
    HashTable();
    //constructor
    
    ~HashTable();
    //destructor
    
    
    HashTable(const HashTable& ht);
    //copy constructor
    
    /**access functions*/
    
    int hash(string key);
    
    
    int countbucket(int index);
    
    hashdata find(string key);
    
    /**manipulation procedures*/
    
    void insert(string key, hashdata data);
    
    void remove(string key);
    
    /**additional functions*/
    
    void printtable();
    
    
    int getnumcollision() { return collision; }
    
    string getkey(hashdata data);
    
    void writeToFile(fstream& outFile);
    
private:
    static const int size = 40;
    int collision;
    List<hashdata> table[size];
};

template <class hashdata>
HashTable<hashdata>::HashTable() {
    collision = 0;
}

template <class hashdata>
HashTable<hashdata>::~HashTable() {
    
}

template <class hashdata>
HashTable<hashdata>::HashTable(const HashTable &ht) {
    for (int i = 0; i < ht.size; i++) {
        List<hashdata> temp = ht.table[i];
        table[i] = temp;
    }
}

template <class hashdata>
int HashTable<hashdata>::hash(string key) {
    int total = 0;
    for (int i = 0; i < key.length(); i++)
        total += key.at(i);
    
    return total % size;
}

template <class hashdata>
int HashTable<hashdata>::countbucket(int index) {
    if (0 <= index && index < size) {
        return table[index].getsize();
    }
    return 0;
}

template <class hashdata>
hashdata HashTable<hashdata>::find(string key) {
    int index = hash(key);
    if (table[index].empty()) {
        return NULL;
    }
    
    table[index].beginIterator();
    
    while (!table[index].offEnd()) {
        if (key == table[index].getIterator()->getPrimaryKey()) {
            return table[index].getIterator();
        }
        
        table[index].advancedIterator();
    }
    
    return NULL;
}

template <class hashdata>
void HashTable<hashdata>::insert(string key, hashdata data) {
    int index = hash(key);
    table[index].insertEnd(data);
    
    if (table[index].getLength() > 1)
        collision++;
}

template <class hashdata>
void HashTable<hashdata>::remove(string key) {
    int index = hash(key);
    int presize = countbucket(index);
    
    if (presize == countbucket(key)) {
        cout << "could not delete the object" << endl;
        
        if (table[key].getSize() > 1)
            collision--;
    }
    else {
        table[index].startIterator();
        while (!table[index].offEnd()) {
            if (key == table[index].getIterator()->getPrimaryKey()) {
                cout << "object has been removed" << endl;
                table[index].removeIterator();
                return;
            }
            
            table[index].advanceIterator();
        }
        cout << "object has been removed" << endl;
    }
}

template <class hashdata>
void HashTable<hashdata>::printtable() {
    for (int i = 0; i < size; i++) {
        if (table[i].getLength() > 0) {
            table[i].beginIterator();
            while (!table[i].offEnd()) {
                cout << table[i].getIterator();
                table[i].advancedIterator();
            }
        }
    }
}

template <class hashdata>
void HashTable<hashdata>::writeToFile(fstream& outFile) {
    for (int i = 0; i < size; i++) {
        if (table[i].getLength() > 0) {
            table[i].beginIterator();
            while (!table[i].offEnd()) {
                table[i].getIterator()->writeToFile(outFile);
                table[i].advancedIterator();
            }
        }
    }
}
#endif 
