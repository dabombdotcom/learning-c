#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
   if (argc > 1) {
      char *front = argv[argc - 1];
      char back[strlen(front) + 1];

      printf("Init with string: %s\n", front);
      
      int itr = 0;
      int len;
      for (len = strlen(front) - 1; len >= 0; len--) {
         back[itr] = front[len];
         itr++;
      }

      printf("Return: %s\n", back);
   } else {
      return 1;
   }

   return 0;
}
