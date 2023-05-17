#include <iostream>
#include <string>
#include <string>
#include <array>
#include <iterator>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

// Representation of Trie Node
int LENGTHOFALPHABET = 26;
struct TrieNode
{
    TrieNode *childNode[26];
    int wordCount;
    TrieNode()
    {
        wordCount = 0;
        for (int i = 0; i < 26; i++)
            childNode[i] = nullptr;
    }
};

// 1. Insertion in Trie Data Structure
void inset_key(TrieNode *root, string &key)
{
    TrieNode *currentnode = root;
    for (auto ch : key)
    {
        if (currentnode->childNode[ch - 'a'] == nullptr)
        {
            TrieNode *newNode = new TrieNode();
            currentnode->childNode[ch - 'a'] = newNode;
        }
        currentnode = currentnode->childNode[ch - 'a'];
    }
    currentnode->wordCount++;
}

// 2.Searching Complete word in Trie Data Structure:
bool search_key(TrieNode *root, string &key)
{
    TrieNode *currentNode = root;
    for (auto ch : key)
    {
        if (currentNode->childNode[ch - 'a'] == nullptr)
        {
            return false;
        }
        currentNode = currentNode->childNode[ch - 'a'];
    }
    return (currentNode->wordCount > 0);
}

// 3. Deletion in Trie Data Structure
bool delete_Key(TrieNode *root, string &word)
{
    TrieNode *currentNode = root;
    TrieNode *lastBranchNode = nullptr;
    char lastBranchChar = 'a';
    for (auto ch : word)
    {
        if (currentNode->childNode[ch - 'a'] == nullptr)
        {
            return false;
        }
        else
        {
            int count = 0;
            for (int moveInRow = 0; moveInRow < 26; moveInRow++)
            {
                if (currentNode->childNode[moveInRow] != nullptr)
                    count++;
            }
            if (count > 0)
            {
                lastBranchNode = currentNode;
                lastBranchChar = ch;
            }
            currentNode = currentNode->childNode[ch - 'a'];
        }
    }
    int count = 0;
    for (int moveInRow = 0; moveInRow < 26; moveInRow++)
    {
        if (currentNode->childNode[moveInRow] != nullptr)
            count++;
    }
    if (count > 0)
    {
        currentNode->wordCount--;
        return true;
    }
    if (lastBranchNode != nullptr)
    {
        lastBranchNode->childNode[lastBranchChar] = nullptr;
        return true;
    }
    else
    {
        root->childNode[word[0]] = nullptr;
        return true;
    }
}

int main()
{
    TrieNode *root = new TrieNode();
    // input string
    vector<string> inpustString = {"and", "ant", "do", "geek", "dad", "ball"};
    int n = inpustString.size();
    for (int i = 0; i < n; i++)
    {
        inset_key(root, inpustString[i]);
    }

    // SEARCH STRING
    vector<string> searchStrings = {"do", "geek", "bat"};
    n = searchStrings.size();
    for (int i = 0; i < n; i++)
    {
        cout << "SEARCH String: " << searchStrings[i] << endl;
        if (search_key(root, searchStrings[i]))
            cout << "The string is present in the Trie" << endl;
        else
            cout << "The string is not present in the Trie" << endl;
    }

    // DELETING
    vector<string> deleteStrings = {"geek", "tea"};
    n = deleteStrings.size();
    for (int i = 0; i < n; i++)
    {
        cout << "DELETING String: " << deleteStrings[i] << endl;
        if (delete_Key(root, deleteStrings[i]))
            cout << "The string is successfully deleted" << endl;
        else
            cout << "The string is not present in the Trie" << endl;
    }
    return 0;
}
// COMMAND LINE TO RUN THE FILE IN POWERSHELL
// g++ ./11.Trie.cpp
// .\a.exe

// 1. Problem - Search Suggestions System

class Solution
{
public:
    struct TrieNode
    {
        TrieNode *childNode[26];
        int wordCount;
        TrieNode()
        {
            wordCount = 0;
            for (int i = 0; i < 26; i++)
                childNode[i] = nullptr;
        }
    };
    void inset_key(TrieNode *root, string &key)
    {
        TrieNode *currentnode = root;
        for (auto ch : key)
        {
            if (currentnode->childNode[ch - 'a'] == nullptr)
            {
                TrieNode *newNode = new TrieNode();
                currentnode->childNode[ch - 'a'] = newNode;
            }
            currentnode = currentnode->childNode[ch - 'a'];
        }
        currentnode->wordCount++;
    }
    void finder(TrieNode *root, vector<string> &temp, string str)
    {
        if (temp.size() >= 3)
            return;
        if (root->wordCount > 0)
        {
            for (int i = 0; i < root->wordCount && temp.size() < 3; i++)
                temp.push_back(str);
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->childNode[i] != nullptr)
            {
                str += ((char)(i + 97));
                finder(root->childNode[i], temp, str);
                str.pop_back();
            }
        }
        return;
    }
    vector<string> search_key(TrieNode *root, string key)
    {
        TrieNode *currentNode = root;
        vector<string> temp;
        string str = key;
        for (auto ch : key)
        {
            if (currentNode->childNode[ch - 'a'] == nullptr)
            {
                return temp;
            }
            currentNode = currentNode->childNode[ch - 'a'];
        }
        finder(currentNode, temp, str);
        return temp;
    }
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        TrieNode *root = new TrieNode();
        int n = products.size();
        for (int i = 0; i < n; i++)
        {
            inset_key(root, products[i]);
        }
        vector<vector<string>> answer;
        for (int i = 1; i <= searchWord.length(); i++)
            answer.push_back(search_key(root, searchWord.substr(0, i)));
        return answer;
    }
};
