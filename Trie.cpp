class Node {
public:
    vector<Node*> v;
    bool end;

    Node() {
        v.resize(26);
        for (auto &x : v) x = NULL;
        end = 0;
    }

};



class Trie {
public:

    Node *root;
    Trie() {
        root = new Node();
    }

    //insert function

    void insert(string word) {
        Node *node = root;
        for (auto x : word) {
            if (node->v[x - 'a'] == NULL) {
                Node *newNode = new Node();
                node->v[x - 'a'] = newNode;
                //dont forget this
                node = newNode;
            } else node = node->v[x - 'a'];
        }
        node->end = true;
    }

    //search and startsWith are almost same except the last return statement

    bool search(string word) {
        Node *node = root;
        for (auto x : word) {
            if (node->v[x - 'a'] == NULL) return false;
            node = node->v[x - 'a'];
        }
        return node->end;
    }

    bool startsWith(string prefix) {
        Node *node = root;
        for (auto x : prefix) {
            if (node->v[x - 'a'] == NULL) return false;
            node = node->v[x - 'a'];
        }
        return true;
    }
};