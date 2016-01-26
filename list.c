#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* current = head;
	if(new_element->index < head->index){
		new_element->next = head;
		return new_element;
	}
	
	while(current->next != NULL && (new_element->index > current->next->index)){
		current = current->next;
	}

	new_element->next = current->next;
	current->next = new_element;

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* current;
	list_t* newelement = head;
	list_t* nroot = NULL;
	while(newelement != NULL){
		current = newelement->next;
		newelement->next = nroot;
		nroot = newelement;
		newelement = current;
	}
	return nroot;
}

