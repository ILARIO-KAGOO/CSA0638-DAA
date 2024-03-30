#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

void containerLoader(int containers[], int numContainers, int items[], int numItems) {
    int currentContainer = 0;
    int remainingSpace = containers[currentContainer];

    printf("Items in Container %d:\n", currentContainer + 1);

    for (int i = 0; i < numItems; i++) {
        if (items[i] > remainingSpace) {
            currentContainer++;
            remainingSpace = containers[currentContainer];
            printf("\nItems in Container %d:\n", currentContainer + 1);
        }

        printf("%d ", items[i]);
        remainingSpace -= items[i];
    }
}

int main() {
    int numContainers, numItems;
    int containers[MAX_CONTAINERS], items[MAX_ITEMS];

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the capacities of containers:\n");
    for (int i = 0; i < numContainers; i++)
        scanf("%d", &containers[i]);

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the sizes of items:\n");
    for (int i = 0; i < numItems; i++)
        scanf("%d", &items[i]);

    containerLoader(containers, numContainers, items, numItems);

    return 0;
}

