#include "stack.h"
#include <stdlib.h>

void StackInit(Stack_t *ps)
{
	ps->top = '\0';
	ps->size = 0;
}

void StackPush(StackEntry_t e, Stack_t *ps) {
	StackNode_t *pNode;
	
	if((pNode = (StackNode_t*)malloc(sizeof(StackNode_t)))) {
		pNode->entry = e;
		ps->size++;
		pNode->next = ps->top;
		ps->top = pNode;
	}
}

void StackPop(StackEntry_t *pe, Stack_t *ps) {
	StackNode_t *pNode;
	*pe = ps->top->entry;
	pNode = ps->top;
	ps->top = ps->top->next;
	free(pNode);
	ps->size--;
}

void RemoveTop(Stack_t *ps) {
	StackNode_t *pNode;
	pNode = ps->top;
	ps->top = ps->top->next;
	free(pNode);
	ps->size--;
}


int StackFull(Stack_t *ps) {
	return 0;
}

int StackEmpty(Stack_t *ps) {
	return !ps->top;
}

StackEntry_t StackTop(Stack_t *ps) {
	return ps->top->entry;
}

int StackSize(Stack_t *ps) {
	return ps->size;
}

void ClearStack(Stack_t *ps) {
	StackNode_t *pNode = ps->top;
	while(pNode) {
		pNode = pNode->next;
		free(ps->top);
		ps->top = pNode;
	}
	ps->size = 0;
}

void TraverseStack(Stack_t *ps, void (*pf) (StackEntry_t)) {
	StackNode_t *pNnode = ps->top;
	while(pNnode) {
		(*pf)(pNnode->entry);
		pNnode = pNnode->next;
	}
}

void SaferFree(void **pp)
{
   if (pp != NULL && *pp != NULL) {
       free(*pp);
       *pp = NULL;
   }
}