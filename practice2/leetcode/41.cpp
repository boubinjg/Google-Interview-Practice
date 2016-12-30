#include<unordered_map>

class Solution {

public:

    int firstMissingPositive(vector<int>& v) {

        std::unordered_map<int,bool> map;

        for(auto it = v.begin(); it<v.end(); it++)

            map[*it] = true;

        int missing = 0;

        for(int i = 1; i<=v.size(); i++)

            if(!map[i])

                return i;

        return v.size()+1;

    }

};
