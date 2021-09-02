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
    float twoSum(vector<int>& nums, int target) {
        auto t1 = std::chrono::high_resolution_clock::now();
        
        std::map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            
            if (m.find(diff) != m.end()){
                std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
                return fp_ms.count();
                // std::cout << "Time taken: " << fp_ms.count() << " ms, ";
                // return {m[diff], i};
            }
            m[nums[i]] = i;
        }
        std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        return fp_ms.count();
        // return 0.0;
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
        
    vector<float> times;
    int sample_size = 1000;
    int iters = 100;
    for (int i = 0; i < iters; i++){
        float prop = float(i) / float(iters);
        int ind = prop * v_split.size();
        float md = 0;
        for (int j = 0; j < sample_size; j++){
            vector<int> mid_vec;
            for (int k = 0; k < ind; k++){
                mid_vec.push_back(v_split[k]);
            }
            md += soln.twoSum(mid_vec, target);
        }
        times.push_back(md / sample_size);
    }
    for (int i = 0; i < times.size(); i++){
        cout << times[i] << ", ";
    }
	}
    return 0;
}