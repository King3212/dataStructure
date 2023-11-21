#include"BST.h"
#include<iostream>
using namespace std;


int main(){
    BST<int> tree;
    int num;
    int data;
    while(true){
        cout << "输入要建立的二叉查找树的结点个数（以-1结束整个程序的运行）：\n";
        cin >> num;
        if (num == -1)
        {
            break;
        }
        cout << "输入建立二叉查找树的数据（整数值序列）\n";
        for (int i = 0; i < num; i++)
        {
            
            cin >> data;
            tree.insert(data);
        }
        cout << "建树完成！\n输入一个待插入的元素:\n";
        cin >> data;
        tree.insert(data);
        cout << "插入完成！\n查询结果：";
        if(tree.Search(data)){
            cout << "查找成功\n";
        }else cout << "查找失败\n";
        tree.deleteData(data);
        cout << "删除完成！\n查询结果：";
        if(tree.Search(data)){
            cout << "查找成功\n";
        }else cout << "查找失败\n";
    }
    return 0;
}
