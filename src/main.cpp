// Copyright 2024 UNN-IASR

#include "Automata.h"
#include <iostream>
#include <string>

int main() {
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int prices[]{ 45, 70, 85 };

    Automata DrinkMachine(menu, prices, 3);
    std::cout << DrinkMachine.On();
    std::cout << DrinkMachine.etMenu();
    std::cout << DrinkMachine.Coin(55);
    std::cout << DrinkMachine.Choice(1);
    std::cout << DrinkMachine.Choice(0);
    std::cout << DrinkMachine.Coin(390);
    std::cout << DrinkMachine.Choice(2);
    std::cout << DrinkMachine.Check();
    std::cout << DrinkMachine.Coin(390);
    std::cout << DrinkMachine.Choice(2);
    std::cout << DrinkMachine.Check();
    std::cout << DrinkMachine.Cook();
    std::cout << DrinkMachine.Finish();
}
