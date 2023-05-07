
#include <iostream>
#include <map>
#include <string>

// 6 лабка -> Вариант 9 -> Задача 1: 
/* Дан текст(английский).Найти все слова, содержащие
наибольшее количество гласных латинских букв(a, e, i, o, u).
Пример.Anna, 123 */ 


// Пример для ввода  ---> So, I've been trying to figure out how I could find out if there is a symbol in the string.

char Find(char s[], char n[]); // Объявление метода Find, чтобы Main "увидел" его

  int main()
{
      // ПРИМЕЧАНИЕ: number of vowels --> число гласных букв
      
      // Массив гласных букв, которые нужно находить в слове
      char letters[] = { "aeiou" };
      
      // Объявляем переменную для ввода текста
      const int n = 300;
      char text[n];

      std::cout << "Input text:\n"; 
      std::cin.getline(text, n); // Ввод текста
      std::cout << "Text:\n";
      std::cout << text << std::endl; // Вывод на экран 
      std::cout << "-----------------START----------------" << "\n";

       // Обращаемся к методу Find    
      int x = Find(letters, text);
}

  // Метод Find найдёт max-слова, которые имеют выбранные гласные
  char Find(char s[], char n[])
  {
      char* next = 0;
      char* p = NULL; // p - это слово из текста
      int coint = 0; // Если имеется гл-я в слове, то coint прибавится на 1
      
      std::map<std::string, unsigned> value_text; // Словарь, где будут храниться все слова и их знач-я coint
      std::map<std::string, unsigned> max; // Словарь, где будут только max-знач-я
      max["Max"] = 0;
      max["Second_max"] = 0;

      std::string result ; // П-я для отобр-я слова с max знач-ем
      std::string result_2nd; // П-я для отобр-я слова с max знач-ем на 2-м месте
    
      // 1-ый for делит текст на слова
      for (p = strtok_s(n, " ", &next); p != NULL; p = strtok_s(NULL, " ", &next)) 
      {
          // 1-ой for делит слово на буквы
          for (int i = 0; i < strlen(p); i++)
          {
              int y = 0;
              // While сравнивает каждую букву в слове с массивом гласных
              while (s[y] != '\0')
              {
                  if (p[i] == s[y]) // Если есть 'a','e','i','o','u'
                  {
                      coint++;
                  }
                  y++;
              }
          }
          value_text[p] = coint;
        
          if (value_text[p] > max["Max"]) // Запись max числа и слова с этим знач-ем
          {
              max["Max"] = value_text[p];
              result = p;
          }
          else if (value_text[p] == max["Max"] - 1) // Запись max числа на 2-м месте и слова с этим знач-ем
          {
              max["Second_max"] = value_text[p];
              result_2nd = p;
          }
          std::cout << "Word: " << '<' << p << '>' << " number of vowels --> " << coint << "\n";
          coint = 0;
      }
      // Вывод результата
      std::cout << "------------------FINISH----------------" << "\n";
      std::cout << "Max: "  << result << " --> " << max["Max"] << "\n";
      std::cout << "Max_2nd: " << result_2nd << " --> " << max["Second_max"] << "\n";
      return coint;
  }