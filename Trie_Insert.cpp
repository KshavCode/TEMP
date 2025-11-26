#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &key) {
        TrieNode* node = root;
        for (char ch : key) {
            if (ch < 'a' || ch > 'z') continue;
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    
    bool search(const string &key) {
        TrieNode* node = root;
        for (char ch : key) {
            if (ch < 'a' || ch > 'z') return false;
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return node != nullptr && node->isEndOfWord;
    }

private:
    TrieNode* root;
};

int main() {
    Trie trie;

    cout << "Inserting words: apple, app, bat, ball\n";
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");

    vector<string> queries = {"app", "apple", "bat", "ball", "cat"};
    for (const string &word : queries) {
        cout << "Search \"" << word << "\": "
             << (trie.search(word) ? "Found" : "Not Found") << "\n";
    }

    return 0;
}
