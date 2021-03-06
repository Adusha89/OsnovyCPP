#include <iostream>
#include "header.hpp"
/* #include "logic.hpp"
#include "io.hpp"
#include "ai.hpp" */
#include "math.h"

int main() {
    

    // while game is not over
    //  - read player input / run AI
    //  - apply move
    //  - process new game state
    //  - print turn outcome
    print_greeting();

    GameField field;
    bool flag = true;//По умолчанию ходит Х
    PlayerSign current_player = get_current_player(flag);
    Get_Field(&field);
    
    TurnOutCome outcome {};
    
    do {
        Pos pos;

        if(current_player == PlayerSign::X) {
            pos = query_player_move(field);
        } else {
            pos = query_ai_move(field);
        } 
         
        set_cell(field, pos.x, pos.y, sign_to_cell(current_player, flag));       

        outcome = check_turn_outcome(field);
        print_field(field);
        current_player = next_player(current_player);

    } while (outcome == TurnOutCome::CONTINUE);

    print_game_outcome(outcome);
    delete [] field;
    return 0;
}