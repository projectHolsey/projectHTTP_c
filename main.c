#include <stdio.h>
#include <string.h>



int main() {

    // Create a new file Stream object
    FILE *filePointer;
    char filename[] = "messages.txt";

    char lineBuffer[8]; // Character buffer to read the file into, 8 bytes at a time
    char fileBuffer[512];

    // Open the file in read mode
    filePointer = fopen(filename, "r");
 
    if (filePointer == NULL) {
        printf("Error: Could not open the file %s\n", filename);
        return 1; // 1 being an error
    }

    // fgets: gets next char from specified stream (unsigned char) and advance ptr postion
    // In this case, we want to read sizeof(buffer) from filePointer stream
    while (fgets(lineBuffer, sizeof(lineBuffer), filePointer) != NULL) {
        printf("%s\n", lineBuffer); // Print each line read
        // strncat is just concatinate the one strinng onto the end of another.
        // this function allows the 3rd argument to specify the amount of characters we want to copy over
        //          note - there is another function 'strcat' that doesn't specify size and just does it. 
        strncat(fileBuffer, lineBuffer, sizeof(lineBuffer)); 
    }

    return 0;
}