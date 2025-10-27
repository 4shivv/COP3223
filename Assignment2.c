#include <stdio.h>
#include <stdlib.h>

// Define structs
struct Node {
    int r, c;
    struct Node* next;
};

struct Stack {
    struct Node* head;
};

struct Elephant {
    struct Stack memory;
};

// Function prototypes
struct Node* createNode(int row, int col);
void push(struct Stack* stk, int row, int col);
void pop(struct Stack* stk);
void top(struct Stack* stk, int* row_ptr, int* col_ptr);
void addBait(int** grid, int row, int col, int amt);
int eatBait(int** grid, int row, int col);
void move(struct Elephant* ele_ptr, int** grid);
int eat(struct Elephant* ele_ptr, int** grid);
int progress_hour(struct Elephant* ele_arr, int num_ele, int** grid);

int main() {
    // Read input
    int num_ele;
    scanf("%d", &num_ele);

    // Allocate memory for elephants
    struct Elephant* elephants = (struct Elephant*)malloc(num_ele * sizeof(struct Elephant));

    // Allocate memory for the grid
    int max_rows = 500;
    int max_cols = 500;
    int** grid = (int**)malloc(max_rows * sizeof(int*));
    for (int i = 0; i < max_rows; i++) {
        grid[i] = (int*)malloc(max_cols * sizeof(int));
    }

    // Initialize grid
    for (int i = 0; i < max_rows; i++) {
        for (int j = 0; j < max_cols; j++) {
            grid[i][j] = 0;
        }
    }

    // Initialize elephants
    for (int i = 0; i < num_ele; i++) {
        elephants[i].memory.head = NULL;
        int r, c;
        scanf("%d %d", &r, &c);
        push(&(elephants[i].memory), r, c);
    }

    // Process commands
    char command[5];
    while (scanf("%s", command) == 1) {
        if (command[0] == 'B') {
            int r, c, amt;
            scanf("%d %d %d", &r, &c, &amt);
            addBait(grid, r, c, amt);
        } else if (command[0] == 'H') {
            int consumed = progress_hour(elephants, num_ele, grid);
            printf("%d\n", consumed);
        } else if (command[0] == 'Q') {
            break;
        }
    }

    // Print final elephant locations
    for (int i = 0; i < num_ele; i++) {
        int row, col;
        top(&(elephants[i].memory), &row, &col);
        printf("%d %d\n", row, col);
    }

    // Free memory
    for (int i = 0; i < max_rows; i++) {
        free(grid[i]);
    }
    free(grid);
    free(elephants);

    return 0;
}

// Implement functions
struct Node* createNode(int row, int col) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->r = row;
    newNode->c = col;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack* stk, int row, int col) {
    struct Node* newNode = createNode(row, col);
    newNode->next = stk->head;
    stk->head = newNode;
}

void pop(struct Stack* stk) {
    if (stk->head != NULL) {
        struct Node* temp = stk->head;
        stk->head = stk->head->next;
        free(temp);
    }
}

void top(struct Stack* stk, int* row_ptr, int* col_ptr) {
    if (stk->head != NULL) {
        *row_ptr = stk->head->r;
        *col_ptr = stk->head->c;
    }
}

void addBait(int** grid, int row, int col, int amt) {
    grid[row - 1][col - 1] += amt;
}

int eatBait(int** grid, int row, int col) {
    int consumed = grid[row - 1][col - 1];
    grid[row - 1][col - 1] = 0;
    return consumed;
}

void move(struct Elephant* ele_ptr, int** grid) {
    int current_row, current_col;
    top(&(ele_ptr->memory), &current_row, &current_col);

    int max_bait = -1;
    int next_row = current_row;
    int next_col = current_col;

    // Check adjacent intersections for most watermelons
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int new_row = current_row + i;
            int new_col = current_col + j;

            if (new_row >= 1 && new_row <= 500 && new_col >= 1 && new_col <= 500) {
                if (grid[new_row - 1][new_col - 1] > max_bait) {
                    max_bait = grid[new_row - 1][new_col - 1];
                    next_row = new_row;
                    next_col = new_col;
                }
            }
        }
    }

    // Move to the intersection with the most watermelons
    if (next_row != current_row || next_col != current_col) {
        push(&(ele_ptr->memory), next_row, next_col);
    }
}

int eat(struct Elephant* ele_ptr, int** grid) {
    int consumed = eatBait(grid, ele_ptr->memory.head->r, ele_ptr->memory.head->c);
    pop(&(ele_ptr->memory));
    return consumed;
}

int progress_hour(struct Elephant* ele_arr, int num_ele, int** grid) {
    // Move all elephants
    for (int i = 0; i < num_ele; i++) {
        move(&(ele_arr[i]), grid);
    }

    // Eat at each location
    int total_consumed = 0;
    for (int i = 0; i < num_ele; i++) {
        if (ele_arr[i].memory.head != NULL) {
            total_consumed += eat(&(ele_arr[i]), grid);
        }
    }

    return total_consumed;
}
