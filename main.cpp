#include "spie.h"
using namespace std;

int main() {
    SPIE_Game game;
    game.print_rules(cout);
    game.print_winning_numbers(cout);

    int score = 5;
    char choice = 'p';

    while (true) {
        choice = game.get_player_choice(cout, cin);

        switch(choice) {
            case 's':
                cout << "CHOICE: s" << endl;
                game.scramble(cout);
                continue;
            case 'i':
                game.print_rules(cout);
                continue; // todo; my change; continue instead of break.
            case 'e':
                cout << "CHOICE: e" << endl;
                cout << "Play again later!!" << endl;
                return 0;
            case 'p':
                cout << "Your score is " << score << endl;
                break;
        }
        game.print_winning_numbers(cout);
        int dice_roll = game.roll_dice();
        cout << "Your dice roll is: " << dice_roll << endl;
        if (dice_roll == 2 || dice_roll == 12) {
            game.add_winning_number();
            cout << "You added a winning number!" << endl;
            game.print_winning_numbers(cout);
        }
        if (game.matches_winning_number(dice_roll)) {
            cout << "You won this round!" << endl;
            score += 5;
        } else {
            cout << "You lost this round!" << endl;
            --score;
            if (score == 0) {
                cout << "You lost this round!" << endl;
                return 0;
            }
        }
    }

}

