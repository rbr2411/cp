#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(Node *root, int key, vector<int> &path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }

    path.pop_back();
    return false;
}

int lca(Node *root, int n1, int n2){
    vector<int> path1, path2;
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int m = path1.size();
    int n = path2.size();
    int pc = 0;
    //1 2 4 6
    //1 2 4 7 8
    for(pc = 0; pc < min(m, n); pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc-1];
}

Node* lca2(Node *root, int n1, int n2){
    if(root == NULL){
        return root;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node *left = lca2(root->left, n1, n2);
    Node *right = lca2(root->right, n1, n2);
    
    if(left && right){
        return root;
    }

    if(left){
        return left;
    }
    if(right){
        return right;
    }
    return NULL;
}

int main()
{

    return 0;
}
