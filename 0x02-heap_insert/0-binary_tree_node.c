#include "binary_trees.h"

/**
 * binary_tree_node - binary tree node
 * @parent: parent node of the node to create
 * @value: put in the new node
 *
 * Return: function that creates a binary tree node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL) 
    {
        return (NULL);
    }
		
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent)
    {
        new_node->parent = parent;
    }

	return (new_node);
}