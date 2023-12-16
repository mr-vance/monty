#include "monty.h"

variables vars;

/**
 * process_file - Process file line by line
 * @file_name: Name of the file to process
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int process_file(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", file_name);
        return EXIT_FAILURE;
    }

    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t read;

    while ((read = getline(&buffer, &buffer_size, file)) != -1) {
        vars.line_num++;

        char *opcode = strtok(buffer, " \r\t\n");
        if (opcode != NULL && execute_function(&vars, opcode) == EXIT_FAILURE) {
            fclose(file);
            free(buffer);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    if (buffer) free(buffer);

    return EXIT_SUCCESS;
}

/**
 * main - Entry point for the LIFO and FILO program
 * @argc: Number of command-line arguments
 * @argv: Array containing command-line arguments
 * Return: 0 on Success, 1 on Failure
 */
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: monty file\n");
        return EXIT_FAILURE;
    }

    if (initialize_vars(&vars) != 0)
        return EXIT_FAILURE;

    if (process_file(argv[1]) == EXIT_FAILURE) {
        free_resources();
        return EXIT_FAILURE;
    }

    free_resources();
    return EXIT_SUCCESS;
}
