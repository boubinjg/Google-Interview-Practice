#include<iostream>
#include<vector>
#include<algorithm>
struct hashPair{
	int value;
	int key;
};
class hashTable{
private:
	int tableSize = 8191;
	std::vector<std::vector<hashPair> > table;
public:
	hashTable(){
		table.resize(tableSize);
	}
	void put(int key, int val)
	{
		int hash = (key%tableSize);
		hashPair p;
		p.value = val;
		p.key = key;
		table[hash].push_back(p);
	}
	int get(int key)
	{
		int hash = (key%tableSize);
		if(table[hash].empty())
			throw 1;
		for(auto it = table[hash].begin(); it<table[hash].end(); it++)
			if((*it).key == key)
				return (*it).value;		
		throw 2;
	}
};
int main()
{
	hashTable t;
	t.put(1, 1);
	t.put(2, 2);
	t.put(3, 3);
	std::cout<<t.get(3)<<std::endl;
	std::cout<<t.get(4)<<std::endl;
	return 0;
}
