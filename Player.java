public class Player {
    private String name;
    private int score;
    private static int playerCount = 0;

    public Player() {
        this.name = "";
        this.score = 0;
        playerCount++;
    }

    public Player(String name) {
        this.name = name;
        this.score = 0;
        playerCount++;
    }

    public String getName() {
        return name;
    }

    public int getScore() {
        return score;
    }

    public void incrementScore() {
        this.score++; // Использование оператора this
    }

    public void resetScore() {
        this.score = 0; // Использование оператора this
    }

    public void setName(String name) {
        this.name = name; // Использование оператора this
    }

    public static int getPlayerCount() {
        return playerCount;
    }
}
