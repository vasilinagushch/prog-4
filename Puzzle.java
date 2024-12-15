public class Puzzle {
    private String question;
    private Option[] options;
    private int correctAnswerIndex;
    private Hint[] hints;
    private int attempts;

    public Puzzle() {
        this.question = "";
        this.correctAnswerIndex = 0;
        this.attempts = 0;
        this.options = new Option[3];
        this.hints = new Hint[3];
    }

    public Puzzle(String question, int correctAnswerIndex, String hintText1, String hintText2, String hintText3, String option1, String option2, String option3) {
        this.question = question;
        this.correctAnswerIndex = correctAnswerIndex;
        this.attempts = 0;
        this.options = new Option[]{new Option(option1), new Option(option2), new Option(option3)};
        this.hints = new Hint[]{new Hint(hintText1), new Hint(hintText2), new Hint(hintText3)};
    }

    public String getQuestion() {
        return question;
    }

    public String getOption(int index) {
        return options[index].getText();
    }

    public String getHint(int index) {
        return hints[index].getText();
    }

    public int getCorrectAnswerIndex() {
        return correctAnswerIndex;
    }

    public int getAttempts() {
        return attempts;
    }

    public void incrementAttempts() {
        attempts++;
    }

    public void resetAttempts() {
        attempts = 0;
    }
}

