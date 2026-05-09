#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Document{
    ll docID;
    string Title;
    string Content;
    public:
        Document(int id,string title,string content):docID(id) ,Title(title),Content(content){}
        ll getID() const{return docID;}
        const string getTitle() const{return Title;}
        string getContent() const{return Content;}
};
class Tokenizer{
    public:
        vector<string> tokenize(const string& text) const {
            vector<string> tokens;
            stringstream ss(text);
            string word;
            while (ss >> word) {
                transform(word.begin(), word.end(),word.begin(),::tolower);
                word.erase(remove_if(word.begin(),word.end(),::ispunct),word.end());
                if(!word.empty()) tokens.push_back(word);
            }
            return tokens;
        }

};

class InvertedIndex {
    unordered_map<string,unordered_map<ll,int>> index;
    public:
        void addDocument(ll docID,const vector<string>& tokens) {
            for(const string& token : tokens)    index[token][docID]++;
            
        }
        vector<ll> searchWord(const string& word) {
            vector<ll> result;
            if(index.find(word) == index.end()) return result;
            for(auto& entry : index[word]) {
                result.push_back(entry.first);
            }
            return result;
        }
        void deleteDocument(ll docID) {
            for(auto& wordEntry : index) {
                wordEntry.second.erase(docID);
            }
        }
};



