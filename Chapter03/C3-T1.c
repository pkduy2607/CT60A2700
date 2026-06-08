#include <stdio.h>

int main() {
    float usage, bill;
    printf("How much electricity did you this month?\n");
    scanf("%f", &usage);
    if(usage <= 500) 
        bill = 0.18 * usage;
    else if(usage <= 1000)
        bill = 90 + 0.21 * (usage - 500);
    else 
        bill = 90 + 105 + 0.25 * (usage - 1000);
    printf("Total electricity bill this month is %.2f EUR.\n", bill);

    return 0;
}