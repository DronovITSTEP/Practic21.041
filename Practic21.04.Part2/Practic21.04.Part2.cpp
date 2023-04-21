#include <iostream>
#include "Man.h"

int main()
{
    setlocale(LC_ALL, "");
    Man* m;
    for (int i = 0; i < 3; i++) {
        m = new Man;
        m->Put();
        m->SaveToFile();
    }

    Man::LoadFromFile();
}
