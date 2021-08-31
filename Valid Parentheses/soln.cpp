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
    bool isValid(string s) {
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
        std::cout << "Time taken: " << fp_ms.count() << " ms, ";
        return Stack.size() == 0;
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
        for (int i = 0; i < 10; i ++){
            cout << soln.isValid(i1) << "\n";
        }
	}
    return 0;
}