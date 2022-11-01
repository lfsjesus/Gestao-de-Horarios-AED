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
        }
    }
}

void Menu::mainMenu() {

    cout << endl << "---------------------------------------------\n";
    cout << "DEI - Departamento de Engenharia Informática" << endl;
    cout << "\t\tGestão de Horários - FEUP" << endl;
    cout << "---------------------------------------------\n";

    cout << "\t" << "[1] CONSULTAS\n";
    cout << "\t" << "[2] MODIFICAR TURMAS DE ESTUDANTES\n";
    cout << "\t" << "[3] GESTÃO DE PEDIDOS\n";

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
        case 0: menuState.pop(); break;
        case 1: menuState.push(INSCREVER_ALUNO_MENU); break;
        case 2: menuState.push(DESINSCREVER_ALUNO_MENU); break;
        case 3: menuState.push(PERMUTACAO_MENU); break;
    }
    getMenu();
}

void Menu::efetivacaoMenu() {
    int escolha;
    do {
        cout << "=======================================" << endl;
        cout << "\t[1] Listar pedidos" << endl;
        cout << "\t[2] Listar pedidos arquivados" << endl;
        cout << "\t[3] Efetivação de pedidos" << endl;

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
            menuState.push(ALUNOS_ANO);
            break;
        case 3:
            menuState.push(ALUNOS_UC);
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
void Menu::horarioAluno(){
    unsigned escolha;
    cout << "\t[0] Voltar atrás" << endl << endl;

    set<Student*, studComp> students = m.getStudents();
    set<Student*>::iterator myStudent;
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
        myStudent = students.find(new Student(escolha));
    } while (myStudent == students.end());

    cout << (*myStudent)->getName() << endl;

    set<Schedule*, schedComp> schedules = m.getSchedules();


    Schedule studentSchedule = Schedule();
    for(Turma _class : (*myStudent)->getClasses()){
        auto mySchedule = schedules.find(new Schedule(_class));
        if(mySchedule != schedules.end()){
            for(Slot slot : (*mySchedule)->getSlots()){
                studentSchedule.addSlot(slot);
            }
        }
    }

    cout << "Horário de: " << (*myStudent)->getName() << endl;
    studentSchedule.sort();
    cout << studentSchedule << endl;

    getMenu();
}
void Menu::horarioTurma(){

    char ano;
    cout << "\t[0] Voltar atrás" << endl << endl;

    do {
        cout << "\tEscolha um ano (1, 2 ou 3): ";
        cin >> ano;
        cout << "\n";
        if(ano == 0){
            menuState.pop();
            return getMenu();
        }
        cin.clear();
        cin.ignore(1000, '\n');

    } while (ano < '1' || ano > '3');

    set<Turma> classesYear = m.getClassesByYear(ano);

    //listagem das turmas

    set<string> printed;
    auto it = printed.begin();

    string primeira = classesYear.begin()->getClassCode();
    printed.insert(primeira);
    //ISTO É PARA VER SE A TURMA JA FOI IMPRESSA E PARA NAO REPETIR TURMAS COM UCS DIFERENTES
    cout << "\t" << *printed.begin() << endl;
    for(Turma turma1 : classesYear){
        it = printed.find(turma1.getClassCode());
        if(it != printed.end()){
            continue;
        }
        printed.insert(turma1.getClassCode());
        cout << "\t"<< turma1.getClassCode()<< endl;
    }
    cout << endl << endl;

    //Parte de escolher a turma e mostrar o horario

    string turma;
    cout << "\t[0] Voltar atrás" << endl << endl;
    auto itr_turma = classesYear.begin(); //este set tem todas as turmas daquele ano (classCode, ucCode)
    vector<Turma> turmasParaHorario;
    do {
        cout << "\tEscolha uma turma: ";
        cin >> turma;
        cout << "\n";
        if(turma == "0"){
            menuState.pop();
            return getMenu();
        }
        cin.clear();
        cin.ignore(1000, '\n');


    } while (printed.find(turma) == printed.end());

    for(Turma t : classesYear){
        if(t.getClassCode() == turma){
            turmasParaHorario.push_back(t);
        }
    }


    set<Schedule*,schedComp> schedules = m.getSchedules();
    Schedule classSchedule = Schedule();
    for(Turma _class : turmasParaHorario){
        auto mySchedule = schedules.find(new Schedule(_class));
        if(mySchedule != schedules.end()){
            for(Slot slot : (*mySchedule)->getSlots()){
                classSchedule.addSlot(slot);
            }
        }
    }
    classSchedule.sort();
    cout << '\t' << classSchedule << endl;
    menuState.pop();
    getMenu();
}

void Menu::horarioUc(){
    char ano;
    cout << "\t[0] Voltar atrás" << endl << endl;

    do {
        cout << "\tEscolha um ano (1, 2 ou 3): ";
        cin >> ano;
        cout << "\n";
        if (ano == '0'){
            cin.clear();
            menuState.pop();
            return getMenu();

        }
    } while (ano < '1' || ano > '3');

    //listagem das UCs

    cout << "\tUCs do " << ano << "º ano:" << "\n";


    set<CourseUnit> ucSet = m.getUcs(ano);
    for (auto uc : ucSet)
        cout << "\t" << uc.getUcCode() << "\n";

    auto it = ucSet.begin();
    string uc;
    do {
        cout << "\n\tescolha uma das UCs acima (código): ";
        cin >> uc;
        if (uc == "0"){
            cin.clear();
            menuState.pop();
            return getMenu();
        }
        CourseUnit tempUc(uc);
        it = ucSet.find(tempUc); //logarithmic
    } while(it == ucSet.end());

    CourseUnit UC = *it; // A UC escolhida pelo utilizador

    //listagem das turmas da uc selecionada

    string turma;
    cout << endl;
    set<Schedule*, schedComp> schedules = m.getSchedules();
    Schedule ucSchedule = Schedule(); //Devia ter so uma turma associada (tem mts)?

    for (auto TURMA : UC.getClasses()){
        Turma _class(TURMA, uc); //fisica
        auto mySchedule = schedules.find(new Schedule(_class)); //procura os slots de fisica
        if(mySchedule != schedules.end()) {
            for (Slot slot: (*mySchedule)->getSlots()) {
                ucSchedule.addSlot(slot);
            }
        }
    }
    ucSchedule.sort(); //aqui ordena todos os slots da UC
    //o ucSchedule nao tem turma associada, uma vez que aqui estamos a falar de uma UC e nao de uma turma
    cout << '\t' << ucSchedule << endl;

    menuState.pop();
    getMenu();


}


void Menu::estudantesMenu() {

    for (Student* student: m.getStudents()) {
        cout << '\t' << *student << endl;
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
        cout << "\tEscolha um ano (1, 2 ou 3): ";
        cin >> ano;
        cout << "\n";
        if (ano == '0'){
            cin.clear();
            menuState.pop();
            return getMenu(); //isto deu fix ao bug , alguem sabe pq? se virem isto perguntem me pela print que eu tirei -> Miguel

        }
    } while (ano < '1' || ano > '3');

    //listagem das UCs

    cout << "\tUCs do " << ano << "º ano:" << "\n";


    set<CourseUnit> ucSet = m.getUcs(ano);
    for (auto uc : ucSet)
        cout << "\t" << uc.getUcCode() << "\n";

    auto it = ucSet.begin();
    string uc;
    do {
        cout << "\n\tescolha uma das UCs acima (código): ";
        cin >> uc;
        if (uc == "0"){
            cin.clear();
            menuState.pop();
            return getMenu();
        }
        CourseUnit tempUc(uc);
        it = ucSet.find(tempUc); //logarithmic
    } while(it == ucSet.end());

    CourseUnit UC = *it; // A UC escolhida pelo utilizador

    //listagem das turmas da uc selecionada

    string turma;
    cout << endl;
    for (auto TURMA : it->getClasses())
        cout << "\t" << TURMA << "\n";

    auto itr = UC.getClasses().begin();
    do {
        cout << "\n\tescolha uma turma: ";
        cin >> turma;
        if (turma == "0"){
            cin.clear();
            menuState.pop();
            return getMenu();
        }
        itr = UC.getClasses().find(turma); //logarithmic
    } while(itr == UC.getClasses().end()); //ok

    Turma Turma(turma, uc);

    cout << "\n\tALunos da Turma " << Turma.getClassCode() << " da UC " << Turma.getUcCode() << ":" << endl;


    menuState.pop();
    getMenu();
}

//TODO: refactor disto e inserir turmas
void Menu::inscreverAluno(){
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
        cout << "\tNome do aluno: ";
        getline(cin, name);
        cin.clear();
        cin.ignore(1000, '\n');
        while (true) {
            inscricao(year, courseUnit, turma, turmas);
            char answer;
            cout << "\t Pedido efetuado. Deseja inscrever em mais turmas? (S/N) ";
            cin >> answer;

            if (answer != 'S')
                break;

        }
        m.addRequest(new Request(upCode, name, turmas, type));
    }

    else {
        while(true) {
            inscricao(year, courseUnit, turma, turmas);
            char answer;
            cout << "\t Pedido efetuado. Deseja inscrever em mais turmas? (S/N) ";
            cin >> answer;

            if (answer != 'S')
                break;
        }
        m.addRequest(new Request(upCode,  turmas, type));
    }
    // Falta impedir que ele se inscreva numa turma que já esteja inscrito ou que já tenha no vector de novas turmas

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
    } while(m.getStudents().find(new Student(upcode)) == m.getStudents().end());

    Student* newStudent = *m.getStudents().find(new Student(upcode));

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

    auto index = newStudentClasses.begin(); // listas não têm [], temos de usar advance() que é O(1)

    if (choice != 0 && (choice != newStudentClasses.size() + 1)) {

        advance(index, choice - 1); //avançar para o index certo da lista
        newStudent->removeClass(*index);

        if (newStudent->getClasses().size() == 0)
            m.eraseStudent(newStudent); // Remover totalmente o estudante se não estiver em nenhuma turma
            cout << "\nEstudante desinscrito com sucesso!";
    }

    else if (choice == newStudentClasses.size() + 1) {
        m.eraseStudent(newStudent);
        cout << "\nEstudante desinscrito com sucesso!";
    }

    // !!!!!!FALTA ATUALIZAR O FICHEIRO -> talvez seja util uma função updateFile() que atualize inscriçoes/desinscriçoes

    getMenu();
}


void Menu::alunosAno() {
    unsigned year;
    do {
        cout << "Introduza um ano: ";
        cin >> year;

    } while (year < 0 || year > 3);

    int count = 1;
    for (Student* s : m.getStudents()) {
        if (s->getYear() == year) {
            cout << "\t[" << count << "] " << (*s) << endl;
            count++;
        }
    }
    menuState.pop();
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


    switch(choice) {
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


void Menu::alunosUC() {
    char year;

    do {
        cout << "Introduza um ano: ";
        cin >> year;

    } while (year < '0' || year > '3');

    string uc;
    set<CourseUnit> UCs = m.getUcs(year);
    CourseUnit c;

    for (CourseUnit uc : UCs) {
        cout << uc.getUcCode()<< endl;
    }

    do {
        cout << "Escolha uma UC: ";
        cin >> uc;
        c.setUcCode(uc);

    } while( UCs.find(c) == UCs.end());
    for (Student* s : m.getStudents()) {
        for (Turma t : s->getClasses()) {
            if (t.getUcCode() == uc)
                cout << (*s) << endl;
        }
    }
    menuState.pop();
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

    while(true) {

        auto it = turmas.begin();

        int counter = 1;
        for (Turma t: turmas) {
            cout << "\t [" << counter << "] ";
            t.printClass();
            counter++;
        }

        do {
            cout << "Escolha o conjunto que quer trocar: ";
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

        turmas.erase(it); // Caso seja feita outra troca, impede trocar a já trocada
        turmas_novas.push_back(Turma(newClass, courseUnit));

        cout << "Pedido efetuado com sucesso!" << endl << endl;
        cout << "Pretende adicionar outra troca [o pedido é considerado único e só é possivel se todas as trocas forem possíveis]? (S/N)";

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
    } while(student_iterator1 == students_set.end());


    do {
        cout << "UP do estudante 2: ";
        cin >> upcode2;
        student_iterator2 = students_set.find(new Student(upcode2));
    } while(student_iterator2 == students_set.end() || upcode2 == upcode1);

    list<Turma> turmas_troca = (*student_iterator2)->getClasses();
    auto itr_troca = turmas_troca.begin();

    int counter = 1;
    for (Turma turma : turmas_troca) {
        cout << "\t[" << counter << "] ";
        turma.printClass();
        counter++;
    }

    cout << "\n\tEstas são as turmas do estudante 2." << endl;

    int choice;
    do {
        cout << "\tQue conjunto pretende trocar? ";
        cin >> choice;
    } while(choice < 1 || choice > turmas_troca.size());

    advance(itr_troca, choice - 1);
    list<Turma> turmas_1 = (*student_iterator1)->getClasses();
    set<CourseUnit> ucs_1;

    bool possible = false;
    for (Turma turma : turmas_1) {
        if (turma.getUcCode() == (*itr_troca).getUcCode() && turma.getClassCode() != (*itr_troca).getClassCode())
            possible = true;
    }

    if (!possible) {
        cout << "\n\tERRO: O estudante 1 não está inscrito nessa UC." << endl;
        menuState.pop();
        return getMenu();
    }

    cout << "\n\tPedido efetuado com sucesso!" << endl << endl;
    m.addRequest(new Request(upcode1, upcode2, novas_turmas, type));

    menuState.pop();
    getMenu();
}

// Colocar os outros menus
// Colocar aqui as funções de listagem (que estão relacionadas
// com as escolhas dos menus



void Menu::inscricao(char& year, string& courseUnit, string& turma, vector<Turma>& turmas) {
    cout << "\tEm que ano quer inscrever: ";
    cin >> year;

    set<CourseUnit> ucSet = m.getUcs(year);
    auto it = ucSet.begin();

    for (CourseUnit uc: ucSet)
        cout << "\t" << uc.getUcCode() << endl;

    do {
        cout << "\tEscolha uma UC: ";
        cin >> courseUnit;
        CourseUnit tempUc(courseUnit);
        it = ucSet.find(courseUnit);

    } while (it == ucSet.end());



    for (string s: (*it).getClasses())
        cout << "\t" << s << endl;

    do {
        cout << "\tEscolha uma Turma: ";
        cin >> turma;
    } while ((*it).getClasses().find(turma) == (*it).getClasses().end());

    turmas.push_back(Turma(turma, courseUnit));

}