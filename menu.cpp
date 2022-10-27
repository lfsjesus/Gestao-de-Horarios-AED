#include "menu.h"
#include <iostream>
using namespace std;

Managing m; // Declaring as global variable so all the functions have access

Menu::Menu() {
    this->menuState.push(MAIN_MENU);
    m.readFiles();
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
            case 4:
                alunosMenu();
                break;
            case 5:
                estudantesMenu();
                break;
            case 6:
                horariosMenu();
                break;
            case 7:
                horarioAluno();
                break;
            case 8:
                // add later
                break;
            case 9:
                // add later
                break;
            case 10:
                turmaMenu();
                break;
        }
    }
}

void Menu::mainMenu() {

    cout << endl << "---------------------------------------------\n";
    cout << "DEI - Departamento de Engenharia Informática" << endl;
    cout << "\t\tGestão de Horários - FEUP" << endl;
    cout << "---------------------------------------------\n";

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
        cout << "\t[1] Alunos" << endl;
        cout << "\t[2] Turmas" << endl;
        cout << "\t[3] Unidades Curriculares" << endl;
        cout << "\t[4] Anos" << endl;
        cout << "\t[5] Horários" << endl;
        //cout << "\t[6] Repetentes" << endl; //commenting for now
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 6) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 6);

    switch (escolha) {
        case 0: menuState.pop(); break;
        case 1: {
            menuState.push(ALUNOS_MENU);
            break;
        }
        case 2: {
            menuState.push(TURMAS_MENU);
            break;
        }
        case 3: {
            menuState.push(COURSE_UNITS_MENU);
            break;
        }
        case 4: {
            menuState.push(YEARS_MENU);
        }
        case 5: {
            menuState.push(HORARIOS_MENU);
            break;
        }

    }
    getMenu();
}

void Menu::modificacoesMenu() {
    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "\t[1] Inscrever Estudante" << endl;
        cout << "\t[2] Desinscrever Estudante" << endl;
        cout << "\t[3] Alteraçao de Class/UC" << endl;
        cout << "\t[4] Alteração de várias turmas/UCs" << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
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
        cout << "\t[1] Listar Pedidos" << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
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


void Menu::alunosMenu() {

    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "\t[1] Listar Alunos Inscritos no Curso " << endl;
        cout << "\t[2] Listar Alunos Iscritos por Ano" << endl;
        cout << "\t[3] Listar Alunos Inscritos por UC" << endl;
        cout << "\t[4] Listar Alunos Inscritos por Turma" << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 4) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 4);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(ESTUDANTES_MENU);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menuState.push(TURMA_MENU);
            break;
    }
    getMenu();
}
void Menu::horariosMenu() {
    int escolha;
    vector<string> options = {
            "Listar Horário de um Aluno",
            "Listar Horário de uma Turma",
            "Listar Horário de uma Unidade Curricular"
    };

    for(int i=0; i<options.size(); i++){
        cout << "\t[" << i+1 << "] " << options[i] << endl;
    }
    cout << "\n[0] Voltar atrás" << endl;

    do {
        cout << "Escolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 3) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 3);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(HORARIO_ALUNO);
            break;
        case 2:
            menuState.push(HORARIO_TURMA); // ano > turma (?)
            break;
        case 3:
            menuState.push(HORARIO_UC); // ano > cadeiras (?)
            break;
    }
    getMenu();
}
void Menu::horarioAluno(){
    unsigned escolha;
    cout << "\t[0] Voltar atrás" << endl << endl;

    set<Student*, studComp> students = m.getStudents();
    Student* myStudent;

    do {
        cout << "\tup do estudante: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if(escolha == 0){
            menuState.pop();
            return getMenu();
        }
        cin.clear();
        cin.ignore(1000, '\n');
        myStudent = *m.getStudents().find(new Student(escolha));
    } while (myStudent == nullptr);

    cout << myStudent->getName() << endl;

    getMenu();

}
void Menu::estudantesMenu() {
    int i = 1;
    for (auto student: m.getStudents()) {
        student->printStudent();
    }

    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 4) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 4);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
    }
    getMenu();

}

void Menu::turmaMenu() {
    char ano;
    cout << "\t[0] Voltar atrás" << endl << endl;

    do {
        cout << "\tescolha um ano (1, 2 ou 3): ";
        cin >> ano;
        cout << "\n";
    } while (ano < '1' || ano > '3');

    //listagem das UCs

    string uc;

    set<CourseUnit, ucComp> ucSet = m.getUcs(ano);
    for (auto uc : ucSet)
        cout << "\t" << uc.getUcCode() << "\n";

    auto it = ucSet.begin();

    do {
        cout << "\n\tescolha uma das UCs acima (código): ";
        cin >> uc;
        CourseUnit tempUc(uc);
        it = ucSet.find(tempUc); //logarithmic
    } while(it == ucSet.end());


    //listagem das turmas da uc selecionada

    string turma;
    /*
    set<string> turmasUcSet = m.getClasses(ucCode uc);
    for (auto turma : turmasUcSet)
        cout << "\t" << turma << "\n";
    */

    do {
        cout << "\n\tescolha uma turma: ";
        cin >> turma;

    } while(turma == ""); //ok



    menuState.pop();
    getMenu();
}



// Colocar os outros menus
// Colocar aqui as funções de listagem (que estão relacionadas
// com as escolhas dos menus