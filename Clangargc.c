#include <stdio.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }


    FILE* source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        perror("Error opening source file");
        return 2;
    }


    FILE* destination_file = fopen(argv[2], "wb");
    if (destination_file == NULL) {
        perror("Error opening destination file");
        fclose(source_file);
        return 3;
    }


    int ch;
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }


    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully.\n");

    return 0;
}