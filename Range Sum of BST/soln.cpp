#include<chrono>
#include<iostream>
#include<fstream>
#include<map>
#include<sstream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rec(TreeNode* node, int low, int high, int v){
        if (low <= node->val && node->val <= high){
            v += node->val;
        }
        if (node->left != NULL){
            v = rec(node->left, low, high, v);
        }
        if (node->right != NULL){
            v = rec(node->right, low, high, v);
        }
        return v;
    };

public:
    float rangeSumBST(TreeNode* root, int low, int high) {
        #include <chrono>
        auto t1 = std::chrono::high_resolution_clock::now();
        int v = 0;
        
        v = rec(root, low, high, v);
        
        chrono::duration<double, std::milli> fp_ms = std::chrono::high_resolution_clock::now() - t1;
        // cout << "Time taken: " << fp_ms.count() << " ms, ";
        // return v;
        return fp_ms.count();
    }
};
 
TreeNode *Node(int key){
  TreeNode *n = new TreeNode();
  n->val = key;
  n->left = n->right = NULL;
  return n;
}

TreeNode *BST(vector<int> &nums, int l, int r){
  if (l <= r){
    int mid = ((l + r) / 2);
    TreeNode *newnode = Node(nums[mid]);
    newnode->left = BST(nums, l, mid - 1);
    newnode->right = BST(nums, mid + 1, r);
    return newnode;
  }
  return NULL;
}

TreeNode *toBST(vector<int> &nums)
{
  size_t size = nums.size();

  if (size == 1){
      return Node(nums[0]);
  }
  return BST(nums, 0, size - 1);
}

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
    int low = stoi(v[1]);
    int high = stoi(v[2]);
    
    vector<int> v_split;
    stringstream s_stream(vsubstr); 
    while(s_stream.good()) {
        string subs;
        getline(s_stream, subs, ','); //get first string delimited by comma
        if (subs == "null"){
            v_split.push_back(0);
        } else{
            v_split.push_back(stoi(subs));
        }
        
        }
    vector<float> times;
    int sample_size = 100;
    int iters = 101;
    for (int i = 1; i < iters; i++){
        float prop = float(i) / float(iters);
        int ind = prop * v_split.size();
        float md = 0;
        for (int j = 0; j < sample_size; j++){
            vector<int> mid_vec;
            for (int k = 0; k < ind; k++){
                mid_vec.push_back(v_split[k]);
            }
            TreeNode *tree = toBST(mid_vec);
            md += soln.rangeSumBST(tree, low, high);
        }
        times.push_back(md / sample_size);
    }
    for (int i = 0; i < times.size(); i++){
        cout << times[i] << ", ";
    }
	}
    return 0;
}