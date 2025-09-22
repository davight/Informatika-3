#include <cmath>
#include <iostream>

void kvadraticka_rovnica(double a, double b, double c)
{
    std::cout << "korene: \n";
    std::cout << (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    std::cout << "\n";
    std::cout << (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}

double nacitaj_cislo(char c)
{
    double n;
    std::cout << "Zadaj cislo " << c << ": ";
    std::cin >> n;
    return n;
}

int main()
{
    double a = nacitaj_cislo('a');
    double b = nacitaj_cislo('b');
    double c = nacitaj_cislo('c');
    kvadraticka_rovnica(a, b, c);
}
