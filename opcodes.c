#include "monty.h"

/**
 * opcodes_get - Selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode.
 */
void (*opcodes_get(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t command[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	int i;

	for (i = 0; command[i].opcode; i++)
		if (_strcmp(command[i].opcode, opcode) == 0)
			break;
	return (command[i].f);
}
