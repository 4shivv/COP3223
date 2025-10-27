#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int posX;
    int posY;
} Position;

typedef struct {
    Position* positions;
    int count;
    int capacity;
} DynamicCollection;

typedef struct {
    char moveDirection;
    int watermelonEaten;
} Movement;

typedef struct {
    Movement* moves;
    int top;
    int capacity;
} MoveStack;

void initializeDynamicCollection(DynamicCollection* collection) {
    collection->count = 0;
    collection->capacity = 10;
    collection->positions = (Position*)malloc(collection->capacity * sizeof(Position));
}

void addPosition(DynamicCollection* collection, Position pos) {
    if (collection->count == collection->capacity) {
        collection->capacity *= 2;
        collection->positions = (Position*)realloc(collection->positions, collection->capacity * sizeof(Position));
    }
    collection->positions[collection->count++] = pos;
}

void initializeMoveStack(MoveStack* stack) {
    stack->top = -1;
    stack->capacity = 10;
    stack->moves = (Movement*)malloc(stack->capacity * sizeof(Movement));
}

void pushMove(MoveStack* stack, char moveDirection, int watermelonEaten) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->moves = (Movement*)realloc(stack->moves, stack->capacity * sizeof(Movement));
    }
    stack->moves[++stack->top].moveDirection = moveDirection;
    stack->moves[stack->top].watermelonEaten = watermelonEaten;
}

Movement popMove(MoveStack* stack) {
    return stack->moves[stack->top--];
}

int main() {
    int numElephants;
    scanf("%d", &numElephants);

    DynamicCollection elephants;
    initializeDynamicCollection(&elephants);

    for (int i = 0; i < numElephants; ++i) {
        Position pos;
        scanf("%d %d", &pos.posX, &pos.posY);
        addPosition(&elephants, pos);
    }

    DynamicCollection watermelons;
    initializeDynamicCollection(&watermelons);

    MoveStack* movementStacks = (MoveStack*)malloc(numElephants * sizeof(MoveStack));
    for (int i = 0; i < numElephants; ++i) {
        initializeMoveStack(&movementStacks[i]);
    }

    char command[5];
    while (scanf("%s", command) != EOF) {
        if (command[0] == 'B') {
            int R, C, A;
            scanf("%d %d %d", &R, &C, &A);
            Position pos = { R, C };
            addPosition(&watermelons, pos);
            for (int i = 0; i < numElephants; ++i) {
                pushMove(&movementStacks[i], 'B', A);
            }
        } else if (command[0] == 'H') {
            int totalWatermelonEaten = 0;
            for (int i = 0; i < numElephants; ++i) {
                char moveDirection;
                int watermelonEaten = 0;

                scanf(" %c", &moveDirection);
                if (moveDirection == 'N' && elephants.positions[i].posX > 1) {
                    --elephants.positions[i].posX;
                } else if (moveDirection == 'S' && elephants.positions[i].posX < 500) {
                    ++elephants.positions[i].posX;
                } else if (moveDirection == 'E' && elephants.positions[i].posY < 500) {
                    ++elephants.positions[i].posY;
                } else if (moveDirection == 'W' && elephants.positions[i].posY > 1) {
                    --elephants.positions[i].posY;
                }

                if (watermelons.count > 0) {
                    for (int j = 0; j < watermelons.count; ++j) {
                        if (elephants.positions[i].posX == watermelons.positions[j].posX &&
                            elephants.positions[i].posY == watermelons.positions[j].posY) {
                            watermelonEaten += 1;
                        }
                    }
                }

                pushMove(&movementStacks[i], moveDirection, watermelonEaten);
                totalWatermelonEaten += watermelonEaten;
            }
            printf("%d\n", totalWatermelonEaten);
        } else if (command[0] == 'Q') {
            break;
        }
    }

    for (int i = 0; i < numElephants; ++i) {
        printf("%d %d\n", elephants.positions[i].posX, elephants.positions[i].posY);
    }

    free(elephants.positions);
    free(watermelons.positions);
    free(movementStacks);

    return 0;
}