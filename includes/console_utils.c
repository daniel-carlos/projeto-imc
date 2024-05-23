#include "console_utils.h"

void Clear()
{
    printf(CLEAR);
}

void DefaultColors()
{
    printf(COLOR_WHITE);
}

void SetColor(const char *color)
{
    printf("%s", color);
}

void SetTextEffect(const char *effect)
{
    printf("%s", effect);
}