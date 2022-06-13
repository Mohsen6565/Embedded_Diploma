/*
 * linked_list.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>

/* Linked List Data Type */
typedef struct S_node{
	unsigned long id ;
	unsigned char name[50] ;
	unsigned long height ;
	struct S_node* next_ptr ;
}S_node;

/* Linked List APIs */
void LL_insert(S_node** head_ll, S_node* new_item, unsigned long indx);
void LL_remove(S_node** head_ll, unsigned long indx);
void LL_append(S_node** head_ll, S_node* new_item);
void LL_reverse(S_node** head_ll);
unsigned long LL_length(S_node* head);
void LL_print(S_node* head);

#endif /* LINKED_LIST_H_ */
