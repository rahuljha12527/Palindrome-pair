#include <iostream>
#include <string>
using namespace std;
#include "Trie.h"
#include <vector>


int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}