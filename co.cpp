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
        string getTitle() const{return Title;}
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
                tokens.push_back(word);
            }
            return tokens;
        }

};
class Invertedindex{
    unordered_map<string,unordered_map<ll,int>> index;
    public:
        void addDoc(string token,){}
        int searchWord(){}
        void deletedDoc(){}
};



