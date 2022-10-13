#include "menu.h"
#include "Classes/Dados.h"
using namespace std;

Menu::Menu() {
    this->menuState.push(MAIN_MENU);
    getMenu();
}

void Menu::getMenu() {
    if (!menuState.empty()) {
        switch (menuState.top()) {
            case 0:
                mainMenu();
                break;
            case 1:
                consultasMenu();
                break;
            case 2:
                modificacoesMenu();
                break;
            case 3:
                efetivacaoMenu();
                break;
        }
    }
}

void Menu::mainMenu() {
    cout << endl << "--------------------------\n";
    cout << "Gestão de Horários - FEUP" << endl;
    cout << "--------------------------\n";

    cout << "\t" << "[1] CONSULTAS\n";
    cout << "\t" << "[2] MODIFICAÇÕES\n";
    cout << "\t" << "[3] EFETIVAÇÃO DE PEDIDOS\n";

    cout << "\n\t" << "[0] Exit\n";

    int escolha;
    cout << "\t" << "Escolha: ";
    cin >> escolha;

    while(!cin.good() || escolha < 0 || escolha > 3) {
        cin.clear();
        cin.ignore();

        cout << endl << "\t" << "Introduza um número\n";
        cout << "\t" << "Escolha: ";

        cin >> escolha;

    }
    cin.ignore();

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(CONSULTAS_MENU);
            break;
        case 2:
            menuState.push(MODIFICACOES_MENU);
            break;
        case 3:
            menuState.push(EFETIVACAO_MENU);
            break;

    }
    getMenu();
}

void Menu::consultasMenu() {
    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "[1] Ocupação" << endl;
        cout << "[2] Horários" << endl;
        cout << "[3] Repetentes" << endl;
        cout << endl;
        cout << "[0] Voltar atrás" << endl;


        cout << "Escolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 3) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 3);

    switch (escolha) {
        case 0: menuState.pop(); break;
    }
    getMenu();
}

void Menu::modificacoesMenu() {
    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "[1] Inscrever Estudante" << endl;
        cout << "[2] Desinscrever Estudante" << endl;
        cout << "[3] Alteraçao de Turma/UC" << endl;
        cout << "[4] Alteração de várias turmas/UCs" << endl;
        cout << endl;
        cout << "[0] Voltar atrás" << endl;


        cout << "Escolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 4) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 4);

    switch (escolha) {
        case 0: menuState.pop(); break;
    }
    getMenu();
}

void Menu::efetivacaoMenu() {
    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "[1] Listar Pedidos" << endl;

        cout << endl;
        cout << "[0] Voltar atrás";


        cout << "Escolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 1) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 1);

    switch (escolha) {
        case 0: menuState.pop(); break;
    }
    getMenu();
}

// Colocar os outros menus
// Colocar aqui as funções de listagem (que estão relacionadas
// com as escolhas dos menus