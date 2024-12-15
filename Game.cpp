#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Phrase.h"
#include "Player.h"
#include "Puzzle.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


Game::Game() : currentPuzzle(0) {}

void Game::initializePuzzles() {
    puzzles[0] = Puzzle("��� ����� ���� ����� � ����, �� ��� ���� �� ���������?", 0, "� ����� �������� ���� ���������.", "�� ������ ��������� ��� � ������.", "��� �������� ����� ������������ ����� �������.", "��������", "���������", "����");
    puzzles[1] = Puzzle("�� �� �����, �� �� �������, ���������� - � ����� �������.", 1, "��� ����������� ����������.", "� ���� ���� ������ � ����� �������.", "� ���� ��� �����.", "���������", "�������", "������");
    puzzles[2] = Puzzle("� ������ ��� ��� � ����� ��� ����. ��� � �����?", 1, "��� ��������� �������, ������� �� ������ ��������.", "��� ���������, ����� ���� ���������� �� �����������.", "�� ������ ������� ��� � ����� ��� �������.", "�����", "���", "�����");
}

void Game::initializePhrases() {
    phrases[0] = Phrase("� ���� ������� ������� �����.\n");
    phrases[1] = Phrase("� ���� ������� ������� �����.\n");
    phrases[2] = Phrase("��� ������� �������� �� �������.\n");
}

void Game::setPlayerName(const std::string& playerName) {
    player = Player(playerName);
}

const std::string& Game::getPlayerName() const {
    return player.getName();
}

int Game::getPlayerScore() const {
    return player.getScore();
}

const std::string& Game::getRandomPhrase() const {
    int randomIndex = rand() % MAX_PHRASES;
    return phrases[randomIndex].getText();
}

bool Game::checkAnswer(int puzzleIndex, int answerIndex) {
    if (answerIndex == puzzles[puzzleIndex].getCorrectAnswerIndex()) {
        player.incrementScore();
        return true;
    }
    else {
        puzzles[puzzleIndex].incrementAttempts();
        return false;
    }
}

void Game::printPuzzle(int puzzleIndex) const {
    std::cout << "\n�������: " << puzzles[puzzleIndex].getQuestion() << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ") " << puzzles[puzzleIndex].getOption(i) << std::endl;
    }
}

void Game::printHint(int puzzleIndex) const {
    int attempts = puzzles[puzzleIndex].getAttempts();
    if (attempts < MAX_HINTS) {
        std::cout << "���������: " << puzzles[puzzleIndex].getHint(attempts) << std::endl;
    }
}

void Game::startGame() {
    for (currentPuzzle = 0; currentPuzzle < MAX_PUZZLES; currentPuzzle++) {
        printPuzzle(currentPuzzle);
        getAnswerAndCheck(currentPuzzle);
    }
    std::cout << "���� ���������! " << getPlayerName() << " �����(�) " << getPlayerScore() << " �������." << std::endl;
    if (getPlayerScore() == 0) {
        std::cout << "�� �� ������ �� ����� �������. ���������� �����!\n" << std::endl;
        player.resetScore();
        startGame();
    }
}

void Game::getAnswerAndCheck(int puzzleIndex) {
    int answerIndex;
    std::cout << "������� ����� ������ (1-3): ";
    std::cin >> answerIndex;

    if (checkAnswer(puzzleIndex, answerIndex - 1)) {
        std::cout << "���������! �������!\n" << std::endl;
        std::cout << getRandomPhrase() << std::endl;
    }
    else {
        if (puzzles[puzzleIndex].getAttempts() < MAX_ATTEMPTS) {
            printHint(puzzleIndex);
            getAnswerAndCheck(puzzleIndex);
        }
        else {
            std::cout << "��� ������� �������. ������� � ��������� �������.\n" << std::endl;
        }
    }
}