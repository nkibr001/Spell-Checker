#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#pragma warning(disable:4996)

int binsearch(char* dictionaryWords[], int listSize, char* keyword)
{
	int mid, low = 0, high = listSize - 1;
	while (high >= low) 
	{
		mid = (high + low) / 2;
		if (strcmp(dictionaryWords[mid], keyword) < 0)
			low = mid + 1;
		else if (strcmp(dictionaryWords[mid], keyword) > 0)
			high = mid - 1;
		else
			return mid;
	}
	return -1; //not found
}

int spellCheck(char* word, char* dictionaryFileName)
{
	FILE* inFile = NULL;
	//inFile = fopen("dictionary.txt", "r");
	inFile = fopen(dictionaryFileName, "r");
	if (inFile == NULL)
	{
		printf("Couldn't open dictionary.\n");
		return;
	}
	char* dictionaryWords[93512];
	char temp[200];

	for (int i = 0; i < 93512; i++) {
		fscanf(inFile, "%199s ", &temp);
		size_t len = strlen(temp); //size in bytes for malloc
		dictionaryWords[i] = (char*)malloc(len + 1);
		strcpy(dictionaryWords[i], temp);
	}

	int x=(binsearch(dictionaryWords, 93512, word));
	return x;
}

int main(void)
{
	printf("Enter the word to spell check:\n");
	char word[50];
	fgets(word, 50, stdin);
	strtok(word, "\n");
	printf("\n");
	//const char* text = "dictionary.txt";

	printf("Enter the dictionary file:\n");
	const char text[100];
	fgets(text, 50, stdin);
	strtok(text, "\n");
	printf("\n");

	int check = spellCheck(word, text);

	if (check == -1)
	{
		printf("Spelled incorrectly!\n");
		printf("0\n");
	}
	else
	{
		printf("Spelled Correctly!\n");
		printf("Located at %d\n", check);
	}

}