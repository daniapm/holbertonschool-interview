#ifndef HEAP_SORT
#define HEAP_SORT

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_sort(int *x, int *y);
void get_down(int *array, int idx, int size, int len);

#endif
