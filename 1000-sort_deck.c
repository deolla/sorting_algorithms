#include "deck.h"

/**
 * compare_cards - Helper function that comapares cards for qsort.
 * @a: first card.
 * @b: second card.
 *
 * Return: The result of the comapred cards.
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = *((const card_t **)a);
	const card_t *card_b = *((const card_t **)b);
	const char *values[] = { "Ace", "2", "3", "4", "5", "6", "7",
				 "8", "9", "10", "Jack", "Queen", "King"
				};
	int value_a, value_b, i;

	if (card_a->kind != card_b->kind)
	{
		return (card_a->kind - card_b->kind);
	}
	else
	{
		value_a = 0;
		value_b = 0;

		for (i = 0; i < 13; i++)
		{
			if (strcmp(card_a->value, values[i]) == 0)
			{
				value_a = i;
			}
			if (strcmp(card_b->value, values[i]) == 0)
			{
				value_b = i;
			}
		}
		return (value_a - value_b);
	}
}

/**
 * sort_deck - Convert the deck to an array and sort it.
 * @deck: The deck.
 */
void sort_deck(deck_node_t **deck)
{
	int num_cards = 0;
	const card_t **cards_array;
	int i;
	deck_node_t *current = *deck;

	while (current != NULL)
	{
		num_cards++;
		current = current->next;
	}
	cards_array = malloc(num_cards * sizeof(card_t *));
	if (cards_array == NULL)
	{
		return;
	}
	current = *deck;
	for (i = 0; i < num_cards; i++)
	{
		cards_array[i] = current->card;
		current = current->next;
	}
	qsort(cards_array, num_cards, sizeof(card_t *), compare_cards);

	current = *deck;
	for (i = 0; i < num_cards; i++)
	{
		current->card = cards_array[i];
		current = current->next;
	}
	free(cards_array);
}

/**
 * strcmp - compares strings.
 * @s1: first string.
 * @s2: secomd string.
 *
 * Return: the comapared string.
 */
int strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
