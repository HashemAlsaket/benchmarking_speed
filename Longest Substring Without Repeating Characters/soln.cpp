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
    int lengthOfLongestSubstring(string s) {
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
        std::cout << "Time taken: " << fp_ms.count() << " ms, ";
        return mx;
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

        string i1 = v[0];
        cout << i1.size() - 2;
        for (int i = 0; i < 10; i ++){
            cout << soln.lengthOfLongestSubstring(i1.substr(1, i1.size() - 1)) << "\n";
        }
	}
    return 0;
}