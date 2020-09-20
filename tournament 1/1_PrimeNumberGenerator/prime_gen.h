#pragma once

#ifndef TOORNAMENT_1_PrimeNumberGenerator_H_
#define TOORNAMENT_1_PrimeNumberGenerator_H_

class PrimeNumberGenerator {
public:
    explicit PrimeNumberGenerator(int start) { start_n = start; }

    int GetNextPrime() {
        while (check) {
            check = isPrime(start_n);
            start_n++;
        }
        check = true;
        return start_n - 1;
    }

private:
    int start_n = 0;
    bool check = true;

    static bool isPrime(int n) {
        if (n > 1) {
            for (int i = 2; i < n; i++)
                if (n % i == 0) return true;
            return false;
        } else return true;
    }
};

#endif // TOORNAMENT_1_PrimeNumberGenerator_H_

