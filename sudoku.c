#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int** matrix = NULL;

int CheckRow(int row) {

	int check[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 9; i++) {
		check[(matrix[row][i])] ++;
		if (check[matrix[row][i]] > 1) {
			return 0;
		}
	}
	return 1;

}

int CheckColumn(int column) {
	int check[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 9; i++) {
		check[matrix[i][column]] ++;
		if (check[matrix[i][column]] > 1) {
			return 0;
		}
	}

	return 1;
}

int CheckBox(int box) {

	int row, column;
	switch (box) {
	case 0: row = 0; column = 0; break;
	case 1: row = 0; column = 3; break;
	case 2: row = 0; column = 6; break;
	case 3: row = 3; column = 0; break;
	case 4: row = 3; column = 3; break;
	case 5: row = 3; column = 6; break;
	case 6: row = 6; column = 0; break;
	case 7: row = 6; column = 3; break;
	case 8: row = 6; column = 6; break;
	default: return 0;
	}

	int check[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = row; i < row + 3; i++) {
		for (int j = column; j < column + 3; j++) {
			check[matrix[i][j]] ++;
			if (check[matrix[i][j]] > 1) {
				return 0;
			}
		}
	}
	return 1;
}

int CheckSudoku() {

	int total = 0;
	for (int i = 0; i < 9; i++) {
		total += CheckRow(i);
		total += CheckColumn(i);
		total += CheckBox(i);

		if (total != 3) {
			return 0;
		}
		total = 0;
	}

	return 1;
}

int SolveSudoku(int firstSpace, int secondSpace) {

	int rowone = firstSpace / 10;
	int rowtwo = secondSpace / 10;
	int columnone = firstSpace % 10;
	int columntwo = secondSpace % 10;
	int countone[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int counttwo[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i;

	if (rowone == rowtwo) {

		for (i = 0; i < 9; i++) {
			countone[matrix[i][columnone]] ++;
			counttwo[matrix[i][columntwo]] ++;

			if (countone[matrix[i][columnone]] > 1 || counttwo[matrix[i][columntwo]] > 1) {
				return 0;
			}
		}

		for (i = 1; i < 10; i++) {
			if (countone[i] == 0) {
				matrix[rowone][columnone] = i;
			}
			if (counttwo[i] == 0) {
				matrix[rowtwo][columntwo] = i;
			}
		}

	}
	else {

		for (i = 0; i < 9; i++) {
			countone[matrix[rowone][i]] ++;
			counttwo[matrix[rowtwo][i]] ++;

			if (countone[matrix[rowone][i]] > 1 || counttwo[matrix[rowtwo][i]] > 1) {
				return 0;
			}

		}

		for (i = 1; i < 10; i++) {
			if (countone[i] == 0) {
				matrix[rowone][columnone] = i;
			}
			if (counttwo[i] == 0) {
				matrix[rowtwo][columntwo] = i;
			}
		}

	}

	if (CheckSudoku() == 1) {
		return 1;
	}

	return 0;

}

FILE* ReadFile(char** argv, int argc)
{
	FILE* fp;
	// before if argc = 2, readfile, wont work if 1
	
	// changed part !!!
if(argc == 2){
	fp = fopen(argv[1], "r");}
	
	
	return fp;
}
int main(int argc, char** argv) {


	FILE* fp = ReadFile(argv, argc);
	
	
	matrix = (int**)malloc(sizeof(int*) * 10);

	int i;
	for (i = 0; i < 10; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * 10);
	}

//	fp = fopen(filename, "r");

	

	char input = 0;
	int row = 0, column = 0, mode = 0, isFirstSpace = 1; // mode=0 -> Check, mode=1 -> solve
	int firstSpace = 0, secondSpace = 0;

	while (fscanf(fp, "%c", &input) == 1) {

		if (input == '\n') continue; // New Line Control

		if (isdigit(input)) {
			int x = input - '0';
			if (x == 0) {
				printf("error\n");
				return 0;
			}
			matrix[row][column] = x;
		}
		else {
			if (input == ' ') {
				matrix[row][column] = 0;
				mode = 1;
				if (isFirstSpace == 1) {
					firstSpace = row * 10 + column;
					isFirstSpace = 0;
				}
				else {
					secondSpace = row * 10 + column;
				}
			}
		}
		column++;

		if (column == 9) {
			column = 0;
			row++;
		}
	}

	if (mode == 0) {
		if (CheckSudoku() != 1) {
			printf("incorrect\n");
			return 0;
		}
		else {
			printf("correct\n");
			return 0;
		}
	}
	else if (mode == 1) {
		if (SolveSudoku(firstSpace, secondSpace) == 1) {
			printf("solvable\n");
			return 0;
		}
		else {
			printf("unsolvable\n");
			return 0;
		}
	}
	fclose(fp);
	
	for(int i = 0; i < 10; i++){
    free(matrix[i]);}
free(matrix);
	
	return 0;}

// BURAYA FREEEE KOY 
