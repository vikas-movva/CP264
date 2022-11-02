/* repeat prompt for input
* HBF 
*/

#include <stdio.h>

int main(){
  // the following two lines are for Eclipse console buffered output
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  char c, temp;
  do {
    printf("Please enter a character\n");
    scanf("%c", &c);

    if (c == '*')
      break;
    else
      printf("%c %d\n", c, c);
  
    // get rid of the rest of input buffer
    // while(getchar()!= '\n'); 
    if (c != '\n') {
      do {  
        scanf("%c", &temp);
        if (temp == '\n') break;
      } while (1);
    }

  } while(1);
  return 0;
}

/*
Please enter a character
a
a 97
Please enter a character
b
b 98
Please enter a character
ab
a 97
Please enter a character
*
*/