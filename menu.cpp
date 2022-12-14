#include "menu.h"
#include <iostream>

using namespace std;

Managing m;

Menu::Menu() {
    menuState.push(MAIN_MENU);
    m.readFiles();
    getMenu();

}

void Menu::chooseStudentsOrder(set<Student *, studComp> students) {
    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Alunos por Ordem Alfabética " << endl;
        cout << "\t[2] Listar Alunos por UP " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;
        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } while (escolha < 0 || escolha > 2);

    if (escolha == 0) {
        menuState.pop();
        return getMenu();
    }

    int count = 0;
    if (escolha == 2) {
        for (Student *student: students) {
            count++;
            cout << '\t' << *student << endl;
        }
    } else {
        auto studentsSet = m.sortStudentsByName(students);
        for (Student *student: studentsSet) {
            count++;
            cout << '\t' << *student << endl;
        }
    }
    cout << "\n\t" << "Total de alunos inscritos: " << count << endl;
    getMenu();
}


void Menu::getMenu() {
    if (!menuState.empty()) {
        switch (menuState.top()) {
            case 0:
                mainMenu();
                break;
            case CONSULTAS_MENU:
                consultasMenu();
                break;
            case MODIFICACOES_MENU:
                modificacoesMenu();
                break;
            case PEDIDOS_MENU:
                efetivacaoMenu();
                break;
            case ALUNOS_MENU:
                alunosMenu();
                break;
            case TURMAS_MENU:
                turmasMenu();
                break;
            case TURMAS_ORDEM_MENU:
                turmasOrdemMenu();
                break;
            case TURMAS_CRESCENTE_MENU:
                turmasCrescenteMenu();
                break;
            case TURMAS_DECRESCENTE_MENU:
                turmasDecrescenteMenu();
                break;
            case TURMAS_ANO_MENU:
                turmasAnoMenu();
                break;
            case TURMAS_UC_MENU:
                turmasUcMenu();
                break;
            case UCS_MENU:
                ucsMenu();
                break;
            case UCS_CRESCENTE_MENU:
                ucsCrescenteMenu();
                break;
            case UCS_DECRESCENTE_MENU:
                ucsDecrescenteMenu();
                break;
            case ANOS_MENU:
                anosMenu();
                break;
            case ANOS_CRESCENTE_MENU:
                anosCrescenteMenu();
                break;
            case ANOS_DECRESCENTE_MENU:
                anosDecrescenteMenu();
                break;
            case ESTUDANTES_MENU:
                estudantesMenu();
                break;
            case HORARIOS_MENU:
                horariosMenu();
                break;
            case HORARIO_ALUNO:
                horarioAluno();
                break;
            case HORARIO_TURMA:
                horarioTurma();
                break;
            case HORARIO_UC:
                horarioUc();
                break;
            case TURMA_MENU:
                turmaMenu();
                break;
            case INSCREVER_ALUNO_MENU:
                inscreverAluno();
                break;
            case DESINSCREVER_ALUNO_MENU:
                desinscreverAluno();
                break;
            case ALUNOS_ANO:
                alunosAno();
                break;
            case ALUNOS_UC:
                alunosUC();
                break;
            case PERMUTACAO_MENU:
                permutacaoMenu();
                break;
            case TROCA_SINGULAR:
                trocaSingular();
                break;
            case TROCA_DUPLA:
                trocaDupla();
                break;
            case LISTAR_PEDIDOS_MENU:
                listarPedidos();
                break;
            case PEDIDOS_ARQUIVADOS_MENU:
                pedidosArquivados();
                break;
            case EFETIVADOS_MENU:
                efetivadosMenu();
                break;
            case ESTUDANTES_NUCS:
                estudantesNUCS();
                break;
        }
    }
}

void Menu::mainMenu() {

    cout << endl << "------------------------------------------------\n";
    cout << "| DEI - Departamento de Engenharia Informática |" << endl;
    cout << "|\t\tGestão de Horários - FEUP              |" << endl;
    cout << "------------------------------------------------\n";

    cout << "|\t" << "[1] CONSULTAS                              |\n";
    cout << "|\t" << "[2] MODIFICAR TURMAS DE ESTUDANTES         |\n";
    cout << "|\t" << "[3] GESTÃO DE PEDIDOS                      |\n";

    cout << "|                                              |";
    cout << "\n|\t" << "[0] Exit                                   |" << endl;
    cout << "------------------------------------------------" << endl;

    int escolha;
    cout << "\t" << "Escolha: ";
    cin >> escolha;

    while (!cin.good() || escolha < 0 || escolha > 3) {
        cin.clear();
        cin.ignore();

        cout << endl << "\t" << "Erro! Introduza um número válido\n";
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
            menuState.push(PEDIDOS_MENU);
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
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;

        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 5) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 6);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1: {
            menuState.push(ALUNOS_MENU);
            break;
        }
        case 2: {
            menuState.push(TURMAS_MENU);
            break;
        }
        case 3: {
            menuState.push(UCS_MENU);
            break;
        }
        case 4: {
            menuState.push(ANOS_MENU);
            break;
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
        cout << "\t[1] Inscrever estudante numa turma" << endl;
        cout << "\t[2] Remover estudante de uma turma" << endl;
        cout << "\t[3] Trocar estudantes de turma" << endl;
        //cout << "\t[3] Alteraçao de Class/UC" << endl;
        //cout << "\t[4] Alteração de várias turmas/UCs" << endl;
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
            menuState.push(INSCREVER_ALUNO_MENU);
            break;
        case 2:
            menuState.push(DESINSCREVER_ALUNO_MENU);
            break;
        case 3:
            menuState.push(PERMUTACAO_MENU);
            break;
    }
    getMenu();
}

void Menu::efetivacaoMenu() {
    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar pedidos" << endl;
        cout << "\t[2] Listar pedidos arquivados" << endl;
        cout << "\t[3] PROCESSAR TODOS OS PEDIDOS EM ESPERA" << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
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
            menuState.push(LISTAR_PEDIDOS_MENU);
            break;
        case 2:
            menuState.push(PEDIDOS_ARQUIVADOS_MENU);
            break;
        case 3:
            menuState.push(EFETIVADOS_MENU);
            break;
    }
    getMenu();
}


void Menu::alunosMenu() { //MENU COM TODAS AS OPÇÕES RELACIONADAS COM ALUNOS

    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Alunos Inscritos no Curso " << endl;
        cout << "\t[2] Listar Alunos Iscritos por Ano" << endl;
        cout << "\t[3] Listar Alunos Inscritos por UC" << endl;
        cout << "\t[4] Listar Alunos Inscritos por Turma" << endl;
        cout << "\t[5] Listar Alunos Inscritos em mais de n UCs" << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 5) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 5);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(ESTUDANTES_MENU);
            break;
        case 2:
            menuState.push(ALUNOS_ANO);
            break;
        case 3:
            menuState.push(ALUNOS_UC);
            break;
        case 4:
            menuState.push(TURMA_MENU);
            break;
        case 5:
            menuState.push(ESTUDANTES_NUCS);
            break;
    }
    getMenu();
}

void Menu::estudantesMenu() {
    chooseStudentsOrder(m.getStudents());
    getMenu();
}

void Menu::alunosAno() {
    unsigned year;

    cout << "\t[0] Voltar atrás" << endl << endl;
    do {

        cout << "\tIntroduza um ano: ";
        cin >> year;
        cout << "\n";

        if (year == 0) {
            menuState.pop();
            return getMenu();
        }

    } while (year < 0 || year > 3);

    chooseStudentsOrder(m.getStudentsByYear(year));
    getMenu();
}


void Menu::alunosUC() {

    char year;

    cout << "\t[0] Voltar atrás" << endl << endl;
    do {

        cout << "\tIntroduza um ano: ";
        cin >> year;
        cout << "\n";

        if (year == 0) {
            menuState.pop();
            return getMenu();
        }

    } while (year < '0' || year > '3');

    if (year == '0') {
        menuState.pop();
        return getMenu();
    }

    set<CourseUnit> UCs = m.getUcs(year);
    for (CourseUnit uc: UCs) {
        cout << "\t" << uc.getUcCode() << endl;
    }
    cout << endl;
    string uc;
    CourseUnit tempUc;
    cout << "\t[0] Voltar atrás" << endl;

    do {

        cout << "\n\tEscolha uma UC do " << year << "º ano: ";
        cin >> uc;
        cout << endl;
        tempUc.setUcCode(uc);

        if (uc == "0") {
            return getMenu();
        }

    } while (UCs.find(tempUc) == UCs.end());

    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Alunos por Ordem Alfabética " << endl;
        cout << "\t[2] Listar Alunos por UP " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 2);

    if (escolha == 0) {
        menuState.pop();
        return getMenu();
    }

    int count = 0;

    if (escolha == 2) {
        for (Student *student: m.getStudents()) {
            for (Turma turma: student->getClasses()) {
                if (turma.getUcCode() == uc) {
                    count++;
                    cout << "\t" << (*student) << endl;
                }
            }
        }
    } else {
        auto studentsSet = m.sortStudentsByName(m.getStudents());
        for (Student *student: studentsSet) {
            for (Turma turma: student->getClasses()) {
                if (turma.getUcCode() == uc) {
                    count++;
                    cout << "\t" << (*student) << endl;
                }
            }
        }

    }

    cout << "\n\tTotal de estudantes inscritos na UC " << uc << ": " << count << endl;
    cout << endl;

    getMenu();
}

void Menu::estudantesNUCS() {
    multiset<Student *, studentByNUCS> studentsbyNUCS = m.sortStudentsByNUCS(m.getStudents());
    auto set_it = studentsbyNUCS.begin();

    int ucs_n;
    do {
        cout << "\n\t[0] Voltar atrás" << endl;
        cout << "\n\tEstudantes com mais de quantas UCs? ";

        cin >> ucs_n;

        if (ucs_n == 0) {
            menuState.pop();
            return getMenu();
        }

    } while (ucs_n < 1);

    list<Turma> fake_turmas;

    for (int i = 0; i < ucs_n + 1; i++) {
        fake_turmas.push_back(Turma());
    }

    set_it = studentsbyNUCS.find(new Student(0, "", fake_turmas));

    int count = 0;
    while (set_it != studentsbyNUCS.end()) {
        count++;
        cout << "\n\t" << (**set_it);
        set_it++;
    }

    cout << "\n\n\tExiste um total de " << count << " estudantes com mais de " << ucs_n << " UCs." << endl;

    getMenu();
}

void Menu::turmaMenu() {
    char year;
    cout << "\t[0] Voltar atrás" << endl << endl;
    do {

        cout << "\tEscolha um ano (1, 2 ou 3): ";
        cin >> year;
        cout << "\n";
        if (year == '0') {
            cin.clear();
            menuState.pop();
            return getMenu();

        }
    } while (year < '1' || year > '3');

    cout << "\tUCs do " << year << "º ano:" << "\n";


    set<CourseUnit> ucSet = m.getUcs(year);

    for (auto uc: ucSet)
        cout << "\t" << uc.getUcCode() << "\n";

    auto it = ucSet.begin();
    string uc;
    cout << endl << "\t[0] Voltar atrás" << endl;

    do {
        cout << "\n\tescolha uma das UCs acima (código): ";
        cin >> uc;

        if (uc == "0") {
            cin.clear();
            menuState.pop();
            return getMenu();
        }

        CourseUnit tempUc(uc);
        it = ucSet.find(tempUc);

    } while (it == ucSet.end());

    CourseUnit UC = *it;

    string turma;
    cout << endl;
    for (auto TURMA: it->getClasses())
        cout << "\t" << TURMA << "\n";

    auto itr = UC.getClasses().begin();
    do {
        cout << "\n\tescolha uma turma: ";
        cin >> turma;
        if (turma == "0") {
            cin.clear();
            menuState.pop();
            return getMenu();
        }
        itr = UC.getClasses().find(turma);

    } while (itr == UC.getClasses().end());


    int count = 0;
    int escolha;

    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Alunos por Ordem Alfabética " << endl;
        cout << "\t[2] Listar Alunos por UP " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 2);

    Turma turma1(turma, uc);

    if (escolha == 0) {
        menuState.pop();
        return getMenu();
    } else if (escolha == 2) {
        for (Student *student: m.getStudents()) {
            for (Turma studTurma: student->getClasses()) {
                if (studTurma == turma1) {
                    count++;
                    cout << "\t" << *student << endl;
                }
            }
        }
    } else {
        auto studentsSet = m.sortStudentsByName(m.getStudents());
        for (Student *student: studentsSet) {
            for (Turma studTurma: student->getClasses()) {
                if (studTurma == turma1) {
                    count++;
                    cout << "\t" << *student << endl;
                }
            }
        }
    }

    cout << "\n\tTotal de ALunos inscritos na Turma " << turma1.getClassCode() << " | " << turma1.getUcCode() << ": "
         << count << endl;
    menuState.pop();
    getMenu();
}


void Menu::turmasMenu() {

    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Todas as Turmas por Nº de Alunos " << endl;
        cout << "\t[2] Listar as Turmas de um Ano por Nº de Alunos " << endl;
        cout << "\t[3] Listar as Turmas de uma UC por Nº de Alunos " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
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
            menuState.push(TURMAS_ORDEM_MENU);
            break;
        case 2:
            menuState.push(TURMAS_ANO_MENU);
            break;

        case 3:
            menuState.push(TURMAS_UC_MENU);
            break;
    }

    getMenu();
}

void Menu::turmasOrdemMenu() {
    int escolha;

    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar por Ordem Decrescente de Nº de Alunos " << endl;
        cout << "\t[2] Listar por Ordem Crescente de Nº de Alunos " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 2);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(TURMAS_DECRESCENTE_MENU);
            break;
        case 2:
            menuState.push(TURMAS_CRESCENTE_MENU);
            break;
    }
    getMenu();
}

void Menu::turmasCrescenteMenu() {

    vector<pair<int, Turma>> numberOfStudentsByClass = m.getOcupacaoTurmas();
    sort(numberOfStudentsByClass.begin(), numberOfStudentsByClass.end());

    for (auto PAIR: numberOfStudentsByClass) {
        cout << "\t(" << PAIR.first << ") " << PAIR.second.getClassCode() << " | " << PAIR.second.getUcCode() << endl;
    }

    menuState.pop();
    getMenu();

}

void Menu::turmasDecrescenteMenu() {
    vector<pair<int, Turma>> numberOfStudentsByClass = m.getOcupacaoTurmas();
    sort(numberOfStudentsByClass.rbegin(), numberOfStudentsByClass.rend());

    for (auto PAIR: numberOfStudentsByClass) {
        cout << "\t(" << PAIR.first << ") " << PAIR.second.getClassCode() << " | " << PAIR.second.getUcCode() << endl;
    }

    menuState.pop();
    getMenu();


}

void Menu::turmasAnoMenu() {
    char year;

    do {
        cout << "\tEscolha uma ano (1, 2 ou 3): " << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;

        cout << "\tEscolha: ";
        cin >> year;
        cout << "=======================================" << endl;

        if (year < '0' || year > '3') cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (year < '0' || year > '3');
    cout << endl;

    if (year == '0') {
        menuState.pop();
        return getMenu();
    }

    set<Turma> classesByYear = m.getClassesByYear(year);

    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Turmas por Ordem Decrescente de Nº de Alunos " << endl;
        cout << "\t[2] Listar Turmas por Ordem Crescente de Nº de Alunos " << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 2);

    if (escolha == 0) {
        menuState.pop();
        return getMenu();
    } else if (escolha == 1) {
        vector<pair<int, Turma>> numOfStudByClass = m.getOcupacaoTurmas(classesByYear);
        sort(numOfStudByClass.rbegin(), numOfStudByClass.rend());

        for (auto PAIR: numOfStudByClass) {
            cout << "\t(" << PAIR.first << ") " << PAIR.second.getClassCode() << " | " << PAIR.second.getUcCode()
                 << endl;
        }

        cout << "=======================================" << endl;

        getMenu();
    } else {
        vector<pair<int, Turma>> numOfStudByClass = m.getOcupacaoTurmas(classesByYear);
        sort(numOfStudByClass.begin(), numOfStudByClass.end());

        for (auto PAIR: numOfStudByClass) {
            cout << "\t(" << PAIR.first << ") " << PAIR.second.getClassCode() << " | " << PAIR.second.getUcCode()
                 << endl;
        }

        cout << "=======================================" << endl;

        getMenu();
    }

    menuState.pop();
    return getMenu();

}


void Menu::turmasUcMenu() {
    char year;

    do {
        cout << "\tEscolha uma ano (1, 2 ou 3): " << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;

        cout << "\tEscolha: ";
        cin >> year;
        cout << "=======================================" << endl;

        if (year < '0' || year > '3') cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (year < '0' || year > '3');
    cout << endl;

    if (year == '0') {
        menuState.pop();
        return getMenu();
    }

    set<CourseUnit> ucsByYear = m.getUcs(year);
    cout << endl;

    for (CourseUnit uc: ucsByYear) {
        cout << "\t" << uc.getUcCode() << "\n";
    }

    cout << endl;
    auto it = ucsByYear.begin();

    string uc;

    do {
        cout << "\n\tescolha uma das UCs acima (código): ";
        cin >> uc;

        if (uc == "0") {
            cin.clear();
            menuState.pop();
            return getMenu();
        }

        CourseUnit tempUc(uc);
        it = ucsByYear.find(tempUc);

    } while (it == ucsByYear.end());

    int escolha;

    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Turmas por Ordem Decrescente de Nº de Alunos " << endl;
        cout << "\t[2] Listar Turmas por Ordem Crescente de Nº de Alunos " << endl;
        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 2);

    set<Turma> classesOfUc = m.getClassesByUc(uc);

    if (escolha == 0) {
        menuState.pop();
        return getMenu();
    } else if (escolha == 2) {
        vector<pair<int, Turma>> numberOfStudentsByClass = m.getOcupacaoTurmas(classesOfUc);

        sort(numberOfStudentsByClass.begin(), numberOfStudentsByClass.end());

        for (auto PAIR: numberOfStudentsByClass) {
            cout << "\t(" << PAIR.first << ") " << PAIR.second.getClassCode() << " | " << PAIR.second.getUcCode()
                 << endl;
        }
        getMenu();

    } else {
        vector<pair<int, Turma>> numberOfStudentsByClass = m.getOcupacaoTurmas(classesOfUc);

        sort(numberOfStudentsByClass.rbegin(), numberOfStudentsByClass.rend());

        for (auto PAIR: numberOfStudentsByClass) {
            cout << "\t(" << PAIR.first << ") " << PAIR.second.getClassCode() << " | " << PAIR.second.getUcCode()
                 << endl;
        }
        getMenu();
    }

    menuState.pop();
    return getMenu();

}

void Menu::ucsMenu() {

    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Todas as UCs por Ordem Decrescente de Nº de Alunos " << endl;
        cout << "\t[2] Listar Todas as UCs por Ordem Crescente de Nº de Alunos " << endl;
        cout << "\t[3] Listar UCs de Um Ano por Nº de Alunos " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
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
            menuState.push(UCS_DECRESCENTE_MENU);
            break;
        case 2:
            menuState.push(UCS_CRESCENTE_MENU);
            break;
        case 3:
            char year;

            do {
                cout << "\tEscolha uma ano (1, 2 ou 3): " << endl;
                cout << endl;
                cout << "\t[0] Voltar atrás" << endl;

                cout << "\tEscolha: ";
                cin >> year;
                cout << "=======================================" << endl;

                if (year < '0' || year > '3') cout << "Erro, por favor tente novamente!" << endl;

                cin.clear();
                cin.ignore(1000, '\n');

            } while (year < '0' || year > '3');

            cout << endl;

            if (year == '0') {
                menuState.pop();
                return getMenu();
            }

            int escolha;
            do {
                cout << "\t[1] Listar UCs por Ordem Decrescente de Nº de Alunos " << endl;
                cout << "\t[2] Listar UCs por Ordem Crescente de Nº de Alunos " << endl;

                cout << endl;
                cout << "\t[0] Voltar atrás" << endl;
                cout << "\tEscolha: ";
                cin >> escolha;
                cout << "=======================================" << endl;

                if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

                cin.clear();
                cin.ignore(1000, '\n');

            } while (escolha < 0 || escolha > 2);

            set<CourseUnit> ucsByYear = m.getUcs(year);

            if (escolha == 0) {
                menuState.pop();
                return getMenu();
            } else if (escolha == 1) {
                vector<pair<int, CourseUnit>> numberOfStudentsByUc = m.getOcupacaoUCS(ucsByYear);
                sort(numberOfStudentsByUc.rbegin(), numberOfStudentsByUc.rend());

                cout << "\n\t" << "UCs do " << year << "º ano: " << endl;

                for (auto PAIR: numberOfStudentsByUc) {
                    cout << "\t(" << PAIR.first << ") " << PAIR.second.getUcCode() << endl;
                }

                cout << endl;
            } else {
                vector<pair<int, CourseUnit>> numberOfStudentsByUc = m.getOcupacaoUCS(ucsByYear);
                sort(numberOfStudentsByUc.begin(), numberOfStudentsByUc.end());

                cout << "\n\t" << "UCs do " << year << "º ano: " << endl;

                for (auto PAIR: numberOfStudentsByUc) {
                    cout << "\t(" << PAIR.first << ") " << PAIR.second.getUcCode() << endl;
                }

                cout << endl;
            }
    }
    getMenu();
}

void Menu::ucsCrescenteMenu() {

    vector<pair<int, CourseUnit>> numberOfStudentsByUc = m.getOcupacaoUCS();

    sort(numberOfStudentsByUc.begin(), numberOfStudentsByUc.end());

    for (auto PAIR: numberOfStudentsByUc) {
        cout << "\t(" << PAIR.first << ") " << PAIR.second.getUcCode() << endl;
    }

    menuState.pop();
    getMenu();


}

void Menu::ucsDecrescenteMenu() {

    vector<pair<int, CourseUnit>> numberOfStudentsByUc = m.getOcupacaoUCS();

    sort(numberOfStudentsByUc.rbegin(), numberOfStudentsByUc.rend());

    for (auto PAIR: numberOfStudentsByUc) {
        cout << "\t(" << PAIR.first << ") " << PAIR.second.getUcCode() << endl;
    }

    menuState.pop();
    getMenu();


}

void Menu::anosMenu() {

    int escolha;
    do {
        cout << "=======================================" << endl << endl;
        cout << "\t[1] Listar Anos por Ordem Decrescente de Nº de Alunos " << endl;
        cout << "\t[2] Listar Anos por Ordem Crescente de Nº de Alunos " << endl;

        cout << endl;
        cout << "\t[0] Voltar atrás" << endl;


        cout << "\tEscolha: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha < 0 || escolha > 2) cout << "Erro, por favor tente novamente!" << endl;

        cin.clear();
        cin.ignore(1000, '\n');

    } while (escolha < 0 || escolha > 2);

    switch (escolha) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(ANOS_DECRESCENTE_MENU);
            break;
        case 2:
            menuState.push(ANOS_CRESCENTE_MENU);
            break;

    }
    getMenu();
}

void Menu::anosCrescenteMenu() {

    vector<pair<int, string>> numberOfStudentsByYear = m.getOcupacaoYear();

    std::sort(numberOfStudentsByYear.begin(), numberOfStudentsByYear.end());

    for (auto PAIR: numberOfStudentsByYear) {
        cout << "\t(" << PAIR.first << ") " << PAIR.second << endl;
    }

    menuState.pop();
    getMenu();


}

void Menu::anosDecrescenteMenu() {

    vector<pair<int, string>> numberOfStudentsByYear = m.getOcupacaoYear();

    std::sort(numberOfStudentsByYear.rbegin(), numberOfStudentsByYear.rend());

    for (auto PAIR: numberOfStudentsByYear) {
        cout << "\t(" << PAIR.first << ") " << PAIR.second << endl;
    }

    menuState.pop();
    getMenu();

}

void Menu::horariosMenu() {
    int escolha;

    vector<string> options = {
            "Listar Horário de um Aluno",
            "Listar Horário de uma Turma",
            "Listar Horário de uma Unidade Curricular"
    };

    for (int i = 0; i < options.size(); i++) {
        cout << "\t[" << i + 1 << "] " << options[i] << endl;
    }
    cout << "\n\t[0] Voltar atrás" << endl;

    do {
        cout << "\tEscolha: ";
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

void Menu::horarioAluno() {
    unsigned escolha;
    cout << "\t[0] Voltar atrás" << endl << endl;

    set<Student *, studComp> students = m.getStudents();
    set<Student *>::iterator myStudent;

    do {
        cout << "\tup do estudante: ";
        cin >> escolha;
        cout << "=======================================" << endl;

        if (escolha == 0) {
            menuState.pop();
            return getMenu();
        }

        cin.clear();
        cin.ignore(1000, '\n');
        myStudent = students.find(new Student(escolha));

    } while (myStudent == students.end());

    Schedule studentSchedule = m.getStudentSchedule((*myStudent));

    cout << "Horário de: " << (*myStudent)->getName() << endl;
    studentSchedule.sort();
    cout << studentSchedule;
    cout << "  ----------------------------------------------------------------------------------------" << endl;

    getMenu();
}

void Menu::horarioTurma() {

    char year;
    cout << "\t[0] Voltar atrás" << endl << endl;

    do {
        cout << "\tEscolha um ano (1, 2 ou 3): ";
        cin >> year;
        cout << "\n";
        if (year == '0') {
            menuState.pop();
            return getMenu();
        }
        cin.clear();
        cin.ignore(1000, '\n');

    } while (year < '1' || year > '3');

    set<Turma> classesYear = m.getClassesByYear(year);

    set<string> printed;
    auto it = printed.begin();

    string primeira = classesYear.begin()->getClassCode();
    printed.insert(primeira);

    cout << "\t" << *printed.begin() << endl;

    for (Turma turma1: classesYear) {
        it = printed.find(turma1.getClassCode());
        if (it != printed.end()) {
            continue;
        }
        printed.insert(turma1.getClassCode());
        cout << "\t" << turma1.getClassCode() << endl;
    }
    cout << endl << endl;

    string turma;
    cout << "\t[0] Voltar atrás" << endl << endl;

    auto itr_turma = classesYear.begin();
    vector<Turma> turmasParaHorario;

    do {
        cout << "\tEscolha uma turma: ";
        cin >> turma;
        cout << "\n";
        if (turma == "0") {
            menuState.pop();
            return getMenu();
        }
        cin.clear();
        cin.ignore(1000, '\n');

    } while (printed.find(turma) == printed.end());

    for (Turma t: classesYear) {
        if (t.getClassCode() == turma) {
            turmasParaHorario.push_back(t);
        }
    }

    set<Schedule *, schedComp> schedules = m.getSchedules();
    Schedule classSchedule = Schedule();

    for (Turma _class: turmasParaHorario) {
        auto mySchedule = schedules.find(new Schedule(_class));
        if (mySchedule != schedules.end()) {
            for (Slot slot: (*mySchedule)->getSlots()) {
                classSchedule.addSlot(slot);
            }
        }
    }

    classSchedule.sort();
    cout << '\t' << classSchedule;
    cout << "  ----------------------------------------------------------------------------------------" << endl;

    menuState.pop();
    getMenu();
}

void Menu::horarioUc() {
    char year;
    cout << "\t[0] Voltar atrás" << endl << endl;

    do {
        cout << "\tEscolha um ano (1, 2 ou 3): ";
        cin >> year;
        cout << "\n";
        if (year == '0') {
            cin.clear();
            menuState.pop();
            return getMenu();
        }

    } while (year < '1' || year > '3');

    cout << "\tUCs do " << year << "º ano:" << "\n";

    set<CourseUnit> ucSet = m.getUcs(year);
    for (auto uc: ucSet)
        cout << "\t" << uc.getUcCode() << "\n";

    auto it = ucSet.begin();
    string uc;

    do {
        cout << "\n\tescolha uma das UCs acima (código): ";
        cin >> uc;
        if (uc == "0") {
            cin.clear();
            menuState.pop();
            return getMenu();
        }
        CourseUnit tempUc(uc);
        it = ucSet.find(tempUc);
    } while (it == ucSet.end());

    CourseUnit UC = *it;

    string turma;
    cout << endl;
    set<Schedule *, schedComp> schedules = m.getSchedules();
    Schedule ucSchedule = Schedule();

    for (auto TURMA: UC.getClasses()) {
        Turma _class(TURMA, uc); //fisica
        auto mySchedule = schedules.find(new Schedule(_class));
        if (mySchedule != schedules.end()) {
            for (Slot slot: (*mySchedule)->getSlots()) {
                ucSchedule.addSlot(slot);
            }
        }
    }

    ucSchedule.sort();

    cout << '\t' << ucSchedule;
    cout << "  ----------------------------------------------------------------------------------------" << endl
         << endl;

    menuState.pop();
    getMenu();
}

void Menu::inscreverAluno() {
    string type = "Inscricao";
    unsigned upCode;
    string name;
    string courseUnit;
    string turma;
    char year;
    vector<Turma> turmas;

    cout << "\t[0] Voltar atrás" << endl << endl;

    cout << "\tUP do aluno: ";
    cin >> upCode;

    if (upCode == 0) {
        menuState.pop();
        return getMenu();
    }
    cin.clear();
    cin.ignore(1000, '\n');

    if (m.getStudents().find(new Student(upCode)) == m.getStudents().end()) {

        cout << "\t ! Está a inscrever um aluno novo no sistema !" << endl << endl;
        cout <<"\t[Após escrever o nome, pressione duas vezes a tecla ENTER]" << endl;
        cout << "\tNome do aluno: ";
        getline(cin, name);
        cin.clear();
        cin.ignore(1000, '\n');
        if (name == "0") {
            menuState.pop();
            return getMenu();
        }
        inscricao(year, courseUnit, turma, turmas);


        m.addRequest(new Request(upCode, name, turmas, type));
    } else {
        inscricao(year, courseUnit, turma, turmas);
        m.addRequest(new Request(upCode, turmas, type));
    }

    menuState.pop();
    getMenu();
}

void Menu::desinscreverAluno() {
    unsigned upcode;

    cout << "\t[0] Voltar atrás" << endl << endl;

    do {
        cout << "\tUP do aluno: ";
        cin >> upcode;
        cin.clear();
        cin.ignore(1000, '\n');
        if (upcode == 0) {
            menuState.pop();
            return getMenu();
        }

    } while (m.getStudents().find(new Student(upcode)) == m.getStudents().end());

    Student *newStudent = *m.getStudents().find(new Student(upcode));

    cout << "\nO estudante (" << upcode << ") " << newStudent->getName()
         << " está inscrito nas seguintes turmas (UC/Turma):\n\n";

    newStudent->printClasses();

    list<Turma> newStudentClasses = newStudent->getClasses();

    cout << "\n" << "[" << newStudent->getClasses().size() + 1 << "] " << "REMOVER DE TODAS AS TURMAS";

    int choice;
    do {
        cout << "\n\n De qual delas quer remover o estudante? ";
        cin >> choice;

    } while (choice < 0 || choice > newStudentClasses.size() + 1);

    auto index = newStudentClasses.begin();

    if (choice != 0 && (choice != newStudentClasses.size() + 1)) {

        advance(index, choice - 1);
        newStudent->removeClass(*index);

        if (newStudent->getClasses().size() == 0)
            m.eraseStudent(newStudent);
        cout << "\nEstudante desinscrito com sucesso!" << endl;
    } else if (choice == newStudentClasses.size() + 1) {
        m.eraseStudent(newStudent);
        cout << "\nEstudante desinscrito com sucesso!" << endl;
    }

    m.writeStudents();
    getMenu();
}


void Menu::permutacaoMenu() {
    cout << "----------------- TROCAS DE TURMAS ---------------------" << endl << endl;
    cout << "\t [1] Trocar turma de um estudante" << endl;
    cout << "\t [2] Trocar turma entre dois estudantes" << endl << endl;
    cout << "\t [0] Voltar atrás" << endl;
    unsigned choice;
    do {
        cout << "\n\tEscolha uma opção: ";
        cin >> choice;

    } while (choice < 0 || choice > 2);

    switch (choice) {
        case 0:
            menuState.pop();
            break;
        case 1:
            menuState.push(TROCA_SINGULAR);
            break;
        case 2:
            menuState.push(TROCA_DUPLA);
            break;
    }
    getMenu();
}


void Menu::trocaSingular() {
    cout << "-------------TROCAR UM ESTUDANTE--------------" << endl;
    string type = "Troca Singular";
    unsigned upcode;
    string courseUnit;
    unsigned choiceClass;
    vector<Turma> turmas_novas;

    set<Student *, studComp> students_set = m.getStudents();
    auto student_it = students_set.begin();

    do {
        cout << "UP do estudante: ";
        cin >> upcode;
        student_it = students_set.find(new Student(upcode));

    } while (student_it == students_set.end());

    list<Turma> turmas = (*student_it)->getClasses();

    while (true) {
        auto it = turmas.begin();

        int counter = 1;
        for (Turma t: turmas) {
            cout << "\t [" << counter << "] " << t << endl;
            counter++;
        }

        do {
            cout << "  \n\tEscolha o conjunto que quer trocar: ";
            cin >> choiceClass;

        } while (choiceClass < 1 || choiceClass > turmas.size());

        advance(it, choiceClass - 1);
        Turma turma(*it);

        string ucCode = turma.getUcCode();

        set<CourseUnit> UCset = m.getUcs();
        auto uc = UCset.find(CourseUnit(ucCode));
        set<string> classes = uc->getClasses();

        for (string c: classes)
            cout << "\t" << c << endl;

        string newClass;

        do {
            cout << "Para que turma deseja trocar: ";
            cin >> newClass;

        } while (classes.find(newClass) == classes.end());

        turmas.erase(it);
        turmas_novas.push_back(Turma(newClass, ucCode));

        cout << "Pedido efetuado com sucesso!" << endl << endl;
        cout << "Pretende adicionar outra troca? (S/N)";

        char answer;
        cin >> answer;
        if (answer != 'S')
            break;
    }

    m.addRequest(new Request(upcode, turmas_novas, type));

    menuState.pop();
    getMenu();
}

void Menu::trocaDupla() {
    cout << "-------------TROCAR DOIS ESTUDANTES--------------" << endl;
    unsigned upcode1;
    unsigned upcode2;
    string type = "Troca Dupla";
    vector<Turma> novas_turmas;

    set<Student *, studComp> students_set = m.getStudents();
    auto student_iterator1 = students_set.begin();
    auto student_iterator2 = students_set.begin();

    do {
        cout << "UP do estudante 1: ";
        cin >> upcode1;
        student_iterator1 = students_set.find(new Student(upcode1));

    } while (student_iterator1 == students_set.end());


    do {
        cout << "UP do estudante 2: ";
        cin >> upcode2;
        student_iterator2 = students_set.find(new Student(upcode2));

    } while (student_iterator2 == students_set.end() || upcode2 == upcode1);

    list<Turma> turmas_troca = (*student_iterator2)->getClasses();
    auto itr_troca = turmas_troca.begin();

    int counter = 1;
    for (Turma turma: turmas_troca) {
        cout << "\t[" << counter << "] " << turma << endl;
        counter++;
    }

    cout << "\n\tEstas são as turmas do estudante 2." << endl;

    int choice;
    do {
        cout << "\tQue conjunto pretende trocar? ";
        cin >> choice;

    } while (choice < 1 || choice > turmas_troca.size());

    advance(itr_troca, choice - 1);
    list<Turma> turmas_1 = (*student_iterator1)->getClasses();
    set<CourseUnit> ucs_1;

    bool possible = false;
    for (Turma turma: turmas_1) {
        if (turma.getUcCode() == (*itr_troca).getUcCode() && turma.getClassCode() != (*itr_troca).getClassCode())
            possible = true;
    }

    if (!possible) {
        cout << "\n\tERRO: O estudante 1 não está inscrito nessa UC." << endl;
        menuState.pop();
        return getMenu();
    }

    novas_turmas.push_back(*itr_troca);
    m.addRequest(new Request(upcode1, upcode2, novas_turmas, type));
    cout << "\n\tPedido efetuado com sucesso!" << endl << endl;

    menuState.pop();
    getMenu();
}

void Menu::inscricao(char &year, string &courseUnit, string &turma, vector<Turma> &turmas) {
    while (true) {
        do {
            cout << "\tEm que ano quer inscrever: ";
            cin >> year;
            if (year == '0'){
                menuState.pop();
                return getMenu();
            }
            cout << endl;

        } while (year < '1' || year > '3');

        set<CourseUnit> ucSet = m.getUcs(year);
        auto it = ucSet.begin();

        for (CourseUnit uc: ucSet)
            cout << "\t" << uc.getUcCode() << endl;

        do {
            cout << "\n\tEscolha uma UC: ";
            cin >> courseUnit;
            if (courseUnit == "0"){
                menuState.pop();
                return getMenu();
            }
            CourseUnit tempUc(courseUnit);
            it = ucSet.find(courseUnit);

        } while (it == ucSet.end());

        cout << endl;
        for (string s: (*it).getClasses())
            cout << "\t" << s << endl;

        do {
            cout << "\n\tEscolha uma Turma: ";
            cin >> turma;
            if(turma == "0"){
                menuState.pop();
                return getMenu();
            }

        } while ((*it).getClasses().find(turma) == (*it).getClasses().end());

        turmas.push_back(Turma(turma, courseUnit));
        char answer;
        cout << "\n\tPedido efetuado. Deseja inscrever em mais turmas? (S/N) ";
        cin >> answer;

        if (answer != 'S' && answer != 's')
            break;
    }
}

void Menu::listarPedidos() {
    if (m.getRequests().empty())
        cout << "\n\tNão existem pedidos para processar!" << endl << endl;
    else {
        queue<Request *> aux_queue = m.getRequests();
        while (!aux_queue.empty()) {
            auto req = aux_queue.front();
            cout << *req << endl << endl;
            aux_queue.pop();
        }
    }

    menuState.pop();
    getMenu();
}

void Menu::pedidosArquivados() {
    if (m.getRejectedRequests().empty()) {
        cout << "\n\t NÃO HÁ PEDIDOS ARQUIVADOS" << endl << endl;
        cout << "=======================================" << endl;
    } else {
        cout << "\n\tNÃO FOI POSSÍVEL CONCRETIZAR OS SEGUINTES PEDIDOS:" << endl << endl;
        for (Request *r: m.getRejectedRequests()) {
            cout << *r << endl << endl;
        }
    }

    char option;

    do {
        cout << "\n\t[D] Apagar todos os pedidos arquivados." << endl;
        cout << "\t[0] Voltar atrás" << endl;
        cout << "\n\tEscolha: ";
        cin >> option;

    } while (!(option == 'D' || option == 'd' || option == '0'));

    switch (option) {
        case '0':
            menuState.pop();
            break;
        case 'D':
            m.emptyRejectedRequests();
            m.writeRejectedRequests();
            cout << "\n\tOperação executada com sucesso!" << endl << endl;
            cout << "===========================================" << endl << endl;
            break;
    }
    getMenu();
}

void Menu::efetivadosMenu() {
    queue<Request *> aux_queue = m.getRequests();
    if (aux_queue.empty()) {
        cout << "\n\tNÃO HÁ PEDIDOS NA FILA!" << endl << endl;
        menuState.pop();
        return getMenu();
    }
    int count = m.getRejectedRequests().size();
    m.processRequests();
    m.writeStudents();
    m.writeRequests();
    m.writeRejectedRequests();

    if (m.getRejectedRequests().size() > count) {
        cout << "Foram rejeitados " << m.getRejectedRequests().size() - count << " pedidos." << endl
             << "Consulte os pedidos arquivados para saber mais." << endl << endl;
        cout << "Os restantes pedidos foram corretamente processados." << endl;
    } else {
        cout << "Todos os pedidos foram aceites." << endl;
    }
    menuState.pop();
    getMenu();
}


