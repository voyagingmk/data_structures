 #include <stdlib.h>
 #include <stdio.h>

 double Power(double base, int exponent) {
    long long p = abs( (long long) exponent);
    double r = 1.0;
    while (p) {
        printf("p %lld \n", p);
        if (p & 1)
            r *= base;
        base *= base;
        p >>= 1;

    }
    return ( exponent > 0 ) ? r : 1/r;
}

int main() {
    // 0.2^-9 =  1 / (0.2^9)
    // r = r * base = 0.2, base = base * base = 0.2 * 0.2 = 0.2^2 = 0.04, p = 4
    // base = base * base = 0.2^2 * 0.2^2 = 0.2^4, p = 2
    // base = base * base = 0.2^4 * 0.2^4 = 0.2^8, p = 1
    // r = r * base = 0.2 * 0.2^8 = 0.2^9
    printf("%f\n", Power(0.2, -9));
    return 0;
}