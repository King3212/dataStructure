#include"BST.h"
#include<iostream>
using namespace std;


int main(){
    BST<int> tree;
    int num;
    int data;
    while(true){
        cout << "����Ҫ�����Ķ���������Ľ���������-1����������������У���\n";
        cin >> num;
        if (num == -1)
        {
            break;
        }
        cout << "���뽨����������������ݣ�����ֵ���У�\n";
        for (int i = 0; i < num; i++)
        {
            
            cin >> data;
            tree.insert(data);
        }
        cout << "������ɣ�\n����һ���������Ԫ��:\n";
        cin >> data;
        tree.insert(data);
        cout << "������ɣ�\n��ѯ�����";
        if(tree.Search(data)){
            cout << "���ҳɹ�\n";
        }else cout << "����ʧ��\n";
        tree.deleteData(data);
        cout << "ɾ����ɣ�\n��ѯ�����";
        if(tree.Search(data)){
            cout << "���ҳɹ�\n";
        }else cout << "����ʧ��\n";
    }
    return 0;
}
