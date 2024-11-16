#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie();

    void insert(const string& word);

    void getSuggestions(const string& prefix, vector<string>& suggestions) const;

    bool search(const string& word) const;

    ~Trie();

private:
    TrieNode* root;

    void collectAllWords(TrieNode* node, const string& currentWord, vector<string>& suggestions) const;


    void deleteTrie(TrieNode* node);
};

#endif // TRIE_H
