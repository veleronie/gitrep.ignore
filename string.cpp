#pragma warning (disable:4996)
#include "iostream"
#include "cstring"
#include "cmath"
using namespace std;

int poisk(const char* str, char simvol) // 1 задание
{
    if (strlen(str) != 0)
    {
        int n = strlen(str);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == simvol) count++;
        }
        return count;
    }
    else return -1;
}

void exchange(char* str, char simvol) // 2 задание
{
    const int length = 81;
    char str_copy[length];
    strcpy(str_copy, str);
    int n = strlen(str_copy);
    if (strlen(str_copy) != 0)
    {
        int n = strlen(str);
        for (int i = 0; i < n; i++)
        {
            if (isdigit(str_copy[i])) str_copy[i] = simvol;
        }
        cout << str_copy << endl;
        cout << endl;
    }
    else cout << "ERROR";
}

void sort(char* str) // 3 задание
{
    const int length = 81;
    char str_copy[length];
    strcpy(str_copy, str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if ((int)str_copy[j] < (int)str_copy[j - 1]) swap(str_copy[j], str_copy[j - 1]);
        }
    }
    cout << str_copy << endl;
}
int glasnie(char* str)
{
    int n = strlen(str);
    int sum = 0;
    char* s = new char[n + 1];
    strcpy(s, str);
    for (int i = 0; i < n; i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < n; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u' || s[i] == 'y')
            sum++;
    return sum;
    delete[]s;
}

void different(char* str)  // 4 задание
{
    const int length = 81;
    char str_copy[length];
    strcpy(str_copy, str);
    int k = 0;
    int n = strlen(str_copy);
    if (strlen(str_copy) != 0)
    {
        bool f;

        for (int i = 0; i < n; i++)
        {
            f = true;
            for (int j = 0; j < n; j++)
                if (str_copy[i] == str_copy[j] && i != j)
                    f = false;
            if (f)
                k++;
        }
        cout << "Количество разных символов: " << k << endl;
        cout << endl;
    }
    else cout << "ERROR";
}

void repeats(char* str) // 5 задание
{
    int count, countmax = 0, imax = 0;
    char temp[1];
    for (int i = 0; i < strlen(str); i++)
    {
        count = 0;
        temp[0] = str[i];
        for (int j = 0; j < strlen(str); j++)
        {
            if (temp[0] == str[j]) count++;
        }
        if (count > countmax)
        {
            imax = i;
            countmax = count;
        }
    }
    cout << "Элемент встречающийся максимальное количество раз:" << str[imax] << endl;
    cout << endl;
}
int digit(char* str)
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i])) count++;
    }
    return count;
}
void forWords(char* str) // 6 задание
{
    const int length = 81;
    char* arr[length];
    char* temp;
    char* p = strtok(str, "!@#$%^&*()_+{}[],./-+=<>~");
    int i = 1, size;
    arr[0] = p;
    cout << "Вывод слов столбиком:\n";
    while (p != NULL)
    {
        cout << p << endl;
        p = strtok(NULL, "!@#$%^&*()_+{}[],./-+=<>~");
        arr[i] = p;
        i++;
    }
    size = i - 2;
    cout << "Вывод по алфавиту:\n";
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Вывод по длине:\n";
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (strlen(arr[i]) > strlen(arr[j]))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Вывод по количеству гласных:\n";
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (glasnie(arr[i]) > glasnie(arr[j]))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "Вывод по количеству цифр:\n";
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (digit(arr[i]) > digit(arr[j]))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
}


void numbs(char* str)
{
    const int length = 81;
    char* arr[length];
    char* temp;
    char* p = strtok(str, "!@#$%^&*()_+{}[],./-+=<>~AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
    int i = 1, size;
    arr[0] = p;
    cout << "Вывод цифр:\n";
    while (p != NULL)
    {
        cout << p << " ";
        p = strtok(NULL, "!@#$%^&*()_+{}[],./-+=<>~AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz");
        arr[i] = p;
        i++;
    }
    cout << endl;
    size = i - 2;
    cout << "Вывод слова–числа по возрастанию числовых величин, представленных в них:\n";
    for (int i = 0; i <= size; i++)
    {
        for (int j = i; j <= size; j++)
        {
            if (atoi(arr[i]) > atoi(arr[j]))
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
}
int words(char* str, char* word)
{
    char* q = str;
    int n = 0;
    while ((q = strstr(q, word)) != NULL)
    {
        n++;
        q++;
    }
    return(n);
}
void personalTask(char* str, char* word, char* zamena)
{
    char* p;
    char* p1;
    p = strstr(str, word);
    while ((p = strstr(p, word)) != NULL)
    {
        for (int i = 0; i < strlen(word); i++) p++;
        strncpy(p, zamena, strlen(zamena));
    }
    cout << str << endl;

}
int main()
{
    setlocale(LC_ALL, ".1251");
    cout << "Я люблю английский алфавит.\n";
    const int nm = 80;
    char string[nm + 1];
    char copy[nm];
    char copy2[nm];
    cout << "Введите строку:";
    cin.getline(string, nm + 1);
    if (strlen(string) != 0)
    {
        strcpy(copy, string);
        strcpy(copy2, string);
        cout << "Число повторений символа \"1\"" << poisk(string, '1') << endl; //1
        cout << "Заменить в строке все символы-цифры на заданный символ \"f\"" << endl;
        exchange(string, 'f'); //2
        cout << "Упорядочить символы в строке по возрастанию(убыванию) их кодов\n";
        sort(string);
        different(string);
        repeats(string);
        forWords(string);
        numbs(copy);
        char slovo[nm];
        cout << "Введите подстроку для 8-ого задания:";
        cin.getline(slovo, nm);
        cout << endl;
        cout << "Количество повторений строки " << slovo << " = " << words(copy2, slovo) << endl;
        cout << "Введите строку(для замены) для 10-ого задания(заданное слово берется из ввода для 8-ого задания):";
        char zamena[nm];
        cin.getline(zamena, nm);
        personalTask(copy2, slovo, zamena);
    } //ggg
    //ff
    else cout << "У вас пустая строка. Попробуйте еще раз.\n";
    return 0; //jjj
}
