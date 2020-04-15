// Calculadora.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <math.h> //biblioteca para utilização de potenciação (função pow)
using namespace std;

int main()
{
    int opcao,valor, resultado = 0, contador = 1;


    cout << "1 - Binario para decimal\n";
    cout << "2 - Decimal para binario\n";
    cout << "Digite o numero referente a opcao de conversao: ";
    cin >> opcao;

//Binario para decimal
    if (opcao == 1) {
        cout << "Binario para decimal\n";
        cout << "Informe o valor em binario para ser convertido em decimal: ";
        cin >> valor;
        while (valor > 0)
        {
            if (valor%10 > 1) //desvio para verificar se é um numero binario valido. O input só pode conter digitos 0 e 1, por isso o %10 não pode ser maior que 1
            {
                valor = 0; //para terminar o laço while
                resultado = 0;
                cout << "Este valor nao e um binario valido\n";
            }
            resultado = resultado + (valor % 10) * pow(2, contador - 1);//contador-1 porque o contador foi declarado com o valor 1. O %10 serve para pegar cada casa do numero em binario
            valor = valor / 10; //remove a ultima casa da direita.
            contador++;
        }

 //Decimal para Binario
    }else if (opcao == 2) {
        cout << "Decimal para binario\n";
        cout << "Informe o valor em decimal para ser convertido em binario: ";
        cin >> valor;

/*Para achar o valor convertido de decimal para binario, deve-se pegar o valor decimal MOD 2 e o resultado é cada um dos bits do valor em binario.
Depois o valor deve ser dividido por dois antes de entrar em uma nova iteração do laço.*/
        while (valor > 0)
        {
            //O resultado de (valor % 2) é multiplicado por contador para que seja adicionado na casa correta, a frente dos demais bits do resultado parcial.
            resultado = resultado + (valor % 2) * contador;

            //if para zerar o valor em decimal para evitar loop infinito depois de converter o decimal 1 para o binario 1
            if (valor == 1)
            {
                valor = 0;
            }
            valor = valor / 2;
            contador = contador * 10;
        }
    }else{
//Verificar de opção
        cout << "Opcao invalida";
    }
    cout << "Resultado: " << resultado << "\n";
    return 0;
}

