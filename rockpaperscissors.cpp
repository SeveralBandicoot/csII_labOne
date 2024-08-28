/* Lab 1 - Enumerations & Conditional Operators

@ AJ Enrique Arguello (8/25/24)

*Objectives:
1. Create a game Rock, Paper, Scissors and play against the computer.
2. Prompt the user to enter their choice but Protect against invalid data.
3. The computer will randomly choose 1-3 after the player makes his choice.
4. Record all wins, ties and losses in their respective Vectors
5. Play until someone scores 5 wins

*/

#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;

int choice; 

 enum Choices {
    rock, paper, scissors
  };

void playerTurn(Choices pchoice, bool pWin);
void computerTurn(bool cWin);
int main() {
  Choices pchoice;
  bool pWin = false;
  bool cWin = false;

  cout << "Rock, Paper, Scissiors\n\n";
  for (int i = 0; i <= 5; i++) {
    while (pWin == false && cWin == false) {
      playerTurn(pchoice, pWin);
      computerTurn(cWin);
    }

  }
}

void playerTurn(Choices pchoice, bool pWin) {
  //Choices pchoice;

  cout << "It's your turn:\n";
  cout << "1.) Rock\n2.) Paper\n3.) Scissors\n\n";
  cin >> choice; 
  (choice = 1) ? void(pchoice = rock) :
    (choice = 2) ? void(pchoice = paper) :
      (choice = 3) ? void(pchoice = scissors) :
        void(cout << "\nThat input was invalid, try again");
        
  /*(choice = rock) ? cout << "You choose rock" :
  (choice = paper) ? cout << "You choose paper" :
  (choice = scissors) ? cout << "You chose scissors" :
  cout << "Invalid input, please try again";*/
}

void computerTurn(bool cWin) {
  Choices cchoice;
  int randNum = rand() % 3;
  cout << "It's the Computer's turn:\n";
 // (randNum = 1) ? void (cchoice = rock)
}

void win() {

}



