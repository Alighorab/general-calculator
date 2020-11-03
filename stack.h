#ifndef STACK_H_
#define STACK_H_

typedef char StackEntry_t;

typedef struct stacknode {
	StackEntry_t entry;
	struct stacknode *next;
} StackNode_t;

typedef struct Stack {
	StackNode_t *top;
	int size;
} Stack_t;

void StackInit(Stack_t *ps);

/**
* Precondition: the stack is initialized and not full.
* Post-condition: the element has been stored at the top of
  the stack and the element does not change.
**/
void StackPush(StackEntry_t e, Stack_t *pe);

/**
* Precondition: the stack is is initialized and not empty.
* Post-condition: the last element entered is returned.
**/
void StackPop(StackEntry_t *pe, Stack_t *ps);

/**
* Precondition: the stack is is initialized and not empty.
* Post-condition: top has removed.
**/
void RemoveTop(Stack_t *ps);

int StackFull(Stack_t *ps);
int StackEmpty(Stack_t *ps);

/**
* Precondition: the stack is is initialized and not empty.
* Post condition: the last element entered is returned but still
  in stack.
**/
StackEntry_t StackTop(Stack_t *ps);

/**
* Precondition: the stack is is initialized.
* Post condition: returns how many elements exist.
**/
int StackSize(Stack_t *ps);

/**
* Precondition: the stack is is initialized.
* Post condition: destroy all elements; stack looks initialized.
**/
void ClearStack(Stack_t *ps);

/**
* Precondition: the stack is is initialized.
* Post condition: print all elements to screen.
**/
void TraverseStack(Stack_t *ps, void (*pf) (StackEntry_t));
/**
* Precondition: the stack is is initialized and not empty.
* Post condition: the last element entered is returned but still
  in stack.
**/


#endif /* STACK_H_ */