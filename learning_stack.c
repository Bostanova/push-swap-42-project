#include <stdio.h>
#include <stdlib.h>

#define N 5
int stack[N];
int top = -1;

void	push(int content) {
	if (top == N - 1) {
		return ;
	} else {
		top++;
		stack[top] = content;
	}
}

void	pop(void) {
	if (top == -1) {
		printf("Underflow!\n");
	} else {
		top--;
	}
}

void	peek(void) {
	if (top == -1) {
		printf("Stack is empty\n");
	} else {
		printf("top element is %d\n", stack[top]);
	}
}

void	display(void) {
	for (int i = top; i >= 0; i--) {
		printf("%d\n", stack[i]);
	}
}

int main(int argc, char *argv[]) {
	int i = 1;
	while (i < argc) {
		push(atoi(argv[i]));
		i++;
	}
	display();
}