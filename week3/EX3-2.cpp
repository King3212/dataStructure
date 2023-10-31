#include<iostream>
#include <stack>
using namespace std;
struct linkNode
{
    int data;
    linkNode *next;
};

void print(linkNode* head){
    while (head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

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
    linkNode *getLeavesLink();
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

linkNode *Tree::getLeavesLink()
{

    linkNode *head = new linkNode(), *Lcurrent = head, *tail;
    treeNode *Tcurrent = root;
    stack<treeNode*> roots;
    if(!root) return nullptr;
    roots.push(this->root);
    while(roots.size()){
        Tcurrent =roots.top();
        roots.pop();
        if (!Tcurrent->left && !Tcurrent->right)
        {
            Lcurrent->data = Tcurrent->data;
            Lcurrent->next = new linkNode();
            tail = Lcurrent;
            Lcurrent = Lcurrent->next;
            continue;
        }
        if (Tcurrent->right)
        {
            roots.push(Tcurrent->right);
        }
        if (Tcurrent->left)
        {
            roots.push(Tcurrent->left);
            
        }
        
    }
    tail->next = nullptr;
    delete Lcurrent;
    
    return head;
}


int main(){
    cout << "输入有多少棵二叉树要进行测试（以-1结束整个程序的运行）" << endl;
    int times;
    Tree one;
    cin >> times;
    while (times != -1 && times)
    {
        cout << "输入扩充的二叉树前序遍历序列（整数值序列），0表示空子树" << endl;
        one.exBuildTree();
        linkNode *oneLink = one.getLeavesLink();
        cout << "建树完成，输出叶子节点：" << endl;
        print(oneLink);
        times--;
    }
    
}
