#include "binary_trees.h"
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *header = NULL;

	if (array == NULL)
		return (NULL);

	if (nodes_binary(array, 0, (int)size - 1, &header) == NULL)
		return (NULL);
	return (header);
}
/**
 * nodes_binary - create binary tree
 * @array: pointer to the first element of the array to be converted
 * @first: initial
 * @last: final
 * @header: header node
 * Return: new node
 */
avl_t *nodes_binary(int *array, int first, int last, avl_t **header)
{
	avl_t *new_node = NULL, *left = NULL, *right = NULL;
	int current;

	if (first > last)
		return (NULL);

	current = (last + first) / 2;

	nodes_binary(array, first, current - 1, &left);
	nodes_binary(array, current + 1, last, &right);

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = array[current];
	new_node->parent = NULL;
	new_node->left = left;
	new_node->right = right;

	if (left != NULL)
		left->parent = new_node;

	if (right != NULL)
		right->parent = new_node;

	*header = new_node;
	return (new_node);
}
