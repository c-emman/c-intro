#include <stdio.h>

int computeOp(char p, char *cOp, int *rSum, int *cNum);

int computeOp(char p, char *cOp, int *rSum, int *cNum) {
	if ( p == '+' || p == '-') {
		if (*cOp == '\0') {
			*cOp = p == '+' ? '+' : '-';
			*rSum = *cNum;
			*cNum = 0;
		}
		else if (*cOp == '+' || *cOp == '-') {
			*rSum = *cOp == '+' ? *rSum + *cNum : *rSum - *cNum;
			*cNum = 0;
			*cOp = p;
		}
	}
        else {
                *cNum = *cNum * 10 + (p - '0');
        }
        return 0;
}

int main(void) 
{
	// What i want to do really is loop through the numbers. 
	char inputNum[256];
	int currentNum = 0;
	int rollingSum = 0;
	char currentOp = '\0';

	printf("Type in a sum into the calculator \n");
	scanf("%255s", inputNum );

	for (char *p = inputNum; *p != '\0'; p++) {
		computeOp(*p, &currentOp, &rollingSum, &currentNum);
	}
	
	if ( currentOp == '+' ) {
		rollingSum += currentNum;
	}
	else if (currentOp == '-') {
		rollingSum -= currentNum;
	}
	printf("Answer:::: ");
	printf("%d", rollingSum);
	printf("\n");
	return 0;

}
