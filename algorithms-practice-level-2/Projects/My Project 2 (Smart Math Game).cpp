#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enGameOP { Add = 1, Sub = 2, Mul = 3, Div = 4, OPMix = 5 };

int wrongCounter;
int rightCounter;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int NumberOfQuestions()
{
    int nums;

    do {
        cout << "How Many Questions do you want to answer (from 1 to 100) ? ";
        cin >> nums;

    } while (nums <= 0 || nums > 100);

    return nums;
}

enGameLevel GameLevel()
{
    int choicegamelevel;

    do {
        cout << "Enter Question Level  [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
        cin >> choicegamelevel;

    } while (choicegamelevel <= 0 || choicegamelevel > 4);

    return (enGameLevel)choicegamelevel;
}

enGameOP GameOP()
{
    int choiceOP;

    do {
        cout << "Enter Opertaion Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> choiceOP;

    } while (choiceOP <= 0 || choiceOP > 5);

    return (enGameOP)choiceOP;
}

string arrOP(enGameOP OP)
{
    string arrOP[5] = { "+" , "-" , "*" , "/"  , "OPMix"};
    return arrOP[OP - 1];
}

string arrLevel(enGameLevel Level)
{
    string arrLevel[4] = { "Easy" , "Med" , "Hard" , "Mix" };
    return arrLevel[Level - 1];
}


enGameOP randomOPMix()
{
    enGameOP RandomOp = (enGameOP)RandomNumber(1, 4);
    return RandomOp;
}

int calcOP(int calc, int calc2, enGameOP OP)
{
    
    if (OP == enGameOP::Add)
    {
        return calc + calc2;
    }
    else if (OP == enGameOP::Sub)
    {
        return calc - calc2;
    }
    else if (OP == enGameOP::Div)
    {
        return calc / calc2;
    }
    else if (OP == enGameOP::Mul)
    {
        return calc* calc2;
    }

}



void ifitRightOrNot(int num, int theRightCalc)
{

    if (num == theRightCalc)
    {
        cout << "Right Answer :-)" << endl;
        system("color 2F");

        rightCounter++;
    }
    else
    {
        cout << "\aWrong Answer :-(" << endl;
        cout << "The right answer is:  " << theRightCalc << endl;
        system("color 4F");

        wrongCounter++;
    }

}


void EasyLevel(enGameOP OP)
{
    short num;
    short calc = RandomNumber(1, 10);
    short calc2 = RandomNumber(1, 10);

    cout << calc << endl;
    cout << calc2 << " " << arrOP(OP) << endl;
    cout << "_______________" << endl << endl;
    cin >> num;

    int theRightCalc = calcOP(calc, calc2, OP);

    ifitRightOrNot(num, theRightCalc);

}

void MedLevel(enGameOP OP)
{
    short num;
    short calc = RandomNumber(10, 50);
    short calc2 = RandomNumber(10, 50);

    cout << calc << endl;
    cout << calc2 << " " << arrOP(OP) << endl;
    cout << "_______________" << endl << endl;
    cin >> num;

    int theRightCalc = calcOP(calc, calc2, OP);


    ifitRightOrNot(num, theRightCalc);
}


void HardLevel(enGameOP OP)
{
    short num;
    short calc = RandomNumber(50, 100);
    short calc2 = RandomNumber(50, 100);

    cout << calc << endl;
    cout << calc2 << " " << arrOP(OP) << endl;
    cout << "_______________" << endl;
    cin >> num;

    int theRightCalc = calcOP(calc, calc2, OP);

    ifitRightOrNot(num, theRightCalc);

}



void TheLevelThatChoiced(enGameLevel Level , enGameOP OP , int i)
{
    enGameOP FinalOP = (OP == enGameOP::OPMix) ? randomOPMix() : OP;

    if (Level == enGameLevel::Easy)
    {
        EasyLevel(FinalOP);
    }
    else if (Level == enGameLevel::Med)
    {
        MedLevel(FinalOP);
    }
    else if (Level == enGameLevel::Hard)
    {
        HardLevel(FinalOP);
    }
    else
    {
        if (i % 3 == 1)
            EasyLevel(FinalOP);
        else if (i % 3 == 2)
            MedLevel(FinalOP);
        else
            HardLevel(FinalOP);
    }

}

void ResetScreen()
{
    system("cls");
    system("color 0F");

}

void showQuestions(int i , int &N , enGameLevel &Level, enGameOP &OP)
{
     N = NumberOfQuestions();
     Level = GameLevel();
     OP = GameOP();

    for (i = 1; i <= N; i++)
    {
        cout << endl << endl << "Question [" << i << '/' << N << ']' << endl << endl;

        TheLevelThatChoiced(Level, OP, i);

    }

}


void showResults(int N, enGameLevel Level, enGameOP OP)
{
    string spaces = "______________________________";

        cout << endl << endl << spaces << endl;

        if (rightCounter >= wrongCounter)
        {
            cout << endl << "  Final Results is PASS :-)";
        }
        else
        {
            cout << endl << "  Final Results is Fail :-(";
        }

        cout << endl << spaces << endl << endl;

        cout << "Number of Questions:  " << N << endl;
        cout << "Question Level     :  " << arrLevel(Level) << endl;
        cout << "OpType             :  " << arrOP(OP) << endl;
        cout << "Number of Right Answers:  " << rightCounter << endl;
        cout << "Number of Wrong Answers:  " << wrongCounter << endl;

        cout << endl << spaces << endl << endl;


}



int main()
{
    srand((unsigned)time(NULL));

    int i = 1;
    int N = 0;
    enGameLevel Level;
    enGameOP OP;

    char Again;

    do
    {
        ResetScreen();

        ::wrongCounter = 0;
        ::rightCounter = 0;

        showQuestions(i, N, Level, OP);
        showResults(N, Level, OP);
        cout << "Do you want to play again? Y/N?";
        cin >> Again;

    } while (Again == 'Y' || Again == 'y');

    return 0;
}