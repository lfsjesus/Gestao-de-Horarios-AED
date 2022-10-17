//
// Created by luis on 10-10-2022.
//

#ifndef AED_PROJ_MENU_H
#define AED_PROJ_MENU_H

#include <stack>
/*
 * Menus' definition
 */
#define MAIN_MENU 0
#define CONSULTAS_MENU 1
#define MODIFICACOES_MENU 2
#define EFETIVACAO_MENU 3
#define OCUPACAO_MENU 4


class Menu {
public:
    Menu();
    void mainMenu();
private:
    void getMenu();
    void consultasMenu();
    void modificacoesMenu();
    void efetivacaoMenu();
    void ocupacaoMenu();
    std::stack<short int> menuState;

};


#endif //AED_PROJ_MENU_H
