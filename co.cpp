#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Document{
    ll docID;
    string title;
    string content;
public:
    Document() {}
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

class SearchEngine{
    unordered_map<ll, Document> documents;
    Tokenizer tokenizer;
    RankingEngine rankingengine;
    InvertedIndex invertedindex;

    public:
        void addDocument(const Document& doc) {
            documents.insert({doc.getID(),doc});
            vector<string> tokens =tokenizer.tokenize(doc.getContent());
            invertedindex.addDocument(doc.getID(),tokens);
        }

        void search(const string& word) {
            string normalizedWord = word;
            transform(normalizedWord.begin(),normalizedWord.end(),normalizedWord.begin(),::tolower);

            auto matchedDocs = invertedindex.searchWord( normalizedWord);
            auto rankedResults = rankingengine.rankings(matchedDocs);

            if (rankedResults.empty()) {
                cout << "No documents found.\n";
                return;
            }
            cout << "\nSearch Results:\n";

            for (const auto& result : rankedResults) {
                ll docID = result.first;
                int frequency = result.second;
                const Document& doc = documents.at(docID);
                cout << "DocID: " << docID << "\n";
                cout << "Title: " << doc.getTitle()<< "\n";
                cout << "Frequency: "<< frequency<< "\n\n";
            }
        }

        void deleteDocument(ll docID) {
            documents.erase(docID);
            invertedindex.deleteDocument(docID);
        }
};

int main(){
    SearchEngine engine;

    Document d1(
        1,
        "C++ Basics",
        "C++ is a powerful programming language"
    );

    Document d2(
        2,
        "Search Engines",
        "Search engines use inverted index for search"
    );

    Document d3(
        3,
        "Advanced C++",
        "C++ supports object oriented programming"
    );

    engine.addDocument(d1);
    engine.addDocument(d2);
    engine.addDocument(d3);

    engine.search("c++");

    return 0;
}