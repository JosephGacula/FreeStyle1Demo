#include <iostream>
#include <string>

bool isPowerOf2Loop(int);
void isPowerOf2LoopTester(int);
bool isPowerOf2NoLoop(int);
void isPowerOf2NoLoopTester(int);
bool isPrimeNumber(int);
void isPrimeNUmberTester(int);
void fractionSimplifier(int,int);

int main() {
    printf("Power of 2 tester with loop:\n");
    isPowerOf2LoopTester(8);
    isPowerOf2LoopTester(27);
    isPowerOf2NoLoopTester(8);
    isPowerOf2NoLoopTester(27);
    isPrimeNUmberTester(3);
    isPrimeNUmberTester(11);
    isPrimeNUmberTester(10);
    fractionSimplifier(2,3);
    fractionSimplifier(4,8);
    return 0;
}

bool isPowerOf2Loop(int num) {
    //Checks whether a number is a power of 2 using a loop
    if (num < 1) {
        return false;
    } else {
        while (num >= 1) {
            if (num == 1) {
                return true;
            }
            if (num % 2 == 0) {
                num = num / 2;
                continue;
            } else {
                return false;
            }
        }
    }

    return false;
}

void isPowerOf2LoopTester(int num) {
    //Tests the Power of 2 tester and prints
    bool flag = isPowerOf2Loop(num);
    if (flag) {
        printf("%d is a power of 2\n", num);
    } else {
        printf("%d is not a power of 2\n", num);
    }
}

bool isPowerOf2NoLoop(int num) {
    //ANSWER ASSISTED WITH CHAT, STILL UNFAMILIAR WITH BINARY STUFF
    if (num < 1) {
        return false;
    } else {
        return (num & (num - 1)) == 0;
    }
}

void isPowerOf2NoLoopTester(int num) {
    //Tests the Power of 2 with no loop tester and prints
    bool flag = isPowerOf2NoLoop(num);
    if (flag) {
        printf("%d is a power of 2\n", num);
    } else {
        printf("%d is not a power of 2\n", num);
    }
}

bool isPrimeNumber(int num) {
    if (num <= 1) {
        return false;
    } else if (num == 2 || num == 3) {
        return true;
    } else {
        for (int divisor = 2; divisor < num; divisor++) {
            if (num % divisor == 0) {
                return false;
            }
        }
        return true;
    }
}
void isPrimeNUmberTester(int num) {
    bool flag = isPrimeNumber(num);
    if (flag) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

void fractionSimplifier(int numer, int denom) {
    int gcd = 1;
    for (int divisor = 1; divisor <= abs(numer) && divisor <= abs(denom); divisor++ ) {
        if (numer % divisor == 0 && denom % divisor == 0) {
            gcd = divisor;
        }
    }
    int rNumer = numer / gcd;
    int rDenom = denom / gcd;


       printf("PASS: %d/%d reduced is %d/%d\n", numer, denom, rNumer, rDenom);


}