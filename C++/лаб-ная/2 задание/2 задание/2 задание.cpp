
#include <iostream>

// Лабка 6 --> Вариант 9 --> Задача 2:
// Дан текст. Проверить, имеется ли в нем баланс открывающих и закрывающих круглых скобок

int main()
{
    const int n = 500;
    char text[n], ** words = NULL, * p = NULL;

    std::cout << "Input text:\n";
    std::cin.getline(text, n); // Ввод текста
    std::cout << "Text:\n";
    std::cout << text << std::endl; // Вывод на экран 

    int count_open = 0;
    int count_close = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '(') count_open++;
        else if (text[i] == ')') count_close++;
    }

    std::cout << "-------------------------" << "\n";
    std::cout << "number of ( ---> " << count_open << "\n";
    std::cout << "number of )  <--- " << count_close << "\n";
    std::cout << "----------RESULT----------" << "\n";

    if (count_open == count_close)
    {
        std::cout << "All right!!! The balance is in the text!" << "\n";
    }
    else
    {
        std::cout << " I'm sorry, it is disbalance" << "\n";
    }
}