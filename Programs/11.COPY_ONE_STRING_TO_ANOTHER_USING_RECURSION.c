#include <stdio.h>
#include <string.h> 

void stringCopy(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0'; 
    } else {
        *destination = *source; 
        stringCopy(source + 1, destination + 1); 
    }
}

int main() {
    char source[100];
    char destination[100];

    printf("Enter the source string: ");
    fgets(source, sizeof(source), stdin);
    
    if (source[strlen(source) - 1] == '\n')
        source[strlen(source) - 1] = '\0';

    stringCopy(source, destination);

    printf("Copied string: %s\n", destination);

    return 0;
}

