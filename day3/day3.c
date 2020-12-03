#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define FILENAME "input.txt"

void fill_map(char ***map, int length, int width);
int map_length();
int map_width();
int count_trees(char **map, int length, int width, int increment, int jcrement);

int main(int argc, const char *argv[]) {
	int length = map_length();
	int width = map_width();
	char **map;
	fill_map(&map, length, width);
	int slope1, slope2, slope3, slope4, slope5;
	slope1 = count_trees(map, length, width, 1, 1);
	slope2 = count_trees(map, length, width, 1, 3);
	slope3 = count_trees(map, length, width, 1, 5);
	slope4 = count_trees(map, length, width, 1, 7);
	slope5 = count_trees(map, length, width, 2, 1);
	printf("Slope 1: %d trees\n", slope1);
	printf("Slope 2: %d trees\n", slope2);
	printf("Slope 3: %d trees\n", slope3);
	printf("Slope 4: %d trees\n", slope4);
	printf("Slope 5: %d trees\n", slope5);

	return 0;
}

int count_trees(char **map, int length, int width, int increment, int jcrement) {
	int trees = 0;
	int j = jcrement;
	for (int i = increment; i < length; i += increment) {
		if (map[i][j] == '#')
			trees++;

		j += jcrement;
		if (j >= 31)
			j %= 31;
	}

	return trees;
}

void fill_map(char ***map, int length, int width) {
	*map = calloc(length, sizeof **map);
	(*map)[0] = calloc(width*length, sizeof *(*map[0]));
	for (int i = 1; i < length; i++) {
		(*map)[i] = &((*map)[0][i*width]);
	}

	FILE *fp = fopen(FILENAME, "r");

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			(*map)[i][j] = fgetc(fp);

		fgetc(fp);
	}

	fclose(fp);

}

int map_length() {
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

int map_width() {
	FILE *fp = fopen(FILENAME, "r");
	char ch;
	int chars = 0;
	while ((ch=fgetc(fp))!='\n') {
		chars++;
	}

	fclose(fp);
	return chars;
} 