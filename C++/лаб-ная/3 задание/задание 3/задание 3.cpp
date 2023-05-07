// 6 лабка --> вариант 9 --> 3 задание:
// Дан текст. Напечатать все различные слова. Различие 
//строчных и прописных букв во внимание не принимать.

#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // Чтобы отображались русские буквы, включаем эти функции

    char* next = 0;
    const int n = 10000;
    char text[n], * p = NULL; // переменная, куда будем писать наш текст
    std::cout << "Input text:     !!!  (не забудь в конце текста поставить +, чтоб закончить ввод) !!!\n";
    
    std::cin.getline(text, n);// Ввод текста
   
    std::string so = text; // передаем текст в string-переменную
    std::string full_text; // сюда будет заноситься весь текст после всех преобразований

    int last_index = so.find(so[so.size() - 1]); // нашли последный символ строки
    setlocale(LC_ALL, "Russian"); // Чтобы отображались русские буквы, включаем эту функцию
    do
    {
        full_text += so + "\n";
        if (so[last_index] == '+') // если в конце есть +
        {
            full_text = "";
            break;
        }
        else // если в конце нет +
        {
            so = ""; // повтор действий: заново ввод текста с новой строки

            std::cin.getline(text, n);// Ввод текста
            so = text;
            last_index = so.find(so[so.size() - 1]);
        }    
    }
    while (so[last_index] != '+'); // пока в конце не найдёт +
    so.pop_back();
    full_text += so + "\n"; // убрали + из строки и занесли текст в переменную full_text

    std::cout << "-----------------" << '\n';
    std::cout << "All text --> " << full_text << '\n';
    std::cout << "-----------------" << '\n';

    char buf[10000];
    strcpy_s(buf, full_text.c_str()); // Заносим текст в char-переменную
   for (p = strtok_s(buf, " ", &next); p != NULL; p = strtok_s(NULL, " ", &next)) // и делим по словам текст
   {
        std::cout << p << "\n";
   }     
} 