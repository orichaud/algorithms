#include <stdio.h>
#include <string.h>

void reverse(char *s) {
    unsigned int l =  strlen(s);
    if(l > 0) {
        for(char *b = s, *e = s + (l - 1); b < e; b++, e--) {
            char tmp = *e;
            *e = *b;
            *b = tmp;
        }
    }
}

int main() {
    char s[256];
    strcpy(s,"abcdefghijklmnopqrstuvwxyz1234567890");
    printf("%s => ", s);
    reverse(s);
    printf("%s\n", s);
    
    return 0;
}