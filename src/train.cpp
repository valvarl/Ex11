// Copyright 2021 valvarl

#include "train.h"

Train::Train(int len) {
    // simple_rand.seed(
    // std::chrono::system_clock::now().time_since_epoch().count());
    simple_rand.seed(44);

    Cage *cage = new Cage((simple_rand() % 2 == 0 ? 1 : 0), getLast());
    setFirst(cage);
    setLast(cage);

    len = len >= 2 ? len : 2;
    for (int i = 0; i < len; i++) {
        addTrain(new Cage((simple_rand() % 2 == 0 ? 1 : 0), getLast()));
    }

    getLast()->next = getFirst();
    getFirst()->prev = getLast();
}

Cage *Train::getFirst() const {
    return first;
}

Cage *Train::getLast() const {
    return last;
}

void Train::addTrain(Cage* cage) {
    getLast()->next = cage;
    setLast(cage);
}

void Train::setFirst(Cage *first) {
    Train::first = first;
}

void Train::setLast(Cage *last) {
    Train::last = last;
}

int Train::calculate() const {
    getFirst()->off();
    Cage* cage = getFirst();
    int result = -1;
    while (false == getFirst()->get()) {
        cage = cage->next;
        cage->on();
        result++;
    }
    return result;
}
