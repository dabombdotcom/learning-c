#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* All of this could be done easier if I use functions from string.h
 * but then what would be the point of learning?
 * I'm going to use strlen only
*/

int check_if_vowel (char test);
void handle_vowel (char str[]);
void handle_consonant (char str[]);

const char vsuff[] = "yay";
const char csuff[] = "ay";
const char vowels[] = "aeiou";


int main (int argc, char *argv[]) {
   if (argc > 1) {
      // Argv from positions 1 on will contain words we need to convert
      int itr;
      for (itr = 1; itr < argc; itr++) {
         char first = argv[itr][0];
         if (check_if_vowel(first) == 0) {
            // first is a vowel, and so we will need to handle a vowel
            handle_vowel(argv[itr]);
         } else {
            handle_consonant(argv[itr]);
         }
         printf(" ");
      }
      printf("\n");
   } else {
      return 1;
   }
}

int check_if_vowel (char test) {
   int itr;
   for (itr = 0; itr < strlen(vowels); itr++) {
      if (test == vowels[itr]) {
         return 0;
      }
   }
   return 1;
}

void handle_vowel (char str[]) {
   // So it's a vowel, we just need to add the suffix for vowels
   char latin[strlen(str) + strlen(vsuff)];
   int itr;
   for (itr = 0; itr < strlen(str); itr++) {
      latin[itr] = str[itr];
   }

   int itr2;
   for (itr2 = 0; itr2 < strlen(vsuff); itr2++) {
      latin[itr] = vsuff[itr2];
      itr++;
   }
   printf("%s", latin);
   memset(latin, 0, sizeof(latin));
}

void handle_consonant (char str[]) {
   // It's a consonant (or a number, since I'm not sanitizing). We need to move the firt
   // letter to the end, and add the suffix

   char latin[strlen(str) + strlen(csuff)];
   int itr;
   for (itr = 1; itr < strlen(str); itr++) {
      latin[itr - 1] = str[itr];
   }
   latin[itr - 1] = str[0];
   itr++;

   int itr2;
   for (itr2 = 0; itr2 < strlen(csuff); itr2++) {
      latin[itr - 1] = csuff[itr2];
      itr++;
   }
   printf("%s", latin);
   memset(latin, 0, sizeof(latin));
}
