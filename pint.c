#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

stack_t *stack = NULL; // Global stack variable

void push(stack_t **stack, unsigned int line_no)
{
    /* Check if there is an argument for push */
    if (line_no == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_no);
        exit(EXIT_FAILURE);
    }

    /* Get the integer value from the argument */
    int value = atoi(line_no);

    /* Create a new node to hold the value */
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Assign the value to the new node */
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    /* Push the new node onto the stack */
    if (*stack != NULL)
        (*stack)->prev = new_node;
    new_node->next = *stack;
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_no)
{
    stack_t *current = *stack;

    /* Traverse the stack and print the values */
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

