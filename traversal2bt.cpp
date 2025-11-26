#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int val;
    Node* left;
    Node* right;

    Node(int key)
    {
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

int findIndex(vector<int> &inorder, int value)
{
    for(int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(vector<int> &inorder, vector<int> &preorder, int &preIndex, int l, int r)
{
    if (l > r) 
        return nullptr;  // important base case

    int rootVal = preorder[preIndex];
    preIndex++;

    Node* root = new Node(rootVal);

    if (l == r) 
        return root; 

    int index = findIndex(inorder, rootVal);

    root->left = buildTree(inorder, preorder, preIndex, l, index - 1);
    root->right = buildTree(inorder, preorder, preIndex, index + 1, r);

    return root;
}

void printLevelOrder(Node* root) 
{
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        int size = q.size();

        while (size--) {
            Node* node = q.front(); 
            q.pop();
            
            cout << node->val << " ";

            if (node->left) 
                q.push(node->left);
            if (node->right) 
                q.push(node->right);
        }
        cout << endl; // new line after each level
    }
}

int main() {
    vector<int> inorder{3, 1, 4, 0, 5, 2};
    vector<int> preorder{0, 1, 3, 4, 2, 5};

    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, preIndex, 0, inorder.size() - 1);

    cout << "Level Order Traversal of constructed tree:" << endl;
    printLevelOrder(root);

    return 0;
}