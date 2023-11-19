#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T value) : val(value), left(NULL), right(NULL) {}
};

template <class T>
TreeNode<T>* buildTree(vector<T>& postorder, vector<T>& inorder) {
    if (postorder.empty() || inorder.empty()) {
        return nullptr;
    }

    T rootVal = postorder.back();
    postorder.pop_back();
    TreeNode<T>* root = new TreeNode<T>(rootVal);

    int inorderIndex = -1;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == rootVal) {
            inorderIndex = i;
            break;
        }
    }
    vector<T> temp = vector<T>(inorder.begin() + inorderIndex + 1, inorder.end());
    root->right = buildTree(postorder, temp);
    temp = vector<T>(inorder.begin(), inorder.begin() + inorderIndex);
    root->left = buildTree(postorder, temp);

    return root;
}

template <class T>
void preorderRec(TreeNode<T>* root) {
    if (root) {
        cout << root->val << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }
}

vector<string> split(string str, char sign = ' '){
    vector<string> result;
    int temp = 0, index = 0;
    while (index <= str.size())
    {
        if (str[index] == sign || str[index] == '\0')
        {
            result.push_back(string(str.begin()+temp,str.begin()+index));
            temp = index+1;
        }
        index ++;
    }
    return result;
}


int main() {
    int numTrees;
    cout << "输入有多少棵二叉树要进行测试（以-1结束整个程序的运行）：";
    cin >> numTrees;
    cin.ignore();
    while (numTrees != -1 && numTrees) {
        vector<string> postorder, inorder;
        // 输入后序遍历序列
        cout << "输入二叉树的后序遍历序列：" << endl;
        string str;
        getline(std::cin,str);
        postorder = split(str);
        // 输入中序遍历序列
        cout<<"输入二叉树中序遍历序列" << endl;
        getline(std::cin,str);
        inorder = split(str);

        // 输出前序遍历序列
        TreeNode<string>* root = buildTree(postorder, inorder);
        cout << "二叉树的前序遍历序列" << endl;
        preorderRec(root);
        cout << endl;

        numTrees--;
    }

    return 0;
}

