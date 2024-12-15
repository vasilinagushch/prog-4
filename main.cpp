#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <locale>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Puzzle.h" 

using namespace std;

#define MAX_HINT_LENGTH 200
#define MAX_OPTION_LENGTH 100
#define MAX_PHRASE_LENGTH 100
#define MAX_HINTS 3

// главная функция
int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // инициализация генератора случайных чисел

    Game game;

    // работа с "статической" переменной
    Player staticPlayer;
    cout << "\nВведите ваше имя (используя английские символы): ";
    char name[MAX_OPTION_LENGTH];
    cin >> name;
    staticPlayer = Player(name);

    // работа с динамической переменной
    Player* dynamicPlayer = new Player(staticPlayer);
    game.setPlayerName(dynamicPlayer->getName());
    game.initializePuzzles();
    game.initializePhrases();
    game.startGame();

    delete dynamicPlayer; // Освобождение памяти, выделенной для динамической переменной

    // работа с динамическим массивом объектов класса
    int numPlayers;
    cout << "Введите количество игроков: ";
    cin >> numPlayers;
    Player* players = new Player[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        players[i] = Player(name);
    }
    delete[] players; // освобождение памяти, выделенной для динамического массива объектов

    // работа с массивом динамических объектов класса
    Player** dynamicPlayers = new Player * [numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        dynamicPlayers[i] = new Player();
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        dynamicPlayers[i]->setName(name); // Задаем имя игрока через метод setName
    }

    delete[] dynamicPlayers; // освобождение памяти, выделенной для массива указателей на динамические объекты

    // Демонстрация использования статического метода
    Puzzle p1("Загадка1", 0, "Hint1", "Hint2", "Hint3", "Option1", "Option2", "Option3");
    Puzzle p2("Загадка2", 1, "Hint1", "Hint2", "Hint3", "Option1", "Option2", "Option3");

    // Демонстрация возврата значения из метода через указатель
    const std::string* questionPtr = p1.getQuestionPtr();
    std::cout << "Загадка (указатель): " << *questionPtr << std::endl;

    // Демонстрация возврата значения из метода через ссылку
    const std::string& questionRef = p1.getQuestionRef();
    std::cout << "Загадка (ссылка): " << questionRef << std::endl;

    // Демонстрация использования оператора this
    p1.setQuestion("Новая загадка");
    std::cout << "Обновлённая загадка: " << p1.getQuestion() << std::endl;

    // Демонстрация использования дружественной функции
    std::cout << p1 << std::endl;

    // Демонстрация перегрузки оператора +
    Puzzle p3 = p1 + p2;
    std::cout << "Загадка: " << p3.getQuestion() << std::endl;

    // Демонстрация перегрузки оператора ++ (префиксный)
    ++p1;
    std::cout << "Количество попыток после префикса: " << p1.getAttempts() << std::endl;

    // Демонстрация перегрузки оператора ++ (постфиксный)
    p1++;
    std::cout << "Количество попыток после постфикса: " << p1.getAttempts() << std::endl;

    return 0;
}