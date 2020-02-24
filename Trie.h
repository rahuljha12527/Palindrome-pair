#include <string>
#include <vector> 
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
			root->childCount++;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    
  string reverse(string in){
        string out="";
        for(int i=in.size()-1;i>=0;i--)
            out+=in[i];
        return out;
    }
    
	
   bool search(TrieNode* root,string word){
        
        if(word.size()==0 ){
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        
        bool ans;
        if(root->children[index]!=NULL)
            ans=search(root->children[index],word.substr(1));
        else
            ans=false;
        return ans;
    }
	

	bool findIfPalindromePair(vector<string> arr) {
		for(int i=0;i<arr.size();i++){
            this->insertWord(arr[i]);
        }
        bool ans;
        for(int i=0;i<arr.size();i++){
            string out=reverse(arr[i]);
        
        
        ans=search(root,out)  || search(root,out.substr(1));
        
        if(ans){
            break;
        }
        }
        return ans;
	}
};
