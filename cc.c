/*******************************************************************************************
 *Program: 	Caesar cipher
 *Name: 	Sathya Ramanathan
 *Date: 	12/19/2016
 *Description:	Takes user input for a message via text or a file and either encrypts or 
		decrypts it using a shift cipher. Also asks for desired encryption key. 
		Allows user to save encrypted message to a file. Includes error handling. 
 *Version:	[1] (Problems creating read() helper function)
 ******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int encrypt(int key){
	int len, i, j, s;
	unsigned char p[256];
	printf("Enter a phrase to be encrypted: ");
	scanf(" %[^\t\n]s", &p);
	len = strlen(p);
	for(j = 0; j < len; j++){
		if(p[j] != ' '){
			if(!(isalpha(p[j]))){
				printf("Invalid input, enter a phrase consisting of (a-z): ");
				scanf("%s", &p);
			}
		}
		else{
			p[j] == ' ';
		}
	} 
	printf("Encrypted word is: ");
	for(i = 0; i < len; i++){
		p[i] = ((p[i] + key) <= 'z') ? (p[i] + key) : (p[i] + key - 26);
		printf("%c", p[i]);
	}
	printf("\n");	
	printf("Do you want to save this to a file? (1)yes / (2)no: ");
	scanf("%d", &s);
	if(s == 1){
		save(p);
		printf("Saved to e.txt\n");
	}
	else{
		printf("Bye!\n");
	}
}

int decrypt(int key){
	int len, i, j, k;
	char p[256];
	printf("Do you want to (1)read from a file or (2)enter a phrase?: ");
	scanf("%d", &k);
	if(k == 1){		
		printf("Reading from e.txt...\n");
		FILE *fptr;
		fptr = fopen("e.txt", "r");
		if(fptr == NULL){
			printf("Error!\n");
			exit(1);
		}
		fscanf(fptr, "%s", p);
		fclose(fptr);
		//*p == read();			return did not work
	}
	else{
		printf("Enter a phrase to be decrypted: ");
		scanf(" %[^\t\n]s", &p);
	}
	//printf("----------------%s\n", p);	test
	len = strlen(p);
	for(j = 0; j < len; j++){
		if(p[j] != '!'){	
			if(!(isalpha(p[j]))){
				printf("Invalid input, enter a phrase (a-z): ");
				scanf("%s", &p);
			}
		}
	} 
	printf("Decrypted phrase is: ");
	for(i = 0; i < len; i++){
		p[i] = ((p[i] - key) >= 'a') ? (p[i] - key) : (p[i] - key + 26);
		printf("%c", p[i]);
	}
	printf("\n");
}

int askey(){
	int key;
	printf("Enter key (1-25): ");
	scanf("%d", &key);
	while(!(key >= 1 && key <= 25)){
		printf("Invalid input, enter (1-25): ");
		scanf("%d", &key);
	}
	return key;
}

int save(char *p){
	FILE *fptr;	
	fptr = fopen("e.txt", "w+");
	if(fptr == NULL){
		printf("Error!\n");
		exit(1);
	}
	fprintf(fptr, "%s", p);
	fclose(fptr);
}

int main(){
	system("clear");
	int ans;
	printf("Welcome to Caesar Cipher\n");
	printf("Enter (1)to encrypt or (2)to decrypt: ");
	scanf("%d", &ans);					//%*c allows fgets() to work
	while(ans != 1 && ans != 2){
		printf("Invalid input, enter 1 or 2: ");
		scanf("%d", &ans);
	}
	if(ans == 1){
		encrypt(askey());		
	}
	else{	
		decrypt(askey());		
	}

	return 0;
}

