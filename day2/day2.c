#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define FILENAME "input.txt"

int old_valid();
int new_valid();

int main(int argc, const char *argv[]) {
    int old = old_valid();
    printf("%d\n", old);

    int new = new_valid();
    printf("%d\n", new);
    return 0;
}

int new_valid() {
    FILE *fp = fopen(FILENAME, "r");
    char buffer[BUFSIZE];
    char foo, bar, target;
    int lower, upper, counter, valid=0;

    while (fscanf(fp, "%d %c %d %c %c %s\n", &lower, &foo, &upper, &target, &bar, buffer)!=EOF) {
        --lower;
        --upper;
        if (buffer[lower] == target && buffer[upper] != target) {
            valid++;
        } else if (buffer[lower] != target && buffer[upper] == target) {
            valid++;
        }
    }

    fclose(fp);
    return valid;
}

int old_valid() {
    FILE *fp = fopen(FILENAME, "r");
    char buffer[BUFSIZE];
    char foo, bar, target;
    int lower, upper, counter, valid=0;

    while (fscanf(fp, "%d %c %d %c %c %s\n", &lower, &foo, &upper, &target, &bar, buffer)!=EOF) {
        counter = 0;
        size_t length = strlen(buffer);
        for (int i = 0; i < length; i++) {
            if (buffer[i] == target) {
                counter++;
            }
        }
        if (counter >= lower && counter <= upper)
            valid++;
    }


    fclose(fp);
    return valid;
}
