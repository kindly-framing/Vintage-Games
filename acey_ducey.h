#ifndef ACEY_DUCEY_H
#define ACEY_DUCEY_H

class aceyDuceyGame {
  private:
    int playerBalance;
    int firstCard;
    int secondCard;
    int thirdCard;

  public:
    aceyDuceyGame(int startingBalance = 100);
    ~aceyDuceyGame();
    displayGreeting();
};

void playAceyDucey();
void displayGreeting();

#endif