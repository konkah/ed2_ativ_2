#include <iostream>
#include "rational.h" 

using std::cout;
using std::endl;

/*
  Observe abaixo que agora somos obrigados a dar um nome para o
  parâmetro. A função já está implementada, use como referência para
  todas as outras.
 */
Rational::Rational(int n, int d) {
    numerator = n;
    denominator = d;
    reduction();
}

/*
  Abaixo o método que deve multiplicar dois números racionais. O
  primeiro número racional é a instância atual da classe, o segundo
  número racional é o que veio por parâmetro. Note que a multiplicação
  não deve alterar nenhum desses objetos, mas criar um terceiro objeto
  que será devolvido ao usuário desta função.
 */

Rational Rational::multiplication(const Rational& m) {
    Rational t; // Cria um objeto racional que será retornaldo.

    /*
      Note que estamos dentro da classe Rational. Nesse caso, podemos
      acessar os atributos privados "numerator" e
      "denominator". Qualquer tentativa de acessar esses atributos feita
      fora da classe gerará um erro. Note que esta filosofia é diferente
      do "private" da linguagem "Java".
     */
    t.numerator = m.numerator * numerator;
    t.denominator = m.denominator * denominator;
    t.reduction(); // Esta função auxiliar evita uma grande quantidade
           // de problema.
    return t;
}


/*
  Abaixo os outros métodos que você deve implementar. Eu já comecei a
  implementação de todos eles para você.
 */
Rational Rational::addition(const Rational& a) {
    Rational t;

    t.numerator = numerator * a.denominator + a.numerator * denominator;
    t.denominator = denominator * a.denominator;
    t.reduction();

    return t;
}

Rational Rational::subtraction(const Rational& s) {
    Rational t;

    t.numerator = numerator * s.denominator - s.numerator * denominator;
    t.denominator = denominator * s.denominator;
    t.reduction();

    return t;
}

Rational Rational::division(const Rational& v) {
    Rational t;

    t.numerator = numerator * v.denominator;
    t.denominator = denominator * v.numerator;
    t.reduction();

    return t;
}

/*
  Crie agora os métodos que vão imprimir o número racional na tela do
  usuário. Não esqueça da divisão por zero. Acredito que você
  precisará fazer algumas pesquisas na internet e no StackOverFlow.
 */
void Rational::printRational() {
    if (denominator == 0) {
        cout << "Não existe divisão por zero" << endl;
    }
    else {
        cout << numerator << "/" << denominator;
    }
}

void Rational::printRationalAsDouble() {
    if (denominator == 0) {
        cout << "Não existe divisão por zero" << endl;
    }
    else {
        cout << numerator * 1.0 / denominator;
    }
}

int gcd(int a, int b) {
    if (a < 0)
        a = -a;

    if (b < 0)
        b = -b;
	
    if (a == 0 || b == 0)
        return 1;

    if (a < b)
        return gcd(b, a);

    if (a == b)
        return a;

    if (a % b == 0)
        return b;

    return gcd(b, a % b);
}

/*
  Implemente agora o método privado "reduction". Mostre ao professor
  que você saber computar o máximo divisor comum de dois números.
 */
void Rational::reduction() {
    int gcd_divisor = gcd(numerator, denominator);

    numerator = numerator / gcd_divisor;
    denominator = denominator / gcd_divisor;
}
