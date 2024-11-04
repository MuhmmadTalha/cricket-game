# Cricket Game Simulation

This is a console-based **Cricket Game Simulation** built in C++. In this interactive game, two players take turns to bat and bowl, aiming to outscore the opponent. The game simulates basic cricket mechanics, allowing players to enjoy a quick game in the terminal with visual elements for immersion.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Example Output](#example-output)
- [License](#license)

## Features

- **Toss Simulation**: Players start with a coin toss to decide who bats or bowls first.
- **Batting and Bowling Turns**: Each player takes turns as the batter and bowler.
- **Scorekeeping**: Tracks runs, wickets, and ball count for each innings.
- **Role Swapping**: After the first innings or when the player is out, roles swap automatically.
- **Winning Outcome**: At the end, the game compares scores and declares the winner.

## Getting Started

### Prerequisites

- C++ Compiler (e.g., `g++`)

### Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/MuhammdTalha/cricket-game-simulation.git
    cd cricket-game-simulation
    ```

2. **Compile the code**:
    ```bash
    g++ cricket_simulation.cpp -o cricket_simulation
    ```

3. **Run the Application**:
    ```bash
    ./cricket_simulation
    ```

## Usage

1. Launch the application in your terminal.
2. Enter names for Player 1 and Player 2.
3. The game will guide you through the toss, where one player picks Heads or Tails.
4. The winner of the toss chooses to bat or bowl first.
5. Players alternate between batting and bowling until the match ends, with results displayed after each innings.

## Example Output

Here’s a sample output for an interactive game session:

```plaintext
Welcome to the Cricket Game Simulation!

Player 1 choose name: Alice
Player 2 choose name: Bob

Who's going for the first choice, Alice or Bob (1 or 2)? 1
Make a choice, Alice: Head (H) or Tail (T): H
Flipping coin... Chances are 50/50;
It's Heads!
Congratulations! Alice, you have won the toss.
What would you choose, batting(1) or bowling(2)? : 1
Alice has decided to bat! Bob will now bowl.

Alice choose your run (0-6): 4
Bob choose your move (0-6): 2
Nice shot! Alice scored 4 runs, total score: 4

Alice choose your run (0-6): 6
Bob choose your move (0-6): 6
Alice is OUT! with a score of 4. Now Bob's turn to bat.

Bob choose your run (0-6): 3
Alice choose your move (0-6): 2
Nice shot! Bob scored 3 runs, total score: 3

... (continues until the end)

Final Scores:
Alice: 4
Bob: 6
Congratulations Bob, you have won the game!
