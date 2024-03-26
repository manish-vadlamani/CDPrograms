#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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
    int numRules = 4;
    char rules[MAX_RULES][MAX_LEN] = {
        "S-> Ab",
        "A-> a",
        "B-> b | epsilon",
        "C-> Cc | D",
    };

    if (isCFG(rules, numRules)) {
        printf("The grammar is a context-free grammar.\n");
    } else {
        printf("The grammar is not a context-free grammar.\n");
    }
    return 0;
}
