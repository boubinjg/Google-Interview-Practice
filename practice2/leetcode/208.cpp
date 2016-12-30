#include<iostream>
#include<vector>
#include<string>
class TrieNode{
public: 
	char c;
	std::vector<TrieNode*> letters;
	TrieNode(){
		for(int i = 0; i<26; i++)
			letters.push_back(NULL);
	}
};

class Trie{
private:
	TrieNode* root;
public:
	Trie()
	{
		root = new TrieNode;
		root->c = '*';
	}
	void insert(std::string s)
	{
		TrieNode* cur = root;
		for(auto it = s.begin(); it<s.end(); it++)
		{
			if(cur->letters[*it-'a'] == NULL)
			{
				cur->letters[*it-'a'] = new TrieNode;
				cur->letters[*it-'a']->c = *it;
			}
			cur = cur->letters[*it-'a'];
		}
	}
	bool search(std::string s)
	{
		TrieNode* cur = root;
		for(auto it = s.begin(); it<s.end(); it++)
		{
			std::cout<< cur->c <<std::endl;
			if(cur->letters[*it-'a'] != NULL)
				cur = cur->letters[*it-'a'];
			else
				return false;
		}	
		return true;
	}
	bool startsWith(std::string prefix)
	{
		TrieNode* cur = root;
		for(auto it = s.begin(); it<s.end(); it++)
		{
			std::cout<< cur->c <<std::endl;
			if(cur->letters[*it-'a'] != NULL)
				cur = cur->letters[*it-'a'];
			else
				return false;
		}	
		return true;
	}
};

int main()
{
	Trie t;
	t.insert("abcd");
	std::cout<<t.search("abcd")<<" "<<t.search("abc")<<" "<<t.search("abd")<<std::endl;
}
