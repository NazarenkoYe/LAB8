#include <stdio.h>
#include <string.h>


long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
long long countanagrams(char *word) {
    int len = strlen(word);
    int count[26] = {0};
    for (int i = 0; i < len; ++i) {
        count[word[i] - 'A']++;
    }
    long long result = factorial(len);
    for (int i = 0; i < 26; ++i) {
        if (count[i] > 1) {
            result /= factorial(count[i]);
        }
    }
    return result;
}
int main() {
    char word[15];
    printf("Enter a word: ");
    scanf("%s", word);
    long long numanagrams = countanagrams(word);
    printf("Number of anagrams: %lld\n", numanagrams);
    return 0;
}

