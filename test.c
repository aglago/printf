#include <stdio.h>

void reverseString(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int intToCharArray(int num, char *result) {
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return 1; // Return the length of the string (1 digit)
    }

    int isNegative = 0;
    int length = 0;

    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    while (num > 0) {
        result[length++] = num % 10 + '0';
        num /= 10;
    }

    if (isNegative) {
        result[length++] = '-';
    }

    result[length] = '\0';
    reverseString(result, length);

    return length;
}

int main() {
    int number1 = 123;
    int number2 = -4567;

    char characterArray1[20]; // Choose an appropriate size for your use case
    char characterArray2[20];

    int length1 = intToCharArray(number1, characterArray1);
    int length2 = intToCharArray(number2, characterArray2);

    printf("Integer: %d, Character Array: %s (length: %d)\n", number1, characterArray1, length1);
    printf("Integer: %d, Character Array: %s (length: %d)\n", number2, characterArray2, length2);

    return 0;
}

