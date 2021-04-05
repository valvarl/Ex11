// Copyright 2021 valvarl

#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

#include <random>

// класс "Вагон"
class Cage
{
    bool light;  // Свет (вкл/выкл)
 public:
    Cage* next;  // следующий вагон
    Cage* prev;  // предыдущий вагон
    Cage(): light(false), next(nullptr), prev(nullptr) {}
    Cage(bool _light, Cage* _prev):
    light(_light), next(nullptr), prev(_prev) {}
    void on()  { light=true;    }
    void off() { light = false; }
    bool get() const  { return light;  }
};

class Train {
 private:
    Cage* first;  // указатель на первый вагон
    Cage* last;  // указатель на последний вагон
 public:
    std::minstd_rand simple_rand;
    Train(int);
    void addTrain(Cage* cage);
    Cage *getFirst() const;
    Cage *getLast() const;
    void setFirst(Cage *first);
    void setLast(Cage *last);
    int calculate() const;
};


#endif  // INCLUDE_TRAIN_H_
