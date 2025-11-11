#include <stdio.h>
#include <string.h>



int main() {

    // Create a new file Stream object
    FILE *filePointer;
    char filename[] = "messages.txt";

    char buffer[512]; // Character buffer to read the file into

    // Open the file in read mode
    filePointer = fopen(filename, "r");
 
    if (filePointer == NULL) {
        printf("Error: Could not open the file %s\n", filename);
        return 1; // 1 being an error
    }

    // fgets: gets next char from specified stream (unsigned char) and advance ptr postion
    // In this case, we want to read sizeof(buffer) from filePointer stream
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        printf("%s", buffer); // Print each line read
    }

    return 0;
}