#include <stdio.h>

typedef struct {

    char question [255];
    char options [4][100];
    int correctAnswer;
} QuizQuestion;

void displayQuestion(QuizQuestion q, int questionNumber) {
    printf ("\nQuestion %d: %s\n", questionNumber, q.question);
    for (int i = 0; i < 4; i++) {
        printf ("%d. %s\n", i + 1, q.options[i]);
      }
}

int askQuestion(QuizQuestion q) {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);

    if (answer == q.correctAnswer) {
      printf ("Correct!\n");
      return 1;

    } else {
        printf("Wrong! The correct answer is %d.\n", q.correctAnswer);
        return 0;
    }
}

int main() {
    QuizQuestion quiz[] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"},3},
        {"Which programming language is known as the 'mother of all languages'?", {"C", "C++", "Assembly", "Fortran"},1},
        {"What is 2 + 2?", {"3", "4", "5", "6"},2},
        {"Who wrote 'To Kill a Mockingbird'?", {"Harper Lee", "J.K. Rowling", "Ernest Hemingway", "Mark Twain"},1}

    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;

    printf ("Welcome to the Quiz Application!\n");

    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(quiz[i], i + 1);
        score += askQuestion (quiz[i]);
    }

    printf ("\n You scored %d out of %d.\n", score, totalQuestions);

    return 0;
}