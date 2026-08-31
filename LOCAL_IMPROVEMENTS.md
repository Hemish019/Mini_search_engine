# Future Improvements

This file is local-only and is excluded from Git.

## Search Quality

- Add BM25 ranking as an alternative to TF-IDF.
- Add phrase search for quoted queries like `"machine learning"`.
- Add boolean query operators such as `AND`, `OR`, and `NOT`.
- Add field-aware ranking so title, headings, and body text can have different weights.
- Add result snippets showing the matched query terms in context.

## Indexing

- Persist the inverted index to disk instead of rebuilding it on every run.
- Store document metadata separately from raw HTML and extracted text.
- Add duplicate document detection using content hashes.
- Track term positions inside documents to support phrase search.
- Add incremental re-indexing for updated pages.

## Crawler

- Implement real crawl depth tracking.
- Add crawl delay / politeness rules per domain.
- Limit crawling to allowed domains or same-domain links.
- Handle relative URLs correctly using the current page URL as the base.
- Add retry logic for temporary network failures.
- Record crawl errors and skipped URLs.
- Avoid re-crawling already seen normalized URLs.

## HTML Parsing

- Replace the basic custom parser with a proper HTML parser library later.
- Ignore hidden content, comments, scripts, styles, nav bars, and boilerplate text.
- Extract title, meta description, headings, and links more accurately.
- Handle malformed HTML more safely.

## Storage

- Use SQLite for documents, metadata, and crawl state.
- Store crawl timestamp, HTTP status code, content type, and final redirected URL.
- Add a storage interface for the inverted index.

## Tests

- Add tests for malformed HTML.
- Add tests for relative URL normalization.
- Add tests for repeated document IDs.
- Add tests for empty queries and stop-word-only queries.
- Add integration tests using a local HTTP server.

## CLI And UX

- Add command-line flags for seed file, max pages, max depth, and output format.
- Add a JSON output mode for search results.
- Add a `--crawl-only` mode and a `--search-only` mode.
- Print crawl statistics after crawling.

## Resume Polish

- Add a short architecture diagram to the README.
- Add a sample `seeds.txt` and expected output.
- Add a limitations section that explains tradeoffs clearly.
- Add a short demo video or terminal recording later.
