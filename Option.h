#pragma once
#ifndef OPTION_H
#define OPTION_H

#include <string>

class Option {
private:
    std::string text; // Используем std::string вместо массива char

public:
    Option(); // Конструктор по умолчанию
    Option(const std::string& optionText); // Конструктор с параметром
    const std::string& getText() const; // Метод для получения текста
    void setText(const std::string& optionText); // Метод для установки текста
};

#endif // OPTION_H