//trie的实现有两种，1是一个连一个字符，最后连接一个terminator表示是字；【crack code interview】
//第2则是使用next【26】来链接，每个节点都包含一个isWord【cpe593】
//别人算法第一名就是用的第二种

class TrieNode {
public:
        bool isWord;
        TrieNode * children[26];
    // Initialize your data structure here.
    TrieNode() {
    isWord = false;
    for(int i=0;i<26;i++)
    children[i] = nullptr;
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * p = root;
        for(int i=0; i<word.length(); i++) {
            int id = word[i] - 'a';
            if(p->children[id]==nullptr)
            p->children[id] = new TrieNode();
            p=p->children[id];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(word=="")
        return true;
        
        TrieNode * p = root;
        for(int i = 0; i<word.length(); i++) {
            int id = word[i] - 'a';
            if(p->children[id]==nullptr)
            return false;
            p= p->children[id];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
               if(prefix=="")
        return true;
        
        TrieNode * p = root;
        for(int i = 0; i<prefix.length(); i++) {
            int id = prefix[i] - 'a';
            if(p->children[id]==nullptr)
            return false;
            p= p->children[id];
        }
    return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
