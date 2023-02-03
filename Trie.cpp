#include <bits/stdc++.h>

class Node {

public:
    vector<pair<Node*, int>> v;
    bool endOf;

    Node() {
        v.resize(26);
        for (auto &x : v) {
            x.first = NULL;
            x.second = 0;
        } endOf = false;
    }
};



class Trie {

public:
    Node *root;
    Trie() {

        root = new Node();
    }

    void insert(string &word) {
        Node *node = root;
        // Node node=*nodePtr;
        for (auto x : word) {
            if (node->v[x - 'a'].first == NULL) {
                Node *newNode = new Node();
                node->v[x - 'a'].first = newNode;
                node->v[x - 'a'].second++;
                node = newNode;
            } else {
                node->v[x - 'a'].second++;
                node = node->v[x - 'a'].first;
            }
        } node->endOf = true;
    }

    int countWordsEqualTo(string &word) {
        int count = 0;
        Node *node = root;
        for (auto x : word) {
            if (node->v[x - 'a'].first == NULL) return 0;
            count = node->v[x - 'a'].second;
            node = node->v[x - 'a'].first;
        }
        return ((node->endOf == true) * count);
    }

    int countWordsStartingWith(string &word) {
        int count = 0;
        Node *node = root;
        for (auto x : word) {
            if (node->v[x - 'a'].first == NULL) return 0;
            count = node->v[x - 'a'].second;
            node = node->v[x - 'a'].first;
        }
        return (count);
    }

    void erase(string &word) {
        Node *node = root;
        for (auto x : word) {
            node->v[x - 'a'].second--;
            node = node->v[x - 'a'].first;
        }
    }
};
