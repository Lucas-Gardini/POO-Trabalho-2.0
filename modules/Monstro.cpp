#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "./.env.h"

using namespace std;

class Monstro {
protected:
  string nome;
  int _HP, _ATQ, _DEF;
  IndiceMonstros _TIPOMONSTRO;
  int vidaAtual = 0;

public:
  Monstro(string nome, int ptVida, int ptDef, int ptAtq, IndiceMonstros tipoMonstro) : nome(nome), _HP(ptVida), _DEF(ptDef), _ATQ(ptAtq), _TIPOMONSTRO(tipoMonstro) {
    this->vidaAtual = ptVida;
  }

  // Fun��o que verifica se o monstro est� vivo, comparando se sua vida � maior que 0.
  bool verificaVivo() {
    if (this->vidaAtual > 0) {
      return true;
    }
    else {
      return false;
    }
  }

  // Fun��o getter para o nome do monstro.
  string getNomeMonstro() {
    return this->nome;
  }

  // Fun��o getter para a defesa do monstro.
  int getDefesaMonstro() {
    return this->_DEF;
  }

  // Fun��o getter para o tipo do monstro.
  IndiceMonstros getTipoMonstro() {
    return _TIPOMONSTRO;
  }

  // Fun��o getter que retorna um vetor com as estat�sticas do monstro.
  int* getEstatisticas(bool valoresAtuais = false) {
    int* estatisticas = new int[4];

    if (valoresAtuais)
      estatisticas[0] = this->vidaAtual;
    else
      estatisticas[0] = this->_HP;
      estatisticas[1] = this->_DEF;
      estatisticas[2] = this->_ATQ;

    return estatisticas;
  }

  // Fun��o que imprime as estat�sticas do monstro.
  /*
  void printDetalhesMonstro(bool valoresAtuais = false) {
    int* estatisticas = this->getEstatisticas(valoresAtuais);

    vector<string> cabecalho = { "Estat�sticas:\n", "" };
    vector<vector<string>> tabela = {
      {"Nome:", this->nome},
      {"Vida:", to_string(estatisticas[0])},
      {"Defesa:", to_string(estatisticas[1])},
      {"Dano de ataque:", to_string(estatisticas[2])},
    };

    delete[] estatisticas;

    printTable(cabecalho, tabela, true);
  } 
  */

  // Fun��o que faz o monstro tomar dano.
  void tomarDano(int dano) {
    if (dano <= this->_DEF) {
      cout << "O monstro defendeu o ataque!" << endl;
      return;
    }

    this->vidaAtual -= (dano - this->_DEF);
  }

  // Fun��o que faz o monstro atacar o jogador.
  int atacar(int defesaJogador) {
    int dano = this->_ATQ - defesaJogador;
    cout << "\nO " << COR_VERMELHA << "monstro" << RESET_COR << " causou " << dano << " de dano!" << endl;

    return this->_ATQ;
  }

  // Fun��o que imprime a vida do monstro.
  void vidaMonstro() {
    int vida = this->vidaAtual < 0 ? 0 : this->vidaAtual;
    cout << "Vida do monstro: " << vida << "/" << this->_HP << endl;
  }
};

class Aranha : public Monstro {
public:
  Aranha() : Monstro("Aranha", ARANHA_VIDA, ARANHA_DEFESA, ARANHA_ATAQUE, IndiceMonstros::ARANHA) {}
};

class AranhaGrande : public Monstro {
public:
  AranhaGrande() : Monstro("Aranha Grande", ARANHA_GRANDE_VIDA, ARANHA_GRANDE_DEFESA, ARANHA_GRANDE_ATAQUE, IndiceMonstros::ARANHA_GRANDE) {}
};

class Escorpiao : public Monstro {
public:
  Escorpiao() : Monstro("Escorpi�o", ESCORPIAO_VIDA, ESCORPIAO_DEFESA, ESCORPIAO_ATAQUE, IndiceMonstros::ESCORPIAO) {}
};
