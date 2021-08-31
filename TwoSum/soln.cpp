#include<chrono>
#include<iostream>
#include<fstream>
#include<map>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto t1 = std::chrono::high_resolution_clock::now();
        
        std::map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            
            if (m.find(diff) != m.end()){
                std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
                
                std::cout << "Time taken: " << fp_ms.count() << " ms, ";
                return {m[diff], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

int main (){
    Solution soln;
	string line;
	int i = 0;
	vector <string> v;
	ifstream fin;
	fin.open ("testcase.txt");

	if (fin.is_open()){
		while (getline(fin, line)){
			stringstream ss(line);

			while (getline(ss, line, '\n')){
				v.push_back(line);
			}
		}
    string vsubstr = v[0].substr(1, v[0].size() - 1);
    int target = stoi(v[1]);
    vector<int> v_split;
    stringstream s_stream(vsubstr); 
    while(s_stream.good()) {
        string subs;
        getline(s_stream, subs, ','); //get first string delimited by comma
        v_split.push_back(stoi(subs));
    }
    cout << v_split[0];
    cout << "\n";
    cout << v[1];

        for (int i = 0; i < 10; i ++){
            soln.twoSum(v_split, target);
            cout << "\n";
        }
	}
    return 0;
}