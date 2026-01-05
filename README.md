# Product Search Engine

A fast, dynamic product search engine built in C++ using Trie data structure.

## Features

- **Real-time search** - Results update as you type each character
- **Case-insensitive** - Search with any case (apple, APPLE, Apple all work)
- **Weighted results** - Products sorted by relevance/weight
- **Prefix matching** - Instantly find products by their starting letters
- **800+ products** - Extensive database of grocery, personal care, household items, and more

## How to Use

### Compile
```bash
g++ -std=c++11 searchengine.cpp -o searchengine
```

### Run
```bash
./searchengine
```

### Usage
1. Start typing product names character by character
2. Results update live as you type
3. Press **Backspace** to delete characters
4. Press **ESC** or **Ctrl+C** to exit

### Example
- Type `a` → Shows all products starting with "A"
- Type `am` → Shows products starting with "Am" (Amul products)
- Type `app` → Shows "Apple" and "Appy Fizz"

## Data Structure

Uses a **Trie (Prefix Tree)** for efficient prefix-based searching:
- O(m) time complexity for search, where m is the length of the prefix
- Fast real-time autocomplete functionality
- Memory-efficient storage of products

## Product Categories

- Dairy & Bakery
- Staples
- Snacks & Beverages
- Personal Care
- Household & Cleaning
- Packaged Foods
- Fruits & Vegetables
- Baby Care
- Frozen & Ready-to-Cook
- Organic & Health
- Pet Care

## Technical Details

- **Language**: C++11
- **Data Structure**: Trie (Prefix Tree)
- **Terminal**: Raw mode for character-by-character input
- **Platform**: macOS/Linux (uses termios.h)
