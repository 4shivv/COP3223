# COP3223 - Introduction to C Programming

University coursework for COP3223 at UCF, containing programming assignments and projects implemented in C. This repository demonstrates fundamental programming concepts including data structures, file I/O, dynamic memory allocation, and algorithm design.

## Repository Structure

```
COP3223/
├── SmallProgram1-7/        # Small programming assignments
├── Assignment2.c           # Elephant movement simulation
├── largeprogram1-4/        # Major programming projects
├── sp5files/              # Small Program 5 files
└── PostToWebcourses/      # Additional coursework materials
```

## Major Projects

### Assignment 2 - Elephant Movement Simulation
**File:** `Assignment2.c`

A grid-based simulation tracking elephant movements as they search for and consume watermelon bait. Implements custom stack data structures for memory management.

**Key Concepts:**
- Custom stack implementation with dynamic memory allocation
- 2D grid-based spatial tracking (500x500)
- Greedy pathfinding algorithm
- Structured command-line interface

**Features:**
- Stack-based movement history for each elephant
- Greedy algorithm for pathfinding (moves to adjacent cell with most bait)
- Command-based interaction (B: add bait, H: progress hour, Q: quit)

**Compile & Run:**
```bash
gcc Assignment2.c -o assignment2
./assignment2
```

### Large Program 1
**File:** `largeprogram1_Nagamandla_Shivaganesh.c`

Early foundational programming assignment focusing on control structures and basic I/O.

**Compile & Run:**
```bash
gcc largeprogram1_Nagamandla_Shivaganesh.c -o lp1
./lp1
```

### Large Program 2 - Knightro's Coffee Shop
**File:** `largeprogram2_Nagamandla_Shivaganesh.c`

Interactive console-based coffee shop ordering system with account management.

**Key Concepts:**
- Financial transaction processing
- Menu-driven program design
- User input validation
- State management

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

**Key Concepts:**
- File I/O operations
- String manipulation
- Game state management
- Dynamic gameplay mechanics

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

### Large Program 4
**File:** `largeprogram4_Nagamandla_Shivaganesh.c`

Advanced programming assignment demonstrating mastery of core C concepts.

**Compile & Run:**
```bash
gcc largeprogram4_Nagamandla_Shivaganesh.c -o lp4
./lp4
```

## Small Programs

The repository includes several small programming assignments (SmallProgram1-7) covering:
- Basic I/O operations
- Control structures (loops, conditionals)
- Functions and parameters
- Arrays and strings
- Pointers and memory management
- File operations

Each small program directory contains the source code and any necessary supporting files.

## Course Information
- **Course:** COP3223 - Introduction to C Programming
- **Instructor:** Dr. Steinberg
- **Student:** Shivaganesh Nagamandla

## Technologies
- Language: C
- Concepts Covered: Pointers, dynamic memory allocation, structs, file I/O, linked lists, stacks

## License
Academic coursework - for educational purposes only.
