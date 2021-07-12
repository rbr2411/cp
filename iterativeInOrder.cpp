#include<iostream>
using namespace std;
#include <stack>
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};


// Preorder: D L R
// Inorder : L D R
// Postorder: L R D
// void iterativeInorder(TreeNode *root){
//     stack<TreeNode*> st;
//     while(!st.empty() || root){
//         while(root != NULL){
//             st.push(root);
//             root = root->left;
//         }

//         while(!st.empty() && root == NULL){
//             TreeNode *temp = st.top();
//             st.pop();
//             cout << temp->data << " ";
//             root = temp->right;
//         }
//     }
//     return;
// }

void iterativeInorder(TreeNode *root){
    if(root == NULL)
        return;
    stack<TreeNode*> st;

    while(true){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty())
                break;
            TreeNode *temp = st.top();
            st.pop();
            cout << temp->data << " ";
            root = temp->right;
        }
        return;
    }
}

// PreOrder: D L R
void iterativePreOrder(TreeNode *root){
    if(root == NULL)
        return;
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
        TreeNode *temp = st.top();
        st.pop();
        cout << temp->data << " ";
        // The element that would be pushed first would be removed at last.
        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
    return;
}

// L R D
void iterativePostOrder(TreeNode *root){
    if(root == NULL)
        return;
    stack<TreeNode*> st;
    while(!st.empty() || root){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            TreeNode *temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else{
                root = temp;
            }
        }
    }
    return;
}