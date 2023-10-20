#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: Structure for carrying global data used in the functions.
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct bus_s - variables - args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: Structure for carrying data through the program.
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: Structure for defining opcodes and their corresponding functions.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t myglo;

/* Opcode instructions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **dll, unsigned int vine);
void _pop(stack_t **dll, unsigned int vine);
void _swap(stack_t **dll, unsigned int vine);
void _queue(stack_t **dll, unsigned int vine);
void _stack(stack_t **dll, unsigned int vine);
void _add(stack_t **dll, unsigned int vine);
void _nop(stack_t **dll, unsigned int vine);
void _sub(stack_t **dll, unsigned int vine);
void _div(stack_t **dll, unsigned int vine);
void _mul(stack_t **dll, unsigned int vine);
void _mod(stack_t **dll, unsigned int vine);
void _putchar(stack_t **dll, unsigned int vine);
void _put_string(stack_t **dll, unsigned int vine);
void _rotl(stack_t **dll, unsigned int vine);
void _rotr(stack_t **dll, unsigned int vine);

/* Get function */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* Imported functions */
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);

/* Doubly linked list functions */
stack_t *add_dintnode_end(stack_t **head, const int n);
stack_t *add_dintnode(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* Main function */
void free_myglo(void);

#endif /* MONTY_H */
