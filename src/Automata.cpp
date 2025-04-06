#include "Automata.h"

Automata::Automata(std::string menu[], int prices[], int size) {
    this->menu = menu;
    this->prices = prices;
    selected = -1;
    state = OFF;
    sizeValue = size;
    cash = 0;
}

std::string Automata::On() {
    std::string massage = "Error, please try again\n";
    if (state == OFF) {
        state = WAIT;
        massage = "Start selecting\n";
    }
    return massage;
}

std::string Automata::Off() {
    std::string massage = "Error, please try again\n";
    if (state == WAIT) {
        state = OFF;
        massage = "Machine is off\n";
    }
    return massage;
}

std::string Automata::Coin(int money) {
    std::string massage = "Error, please try again\n";
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        massage = "Received " + std::to_string(money) +
            " money.Balance " + std::to_string(cash) + "\n";
    }
    return massage;
}

std::string Automata::etMenu() {
    std::string massage = "\nMenu\n";
    for (int i = 0; i < sizeValue; i++) {
        massage += menu[i] + ": " + std::to_string(prices[i]) + " rubels\n";
    }
    return massage + "\n";
}

std::string Automata::getState() {
    std::string massage = "Error, please try again\n";
    switch (state) {
    case Automata::OFF:
        massage = "OFF";
        break;
    case Automata::WAIT:
        massage = "WAIT";
        break;
    case Automata::ACCEPT:
        massage = "ACCEPT";
        break;
    case Automata::CHECK:
        massage = "CHECK";
        break;
    case Automata::COOK:
        massage = "COOK";
        break;
    case Automata::COLLECT:
        massage = "COLLECT";
        break;
    default:
        break;
    }
    return massage;
}

std::string Automata::Choice(int selected) {
    std::string massage = "Error, please try again\n";
    if (state == ACCEPT || state == CHECK) {
        state = CHECK;
        this->selected = selected;
        massage = "Selected drink '" + menu[selected] + "'\n";
    }
    return massage;
}

std::string Automata::Check() {
    std::string massage = "Error, please try again\n";
    if (state == CHECK) {
        if (prices[selected] <= cash) {
            state = COOK;
            massage = "Okay\n";
        } else {
            state = ACCEPT;
            massage = "Not enough money on the cash\n";
        }
    }
    return massage;
}

std::string Automata::Cancel() {
    std::string massage = "Error, please try again\n";
    if (state == ACCEPT || state == CHECK || state == COOK) {
        state = WAIT;
        massage = "Switching to waiting mode\n";
    }
    return massage;
}

std::string Automata::Cook() {
    std::string massage = "Error, please try again\n";
    if (state == COOK) {
        massage = "Cooking your product '" + menu[selected] + "'\n";
        state = COLLECT;
    }
    return massage;
}

std::string Automata::Finish() {
    std::string massage = "Error, please try again\n";
    if (state == COLLECT) {
        massage = "Switching to waiting mode\n";
        state = WAIT;
    }
    return massage;
}
