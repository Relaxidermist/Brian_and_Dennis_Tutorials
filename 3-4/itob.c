/*
Code to test the itob function.
This is my solultion to Exercise 3-3 of "The C Programming Language"
by Brian W. Kernighan and Dennis M. Ritchie.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define LOWLIMIT -2147483648
#define HIGHLIMIT 2147483647

char s[MAX];

// Function declaration
int itoh(int n, char* s);
int itob(int n, char* s);
void reverse(char* s);

int main(void)
{
  // Convert an integer to a string representation
  for(int i = LOWLIMIT; i <= HIGHLIMIT; i++)
  {
    itoh(i, s);

    puts(s);
  }

  return EXIT_SUCCESS;
}

// Integer argument is converted to a string representation
int itoh(int n, char* s)
{
  int i, sign;
  int max = 1;
  int temp = 1;

  // Left shift to get max possible size for input int
  for(i=0 ; temp>0; i++)
  {
    max = temp;
    temp = (temp << 1) + 1;
  }

  // Check if input is greater in magnitude than max value for positive
  // integer. If so, then return max negative.
  if(((sign = n) < 0) && ((-max) > n))
  {
    sprintf(s, "-80000000");

    return EXIT_SUCCESS;

  } else if((sign = n) < 0)
  {
    n = -n;
  }

  i = 0;

  // Find remainder of division by 10 and add to ASCII code offset for
  // numeric symbols.
  // While there is still another order of magnitude, repeat the loop.
  do
  {
    s[i++] = n % 16 + '0';
  } while((n /= 16) > 0);

  // If the number was negative, then add a hyphen to the array.
  if(sign < 0)
  {
    s[i++] = '-';
  }
  // Add end of string character.
  s[i] = '\0';

  reverse(s);

  for(int i = 0; s[i]!='\0'; i++)
  {
    if(s[i] > 57)
    {
      s[i] += 7;
    }
  }

  return EXIT_SUCCESS;
}

// Integer argument is converted to a string representation
int itob(int n, char* s)
{
  int i, sign;
  int max = 1;
  int temp = 1;

  // Left shift to get max possible size for input int
  for(i=0 ; temp>0; i++)
  {
    max = temp;
    temp = (temp << 1) + 1;
  }

  // Check if input is greater in magnitude than max value for positive
  // integer. If so, then return max negative.
  if(((sign = n) < 0) && ((-max) > n))
  {
    sprintf(s, "-10000000000000000000000000000000");

    return EXIT_SUCCESS;

  } else if((sign = n) < 0)
  {
    n = -n;
  }

  i = 0;

  // Find remainder of division by 10 and add to ASCII code offset for
  // numeric symbols.
  // While there is still another order of magnitude, repeat the loop.
  do
  {
    s[i++] = n % 2 + '0';
  } while((n /= 2) > 0);

  // If the number was negative, then add a hyphen to the array.
  if(sign < 0)
  {
    s[i++] = '-';
  }
  // Add end of string character.
  s[i] = '\0';

  reverse(s);

  return EXIT_SUCCESS;
}

// Reverse a string of input chars
void reverse(char* s)
{
  int i, j;
  char temp[MAX];

  // Get length of input string
  for(i=0; s[i]!='\0'; i++);

  // Copy to reverse to temporary string
  for(j=0; j<=i; j++)
  {
    temp[j] = s[i-(j+1)];
  }

  temp[j] = '\0';

  // Copy reversed string back to original
  for(i=0; temp[i]!='\0'; i++)
  {
    s[i] = temp[i];
  }
}
