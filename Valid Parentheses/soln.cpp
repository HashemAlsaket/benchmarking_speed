#include<chrono>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    float isValid(string s) {
        auto t1 = std::chrono::high_resolution_clock::now();
        stack<char> Stack;
        
        for (int i = 0; i < s.size(); i++){
            string l;
            l = s[i];
            if (l == "(" || l == "{" || l == "["){
                Stack.push(s[i]);
                continue;
            }
            if (Stack.size() == 0){
                return false;
            }
            string p;
            p = Stack.top();
            Stack.pop();

            if (l == ")" && p != "("){
                return false;
            }
            if (l == "]" && p != "["){
                return false;
            }
            if (l == "}" && p != "{"){
                return false;
            }
        }
        std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        return fp_ms.count();
        // std::cout << "Time taken: " << fp_ms.count() << " ms, ";
        // return Stack.size() == 0;
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
        int sample_size = 1000;
        int iters = 100;
        for (int i = 0; i < iters; i++){
            float prop = float(i) / float(iters);
            int ind = prop * vars.size();
            float md = 0;
            for (int j = 0; j < sample_size; j++){
                md += soln.isValid(vars.substr(0, ind));
            }
            times.push_back(md / sample_size);
        }
        for (int i = 0; i < times.size(); i++){
            cout << times[i] << ", ";
        }
	}
    return 0;
}