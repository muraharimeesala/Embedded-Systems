#include <stdio.h>
#include <ctype.h>
int main() {
	int ch, vowels = 0, consonants = 0;
    	FILE *fp = fopen("input.txt", "r");
    	if (!fp) { perror("fopen"); return 1; }
	while ((ch = fgetc(fp)) != EOF) {
		if (isalpha(ch)) {
			ch = tolower(ch);
		       		if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
		    			vowels++;
			       	}
				else{
					consonants++;
				}
		}
	}
	printf("Vowels = %d\nConsonants = %d\n", vowels, consonants);
     	fclose(fp);
       	return 0;
}

