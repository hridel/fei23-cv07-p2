#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size;
    printf("Zadejte velikost pole: ");
    scanf("%d", &size);

    // dynamically allocate memory for array
    int *arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) { // check if allocation was successful
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL)); // initialize random seed
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    printf("Vygeneroval jsem tato čísla:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    FILE *fp = fopen("data.bin", "wb"); // open binary file for writing
    if (fp == NULL) { // check if file was opened successfully
        printf("Otevreni souboru selhalo.\n");
        return 1;
    }

    fwrite(&size, sizeof(int), 1, fp); // write size of array to file
    fwrite(arr, sizeof(int), size, fp); // write array to file
    fclose(fp); // close file
    free(arr);

    fp = fopen("data.bin", "rb");
    fread(&size, sizeof(int), 1, fp);
    int *arr2 = (int*) malloc(size * sizeof(int));
    fread(arr2, sizeof(int), size, fp);
    fclose(fp);

    printf("\n\nV souboru jsou uložena tato čísla:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }

    free(arr2);


    return 0;
}
