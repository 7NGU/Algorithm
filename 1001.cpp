#include <stdio.h>

int main() {
    int n;
    char c[110];
    scanf("%d", &n);
    fgets(c, 110, stdin);
    for(int i=0; i<n; i++) {
        int count = 0;
        fgets(c, 109, stdin);
        for(int j=0; c[j]!='\0'; j++) {
            if('0'<=c[j] && c[j]<='9') {
                count++;
            }
        }
        printf("%d\n", count);
    }
}
