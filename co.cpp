#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Document{
    ll docID;
    string title;
    string content;
public:
    Document(ll id,const string& Title,const string& Content): docID(id),title(Title),content(Content) {}
    ll getID() const {
        return docID;
    }
    const string& getTitle() const {
        return title;
    }
    const string& getContent() const {
        return content;
    }
};

class Tokenizer {
public:
    vector<string>tokenize(const string& text) const {
        vector<string> tokens;
        stringstream ss(text);
        string word;
        while (ss >> word) {
            transform(word.begin(),word.end(),word.begin(),::tolower);
            word.erase(remove_if(word.begin(),word.end(),::ispunct),word.end());
            if (!word.empty()) {
                tokens.push_back(word);
            }
        }
        return tokens;
    }
};

class InvertedIndex {
    unordered_map<string,unordered_map<ll,int>> index;
public:
    void addDocument(ll docID,const vector<string>& tokens) {
        for (const string& token : tokens)
            index[token][docID]++;
    }
    unordered_map<ll,int>searchWord(const string& word) const {
        auto it = index.find(word);
        if (it == index.end()) {
            return {};
        }
        return it->second;
    }
    void deleteDocument(ll docID) {
        for (auto& wordEntry : index) {
            wordEntry.second.erase(docID);
        }
    }
};

class RankingEngine {
public:
    vector<pair<ll,int>>
    rankings(const unordered_map<ll,int>& docs) const {
        priority_queue<pair<int,ll>> pq;
        for (const auto& entry : docs) {
            ll docID = entry.first;
            int frequency = entry.second;
            pq.push({frequency, docID});
        }
        vector<pair<ll,int>> rankedResults;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            rankedResults.push_back({
                top.second,
                top.first
            });
        }
        return rankedResults;
    }
};