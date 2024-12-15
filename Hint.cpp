#define _CRT_SECURE_NO_WARNINGS
#include "Hint.h"

// Конструктор по умолчанию
Hint::Hint() : text("") {}

// Конструктор с параметром
Hint::Hint(const std::string& hintText) : text(hintText) {}

// Метод для получения текста
const std::string& Hint::getText() const {
    return text;
}

// Метод для установки текста
void Hint::setText(const std::string& hintText) {
    text = hintText;
}