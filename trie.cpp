#include "trie.h"

Trie::Trie() {
        root = new TrieNode();
}


void Trie::insert(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            int index = ch - 'a';
            if (index < 0 || index >= 26) continue;
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
    }
    node->isEndOfWord = true;
}

bool Trie::search(const string& word) const {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (index < 0 || index >= 26 || !node->children[index]) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWord;
}

void Trie::getSuggestions(const string& prefix, vector<string>& suggestions) const {
    TrieNode* node = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (index < 0 || index >= 26 || !node->children[index]) {
            return;
        }
        node = node->children[index];
    }
    collectAllWords(node, prefix, suggestions);
}


void Trie::collectAllWords(TrieNode* node, const string& currentWord, vector<string>& suggestions) const {
    if (node->isEndOfWord) {
        suggestions.push_back(currentWord);
    }
    for (int i = 0; i < 26; ++i) {
        if (node->children[i]) {
            collectAllWords(node->children[i], currentWord + char('a' + i), suggestions);
        }
    }
}


void Trie::deleteTrie(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; ++i) {
        deleteTrie(node->children[i]);
    }
    delete node;
}

Trie::~Trie() {
    deleteTrie(root);
}
