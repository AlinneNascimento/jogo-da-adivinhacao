#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "************************************\n";
    cout << "* Bem vindo ao jogo da adivinhação *\n";
    cout << "************************************\n";

    cout << "Escolha o nível de dificuldade:\n";
    cout << "Fácil (F), Médio (M), Difícil (D)\n";

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    if (dificuldade == 'F'){
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M'){
        numero_de_tentativas = 10;
    }
    else
    {
        numero_de_tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() %100;

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++){   
        int chute;
        cout << "Tentativa:" << tentativas << endl;
        cout << "Qual o seu chute?\n";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;

        cout << "Seu chute é:" << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou) {
            cout << "Parabéns! Você acertou o número secreto!\n";
            nao_acertou = false;
        }
        else if (maior) {
            cout << "Seu chute foi maior que o número secreto!\n";
        }
        else {
            cout << "Seu chute foi menor que o número secreto!\n";
        }
    }

    cout << "Fim de jogo!\n";
    if (nao_acertou){
        cout << "Você perdeu! Tente novamente\n";
    }else{
        cout << "Você acertou o número secreto em: " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de: " << pontos << " pontos" << endl;

    }
    
    return 0;
}
