#include<algorithm>
#include<chrono>
#include<iostream>
#include<fstream>
#include<map>
#include<sstream>
#include<stack>
#include<string>
#include <unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    float groupAnagrams(vector<string>& strs) {
        #include <chrono>
        auto t1 = std::chrono::high_resolution_clock::now();
        
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        
        for (int i = 0; i < strs.size(); i ++){
            string s = strs[i];
            sort(s.begin(), s.end());
            
            m[s].push_back(strs[i]);
        }
        
        for(auto pair: m){
            res.push_back(pair.second);
        }
        
        chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        // cout << "Time taken: " << fp_ms.count() << " ms, ";
        // return res;
        return fp_ms.count();
    }
};

int main (){
    Solution soln;
	string line;
	int i = 0;
	vector<string> v;
	ifstream fin;
	fin.open ("testcase.txt");

	if (fin.is_open()){
		while (getline(fin, line)){
			stringstream ss(line);

			while (getline(ss, line, '\n')){
				v.push_back(line);
			}
		}

        string strs = v[0];
        string m2 = strs.substr(1, strs.size() - 2);
        
        vector<string> res;
        int j = 0;
        for (int i = 1; i < m2.size(); i += 6){
            string a = m2.substr(i, 3);
            res.push_back(a);
            j ++;
        }
        
        vector<float> times;
        vector<string> vars = res;
        int sample_size = 100;
        int iters = 100;
        for (int i = 0; i < iters; i++){
            float prop = float(i) / float(iters);
            int ind = prop * vars.size();
            float md = 0;
            for (int j = 0; j < sample_size; j++){
                vector<string> mid_vec;
                for (int k = 0; k < ind; k++){
                    mid_vec.push_back(res[k]);
                }
                md += soln.groupAnagrams(mid_vec);
            }
            times.push_back(md / sample_size);
        }
        for (int i = 0; i < times.size(); i++){
            cout << times[i] << ", ";
        }
	}
    return 0;
}