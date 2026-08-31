# Search Engine Learning

A mini search engine project built in C++ to learn:

- Object-Oriented Programming (OOP)
- Inverted Indexing -> Positional Inverted Index
- Tokenization
- Ranking Systems
- Search Engine Architecture

---

## Features

- Parses simple HTML into a DOM tree
- Extracts visible text from parsed HTML
- Tokenizes and normalizes text
- Removes stop words from documents and queries
- Applies a simple stemmer
- Builds an inverted index from terms to document postings
- Ranks results with TF-IDF
- Includes crawler, storage, parser, indexing, query, and ranking modules

## Architecture

             Documents
                 │
                 ▼
             Tokenizer
                 │
                 ▼
       Inverted Index Builder
                 │
      ┌──────────┴──────────┐
      ▼                     ▼
      Normal Index      Positional Index
      │                     │
      └──────────┬──────────┘
                 ▼
          TF/IDF Ranking Engine
                 ▼
             Search Results

---

## Project Structure
```text
.
├── CMakeLists.txt
├── data/
│   ├── seeds.txt
│   └── stopWords.txt
├── include/
│   ├── core/
│   ├── crawler/
│   ├── indexing/
│   ├── parser/
│   ├── query/
│   ├── ranking/
│   └── storage/
├── src/
│   ├── core/
│   ├── crawler/
│   ├── indexing/
│   ├── parser/
│   ├── query/
│   ├── ranking/
│   ├── storage/
│   └── main.cpp
├── tests/
│   ├── crawler/
│   ├── indexing/
│   ├── parser/
│   ├── query/
│   ├── ranking/
│   └── storage/
└── MVP-model.cpp

## Important Classes

- `Document`: stores document ID, URL, raw HTML, and extracted text.
- `SearchEngine`: coordinates document preparation, indexing, query processing, and result lookup.
- `HTMLParser`: parses simple HTML into a `DOMTree`.
- `TextExtractor`: extracts searchable text from a `DOMTree`.
- `Tokenizer`: converts text into lowercase terms.
- `stopWordRemover`: removes common terms loaded from `data/stopWords.txt`.
- `Indexer`: tokenizes, filters, stems, and inserts terms into the inverted index.
- `QueryProcessor`: parses queries and gathers posting lists.
- `TFIDFRanker`: scores and sorts matching documents.

---

## Future Improvements
* Stop-word removal filtering & Porter Stemming integration.
* Advanced TF-IDF ranking transformations.
* Multi-term full phrase parsing algorithms and direct Boolean query integration.

---

## Requirements

- C++17-compatible compiler
- CMake 3.15 or newer
- - libcurl development package, because the crawler module uses curl

## Build

```bash
cmake -S . -B build
cmake --build build
```

Or configure, build, and start the program with one command:

```bash
./run.sh
```

## Test

```bash
cmake --build build --target search_engine_tests
ctest --test-dir build --output-on-failure
```

To configure, build, and run the test program with one command:

```bash
./run_tests.sh

## Run

Add one seed URL per line:

```text
https://example.com
https://example.org
```

Then run from the repository root so the app can find `data/seeds.txt` and `data/stopWords.txt`:

```bash
./build/search_engine
```

You can also pass a different seed file:

```bash
./build/search_engine /path/to/seeds.txt
# or
./run.sh /path/to/seeds.txt
```

Example:

```text
Crawled and indexed documents: 2
Enter query (type exit to quit): example domain
Doc ID: 1 Score: 1 URL: https://example.com
Enter query (type exit to quit): exit
```
---

## Limitations

- No phrase search
- No boolean query operators
- No persistent index save files
- Basic structural token validation
