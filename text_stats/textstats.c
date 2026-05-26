#include <stdio.h>

int main(int argc, char* argv[]) {

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    FILE *fileptr;
    int c;
    int wordActive = 1;
    int currentChar;

    // printf("Number of command line arguments supplied: %d \n", argc-1);

    if (argc <= 1) {
        printf("Error::: User failed to supply a file path \n");
        return 1;
    }

    // for (int i = 1; i < argc; i++) {
    //     printf("%s \n", argv[i]);
    // }

    const char* filename = argv[1];

    fileptr = fopen(filename, "r");

    // Now you've read the file check if it exists

    if (fileptr == NULL) {
        printf("ERROR :::: could not open file: %s \n", filename);
        return 1;
    }

    if ((c = fgetc(fileptr) ) == EOF) {

        printf("lines: %d \n", lineCount);
        printf("words: %d \n", wordCount);
        printf("chars: %d \n", charCount);

        return 0;
    }

    while ((c = fgetc(fileptr)) != EOF) {
        currentChar = c;
        // all eligible characters
        charCount++;
        // printf("Current character: %d \n", c);

        // Determine if a whitespace or a new line has been hit

        if ( ( (9 <= c) && (c <= 13) ) || c == 32) {
            // if the word is active then increment 
            if (wordActive == 0) {
                wordCount++;
                // make inactive till another non-whitespace char is seen
                wordActive = 1;
            }

            if (c == 10) {
                lineCount++;
            }

        }
        else {
            wordActive = 0;
        }
    }

    fclose(fileptr);

    if (wordActive == 0) {
        wordCount++;
    }

    // If the last char is not a newline increment line again
    if (currentChar != 10) {
        lineCount++;
    }


    printf("lines: %d \n", lineCount);
    printf("words: %d \n", wordCount);
    printf("chars: %d \n", charCount);

    return 0;
}