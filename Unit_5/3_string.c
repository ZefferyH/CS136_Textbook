// string, string initialization, string.h, string functions

#include <stdio.h>
#include <string.h>
#include <assert.h>

// char_count(c, s) counts the number of c that appear in the string s
int char_count(const char c, const char *s) { 
    assert(s);
    int count = 0;
    /* BAD implementation: O(n^2) time <- See chapter 7 for efficiency
    for (int i = 0; i < strlen(s); ++i) {
  	    if (s[i] == c) ++count;
    }
    */
    // GOOD implementation: O(n) time
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
  	    if (s[i] == c) ++count;
    }

  return count;
}

// string in c is an array of characters, terminated by the NULL character.

int main(void)
{
    // string initialization
    char a[4] = {'c', 'a', 't', '\0'};
    char b[4] = {'c', 'a', 't', 0};
    char c[4] = {'c', 'a', 't'};
    char d[4] = {99, 97, 116, 0};
    char e[] = "cat";
    char f[4] = "cat\0";
    // all a-f initialzed the exact same string.

    // '\0', 0, or putting nothing at all, represents the Null terminator. 

    // strlen(s)L a function in string.h, which returns the length of s, doesn't include the NULL terminator.

    // Lexicographical order:
    // Do not use == to compare strings. It compares the address, which is meaningless.
    // strcmp(s1,s2) from string.h, returns 0 if s1 and s2 are identical, if s1 precedes s2,
    // it returns a negative integer, and positive otherwise (think of it returns s1 - s2)

    // Copy strings:
    // strcpy(dest, src) overwrites whats in *dest with the content of *src, and returns the address of dest.
    char s[15] = "spam";
    strcpy(s + 4, s); // should be spamspam, or not?
    printf("Not what you expect: %s",s);
    // this is very dangerous as strcpy overwrites the null terminator in s, 
    // which cause strcpy tries to add "spam" to s without stopping.
    
    // Appending strings:
    // strcat(dest,src) from string.h, appends src to the end of dest.
}