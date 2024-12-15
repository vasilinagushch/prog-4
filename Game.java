import java.util.Random;
import java.util.Scanner;

public class Game {
    private static final int MAX_PUZZLES = 3;
    private static final int MAX_ATTEMPTS = 3;
    private static final int MAX_PHRASES = 3;

    private Puzzle[] puzzles;
    private Player player;
    private int currentPuzzle;
    private Phrase[] phrases;

    public Game() {
        this.currentPuzzle = 0;
        this.puzzles = new Puzzle[MAX_PUZZLES];
        this.phrases = new Phrase[MAX_PHRASES];
    }

    public void initializePuzzles() {
        puzzles[0] = new Puzzle("Что может идти вверх и вниз, но при этом не двигается?", 0, "У этого предмета есть ступеньки.", "Ты можешь встретить его в здании.", "Это помогает людям перемещаться между этажами.", "Лестница", "Эскалатор", "Лифт");
        puzzles[1] = new Puzzle("То ли зебра, то ли лесенка, прикоснись - и будет песенка.", 1, "Это музыкальный инструмент.", "У него есть черные и белые клавиши.", "У него нет струн.", "Эскалатор", "Пианино", "Гитара");
        puzzles[2] = new Puzzle("Я говорю без рта и слышу без ушей. Что я такое?", 1, "Это природное явление, которое ты можешь услышать.", "Оно возникает, когда звук отражается от поверхности.", "Ты можешь слышать его в горах или пещерах.", "Голос", "Эхо", "Ветер");
    }

    public void initializePhrases() {
        phrases[0] = new Phrase("У дома Круэллы красная крыша.");
        phrases[1] = new Phrase("У дома Круэллы красная дверь.");
        phrases[2] = new Phrase("Дом Круэллы построен из кирпича.");
    }

    public void setPlayerName(String playerName) {
        player = new Player(playerName);
    }

    public String getPlayerName() {
        return player.getName();
    }

    public int getPlayerScore() {
        return player.getScore();
    }

    public String getRandomPhrase() {
        int randomIndex = new Random().nextInt(MAX_PHRASES);
        return phrases[randomIndex].getText();
    }

    public boolean checkAnswer(int puzzleIndex, int answerIndex) {
        if (answerIndex == puzzles[puzzleIndex].getCorrectAnswerIndex()) {
            player.incrementScore();
            return true;
        } else {
            puzzles[puzzleIndex].incrementAttempts();
            return false;
        }
    }

    public void printPuzzle(int puzzleIndex) {
        System.out.println("Загадка: " + puzzles[puzzleIndex].getQuestion());
        for (int i = 0; i < 3; i++) {
            System.out.println((i + 1) + ") " + puzzles[puzzleIndex].getOption(i));
        }
    }

    public void printHint(int puzzleIndex) {
        int attempts = puzzles[puzzleIndex].getAttempts();
        if (attempts < MAX_ATTEMPTS) {
            System.out.println("Подсказка: " + puzzles[puzzleIndex].getHint(attempts));
        }
    }

    public void startGame() {
        Scanner scanner = new Scanner(System.in);

        for (currentPuzzle = 0; currentPuzzle < MAX_PUZZLES; currentPuzzle++) {
            printPuzzle(currentPuzzle);
            getAnswerAndCheck(scanner, currentPuzzle);
        }
        System.out.println("Игра завершена! " + getPlayerName() + " решил(а) " + getPlayerScore() + " загадок.");
        if (getPlayerScore() == 0) {
            System.out.println("Вы не решили ни одной загадки. Попробуйте снова!\n");
            player.resetScore();
            startGame();
        }
    }

    public void getAnswerAndCheck(Scanner scanner, int puzzleIndex) {
        int answerIndex;

        System.out.print("Введите номер ответа (1-3): ");
        answerIndex = scanner.nextInt();

        if (checkAnswer(puzzleIndex, answerIndex - 1)) {
            System.out.println("Правильно! Молодец!\n");
            System.out.println(getRandomPhrase() + "\n");
        } else {
            if (puzzles[puzzleIndex].getAttempts() < MAX_ATTEMPTS) {
                printHint(puzzleIndex);
                getAnswerAndCheck(scanner, puzzleIndex);
            } else {
                System.out.println("Три попытки истекли. Переход к следующей загадке.\n");
            }
        }
    }
    // Метод для демонстрации работы с массивом объектов
    public void printAllPuzzles() {
        for (Puzzle puzzle : puzzles) {
            System.out.println(puzzle.getQuestion());
        }
    }

    // Новый метод в Game.java для возврата значения через вспомогательный класс
    public ScoreHelper getPlayerScoreHelper() {
        return new ScoreHelper(player.getScore());
    }
}


