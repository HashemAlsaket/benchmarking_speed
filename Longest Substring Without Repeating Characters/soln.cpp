#include<algorithm>
#include<chrono>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stack>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    float lengthOfLongestSubstring(string s) {
        #include <chrono>
        auto t1 = std::chrono::high_resolution_clock::now();
        
        int n = s.size(), i = 0, j = 0, mx = 0;
        
        unordered_map<char, int> m;
        
        while (j < n){
            mx = max(mx, j - i);
            
            if (m.find(s[j]) != m.end()){
                if (m[s[j]] > 0){
                    while (m[s[j]] > 0){
                        m[s[i]] = m[s[i]] - 1;
                        i ++;
                    }
                }
            }
            if (m.find(s[j]) == m.end()){
                m[s[j]] = 1;
            } else{
                m[s[j]] = m[s[j]] + 1;
            }
            j ++;
        }
        mx = max(mx, j - i);
        
        std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        // std::cout << "Time taken: " << fp_ms.count() << " ms, ";
        // return mx;
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

			while (getline(ss, line, ',')){
				v.push_back(line);
			}
		}

        vector<float> times;
        string vars = v[0];
        int sample_size = 100;
        int iters = 100;
        for (int i = 0; i < iters; i++){
            float prop = float(i) / float(iters);
            int ind = prop * vars.size();
            float md = 0;
            for (int j = 0; j < sample_size; j++){
                md += soln.lengthOfLongestSubstring(vars.substr(1, ind));
            }
            times.push_back(md / sample_size);
        }
        for (int i = 0; i < times.size(); i++){
            cout << times[i] << ", ";
        }
	}
    return 0;
}