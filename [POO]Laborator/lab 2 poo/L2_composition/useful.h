#ifndef USEFUL_H
#define USEFUL_H

class X 
{
  int i;
public:
  X() { i = 0; }
  void set(int ii) { i = ii; }

  /* !!!  
  
  Aceasta este o functie membra const. Cuvantul cheie const trebuie repetat in definitie asa cum apare in declaratie, 
  altfel compilatorul va semnala o eroare.
  
  De asemeni, orice incercare de modificare a variabilelor membru sau un apel catre o alta functie care nu este const va determina compilatorul
  sa semnaleze o eroare.

  Functiile const pot opera atat pe obiecte const cat si pe obiecte non-const.

  */
  int read() const { return i; } 
  int permute() { return i = i * 47; }
};
#endif
