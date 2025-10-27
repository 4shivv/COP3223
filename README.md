# COP3223 - Introduction to C Programming

University coursework for COP3223, containing programming assignments implemented in C.

## Projects

### Assignment 2 - Elephant Movement Simulation
**File:** `Assignment2.c`

A grid-based simulation tracking elephant movements as they search for and consume watermelon bait. Implements custom stack data structures for memory management.

**Features:**
- 500x500 grid system for spatial tracking
- Stack-based movement history for each elephant
- Greedy algorithm for pathfinding (moves to adjacent cell with most bait)
- Command-based interaction (B: add bait, H: progress hour, Q: quit)

**Compile & Run:**
```bash
gcc Assignment2.c -o assignment2
./assignment2
```

### Large Program 2 - Knightro's Coffee Shop
**File:** `largeprogram2_Nagamandla_Shivaganesh.c`

Interactive console-based coffee shop ordering system with account management.

**Features:**
- Account balance management with reload functionality
- Menu-based ordering system (8 items available)
- Transaction processing with insufficient funds handling
- Input validation and error handling

**Compile & Run:**
```bash
gcc largeprogram2_Nagamandla_Shivaganesh.c -o coffeeshop
./coffeeshop
```

### Large Program 3 - Hangman Game
**File:** `largeprogram3_Nagamandla_Shivaganesh.c`

Classic word-guessing game with file I/O and dynamic gameplay features.

**Features:**
- File-based word loading from `words.txt`
- Strike system (6 strikes maximum)
- Consecutive correct guess bonus (option to guess full word after 2 correct guesses)
- Guess history tracking
- Multi-round gameplay

**Compile & Run:**
```bash
gcc largeprogram3_Nagamandla_Shivaganesh.c -o hangman
./hangman
```
*Note: Requires `words.txt` file in the same directory*

## Course Information
- **Course:** COP3223 - Introduction to C Programming
- **Instructor:** Dr. Steinberg
- **Student:** Shivaganesh Nagamandla

## Technologies
- Language: C
- Concepts Covered: Pointers, dynamic memory allocation, structs, file I/O, linked lists, stacks

## License
Academic coursework - for educational purposes only.
