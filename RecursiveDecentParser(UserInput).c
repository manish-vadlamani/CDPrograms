#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include <ctype.h>

#define MAX_RULES 10
#define MAX_LEN 100

bool isNonTerminal(char c) {
    return isupper(c);
}

bool isCFG(char rules[MAX_RULES][MAX_LEN], int numRules) {
	int i,j;
    for (i = 0; i < numRules; i++) {
        if (!isNonTerminal(rules[i][0]) || rules[i][1] != '-' || rules[i][2] != '>') {
            return false;
        }
        for (j = 3; rules[i][j] != '\0'; j++) {
            if (!isNonTerminal(rules[i][j]) && !islower(rules[i][j]) && rules[i][j] != '|' && rules[i][j] != ' ' && strcmp(&rules[i][j], "epsilon") != 0 && strcmp(&rules[i][j], "eps") != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int numRules;
    char rules[MAX_RULES][MAX_LEN];
    printf("Enter the number of production rules: ");
    scanf("%d", &numRules);
    printf("Enter the production rules:\n");
    for (int i = 0; i < numRules; i++) {
        printf("Rule %d: ", i + 1);
        scanf(" %[^\n]", rules[i]);
    }
    if (isCFG(rules, numRules)) {
        printf("The grammar is a context-free grammar.\n");
    } else {
        printf("The grammar is not a context-free grammar.\n");
    }
    return 0;
}
