# Spell Checker and Word Suggestion Application

## Project Overview
A spell checker and word suggestion application built using Qt framework in C++. The application provides real-time word suggestions as users type and verifies spelling correctness through an interactive graphical user interface.

## Features
- Real-time word suggestions while typing
- Spell checking functionality
- Similar word suggestions for incorrect words
- Case-insensitive word processing
- Interactive graphical user interface

## Technical Architecture

### Core Components
1. **MainWindow Class**
   - Handles UI interactions and events
   - Manages the search bar and suggestions list
   - Connects user actions to Trie operations

2. **Trie Class**
   - Implements the core data structure
   - Manages word storage and retrieval
   - Provides suggestion generation functionality

3. **JsonParser Class**
   - Handles dictionary file loading
   - Parses JSON format word lists
   - Provides error handling for file operations

## Data Structure: Trie

### Implementation Details
- Each node contains:
  - Array of 26 child pointers (for lowercase letters)
  - Boolean flag for word completion
- Case-insensitive implementation
- Efficient prefix-based operations

### Time Complexity
| Operation | Complexity | Description |
|-----------|------------|-------------|
| Insertion | O(L) | L = length of word |
| Search | O(L) | L = length of word |
| Get Suggestions | O(N) | N = nodes in prefix subtree |

### Space Complexity
- O(ALPHABET_SIZE * M * N)
  - M = maximum length of words
  - N = number of words
  - ALPHABET_SIZE = 26 (English lowercase letters)

## Why Trie Over Alternatives?

### Comparison with Hash Tables
- **Advantage**: Efficient prefix operations
- **Advantage**: Space-efficient for common prefixes
- **Trade-off**: Slightly higher memory overhead per node

### Comparison with Binary Search Trees
- **Advantage**: Better prefix searching
- **Advantage**: Natural alphabetical ordering
- **Trade-off**: More complex implementation

## Performance Characteristics

### Strengths
1. Fast prefix-based operations
2. Predictable performance
3. Natural word ordering
4. Memory efficiency for similar words

### Limitations
1. Memory overhead for sparse datasets
2. Fixed alphabet size constraint
3. Case-insensitive implementation trade-offs

## Code Organization

```
project/
├── include/
│   ├── JsonParser.h
│   ├── mainwindow.h
│   └── trie.h
├── src/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   └── trie.cpp
└── resources/
    └── words_dictionary.json
```

## Key Learning Outcomes

### Technical Skills
1. **Data Structures**
   - Trie implementation
   - Memory management
   - Algorithm optimization

2. **Qt Framework**
   - GUI development
   - Event handling
   - Signal-slot mechanism

3. **C++ Programming**
   - Object-oriented design
   - Memory management
   - File I/O operations

### Software Design
1. **Architecture**
   - Separation of concerns
   - Component interaction
   - Event-driven programming

2. **Best Practices**
   - Error handling
   - Code organization
   - Documentation

## Future Enhancements
1. Support for multiple languages
2. Fuzzy search capabilities
3. Custom dictionary support
4. Performance optimizations
5. Advanced suggestion algorithms

## Build and Run

### Prerequisites
- Qt 5.x or higher
- C++11 compatible compiler
- CMake 3.x or higher

### Build Steps
1. Clone the repository
2. Run CMake to generate build files
3. Build the project
4. Ensure dictionary file is in the correct location

### Running the Application
1. Launch the executable
2. Type in the search bar
3. Use suggestion list or buttons for spell checking

## Conclusion
This project demonstrates the practical application of Trie data structure in solving real-world problems like spell checking and word suggestions. The implementation shows a good balance between performance, functionality, and code organization while providing valuable learning opportunities in both data structures and GUI development.
