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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int max = 80;

	char str1[max + 1];
	cout << "Решение задачи №1. Число повторений заданного символа" << endl  << "Введите строку" << endl;
	cin.getline(str, max + 1);
  cout << "Введите символ" << endl;
        char simvol;
        cin >> simvol;
        cout << "Число повторений символа " << simvol << ": " << poisk(str1, simvol) << endl; //1

	char str2[max + 1];
	cout << "Решение задачи №2. Замена в строке всех цифр на заданный символ" << endl << endl << "Введите строку" << endl;
	cin.getline(str2, max + 1);
  cout << "Введите символ" << endl;
       cin >> simvolchange;
       cout << "Заменить в строке все символы-цифры на заданный символ " << simvolchange << ": " << endl;
	cout << endl << exchange(str2, simvolchange) << endl;

	char str3[max + 1];
	cout << "Решение задачи №3.1. Символы по возрастанию" << endl << endl << "Введите строку" << endl;
	cin.getline(str3, max + 1);
	cout << endl << "Ответ: " << increase(str2) << endl << endl;

	char str3[max + 1];
	cout << "Решение задачи №3.2. Символы по убыванию" << endl;
	cout << endl << "Ответ: " << decrease(str3) << endl << endl;

	char str4[max + 1];
	cout << "Решение задачи №4. Количество различных символов" << endl << endl << "Введите строку" << endl;
	cin.getline(str4, max + 1);
	cout << endl << "Ответ: " << diffsymbols(str4) << endl << endl;

	char str5[max + 1];
	cout << "Решение задачи №5. Часто встречающийся символ" << endl << endl << "Введите строку" << endl;
	cin.getline(str5, max + 1);
	cout << endl << "Ответ: " << different(str5)  << endl;

	char str6[max + 1];
	cout << "Решение задачи №6. Вывод слов" << endl << endl << "Введите строку" << endl;
	cin.getline(str6, max + 1);
	cout << endl << endl;

	int n = strlen(str6);
	char** words = new char* [n + 1];
	int k = 0;
	char* p = strtok(str6, " ,.-;^&*#,:()");
	while (p != NULL)
	{
		words[k++] = p;
		p = strtok(NULL, " ,.-;^&*#:()");
	}
	cout << "Слова" << endl << endl;
	if (k > 0)
	{
		for (int i = 0; i < k; i++)
			cout << words[i] << endl;

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k - i - 1; j++)
				if (strcmp(words[j], words[j + 1]) > 0)
				{
					p = words[j];
					words[j] = words[j + 1];
					words[j + 1] = p;
				}
		}
		cout << endl << "Слова после сортировки по алфавиту" << endl << endl;
		for (int i = 0; i < k; i++)
			cout << words[i] << endl;

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k - i - 1; j++)
				if (strlen(words[j]) > strlen(words[j + 1]))
				{
					p = words[j];
					words[j] = words[j + 1];
					words[j + 1] = p;
				}
		}
		cout << endl << "Слова после сортировки по длине" << endl << endl;
		for (int i = 0; i < k; i++)
			cout << words[i] << endl;
	}
	else cout << "В строке нет слов" << endl;
	cout << endl;

	char str7[max + 1];
	cout << "Решение задачи №7. Вывод цифр" << endl << endl << "Введите строку" << endl;
	cin.getline(str7, max + 1);
	cout << endl << endl;

	char** digits = new char* [n + 1];
	int i = 0, l = 0;
	int len = strlen(str7);
	while (i < len)
	{
		while (!isdigit(str7[i]) && i < len) i++;
		if (i < len)
		{
			digits[l++] = &str7[i];
			while (isdigit(str7[i])) i++;
			str7[i] = '\0';
		}
	}

	if (l > 0)
	{
		cout << "Числа" << endl << endl;
		for (int i = 0; i < l; i++)
			cout << digits[i] << " ";

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l - i - 1; j++)
				if (strcmp(digits[j], digits[j + 1]) > 0)
				{
					char* s = digits[j];
					digits[j] = digits[j + 1];
					digits[j + 1] = s;
				}
		}
		cout << endl << endl;
		cout << "Числа после лексикографической сортировки" << endl << endl;
		for (int i = 0; i < l; i++)
			cout << digits[i] << " ";

		int* mas = new int[l];
		for (int i = 0; i < l; i++)
			mas[i] = atoi(digits[i]);

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l - i - 1; j++)
				if (mas[j] > mas[j + 1])
				{
					int y = mas[j];
					mas[j] = mas[j + 1];
					mas[j + 1] = y;
				}
		}
		cout << endl << endl;
		cout << "Числа после сортировки по возрастанию" << endl << endl;
		for (int i = 0; i < l; i++)
			cout << mas[i] << " ";
		cout << endl << endl;
	}
	else cout << "В строке нет чисел" << endl;

	char str8[max + 1];
	char word[max / 2];
	cout << "Решение задачи №8. Количество слов" << endl << endl << "Введите строку" << endl;
	cin.getline(str8, max + 1);
	cout << endl << "Введите слово" << endl;
	cin.getline(word, max / 2);
	cout << "Ответ: " << wordsamount(str8, word) << endl << endl;
}
