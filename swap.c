#include "monty.h"

int main(void)
{
   return(0);
}
/**
 * swap - swap the first two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top_rear, *rear_top;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top_rear = *stack;
    rear_top = (*stack)->next;

    if (rear_top->next != NULL)
    {
        top_rear->next = rear_top->next;
        rear_top->next->prev = top_rear;
    }
    else
    {
        top_rear->next = NULL;
    }

    top_rear->prev = rear_top;
    rear_top->next = top_rear;
    rear_top->prev = NULL;

    *stack = rear_top;
}
