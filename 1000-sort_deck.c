#include <stdlib.h>
#include "deck.h"

/*create a function that compares 2 strings*/
int _strcmp(const char *s1,const char *s2);
/**
*_strcmp - compares two strings
*@s1: string 1
*@s2: string 2
*
*Return: *s1 - *s2
*/

/**
*_strcmp - compares two strings
*@s1: string 1
*@s2: string 2
*
*Return: *s1 - *s2
*/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/*create a compare fuinction for qsort*/
int compare_cards(const void *a, const void *b);
/*This function will establish the order of cards*/
/*based,on their kind and value*/
/*the function takes in 2 pointers to deck_node elements*/
/*it dereferences them to get the actual node, then*/
/*get the actual pointers to the cards*/
/**
*@a: pointer to a deck_node element a
*@b: pointer to a deck_node element b
*
*Return: negative if a is less than b,
*	positive if greater,
*	zero if equal
*/
int compare_cards(const void *a, const void *b)
{
	deck_node_t *node_a = *(deck_node_t **)a;
	deck_node_t *node_b = *(deck_node_t **)b;
	int value_a = node_a->card->kind;
	int value_b = node_b->card->kind;

	if (value_a != value_b)
	{
		return (value_a - value_b);
	}
	return (_strcmp(node_a->card->value, node_b->card->value));
}
/*sorting function*/
/**
*sort_deck- sorts out the cards as per criteria
*@deck: this is a pointer to a pointer to the card deck
*
*Return: Nothing
*/
void sort_deck(deck_node_t **deck)
{
	/*start by counting the number of cards in the deck*/
	int i = 0, j = 0;
	int no_of_cards = 0;
	deck_node_t **card_array;
	deck_node_t *current_card = *deck;
	deck_node_t *current = *deck;

	while (current_card != NULL)
	{
		no_of_cards++;
		current_card = current_card->next;
	}
	/*then create an array of pointers to the DS elements*/
	card_array = (deck_node_t **)malloc(no_of_cards
		* sizeof(deck_node_t *));
	if (card_array == NULL)
	{
		return;
	}
	while (current != NULL)
	{
		card_array[i] = current;
		current = current->next;
		i++;
	}
	/*proceed to sort the array using qsort*/
	qsort(card_array, no_of_cards, sizeof(deck_node_t *),
		compare_cards);

	/*rearrange the linked list based on the resulting array*/
	for (j = 0; j < no_of_cards - 1; j++)
	{
		card_array[j]->next = card_array[j + 1];
		card_array[j + 1]->prev = card_array[j];
	}
	card_array[0]->prev = NULL;
	card_array[no_of_cards - 1]->next = NULL;
	/*After this you need to update the pointer to*/
	/*the deck to point to the new head of the */
	/*sorted deck*/
	*deck = card_array[0];
	/*next, frree up the temporary memory allocated*/
	/*through malloc*/
	free(card_array);
}
