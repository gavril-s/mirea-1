#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <limits>

int main()
{
    system("chcp 65001 > nul");
    srand(time(NULL));

    const char* ESC = "\033[";
    const char* WHITE_BACKGROUD = "47";
    const char* WHITE_TEXT = "37";
    const char* BLACK_BACKGROUND = "40";
    const char* BLACK_TEXT = "30";  
    const char* RESET = "\033[m";

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            const char* background_color;
            const char* text_color;

            if ((i + j) % 2 == 0)
            {
                background_color = WHITE_BACKGROUD;
                text_color = BLACK_TEXT;
            }
            else 
            {
                background_color = BLACK_BACKGROUND;
                text_color = WHITE_TEXT;
            }

            std::string num = std::to_string(std::rand() % 100 + 1);
            while (num.length() < 3)
            {
                num = " " + num;
            }
            
            std::cout << ESC << background_color << ";" << text_color << "m" << num << RESET;
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
    
    int color_choice = 0;
    std::cout << "Выберите цвет фигур (0 - белые, 1 - чёрные): ";
    while (!(std::cin >> color_choice))
    {
        std::cout << "Неверный ввод!" << std::endl;
        std::cout << "Выберите цвет фигур (0 - белые, 1 - чёрные): ";

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << color_choice;

    return 0;
}