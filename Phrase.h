#pragma once
#ifndef PHRASE_H
#define PHRASE_H

#include <string>

class Phrase {
private:
    std::string text; // Используем std::string вместо массива char

public:
    Phrase(); // Конструктор по умолчанию
    Phrase(const std::string& phraseText); // Конструктор с параметром
    const std::string& getText() const; // Метод для получения текста
    void setText(const std::string& phraseText); // Метод для установки текста
};

#endif // PHRASE_H