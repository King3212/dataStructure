#include<iostream>
#include <stack>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

class Tree{
private:
    treeNode* root;
    int size;
    treeNode* exBuild();
public:
    void exBuildTree();
    friend bool checkBST(Tree tree);
};


treeNode* Tree::exBuild()
{
    int temp;
    cin >> temp;
    if (temp)
    {
        treeNode* tempNode = new treeNode();
        tempNode->data = temp;
        tempNode->left = exBuild();
        tempNode->right = exBuild();
        return tempNode;
    }
    return nullptr;
    
}

void Tree::exBuildTree()
{
    root = exBuild();
}



int main(){
    Tree one;
    int times = -1;
    while (true)
    {
        cout << "输入有多少棵二叉树要进行测试（以-1结束整个程序的运行）" << endl;
        cin >> times;
        if (times == -1)
        {
            break;
        }
        
        while (times != -1 && times)
        {
            cout << "输入扩充的二叉树前序遍历序列（整数值序列），0表示空子树" << endl;
            one.exBuildTree();
            cout << "建树完成，判断是否为二叉搜索树：" << endl;
            if (checkBST(one))
            {
                cout << "是二叉搜索树\n";
            }else cout << "不是二叉搜索树\n";
            cout << endl;
            times--;
        }
    }
    
    
    
}

bool checkBST(Tree tree)
{
    stack<treeNode*> nodes;
    treeNode *curr = tree.root;
    int lastData;

    while (curr)
    {
        lastData = curr->data;
        curr = curr->left;
    }
    curr = tree.root;
    while (curr || !nodes.empty())
    {
        if(curr){
            nodes.push(curr);
            curr = curr->left;
        }else{
            curr = nodes.top();
            nodes.pop();
            if (curr){
                if(curr->data < lastData) return false;
                else lastData = curr->data;
                curr = curr->right;
            }
        }
    }
    
    
    return true;

}
