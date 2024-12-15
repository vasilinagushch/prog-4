#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name; // Используем std::string вместо массива char
    int score;

public:
    Player(); // Конструктор по умолчанию
    Player(const std::string& playerName); // Конструктор с параметром
    const std::string& getName() const; // Метод для получения имени
    int getScore() const; // Метод для получения счета
    void incrementScore(); // Метод для увеличения счета
    void resetScore(); // Метод для сброса счета
    void setName(const std::string& playerName); // Метод для установки имени
};

#endif // PLAYER_H