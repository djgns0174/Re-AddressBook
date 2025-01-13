#include "list.h"
#include "c.h"

int c(List* list) {
	if (printList(list) == 0) return 0;
	return 1;
}