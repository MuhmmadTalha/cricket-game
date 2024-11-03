#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player
{
protected:
    string name1;
    string name2;

public:
    Player(string n1, string n2) : name1(n1), name2(n2) {}

    void setNames()
    {
        cout << "Player 1 choose name: ";
        cin >> name1;
        cout << "Player 2 choose name: ";
        cin >> name2;
    }

    string getName1() const { return name1; }
    string getName2() const { return name2; }
};

class Choices : public Player
{
protected:
    char choice;
    int outcome;
    string firstmover;
    string secondmover;
    string tossW;
    string tossL;
    string bater;
    string baller;
    int bb;

public:
    Choices(string n1, string n2, char c) : Player(n1, n2), choice(c) {}

    void selectChoices()
    {
        int tempc;

        while (true)
        {
            cout << "Who's going for the first choice, " << name1 << " or " << name2 << " (1 or 2)? ";
            cin >> tempc;

            if (tempc == 1)
            {
                firstmover = name1;
                secondmover = name2;
                break;
            }
            else if (tempc == 2)
            {
                firstmover = name2;
                secondmover = name1;
                break;
            }
            else
            {
                cout << "Invalid input! Please try again." << endl;
            }
        }
        cout << endl;

        cout << "Make a choice, " << firstmover << ": Head (H) or Tail (T): ";
        cin >> choice;

        if (choice == 'H' || choice == 'h' || choice == 'T' || choice == 't')
        {
            cout << "Flipping coin... Chances are 50/50;" << endl;

            outcome = rand() % 2;
            if (outcome == 1)
                cout << "It's Heads!" << endl;
            else
                cout << "It's Tails!" << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
            selectChoices();
        }
    }

    void tossResult()
    {
        if ((choice == 'H' || choice == 'h') && outcome == 1 || (choice == 'T' || choice == 't') && outcome == 0)
        {
            tossW = firstmover;
            tossL = secondmover;
            cout << "Congratulations! " << firstmover << ", you have won the toss." << endl;
            cout << "What would you choose, batting(1) or bowling(2)? : ";
            cin >> bb;
        }
        else
        {
            tossW = secondmover;
            tossL = firstmover;
            cout << "Sorry, " << firstmover << ", you have lost the toss." << endl;
            cout << secondmover << ", what would you choose, batting(1) or bowling(2)? : ";
            cin >> bb;
        }
    }

    void chooseRole()
    {
        if (bb == 1)
        {
            cout << tossW << " has decided to bat! " << tossL << " will now bowl." << endl;
            bater = tossW;
            baller = tossL;
        }
        else if (bb == 2)
        {
            cout << tossW << " has decided to bowl! " << tossL << " will now bat." << endl;
            bater = tossL;
            baller = tossW;
        }
        else
        {
            cout << "Invalid choice for batting or bowling. Please enter 1 for batting or 2 for bowling." << endl;
            tossResult();
            chooseRole();
        }
    }

    string getBatter() const { return bater; }
    string getBowler() const { return baller; }
};

class Gameplay : public Choices
{
private:
    int baterMove;
    int ballerMove;
    int score = 0;

public:
    Gameplay(string n1, string n2, char c) : Choices(n1, n2, c) {}

    void moveSelection()
    {
        for (int i = 0; i < 7; i++)
        {
            cout << "." << endl;
        }

        for (int i = 6; i >= 0; i--)
        {
            cout << getBatter() << " choose your run(0-6)!: ";
            cin >> baterMove;

            for (int j = 0; j < 3; j++)
            {
                cout << "." << endl;
            }
            cout << getBowler() << " choose your move(0-6)!: ";
            cin >> ballerMove;

            cout << endl
                 << "Matching Result!..";
            for (int k = 0; k < 3; k++)
            {
                cout << "." << endl;
            }
            moveChecker();

            cout << endl
                 << "Remaining balls: " << i << endl;
        }
    }

    void moveChecker()
    {
        if (baterMove == ballerMove)
        {
            cout << getBatter() << " is OUT! with a score of " << score << ". Now " << getBowler() << "'s turn to bat." << endl;
            // Reset or swap roles for the next innings can be handled here
        }
        else if (baterMove >= 0 && baterMove <= 6)
        {
            score += baterMove;
            cout << "Nice shot! " << getBatter() << " scored " << baterMove << " runs, total score: " << score << endl;
        }
        else
        {
            cout << "Invalid move by " << getBatter() << ". Please choose a run between 0 and 6." << endl;
        }
    }
};

int main()
{
    srand(time(0));
    cout << "Welcome to the Cricket Game Simulation!" << endl;

    Gameplay game("", "", ' ');
    game.setNames();
    game.selectChoices();
    game.tossResult();
    game.chooseRole();
    game.moveSelection();

    return 0;
}
