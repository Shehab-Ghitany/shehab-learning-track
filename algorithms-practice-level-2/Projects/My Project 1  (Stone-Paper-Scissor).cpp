#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum enchoices {Stone=1,Paper=2,Scissors=3};

string whoiswin(int PChoice, int CChoice)
{
    if (PChoice == CChoice)
    {
        return "[No Winner]";
    }
    else if ((PChoice == Stone && CChoice == Scissors)
        || (PChoice == Paper && CChoice == Stone)
        || (PChoice == Scissors && CChoice == Paper))
    {
        return "Player";
    }
    else
    {
        return "Computer";
    }

}

string ChoiceName(int numberofChoice)
{
    if (numberofChoice == Stone)
        return "Stone";
    else if (numberofChoice == Paper)
    {
        return "Paper";
    }
    else
    {
        return "Scissors";
    }

}

void Colors(string winner)
{
    if (winner == "[No Winner]")
    {
        system("color 6F");
    }
    else if (winner == "Player")
    {
        system("color AF");
    }
    else
    {
        system("color 4F");
    }
}

void ScreenResult(int i , int PChoice ,int CChoice )
{
    string winner = whoiswin(PChoice, CChoice);

    cout << endl;
    cout << "____________Round [" << i << "] ____________" << endl << endl;
    cout << "Player1  Choice: " << ChoiceName(PChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(CChoice) << endl;
    cout << "Round Winner   : " << winner << endl;
    cout << "___________________________________" << endl << endl;
    Colors(winner);
}



int RrandomNumber(int from, int to)
{
    int Randomnum = rand() % (to - from + 1) + from;

    return Randomnum;
}

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}
int ReadnumberFromTo(string Message ,int From, int To)
{
    int number;

    do
    {
        cout << Message;
        cin >> number;

    } while (number < From || number > To);

    return number;
}

int ReadRounds()
{
    int Rounds;

    cout << "How many rounds the game will be ? " << endl;
    cin >> Rounds;

    return Rounds;
}


void RoundsResult(int& Rounds, int& PChoice, int& CChoice, int& CounterPlayer, int& CounterComputer, int& CounterDraw)
{
    CounterPlayer = 0;
    CounterComputer = 0;
    CounterDraw = 0;


    for (int i = 0; i < Rounds; i++)
    {
        cout << "\nRound [" << i + 1 << "] begins: " << endl << endl;

        PChoice = ReadnumberFromTo("Your Choise: [1]:Stone, [2]Paper, [3]:Scissors ? ",1, 3);

        CChoice = RrandomNumber(1, 3);

        ScreenResult(i +1, PChoice, CChoice);


        string winner = whoiswin(PChoice, CChoice);

        if (winner == "[No Winner]")
        {
            ++CounterDraw;
        }
        else if (winner == "Player")
        {
            ++CounterPlayer;
        }
        else
        {
            ++CounterComputer;
        }

    }

}

string WhoisFinalWinner(int CounterPlayer, int CounterComputer, int CounterDraw)
{
    if (CounterPlayer > CounterComputer)
    {
        return "Player";
    }
    else if (CounterComputer > CounterPlayer)
    {
        return "Computer";
    }
    else
    {
        return "No Winner";
    }

}

void GameOver(int Rounds , int CounterPlayer, int CounterComputer, int CounterDraw)
{
    string WinnerIs = WhoisFinalWinner(CounterPlayer, CounterComputer, CounterDraw);


    cout << endl << endl;
    cout << "\t\t____________________________________________________________" << endl << endl;
    cout << "\t\t\t\t +++ G a m e  O v e r +++ " << endl;
    cout << "\t\t____________________________________________________________" << endl << endl;
    cout << "\t\t_______________________ [Game Results  ] ___________________" << endl << endl;
    cout << "\t\tGame Rounds         : " << Rounds << endl;
    cout << "\t\tPlayer1 won times   : " << CounterPlayer << endl;
    cout << "\t\tComputer won times  : " << CounterComputer << endl;
    cout << "\t\tDraw times          : " << CounterDraw << endl;
    cout << "\t\tFinal Winner        : " << WinnerIs << endl;
    cout << "\t\t____________________________________________________________" << endl << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    char newGame;

    do
    {
        int arr[100];
        int PChoice = 0;
        int CChoice = 0;
        int Rounds = ReadRounds();

        int CounterPlayer = 0;
        int CounterComputer = 0;
        int CounterDraw = 0;



        RoundsResult(Rounds, PChoice, CChoice, CounterPlayer, CounterComputer, CounterDraw);

        GameOver(Rounds, CounterPlayer, CounterComputer, CounterDraw);

        cout << "Do you want to play again? Y/N? ";
        cin >> newGame;
        cout << endl << endl;
    } while (newGame == 'Y' || newGame == 'y');

    return 0;
}