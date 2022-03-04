#include "menger.h"

void print_level(int level, int size);

/**
 * menger - draws 2D Menger
 * @level: level of the Menger
 *
 */

void menger(int level)
{
	int size = pow(3, level), row = 0, column = 0, n = 1;
	int draw = pow(3, 0), r_remain = 0, c_remain = 0;

	if (level < 0)
		return;
	if (level == 0)
		printf("#\n");
	if (level > 0)
	{
		for (row = 0; row < size; row++)
		{
			for (column = 0; column < size; column++)
			{
				n = 1;
				for (draw = 1; draw < size; draw *= 3)
				{
					r_remain = ((row / draw) % 3) == 1;
					c_remain = ((column / draw) % 3) == 1;
					if (r_remain && c_remain && n)
						n = 0;
				}
				if (n)
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
