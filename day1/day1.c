#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSIZE 1024
#define FILENAME "input.txt"

int file_length();
void create_array(int **expenses, int n);
int add_two_expenses(int *expenses, int n);
int add_three_expenses(int *expenses, int n);

int main(int argc, char const *argv[]) {
    int lines = file_length();
    int *expenses;
    create_array(&expenses, lines);

    time_t end1, start1 = clock();
    add_two_expenses(expenses, lines);
    end1 = clock();
    printf("Time usage add_two_expenses: %f ms\n", ((double)1000*(end1 - start1)) / CLOCKS_PER_SEC);

    time_t end2, start2 = clock();
    add_three_expenses(expenses, lines);4
    end2 = clock();
    printf("Time usage add_three_expenses: %f ms\n", ((double)1000*(end2 - start2)) / CLOCKS_PER_SEC);

    free(expenses);
    return 0;
}

int add_three_expenses(int *expenses, int n) {
    int currenti, currentj, sum, prod, idxi, idxj;
    idxi = 1;

    for (int i = 0; i < n; i++) {
        currenti = expenses[i];
        idxj = idxi + 1;
        for (int j = idxi; j < n; j++) {
            currentj = expenses[j];
            for (int k = idxj; k < n; k++) {
                sum = currenti + currentj + expenses[k];
                if (sum == 2020) {
                    prod = currenti * currentj * expenses[k];
                    break;
                }
            }

            idxj++;
        }

        idxi++;
    }

    return prod;
}

int add_two_expenses(int *expenses, int n) {
    int current, sum, prod, idx = 1;

    for (int i = 0; i < n; i++) {
        current = expenses[i];
        for (int j = idx; j < n; j++) {
            sum = current + expenses[j];
            if (sum == 2020) {
                prod = current * expenses[j];
                break;
            }
        }

        idx++;
    }
    return prod;
}

void create_array(int **expenses, int n) {
    *expenses = malloc(n * sizeof(*expenses));
    FILE *fp = fopen(FILENAME, "r");
    int current, counter = 0;

    while (fscanf(fp, "%d \n", &current)!=EOF) {
        (*expenses)[counter] = current;
        counter++;
    }

    fclose(fp);
}

int file_length() {
    FILE *fp = fopen(FILENAME, "r");
    char ch;
    int lines = 0;
    while ((ch=fgetc(fp))!=EOF) {
        if (ch == '\n')
            lines++;
    }

    fclose(fp);
    return lines;
}
