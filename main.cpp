#include <iostream>
#include <string>
using namespace std;
bool isPowerOf2Loop(int);
void isPowerOf2LoopTester(int);
bool isPowerOf2NoLoop(int);
void isPowerOf2NoLoopTester(int);
bool isPrimeNumber(int);
void isPrimeNUmberTester(int);
void fractionSimplifier(int,int);
void test();

class Fraction { //Class created during 4/3 demo
public:
    int numerator;
    int denominator;
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    string toString() {
        return to_string(numerator) + "/" + to_string(denominator);
    }
};

int main() {
    //All test code methods are called here
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
    Fraction num1(2,4);
    printf("%d/%d",num1.numerator,num1.denominator);
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
    //Tests the Power of 2 tester and prints as a test
    bool flag = isPowerOf2Loop(num);
    if (flag) {
        printf("%d is a power of 2\n", num);
    } else {
        printf("%d is not a power of 2\n", num);
    }
}

bool isPowerOf2NoLoop(int num) {
    //Checks whether a number is a power of 2 without a loop, using the bit manipulation trick
    //Understanding of bit manipulation trick aided by ChatGPT
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
    //Checks whether a number is a prime number
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
    //Tests the prime number checker
    bool flag = isPrimeNumber(num);
    if (flag) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

void fractionSimplifier(int numer, int denom) {
    if (denom == 0) {
        cout << "Invalid denominator" << endl;
        return;
    } else {
        int gcd = 1;
        for (int divisor = 1; divisor <= abs(numer) && divisor <= abs(denom); divisor++ ) {
            if (numer % divisor == 0 && denom % divisor == 0) {
                gcd = divisor;
            }
        }
        int rNumer = numer / gcd;
        int rDenom = denom / gcd;

        if ((rNumer / rDenom) == (numer / denom)) {
            printf("PASS: %d/%d reduced is %d/%d\n", numer, denom, rNumer, rDenom);
        } else {
            printf("Fail: %d/%d reduced is not %d/%d\n", numer, denom, rNumer, rDenom);
        }
    }

}

Fraction reduce(Fraction input) { //DONE IN CLASS AS A DEMO, a/b

int gcd = 1;
    for (int divisor = 1; divisor <=abs(input.numerator) && divisor <= abs(input.denominator); divisor++) {
        if (input.numerator % divisor == 0 && input.denominator % divisor == 0) {
            gcd = divisor;
        }
    }
return Fraction(input.numerator / gcd, input.denominator / gcd);

}

void test() {
//given an input, the actual output should match the expected output
    Fraction arrayInput[] = {Fraction(1,2), Fraction(2,4), Fraction (6,7)};
    Fraction arrayOutput[] = {Fraction(1,2), Fraction(1,2), Fraction (6,7)};
    Fraction input(2,4);
    Fraction expectedOutput(1,2);

    //call the function
    Fraction actualOutput = reduce(input);

    for (int i = 0; i < sizeof(arrayInput); i++) {
        Fraction input = arrayInput[i];
        Fraction expect = arrayOutput[i];
    }


    //compare expected vs actual
    if ((expectedOutput.denominator == actualOutput.denominator) && (expectedOutput.numerator == actualOutput.numerator)){
    printf("pass");

    } else {
        printf("fail");
    }
}
