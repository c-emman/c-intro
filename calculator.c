#include <stdio.h>

int computeOp(char p, char *cOp, int *rSum, int *cNum, char *cumOp, int *cSum);
// 3 + 5 * 2 - 1
// cOp = +; rSum = 3;

int flushCumSum(int *cNum, char *cumOp, int *cSum);

int flushCumSum(int *cNum, char *cumOp, int *cSum) {
	if (*cumOp != '\0') {
		*cSum = *cumOp == '*' ? *cSum * *cNum : *cSum / *cNum;
		*cNum = *cSum;
		*cumOp = '\0';
		*cSum = 0;
	}
	return 0;
}



int computeOp(char p, char *cOp, int *rSum, int *cNum, char *cumOp, int *cSum) {
	if ( p == '+' || p == '-' ) {
		if (*cOp == '\0') {
			*cOp = p == '+' ? '+' : '-';
			flushCumSum(cNum, cumOp, cSum);
			*rSum += *cNum;
			*cNum = 0;
		}
		else if (*cOp == '+' || *cOp == '-') {
			flushCumSum(cNum, cumOp, cSum);
			*rSum = *cOp == '+' ? *rSum + *cNum : *rSum - *cNum;
			*cNum = 0;
			*cOp = p;
		}
	}
	else if ( p == '/' || p == '*' ) {
		if (*cumOp == '\0') {
			*cumOp = p == '*' ? '*' : '/';
			*cSum = *cNum;
			*cNum = 0;
		}
		else if (*cumOp == '*' || *cumOp == '/') {
			*cSum = *cumOp == '*' ? *cSum * *cNum : *cSum / *cNum;
			*cumOp = p;
			*cNum = 0;
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
	char cumutativeOp = '\0';
	int cumutativeSum = 0;

	printf("Type in a sum into the calculator \n");
	scanf("%255s", inputNum );

	for (char *p = inputNum; *p != '\0'; p++) {
		computeOp(*p, &currentOp, &rollingSum, &currentNum, &cumutativeOp, &cumutativeSum);
	}
	
	flushCumSum(&currentNum, &cumutativeOp, &cumutativeSum);
	if (currentOp != '\0'){
		rollingSum = currentOp == '+' ? rollingSum + currentNum : rollingSum - currentNum;
	} else {
		rollingSum = currentNum;
	}
	
	printf("Answer:::: ");
	printf("%d", rollingSum);
	printf("\n");
	return 0;

}
