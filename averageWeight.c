#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_LENGTH 100

int main(void)
{
    char *ptr = NULL;
    char input[MAX_LENGTH + 1] = {0};
    float averageWeight = 0.0;
    char *tempString = NULL;
    uint32_t totleLength = 0;
    uint32_t number = 0;
    printf("please input string :");
    gets(input);
    ptr = input;
    do {
        tempString = strtok(ptr, " ");
        if (tempString) {
            printf("tempString = %s\n", tempString);
            ptr = ptr + strlen(tempString) + 1;
            totleLength += strlen(tempString);
            number += 1;
        }
    } while (tempString);
    averageWeight = (float)totleLength / (float)number;
    printf("averageWeight = %.2f\n", averageWeight);
    return 0;
}
