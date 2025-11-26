#include <bits/stdc++.h>
using namespace std;

const int T = 3; // Minimum degree

class BTreeNode 
{
    public:
        int keys[2 * T - 1];   // Array of keys
        BTreeNode* children[2 * T]; // Array of child pointers
        int n;   // Current number of keys
        bool leaf; // Is true when node is leaf

        BTreeNode(bool leaf1) 
        {
            leaf = leaf1;
            n = 0;
            for (int i = 0; i < 2 * T; i++)
                children[i] = nullptr;
        }

        void traverse() 
        {
            int i;
            for (i = 0; i < n; i++) 
            {
                if (!leaf)
                    children[i]->traverse();
                cout << " " << keys[i];
            }
            if (!leaf)
                children[i]->traverse();
        }

        void insertNonFull(int k);
        void splitChild(int i, BTreeNode* y);
};

class BTree 
{
    public:
        BTreeNode* root;

        BTree() 
        {
            root = nullptr;
        }

        void traverse() 
        {
            if (root != nullptr)
                root->traverse();
        }

        void insert(int k);
};

void BTreeNode::insertNonFull(int k) 
{
    int i = n - 1;

    if (leaf) 
    {
        while (i >= 0 && keys[i] > k) 
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    }
    else 
    {
        while (i >= 0 && keys[i] > k)
            i--;

        if (children[i + 1]->n == 2 * T - 1) 
        {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) 
{
    BTreeNode* z = new BTreeNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];

    if (!y->leaf) 
    {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];
    }

    y->n = T - 1;

    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[T - 1];
    n++;
}

void BTree::insert(int k) 
{
    if (root == nullptr) 
    {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->n = 1;
    }
    else 
    {
        if (root->n == 2 * T - 1) 
        {
            BTreeNode* s = new BTreeNode(false);
            s->children[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->children[i]->insertNonFull(k);

            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

int main() {
    BTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of B-Tree: ";
    t.traverse();

    return 0;
}
