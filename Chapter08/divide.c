#include <stdio.h>
#include "divide.h"

float divide(int a, int b) {
    if(b == 0) {
        puts("Error: Division by zero");
        return 0.0;
    }
    return (float)a / b;
}