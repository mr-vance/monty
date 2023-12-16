#include "monty.h"

/**
 * initialize_vars - Initialize global variables
 * @var: Pointer to global variables to initialize
 * Return: 0 on Success, 1 on Failure
 */
int initialize_vars(vars *var) {
    var->file = NULL;
    var->buff = NULL;
    var->tmp = 0;
    var->dict = create_instruction_set();
    if (var->dict == NULL)
        return (EXIT_FAILURE);
    var->head = NULL;
    var->line_number = 1;
    var->MODE = 0;

    return (EXIT_SUCCESS);
}

/**
 * create_instruction_set - Create the instruction dictionary
 * Return: Pointer to the instruction dictionary
 */
instruction_t *create_instruction_set() {
    instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

    if (!ptr) {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    // Initializing the instruction set with respective function pointers
    ptr[0].opcode = "pall", ptr[0].f = print_stack;
    ptr[1].opcode = "push", ptr[1].f = push_stack;
    ptr[2].opcode = "pint", ptr[2].f = print_top;
    ptr[3].opcode = "pop", ptr[3].f = pop_stack;
    ptr[4].opcode = "swap", ptr[4].f = swap_elements;
    ptr[5].opcode = "add", ptr[5].f = add_elements;
    ptr[6].opcode = "nop", ptr[6].f = NULL;
    ptr[7].opcode = "sub", ptr[7].f = subtract_elements;
    ptr[8].opcode = "div", ptr[8].f = divide_elements;
    ptr[9].opcode = "mul", ptr[9].f = multiply_elements;
    ptr[10].opcode = "mod", ptr[10].f = modulo_elements;
    ptr[11].opcode = "pchar", ptr[11].f = print_char;
    ptr[12].opcode = "pstr", ptr[12].f = print_string;
    ptr[13].opcode = "rotl", ptr[13].f = rotate_left;
    ptr[14].opcode = "rotr", ptr[14].f = rotate_right;
    ptr[15].opcode = "stack", ptr[15].f = set_stack_mode;
    ptr[16].opcode = "queue", ptr[16].f = set_queue_mode;
    ptr[17].opcode = NULL, ptr[17].f = NULL;

    return (ptr);
}

/**
 * execute_instruction - Execute the given instruction
 * @var: Pointer to global variables
 * @opcode: Command to execute
 * Return: 0 on Success, 1 on Failure
 */
int execute_instruction(vars *var, char *opcode) {
    int i;

    for (i = 0; var->dict[i].opcode; i++) {
        if (strcmp(opcode, var->dict[i].opcode) == 0) {
            if (!var->dict[i].f)
                return (EXIT_SUCCESS);
            var->dict[i].f(&var->head, var->line_number);
            return (EXIT_SUCCESS);
        }
    }

    if (strlen(opcode) != 0 && opcode[0] != '#') {
        fprintf(stderr, "L%u: unknown instruction %s\n", var->line_number, opcode);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

/**
 * free_resources - Free dynamically allocated memory
 * Return: None
 */
void free_resources(void) {
    if (var.buff != NULL)
        free(var.buff);

    if (var.file != NULL)
        fclose(var.file);

    free(var.dict);

    if (var.head != NULL) {
        while (var.head->next != NULL) {
            var.head = var.head->next;
            free(var.head->prev);
        }
        free(var.head);
    }
}

/**
 * is_number - Check if the string represents a valid number
 * @string: String to validate
 * Return: 0 if Success, 1 if Failed
 */
int is_number(char *string) {
    int i;

    for (i = 0; string[i]; i++) {
        if (string[i] < '0' || string[i] > '9')
            return (1);
    }

    return (0);
}
