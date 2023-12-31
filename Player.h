#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <sstream> // Se agrega la librería para stringstream
#include <string>
#include <vector>

class Player {
private:
  std::string nombre, liga, posicion;
  int Goles, promedioPases, valor;

public:
  // Constructores
  Player();
  Player(std::string, std::string, std::string, int, int, int);

  // Getters
  std::string getNombre() const;
  std::string getPosicion() const;
  std::string getLiga() const;
  int getPromedioPases() const;
  int getGoles() const;
  int getValor() const;

  // Setters
  void setNombre(std::string);
  void setPosicion(std::string);
  void setLiga(std::string);
  void setPromedioPases(int);
  void setGoles(int);
  void setValor(int);

  // Sobrecarga de operadores
  bool operator<(const Player &jugador) const {
    return this->Goles < jugador.Goles;
  }

  bool operator>(const Player &jugador) const {
    return this->Goles > jugador.Goles;
  }

  bool operator==(const Player &other) const {
    return this->getNombre() == other.getNombre();
  }

  // Método para convertir a cadena
  std::string toString() const {
    std::stringstream ss;
    ss << "Nombre: " << nombre << " Goles: " << Goles;
    return ss.str();
  }
};
Player::Player() {
  this->nombre = "Jugador no Encontrado";
  this->liga = "Sin liga";
  this->posicion = "No tiene posicion";
  this->Goles = 0;
  this->promedioPases = 0.0;
  this->valor = 0.0;
}

Player::Player(std::string nombre, std::string posicion, std::string liga,
               int Goles, int PromedioPases, int valor) {
  this->nombre = nombre;
  this->liga = liga;
  this->posicion = posicion;
  this->Goles = Goles;
  this->promedioPases = PromedioPases;
  this->valor = valor;
}

std::string Player::getNombre() const { return nombre; }

std::string Player::getPosicion() const { return posicion; }

std::string Player::getLiga() const { return liga; }

int Player::getGoles() const { return Goles; }

int Player::getPromedioPases() const { return promedioPases; }

int Player::getValor() const { return valor; }

// Setters

void Player::setNombre(std::string nombre) { this->nombre = nombre; }

void Player::setPosicion(std::string posicion) { this->posicion = posicion; }

void Player::setLiga(std::string liga) { this->liga = liga; }

void Player::setGoles(int Goles) { this->Goles = Goles; }

void Player::setPromedioPases(int promedioPases) {
  this->promedioPases = promedioPases;
}

void Player::setValor(int valor) { this->valor = valor; }

#endif
