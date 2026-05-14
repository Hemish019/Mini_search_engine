# Search Engine Learning

A mini search engine project built in C++ to learn:

- Object-Oriented Programming (OOP)
- Inverted Indexing
- Tokenization
- Ranking Systems
- Search Engine Architecture

---

## Features

- Document storage
- Tokenization using stringstream
- Lowercase normalization
- Inverted indexing
- Word frequency tracking
- Basic document ranking

---

## Project Structure

text Document Tokenizer InvertedIndex RankingEngine 

### Document
Stores:
- document ID
- title
- content

### Tokenizer
Responsible for:
- splitting text into words
- lowercase conversion

### InvertedIndex
Stores:

text word -> { documentID -> frequency } 

Used for fast word search.

### RankingEngine
Ranks documents based on word frequency.

---


## Technologies Used
- C++
- STL
- unordered_map
- vector
- priority_queue
- stringstream

---

## Future Improvements
- Stop-word removal
- Stemming
- TF-IDF ranking
- Phrase search
- Boolean queries
- File-based document loading

---

## How to Run

Compile:

bash g++ main.cpp -o main 

Run:

bash ./main 

---

## Learning Goals

This project is built for understanding:
- search engine internals
- indexing systems
- data structures
- clean OOP design in C++
