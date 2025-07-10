#include <bitset>
#include <iostream>
#include <cstdint>

enum control{
    leftbutton = 1 << 0,
    rightbutton = 1 << 1,
    backbutton = 1 << 2,
};

uint8_t checkbits(uint8_t flags, uint8_t bitindex) {
    uint8_t mask = 1 << bitindex;
    if ((flags & mask) == 0)
        flags |=mask;
    return flags;
}

int main() {
    uint8_t state{0x0000'0000};

    state = checkbits(state, 2);
    state = checkbits(state, 0);

    std::bitset<8> bits(state);
    std::cout << bits << '\n';

    if (state & leftbutton)
        std::cout << "Left button is ON\n";
    if (state & rightbutton)
        std::cout << "Right button is ON\n";
    if (state & backbutton)
        std::cout << "Back button is ON\n";

    return 0;
}
