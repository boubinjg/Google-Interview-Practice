#include<iostream>
#include<vector>

int main() {
	std::vector<std::vector<int> > v;
	for(int i = 0; i<10; i++) {
		std::vector<int> n;
		for(int j = 0; j<10; j++) {
			n.push_back(i*j);
		}
		v.push_back(n);
	}
	
	for(auto it = v.begin(); it<v.end(); it++){
		for(auto lit = (*it).begin(); lit < (*it).end(); lit++)
			std::cout<<*lit<<std::endl;
	}
	return 0;
}
