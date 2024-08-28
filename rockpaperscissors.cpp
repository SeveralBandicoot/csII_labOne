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
#include <ctime>
#include <limits>
#include <vector>

using namespace std;

 enum Choices { // enum values 
    rock, paper, scissors
  };

// Function Prototypes vvv
void playerTurn(int &pChoice);
void win(vector<string> log, int pTally, int cTally);
void barrier();

int main() {
  Choices pchoice; // selected player enum 
  Choices cchoice; // selected computer enum 
  vector<string> log; // vector used to log wins/ties/losses
  int pChoice, cChoice, pTally, cTally; // pTally = # of player wins | cTally = # of computer wins 
  bool pWin; // player win boolean
  bool cWin; // computer win boolean 

  cout << "Rock, Paper, Scissiors\n";
  while(pTally < 5 && cTally < 5) { // while both values for pTally and cTally are less than 5 
    do { // run this block of code while cWin/pWin values are false 
      pWin = false;
      cWin = false;
      int x = time(0); 
      srand(x);
      cChoice = 1 + rand() % 3; // fetches cChoice value from 1-3 (random number)

      barrier();

      playerTurn(pChoice); // passes player choice value into playerTurn function 

      switch(pChoice) { // checks userInput
        case 1: 
          cout << "\nYou chose rock\n";
          pchoice = rock; // players assigned enum is rock 
          break;
        case 2:
          cout << "\nYou chose paper\n";
          pchoice = paper; // players assigned enum is paper
          break;
        case 3:
          cout << "\nYou chose scissors\n";
          pchoice = scissors; // players assigned enum is scissors
          break;
        default:
          playerTurn(pChoice); // in the case of invalid input, loop playerTurn function 
          break;
      }

      if(cChoice == 1) { // checks the cChoice int fetched by computer 
        cchoice = rock;
        cout << "\nThe computer chose rock\n";
      } else if (cChoice == 2) {
        cchoice = paper;
        cout << "\nThe computer chose paper\n";
      } else if (cChoice == 3){
        cchoice = scissors;
        cout << "\nThe computer chose scissors\n";
      };

      if(pchoice == rock && cchoice == scissors) { // this block of code compares both the player enum and computer enum with eachother, simulates a rock paper scissors game
        log.push_back("Player Win"); // adds "Player Win" to the log vector 
        pTally+=1; // adds 1 to the pTally value 
        pWin = true; // sets the boolean value pWin to true, exiting the loop
      } else if(pchoice == paper && cchoice == rock) {
        log.push_back("Player Win");
        pTally+=1;
        pWin = true;
      } else if(pchoice == scissors && cchoice == paper) {
        log.push_back("Player Win");
        pTally+=1;
        pWin = true;
      } else if(cchoice == rock && pchoice == scissors) {
        log.push_back("Computer Win"); // adds "Computer Win" to the log vector 
        cTally+=1; // adds 1 to the cTally value 
        cWin = true; // sets the boolean value cWin to true, exiting the loop 
      } else if(cchoice == paper && pchoice == rock) {
        log.push_back("Computer Win");
        cTally+=1;
        cWin = true;
      } else if(cchoice == scissors && pchoice == paper) {
        log.push_back("Computer Win");
        cTally+=1;
        cWin = true;
      } else { // in the case of both enums being the same, output a tie where no point is given 
        cout << "\nTie!\nPlayer wins: " << pTally << " Computer wins: " << cTally << "\n"; 
        log.push_back("TIE"); // adds "TIE" to the log vector 
      }

      /*(pChoice == 1) ? void(pchoice = rock) : 
      void(cout << "\nYou broke it!");

      (pchoice == rock) ? void(cout << "\nYou chose rock") : 
      void (cout << "\nYou broke it!");*/
    


      /*playerTurn(pchoice);
      cout << "It's the computer's turn!\n";
      //computerTurn(cChoice);
      int x = time(0);
      srand(x);
      cChoice = 1 + rand() % 3;
      (cChoice = 1) ? void(cchoice == rock) :
        (cChoice = 2) ? void(cchoice == paper) :
          (cChoice = 3) ? void(cchoice == scissors) : 
            void(cout << "\nYou broke it!");
      (cchoice == rock) ? void(cout << "\nThe computer chose rock") :
        (cchoice == paper) ? void(cout << "\nThe computer chose paper") :
          (cchoice == scissors) ? void(cout << "\nThe computer chose scissors") :
            void(cout << "\nYou broke it!");*/
      

      /*(cChoice == 1) ? void(cout << "\nThe computer chose rock") :
        (cChoice == 2) ? void(cout << "\nThe computer chose paper") :
          (cChoice == 3) ? void(cout << "\nThe computer chose scissors") :
            void(cout << "\nYou broke it!");

      (cChoice == 1) ? void(cchoice == rock) :
        (cChoice == 2) ? void(cchoice == paper) :
          (cChoice == 3) ? void(cchoice == scissors) : 
            void(cout << "\nYou broke it!");*/
      
      /*(pchoice == rock && cchoice == paper) ? void(cWin == true) :
        (pchoice == paper && cchoice == scissors) ? void(cWin == true) :
          (pchoice == scissors && cchoice == rock) ? void(cWin == true) :
            (pchoice == rock && cchoice == scissors) ? void(pWin == true) :
              (pchoice == paper && cchoice == rock) ? void(pWin == true) :
                (pchoice == scissors && cchoice == paper) ? void(pWin == true) :
                  void("\nTie!");   */
    }
    while(pWin == false && cWin == false);
      //computerTurn(min, max, cChoice);
      /*int x = time(0);
      srand(x);
      cChoice = 1 + rand() % 3;
      (cChoice == 1) ? void(cout << "\nThe computer chose rock") :
        (cChoice == 2) ? void(cout << "\nThe computer chose paper") :
          (cChoice == 3) ? void(cout << "\nThe computer chose scissors") :
            void(cout << "\nYou broke it!");
      (cChoice == 1) ? void(cchoice = rock) :
        (cChoice == 2) ? void(cchoice = paper) :
          (cChoice == 3) ? void(cchoice = scissors) : 
            void(cout << "\nYou broke it!");*/
      
      //computerTurn(cWin);
    
    (pWin == true) ? void(cout << "\nPlayer wins! " << "\nPlayer wins: " << pTally << " Computer wins: " << cTally << "\n") : // if the player wins, print this line
      (cWin == true) ? void(cout << "\nComputer wins!" << "\nPlayer wins: " << pTally << " Computer wins: " << cTally << "\n") : // if the computer wins, print this line
        void(cout << "\nIt's a tie!\n Player wins: " << pTally << " Computer wins: " << cTally << "\n"); // if it is a tie, print this line 

  }
  win(log, pTally, cTally); // win function after the player/computer gets 5 wins 
  
  return 0;
}

void playerTurn(int &pChoice) { // player turn function, pChoice is passed through by reference 
  bool validInput = false; // valid input boolean value set to false 
  /*(choice = 1) ? void(pchoice == rock) :
    (choice = 2) ? void(pchoice == paper) :
      (choice = 3) ? void(pchoice == scissors) :
        void(cout << "\nThat input was invalid, try again");*/


  while(!validInput) { // while valid input is not true 
    cout << "\nIt's your turn:\n";
    cout << "1.) Rock\n2.) Paper\n3.) Scissors\n\n";
    cin >> pChoice; 

    if (cin.fail()) { // if the input is a wrong data type, run the block of code below 
            cout << "Invalid input! Expected an integer."
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),
                       '\n');
        }
        else {
            validInput = true; // valid input is set to true, exits the if statement 
        }

    (pChoice == 1) ? void(validInput = true) :
      (pChoice == 2) ? void(validInput = true) :
        (pChoice == 3) ? void(validInput = true) :
          void(cout << "\nInput invalid, try again:\n"); // if a wrong number is input, rerun the function 
  }
}
/*void computerTurn(bool cWin) {
  Choices cchoice;
  //int randNum = rand() % 3;
  double randNum = rand()/static_cast<double>(RAND_MAX+1);

  int cChoice = 1 + static_cast<int>(x * (max - min));
  
  return cChoice; 
  cout << "It's the Computer's turn:\n";
  (randNum = 1) ? void( cout << "The computer chose rock") :
    (randNum = 2) ? void(cout << "The computer chose paper") :
      (randNum = 3) ? void(cout << "The computer chose scissors")
 // (randNum = 1) ? void (cchoice = rock)
}*/

/*void computerTurn(int cChoice) {
}*/

void win(vector<string> log, int pTally, int cTally) { 
  barrier();
  cout << "\nRESULTS OVERALL:\n";
  for(auto i: log) { // print out the entire log vector 
    cout << i << "\n";
  }
  cout << "\nEND GAME:\n";
  (pTally > cTally) ? cout << "\nCONGRATS PLAYER, YOU WON!\nFinal Scores: Player wins: " << pTally << " Computer wins: " << cTally: // print if player wins overall
    (pTally < cTally) ? cout << "\nBetter luck next time!\nFinal Scores: Player wins: " << pTally << " Computer wins: " << cTally: // print if commputer wins overall
      cout << "Congrats you broke the program!";
}

void barrier() { // barrier function to create lines to seperate turns 
  for (int i = 0; i < 20; i++) {
    cout << "=";
  }
}



