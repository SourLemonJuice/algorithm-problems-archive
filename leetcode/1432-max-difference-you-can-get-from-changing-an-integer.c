#include <stdint.h>
#include <math.h>

int32_t ReplaceNumber(int num, int8_t num_digit, int8_t x, int8_t y)
{
    for (int8_t i = 1; i <= num_digit; i++) {
        int32_t digit = num;
        digit %= (int32_t)powl(10, i);
        digit /= (int32_t)powl(10, i - 1);

        if (digit == x) {
            if (digit > y)
                num -= (digit - y) * (int32_t)powl(10, i - 1);
            else
                num += (y - digit) * (int32_t)powl(10, i - 1);
        }
    }

    return num;
}

int maxDiff(int num) {
    int8_t y_max = 9;
    int8_t y_min = 0;

    int8_t digit_table[9] = {0};
    int8_t digit_num = 1;
    int num_temp = num;
    while (num_temp > 9) {
        digit_table[digit_num - 1] = num_temp % 10;
        num_temp /= 10;
        digit_num++;
    }
    digit_table[digit_num - 1] = num_temp % 10;

    int8_t x = 0; // start with 1
    for (int8_t i = digit_num - 1; i >= 0; i--) {
        if (digit_table[i] < 9) {
            x = digit_table[i];
            break;
        }
    }
    int32_t out = 0;
    out = ReplaceNumber(num, digit_num, x, y_max);

    x = 0;
    for (int8_t i = digit_num - 1; i >= 0; i--) {
        if (digit_table[i] > 1) {
            x = digit_table[i];
            break;
        }
    }
    if (x == digit_table[digit_num - 1])
        y_min = 1;
    out -= ReplaceNumber(num, digit_num, x, y_min);

    return out;
}
