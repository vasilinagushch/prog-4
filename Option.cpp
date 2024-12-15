#define _CRT_SECURE_NO_WARNINGS
#include "Option.h"

// Конструктор по умолчанию
Option::Option() : text("") {}

// Конструктор с параметром
Option::Option(const std::string& optionText) : text(optionText) {}

// Метод для получения текста
const std::string& Option::getText() const {
    return text;
}

// Метод для установки текста
void Option::setText(const std::string& optionText) {
    text = optionText;
}
