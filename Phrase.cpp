#define _CRT_SECURE_NO_WARNINGS
#include "Phrase.h"

// Конструктор по умолчанию
Phrase::Phrase() : text("") {}

// Конструктор с параметром
Phrase::Phrase(const std::string& phraseText) : text(phraseText) {}

// Метод для получения текста
const std::string& Phrase::getText() const {
    return text;
}

// Метод для установки текста
void Phrase::setText(const std::string& phraseText) {
    text = phraseText;
}