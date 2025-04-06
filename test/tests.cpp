// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(InitialState, CheckOffState) {
    std::string state = "OFF";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);

    EXPECT_EQ(machine.getState(), state);
}

TEST(PowerOn, TestWAIT_A) {
    std::string state = "WAIT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();

    EXPECT_EQ(machine.getState(), state);
}

TEST(PowerOn, TestWAIT_B) {
    std::string state = "WAIT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Cook();

    EXPECT_EQ(machine.getState(), state);
}

TEST(PowerOn, TestWAIT_C) {
    std::string state = "WAIT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Cook();

    EXPECT_EQ(machine.getState(), state);
}

TEST(PowerOn, TestWAIT_D) {
    std::string state = "WAIT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Check();

    EXPECT_EQ(machine.getState(), state);
}

TEST(PowerOn, TestWAIT_E) {
    std::string state = "WAIT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Choice(2);
    machine.Choice(0);
    machine.Check();
    machine.Cook();
    machine.Finish();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Payment, TestACCEPT_A) {
    std::string state = "ACCEPT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Payment, TestACCEPT_B) {
    std::string state = "ACCEPT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Coin(25);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Payment, TestACCEPT_C) {
    std::string state = "ACCEPT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Choice(2);
    machine.Check();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Selection, TestCHECK_A) {
    std::string state = "CHECK";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Choice(2);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Selection, TestCHECK_B) {
    std::string state = "CHECK";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Choice(2);
    machine.Choice(0);

    EXPECT_EQ(machine.getState(), state);
}

TEST(Preparation, TestCOOK_A) {
    std::string state = "COOK";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Choice(2);
    machine.Choice(0);
    machine.Check();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Collection, TestCOLLECT_A) {
    std::string state = "COLLECT";
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };

    Automata machine(menu, price, 3);
    machine.On();
    machine.Coin(60);
    machine.Choice(2);
    machine.Choice(0);
    machine.Check();
    machine.Cook();

    EXPECT_EQ(machine.getState(), state);
}

TEST(Transaction, TestSequentialTransactions) {
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };
    Automata machine(menu, price, 3);
    
    // Первая транзакция
    machine.On();
    machine.Coin(60);
    machine.Choice(1);
    machine.Check();
    machine.Cook();
    machine.Finish();
    EXPECT_EQ(machine.getState(), "WAIT");

    // Вторая транзакция
    machine.Coin(60);
    EXPECT_EQ(machine.getState(), "ACCEPT");
}

TEST(EdgeCase, TestCoinWithoutPowerOn) {
    std::string menu[]{ "Americano", "Raf", "Cappuccino" };
    int price[]{ 45, 70, 85 };
    Automata machine(menu, price, 3);
    
    machine.Coin(60);
    EXPECT_EQ(machine.getState(), "OFF");
}
