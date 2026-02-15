#include <iostream>
#include <string>

int main() {
    int score = 82;
    std::string grade;
    if (score >= 90) grade = "A";
    else if (score >= 80) grade = "B";
    else grade = "C";

    std::cout << "점수: " << score << "\n등급: " << grade << "\n";
}
