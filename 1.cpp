#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

char BASH_SCRIPT_NAME[14] = "knb_by_cpp.sh";

int main()
{
    std::ofstream script(BASH_SCRIPT_NAME);

    const std::string bash_code = R"(
        #!/usr/bin/bash

        echo "Enter K - kamen, N - nognici, B - paper:"
        read USER_MOVE

        #0 == K, 1 == N, 2 == B
        COMPUTER_MOVE=$(($RANDOM%3))

        if [ "$COMPUTER_MOVE" -eq 0 ]
        then
            echo "Your opponent get kamen"
        elif [ "$COMPUTER_MOVE" -eq 1 ]
        then
            echo "Your opponent get nognici"
        else 
            echo "Your opponent get paper"
        fi


        if [ "$USER_MOVE" = "K" ]
        then
            if [ "$COMPUTER_MOVE" -eq 0 ]
            then
                echo "draw"
            elif [ "$COMPUTER_MOVE" -eq 1 ]
            then
                echo "YOU WIIINNN!!!!"
            else 
                echo "loss("
            fi

        elif [ "$USER_MOVE" = "N" ]
        then
                if [ "$COMPUTER_MOVE" -eq 1 ]
                then
                        echo "draw"
                elif [ "$COMPUTER_MOVE" -eq 2 ]
                then
                        echo "YOU WIIINNN!!!!"
                else 
                        echo "loss("
                fi

        elif [ "$USER_MOVE" = "B" ]
        then
                if [ "$COMPUTER_MOVE" -eq 2 ]
                then
                        echo "draw"
                elif [ "$COMPUTER_MOVE" -eq 0 ]
                then
                        echo "YOU WIIINNN!!!!"
                else 
                echo "loss("
                fi
        else
            echo "Not right input("
            exit $?
        fi
    )";

    script << bash_code;
    script.close();
    
    char command[24] = "chmod +x ";
    std::strcat(command, BASH_SCRIPT_NAME);
    system(command);
    
    std::cout << "bash script generated succesfully" << std::endl << "Name: " << BASH_SCRIPT_NAME << std::endl;
    return 0;
}