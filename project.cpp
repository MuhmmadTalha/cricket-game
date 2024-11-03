#include <iostream>
#include <string>
#include <vector>
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
private:
    char choice;
    int outcome;
    string firstmover;
    string secondmover;
    string onfield;

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

    void assignRoles()
    {
        if ((choice == 'H' || choice == 'h') && outcome == 1 || (choice == 'T' || choice == 't') && outcome == 0)
        {
            firstmover = onfield;
            cout << "Congratulations! " << firstmover << " you have won the toss. " << endl;
            cout << "What would you choose batting or balling?";
        }

        else
        {
            secondmover = onfield;
            cout << "Sorry, " << firstmover << " you have lost the toss." << endl;
            cout << secondmover << " What would you choose batting or balling?";
        }
    }
};

int main()
{
    srand(time(0));
    cout << "Hello World" << endl;

    Player player("", "");
    player.setNames();

    Choices choice(player.getName1(), player.getName2(), ' ');
    choice.selectChoices();
    choice.assignRoles();

    return 0;
}
