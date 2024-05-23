#include <stdio.h>

#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

#define CLEAR "\e[1;1H\e[2J"

#define COLOR_RESET "\033[0m"

// Cores básicas
#define COLOR_BLACK "\033[30m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"

// Cores brilhantes
#define COLOR_BRIGHT_BLACK "\033[90m"
#define COLOR_BRIGHT_RED "\033[91m"
#define COLOR_BRIGHT_GREEN "\033[92m"
#define COLOR_BRIGHT_YELLOW "\033[93m"
#define COLOR_BRIGHT_BLUE "\033[94m"
#define COLOR_BRIGHT_MAGENTA "\033[95m"
#define COLOR_BRIGHT_CYAN "\033[96m"
#define COLOR_BRIGHT_WHITE "\033[97m"

// Fundos de cores básicas
#define COLOR_BLACK_BG "\033[40m"
#define COLOR_RED_BG "\033[41m"
#define COLOR_GREEN_BG "\033[42m"
#define COLOR_YELLOW_BG "\033[43m"
#define COLOR_BLUE_BG "\033[44m"
#define COLOR_MAGENTA_BG "\033[45m"
#define COLOR_CYAN_BG "\033[46m"
#define COLOR_WHITE_BG "\033[47m"

// Fundos de cores brilhantes
#define COLOR_BRIGHT_BLACK_BG "\033[100m"
#define COLOR_BRIGHT_RED_BG "\033[101m"
#define COLOR_BRIGHT_GREEN_BG "\033[102m"
#define COLOR_BRIGHT_YELLOW_BG "\033[103m"
#define COLOR_BRIGHT_BLUE_BG "\033[104m"
#define COLOR_BRIGHT_MAGENTA_BG "\033[105m"
#define COLOR_BRIGHT_CYAN_BG "\033[106m"
#define COLOR_BRIGHT_WHITE_BG "\033[107m"

// Tons de cinza
#define COLOR_GRAY "\033[90m"
#define COLOR_DARK_GRAY "\033[92m"
#define COLOR_LIGHT_GRAY "\033[97m"

// Fundos de tons de cinza
#define COLOR_GRAY_BG "\033[100m"
#define COLOR_DARK_GRAY_BG "\033[102m"
#define COLOR_LIGHT_GRAY_BG "\033[107m"

// Cores adicionais
#define COLOR_ORANGE "\033[38;5;202m"
#define COLOR_PURPLE "\033[38;5;56m"
#define COLOR_TURQUOISE "\033[38;5;39m"
#define COLOR_PINK "\033[38;5;250m"

// Fundos de cores adicionais
#define COLOR_ORANGE_BG "\033[48;5;202m"
#define COLOR_PURPLE_BG "\033[48;5;56m"
#define COLOR_TURQUOISE_BG "\033[48;5;39m"
#define COLOR_PINK_BG "\033[48;5;250m"

// Efeitos de texto
#define TEXT_BOLD "\033[1m"
#define TEXT_ITALIC "\033[3m"
#define TEXT_UNDERLINE "\033[4m"
#define TEXT_STRIKE "\033[9m"
#define TEXT_INVERT "\033[7m"
#define TEXT_HIDE "\033[8m"

void Clear();
void DefaultColors();
void SetColor(const char *color);
void SetTextEffect(const char *effect);

#endif
