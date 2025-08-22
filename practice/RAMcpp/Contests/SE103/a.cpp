// Rbrgs.cpp
#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> childrens;
    bool isEndOfWord;
    int sizeOfChilds;
    TrieNode()
    {
        childrens = vector<TrieNode *>(26, nullptr);
        isEndOfWord = false;
        sizeOfChilds = 0;
    }
    void insertWord(string s, int i = 0)
    {
        if (s.size() == i)
        {
            isEndOfWord = true;
            return;
        }
        if (childrens[s[i] - 'a'] == nullptr)
        {
            childrens[s[i] - 'a'] = new TrieNode();
            sizeOfChilds++;
        }
        childrens[s[i] - 'a']->insertWord(s, i + 1);
    }
};

void traverseTrie(TrieNode *node, string prefix, bool &oneMatch, string &original)
{
    if (node == nullptr)
        return;
    if (node->isEndOfWord && prefix != original)
    {
        cout << prefix << endl;
        oneMatch = true;
    }

    for (int i = 0; i < 26; i++)
    {
        if (node->childrens[i] != nullptr)
        {
            char nc = 'a' + i;
            traverseTrie(node->childrens[i], prefix + nc, oneMatch, original);
        }
    }
}

TrieNode *gethead(string s, TrieNode *root)
{
    int index = 0;
    while (root != nullptr && index < s.size())
    {
        root = root->childrens[s[index++] - 'a'];
    }
    return root;
}

int main()
{
    int n;
    cin >> n;

    TrieNode *root = new TrieNode();

    for (int i = 0; i < n; i++)
    {
        string next;
        cin >> next;
        root->insertWord(next);
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cout << "Case #" << i + 1 << ":\n";
        string q;
        cin >> q;
        TrieNode *head = gethead(q, root);
        bool oneMatch = false;
        traverseTrie(head, q, oneMatch, q);
        if (!oneMatch){
            cout << "No match.\n";
        }
    }

    return 0;
}