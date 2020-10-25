
#include <stdlib.h>

int main(int argc, char** argv) {
	int* arr= (int*)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		arr[i] = i;

	free(arr);
	free(arr);

	return EXIT_SUCCESS;
}