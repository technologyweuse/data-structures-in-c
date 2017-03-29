/****************************************************************************
 * Copyright (C) 2017 by Maduranga Jayasinghe                               *
 *                                                                          *
 *  Linked list operations demonstration program.                           *
 *                                                                          *
 *   This program is a free software : you can redistribute it and / or     *
 *   modify it under the terms of the GNU Lesser General Public  License    *
 *   as published by the Free Software Foundation, either version 3 of      *
 *   the License, or ( at your option ) any later version.                  *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 *   You should have received a copy of the GNU Lesser General Public       *
 *   License along with Self Drive Car.                                     *
 *   If not, see <http://www.gnu.org/licenses/>.                            *
 *                                                                          *
 *   For detail tutorial about linked list, see                             *
 *   <http://www.bitexperiemnts.com/>                                       *
 *                                                                          *
 ****************************************************************************/

/**
 * @file    linked_list_demo.c
 * @author  Maduranga Jayasinghe
 * @date    2017-01-10
 * @brief   This is a demonstration of linked list operations.
 * 
 * In this demo program, I'm going to explain following operations
 * with linked list.
 *    1. Display linked list data
 *    2. Add a new node to the end of the list
 *    3. Add a new node at the begining of the list
 *    4. Find a node and insert a new node before the node
 *    5. Find a node and insert a new node after the node
 *    6. Find the index of node
 *    7. Find and remove a node from list
 *    8. Remove the last node from the list
 *    9. Remove the first node from the list
 *   10. Display linked list data in reverse order
 *   11. Clear allocated heap memory before extit
 */
 
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Basic node structure
 * 
 * @internal
 *      History:
 *      2017.01.10      Initialise
 */
struct node{
    int data;		/* Data of the linked list node */
    struct node *next;	/* Hold the structure pointer of next node */
};

/**
 * @brief Initialize list root
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
struct node *root = NULL;

/**
 * @brief Print linked list data
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void print_list(){
    if(root == NULL){ /* Empty List */
	printf("List is empty\n");
    }
    else{ /* Print the linked list data sequence */
	struct node *curr = root;

	printf("Linked List >> ");
	while(1){
	    printf("[%d]", curr->data);
	    if(curr->next == NULL){
		break;
	    }
	    else{
		printf("->");
	    }
	    curr = curr->next;
	}
	printf("\n");
    }
}

/**
 * @brief Print linked list data in reverse order
 * @param   n	Struct pointer of next node
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void print_list_reverse(struct node * n){
    if( n == NULL){
	return;
    }
    else{ /* Print the linked list data sequence in reverse order */
	print_list_reverse(n->next);
	printf("[%d]", n->data);
	if(n != root){
	    printf("->");
	}
    }
}

/**
 * @brief Add new node to the end of linked list
 * @param   data    New node's data value
 * @return  void
 *
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void add_last(int data){
    /* Create a new node */
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    
    /* Set data to the new node */
    tmp->data = data;
    tmp->next = NULL;

    /* Set new node at the end of the list */
    if(root == NULL){
	root = tmp;
    }
    else{
	struct node *curr = root;
	while(curr->next != NULL){
	    curr = curr->next;
	}
	curr->next = tmp;
    }
}

/**
 * @brief Remove last node from the linked list
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void remove_last(){
    struct node *curr = root;
    struct node *prv;
    int data;

    if(curr == NULL){
	printf("List is empty\n");
	return;
    }
    else if(curr->next == NULL){
	data = curr->data;
	free(curr);
	root = NULL;
    }
    else{
	while(curr->next != NULL){
	    prv = curr;
	    curr = curr->next;
	}
	data = curr->data;
	prv->next = NULL;
	free(curr);
    }
    printf("Removed last node's data is : %d\n", data);
}

/**
 * @brief Add new node to the beginning of the linked list
 * @param   data    New node's data
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void add_begin(int data){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;

    if(root == NULL){
	root = tmp;
	root->next = NULL;
    }
    else{
	tmp->next = root;
	root = tmp;
    }
}

/**
 * @brief Remove the first node of linked list
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void remove_begin(){
    int data;
    if(root == NULL){
	printf("List is empty\n");
	return;
    }
    else if(root->next == NULL){
	data = root->data;
	root = NULL;
    }
    else{
	data = root->data;
	root = root->next;
    }
    printf("Removed first node's data is : %d\n", data);
}

/**
 * @brief Find the index of node
 * @param   data    Search node's data
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
 
int find_index(int data){
    int index = 1;
    struct node *curr = root;
    if(curr == NULL){
	return -1;
    }
    else if(curr->next == NULL){
	if(curr->data == data){
	    return index;
	}
	return -2;
    }
    else{
	while(1){
	    if(curr->data == data){
		return index;
	    }
	    if(curr->next == NULL){
		break;
	    }
	    curr = curr->next;
	    index++;
	}
	return -2;
    }
	
}

/**
 * @brief Find and remove a node from linked list
 * @param   data    New node's data
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void find_and_remove(int data){
    int index = find_index(data);
    if(index == -1){
	printf("Not found (%d), List is empty\n", data);
	return;
    }
    else if(index == -2){
	printf("Not found! ( %d )\n", data);
	return;
    }
    else if(index == 1){
	if(root->next == NULL){
	    free(root);
	    root = NULL;
	}
	else{
	    struct node *found = root;
	    root = root->next;
	    free(found);
	}
    }
    else{
	int i = 1;
	struct node *prv = NULL;
	struct node *curr = root;

	while(i < index){
	    prv = curr;
	    curr = curr->next;
	    i++;
	}
	prv->next = curr->next;
	free(curr);
    }
    printf("Node(Data:%d) at index of %d\n", data, index);
}

/**
 * @brief Search a node data and insert new node after
 * @param   search_value    Search node's data
 * @param   data    New node's data
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void insert_after(int search_value, int data){
    int index = find_index(search_value);
    if(index == -1){
	printf("Not found (%d), List is empty\n", search_value);
	return;
    }
    else if(index == -2){
	printf("Not found! ( %d )\n", search_value);
	return;
    }
    else if(index == 1){
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->next = NULL;

	if(root->next == NULL){
	    root->next = tmp;
	}
	else{
	    tmp->next = root->next;
	    root->next = tmp;
	}
    }
    else{
	int i = 1;
	struct node *curr = root;
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->next = NULL;

	while(i < index){
	    curr = curr->next;
	    i++;
	}
	tmp->next = curr->next;
	curr->next = tmp;
    }
}

/**
 * @brief Search a node data and insert new node before the node
 * @param   search_value    Search node's data
 * @param   data    New nod'se data
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void insert_before(int search_value, int data){
    int index = find_index(search_value);
    if(index == -1){
	printf("Not found (%d), List is empty\n", search_value);
	return;
    }
    else if(index == -2){
	printf("Not found! ( %d )\n", search_value);
	return;
    }
    else if(index == 1){
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->next = root;
	root = tmp;
    }
    else{
	int i = 1;
	struct node *prv = NULL;
	struct node *curr = root;
	struct node *tmp = (struct node*)malloc(sizeof(struct node));
	tmp->data = data;
	tmp->next = NULL;

	while(i < index){
	    prv = curr;
	    curr = curr->next;
	    i++;
	}
	tmp->next = curr;
	prv->next = tmp;
    }
}

/**
 * @brief clear memory allocation and delete all node
 * @param   n	Struct pointer of next node
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void memory_free(struct node * n){
    if( n == NULL){
	return;
    }
    else{ /* free memory */
	memory_free(n->next);
	free(n);
    }
}

/**
 * @brief Display main menu
 * @return  void
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
void print_menu(){
    printf("-----------------------------------------------------------\n");
    printf(" Linked List Operation Menu\n");
    printf("-----------------------------------------------------------\n");
    printf(" 1. Display linked list data\n");
    printf(" 2. Add a new node to the end of the list\n");
    printf(" 3. Add a new node at the begining of the list\n");
    printf(" 4. Find a node and insert a new node before the node\n");
    printf(" 5. Find a node and insert a new node after the node\n");
    printf(" 6. Find the index of node\n");
    printf(" 7. Find and remove a node from list\n");
    printf(" 8. Remove the last node from the list\n");
    printf(" 9. Remove the first node from the list\n");
    printf("10. Display linked list data in reverse order\n");
    printf("\n");
    printf(" 0. Exit\n");
}

/**
 * @brief Main entry point to the program
 * @return  0:Execution succeeded
 * @internal
 *      History:
 *      2017.01.10      Initialize
 */
int main(){
    int menu_selection;		/* selected menu item */
    int search_data;		/* search node's data */
    int data;			/* new node's data */
    int ret;			/* hold the function return value */

    /* menu operation */
    while(1){
	/* Display linked list operation menu */
	print_menu();
	
	/* Get user input */
	printf("Enter menu index:");
	scanf("%d", &menu_selection);

	/* Hnadle the menu operation */
	switch(menu_selection){
	    case 1: /* Display linked list data */
		print_list();
		break;
	    case 2: /* Add a new node to the end of the list */
		printf("Enter a integer data for new node:");
		scanf("%d", &data);
		add_last(data);
		break;
	    case 3: /* Add a new node at the begining of the list */
		printf("Enter a integer data for new node:");
		scanf("%d", &data);
		add_begin(data);
		break;
	    case 4: /* Find a node and insert a new node before the node */
		printf("Enter data value of searching node:");
		scanf("%d", &search_data);
		printf("Enter a integer data for new node:");
		scanf("%d", &data);
		insert_before(search_data, data);
		break;
	    case 5: /* Find a node and insert a new node after the node */
		printf("Enter data value of searching node:");
		scanf("%d", &search_data);
		printf("Enter a integer data for new node:");
		scanf("%d", &data);
		insert_after(search_data, data);
		break;
	    case 6: /* Find the index of node */
		printf("Enter data value of searching node:");
		scanf("%d", &search_data);
		ret = find_index(search_data);
		if(ret == -1){
		    printf("Not found! (%d), List is empty\n", search_data);
		}
		else if(ret == -2){
		    printf("Not found! (%d)\n", search_data);
		}
		else{
		    printf("Index of the searched node is: %d\n", ret);
		}
		break;
	    case 7: /* Find and remove a node from list */
		printf("Enter data value of searching node:");
		scanf("%d", &search_data);       
		find_and_remove(search_data);
		break;
	    case 8: /* Remove the last node from the list */
		remove_last();
		break;
	    case 9: /* Remove the first node from the list */
		remove_begin();
		break;
	    case 10: /* Display linked list data in reverse order */
		printf("Reverse linked list >> ");
		print_list_reverse(root);
		printf("\n");
		break;
	    case 0: /* Exit operations  */
		goto EXIT;
		break;
	    default:
		printf("Invalid menu selection\n");
		break;
	}
    }

EXIT:
    memory_free(root);
    return 0;
}

