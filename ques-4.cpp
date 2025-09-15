a)
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);

    strcat(str1, str2);   // concatenate str2 to str1

    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
b)
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    cout << "Reversed string: " << str << endl;
    return 0;
}

c)
#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char str[100], result[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            result[k++] = str[i];
        }
    }
    result[k] = '\0';

    cout << "String after deleting vowels: " << result << endl;
    return 0;
}

d)
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    char str[20][50];  // array of strings

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin.getline(str[i], 50);
    }

    // Bubble sort for strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                char temp[50];
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}
e)
#include <iostream>
using namespace std;

int main() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;

    if (c >= 'A' && c <= 'Z') {
        c = c + 32;   // ASCII conversion
        cout << "Lowercase character: " << c << endl;
    } else {
        cout << "Not an uppercase character!" << endl;
    }

    return 0;
}
