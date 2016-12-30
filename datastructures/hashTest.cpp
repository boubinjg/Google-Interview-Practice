#include <algorithm>
#include <iostream>
int tablesize = 8191;
class HashPair
{
private:
	int val;
	int key;
public:
	HashPair(int key, int val)
	{
		this->key = key;
		this->val = val;
	}
	int getkey()
	{
		return key;
	}
	int getval()
	{
		return val;
	}
};
class HashTable
{
private:
	HashPair **table;
public:
	HashTable()
	{
		table = new HashPair*[tablesize];
	}
	int get(int key)
	{
		int hash = (key % tablesize);
		while(table[hash] != NULL && table[hash]->getkey() != key)
			hash = (hash+1)%tablesize;
		if(table[hash] == NULL)
			return -1;
		else
			return table[hash] ->getval();
	}
	void put(int key, int val)
	{
		int hash = (key%tablesize);
		while(table[hash] != NULL && table[hash] ->getkey() != key)
			hash = (hash+1) % tablesize;
		if(table[hash] != NULL)
			delete table[hash];
		table[hash] = new HashPair(key, val);
	}
	~HashTable()
	{
		for(int i = 0; i<tablesize; i++)
		{
			if(table[i] != NULL)
				delete table[i];
		}
		delete[] table;
	}
};
int main()
{
	HashTable h;
	h.put(2,2);
	h.put(2,3);
	std::cout<<h.get(2)<<std::endl;
	std::cout<<"hello"<<std::endl;
}
