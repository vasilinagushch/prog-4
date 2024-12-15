#include "Player.h"

// Конструктор по умолчанию
Player::Player() : name(""), score(0) {}

// Конструктор с параметром
Player::Player(const std::string& playerName) : name(playerName), score(0) {}

// Метод для получения имени игрока
const std::string& Player::getName() const {
    return name;
}

// Метод для получения счета игрока
int Player::getScore() const {
    return score;
}

// Метод для увеличения счета
void Player::incrementScore() {
    score++;
}

// Метод для сброса счета
void Player::resetScore() {
    score = 0;
}

// Метод для установки имени
void Player::setName(const std::string& playerName) {
    name = playerName;
}