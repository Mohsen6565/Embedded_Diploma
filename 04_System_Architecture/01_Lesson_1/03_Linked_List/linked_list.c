/*
 * linked_list.c
 *
 *  Created on: Jun 12, 2022
 *      Author: Mohamed Mohsen
 */
#include "linked_list.h"

void LL_insert(S_node** head_ll, S_node* new_item, unsigned long indx){
	/* Check if the element is the first element */
	S_node* ptr_indx_element = (S_node*)(*(head_ll)) ;
	S_node* ptr_previous_element = (S_node*)(*(head_ll)) ;
	unsigned long i ;
	if(indx == 0){
		new_item->next_ptr = (S_node*)(*(head_ll)) ;
		*(head_ll) = (S_node*)new_item;
	}else{
		for(i=1; i<=indx; i++){
			ptr_indx_element = ptr_indx_element->next_ptr ;
			if(i == indx){
				ptr_previous_element->next_ptr = (S_node*)new_item ;
				new_item->next_ptr = (S_node*)ptr_indx_element ;
			}
			ptr_previous_element = ptr_previous_element->next_ptr ;
		}

	}
}

void LL_remove(S_node** head_ll, unsigned long indx){
	/* Check if the element is the first element */
	S_node* ptr_indx_element ;
	S_node* ptr_previous_element ;
	unsigned long i = 0 ;
	if(indx == 0){
		ptr_indx_element = (S_node*)(*(head_ll));
		(*(head_ll)) = (S_node*)ptr_indx_element->next_ptr ;
		free(ptr_indx_element);
	}else{
		ptr_indx_element = (S_node*)(*(head_ll));
		ptr_previous_element = (S_node*)(*(head_ll)) ;
		for(i=1; i<=indx; i++){
			ptr_indx_element = ptr_indx_element->next_ptr ;
			if(i == indx){
				ptr_previous_element->next_ptr = ptr_indx_element->next_ptr;
				free(ptr_indx_element);
			}
			ptr_previous_element = ptr_previous_element->next_ptr ;
		}
	}
}

void LL_append(S_node** head_ll, S_node* new_item){
	S_node* head_ptr = (S_node*)(*(head_ll));
	while(head_ptr){
		if(head_ptr->next_ptr == NULL){
			head_ptr->next_ptr = (S_node*)new_item ;
			new_item->next_ptr = NULL ;
		}
		head_ptr = head_ptr->next_ptr ;
	}
}

void LL_reverse(S_node** head_ll){
	S_node* prev_ptr ;
	S_node* nxt_ptr ;
	S_node* mid_ptr ;

	prev_ptr = (S_node*)(*(head_ll));		/* Keeps the address to reverse to */
	mid_ptr = prev_ptr->next_ptr ;			/* Pointer causing reverse */
	nxt_ptr = mid_ptr->next_ptr ;			/* Guides the forward movement */
	while(mid_ptr){
		/* Reverse Step */
		if(prev_ptr == (S_node*)(*(head_ll))){
			prev_ptr->next_ptr = NULL ;
		}
		mid_ptr->next_ptr = prev_ptr ;

		/* Moving Step*/
		prev_ptr = mid_ptr ;
		mid_ptr = nxt_ptr ;
		if(nxt_ptr != NULL){
			nxt_ptr = nxt_ptr->next_ptr ;
		}
	}
	/* Update Head */
	*(head_ll) = prev_ptr;
}

unsigned long LL_length(S_node* head){
	unsigned long length = 0 ;
	while(head){
		length ++ ;
		head = head->next_ptr ;
	}
	return length ;
}

void LL_print(S_node* head){
	unsigned int i ;
	i = 0 ;
	while(head){
		printf("%d : Data = %d\t My Address = %p\t Next Address = %p\n", i, head->data, head, head->next_ptr);
		head = head->next_ptr ;
		i ++ ;
	}
}


