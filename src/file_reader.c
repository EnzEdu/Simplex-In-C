#include <stdio.h>
#include <stdlib.h>

char* read_file(char* filename) {
    char* file_content;
    long file_size;
    int file_character_ascii;
    size_t count = 0;
    size_t i;

    /* Open file */
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("ERROR: File not opened!");
    }

    /* Get size of file */
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory for saving the entire file */
    file_content = malloc(file_size);

    /* Read every character of file */
    while ((file_character_ascii = fgetc(file)) != EOF) {
        file_content[count++] = (char) file_character_ascii;
    }
    file_content[count] = '\0';

    for (i = 0; i < count; i++) {
        printf("%c", file_content[i]);
    }

    return file_content;
}