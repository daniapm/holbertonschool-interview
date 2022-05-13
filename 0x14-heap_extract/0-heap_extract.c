#include "binary_trees.h"
/**
 * get_tree_size - gets the size of the tree
 * @root: pointer to the first node of the tree
 * Return: size of the tree
 **/
int get_tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + get_tree_size(root->left) + get_tree_size(root->right));
}
/**
 * swap - swaps
 * @a: node to swap value
 * @b: node to swap value
 * Return: the first given node
 **/
heap_t *swap(heap_t *node, heap_t *node1)
{
	node->n = node->n * node1->n;
	node1->n = node->n / node1->n;
	node->n = node->n / node1->n;
	return (node);
}
/**
 * get_node - returns the last node
 * @root: pointer to the root node
 * @size: size of the tree
 *
 * Return: the found node ptr
 **/
heap_t *get_node(heap_t *root, int size)
{
	int idx, mask  = 0;

	for (; 1 << (idx + 1) <= size; idx++)
		;
	for (idx--; idx >= 0; idx--)
	{
		mask = 1 << idx;
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heapify - converts the tree into a max heap tree
 * @root: pointer to the root node
 */
void heapify(heap_t *root)
{
	heap_t *max;
	int first = 0;

    if (!root)
	    return;
	while (max || !first)
	{
		max = NULL;
		first = 1;
		if (root->left && root->left->n > root->n)
			max = root->left;
		if (root->right && root->right->n > root->n &&
				(max && root->right->n > max->n))
			max = root->right;
		if (max)
			root = swap(max, root);
	}
}
/**
 * heap_extract - extracts the root
 * @root: is a double pointer to the root
 * Return: the value stored in the root node, otherwise 0
 */
int heap_extract(heap_t **root)
{
	int max = (*root)->n;
	int size = get_tree_size(*root);
	heap_t *last_node = get_node(*root, size);

	swap(last_node, *root);
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);
	heapify(*root);
	return (max);
}
