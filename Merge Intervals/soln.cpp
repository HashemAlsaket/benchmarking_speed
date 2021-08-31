#include<algorithm>
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto t1 = std::chrono::high_resolution_clock::now();
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        vector<int> arr;
        arr = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++){
            if (arr[1] >= intervals[i][0]){
                arr = {min(arr[0], intervals[i][0]), max(arr[1], intervals[i][1])};
            } else{
                res.push_back(arr);
                arr = intervals[i];
            }
        }
        res.push_back(arr);
        
        std::chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        std::cout << "Time taken: " << fp_ms.count() << " ms, ";
        for (int i = 0; i < res.size(); i++){
            cout << '[' << res[i][0] << ',' << res[i][1] << ']' << ',';
        }
        return res;
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

        string margins = v[0];
        string m2 = margins.substr(2, margins.size() - 4);
        stringstream ss(m2);
        vector<int> res;

        int j = 0;
        while (ss.good()){
            string a;
            getline(ss, a, ',');
            if (a[0] == '['){
                res.push_back(stoi(a.substr(1, a.size())));
                i++;
                continue;
            }
            if (a[a.size() - 1] == ']'){
                res.push_back(stoi(a.substr(0, a.size() - 1)));
                i++;
                continue;
            }
            res.push_back(stoi(a));
            i ++;

        }
        
        vector<vector<int>> res2;
        
        for (int i = 0; i < res.size(); i += 2){
            res2.push_back({res[i], res[i + 1]});
        }

        for (int i = 0; i < 10; i ++){
            soln.merge(res2);
            cout << "\n";
        }
	}
    return 0;
}