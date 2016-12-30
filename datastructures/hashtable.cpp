#include <iostream>
#include <algorithm>
#include <vector>

int tablesize = 100;

class HashEntry {
private:
	int key;
	int value;
public:
	HashEntry(int key, int value) 
	{	
		this -> key = key;
		this -> value = value;
	}
	int getKey() 
	{
		return key;
	}
	int getValue() 
	{
		return value;
	}
};

class HashTable {
private: 
	HashEntry **table;
public:
	HashTable()
	{
		table = new HashEntry*[tablesize];
		for (int i = 0; i<tablesize; i++)
			table[i] = NULL;
	}
	int get (int key) 
	{
		int hash = (key % tablesize);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash+1) % tablesize;
		if(table[hash] == NULL)
			return -1;
		else
			return table[hash]->getValue();
	}
	void put(int key, int value)
	{
		int hash = (key%tablesize);
		while (table[hash] != NULL && table[hash]->getKey() != key)
			hash = (hash + 1) % tablesize;
		if(table[hash] == NULL)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}
	~HashTable() 
	{
		for(int i = 0; i<tablesize; i++)
			if(table[i] != NULL)
				delete table[i];
		delete[] table;	
	}
};
int main()
{
	HashTable h;
	h.put(1234512345, 1000000);
	std::cout<<h.get(1234512345)<<std::endl;
}
