
#include "pokedex.h"
#include <iostream>

using namespace std;

// Your code goes here

// Constructor - create empty Pokedex
Pokedex::Pokedex() { msize = 0; }

// Return size
int Pokedex::size() const { return msize; }

// Return maximum size of Pokedex
int Pokedex::max_size() { return MAX; }

// Return true if Pokedex is empty
bool Pokedex::empty() const { return (msize == 0); }

// Return pokemon at given index
const string &Pokedex::at(int n) const {
  if (n < 0 || n >= msize) {
    cerr << "Error: Cannot access element at " << n << endl;
    return pokemons[0];
  }
  return pokemons[n];
}

// Return pokemon at the front, alphabetically first one
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "Error: Cannot access front for empty Pokedex" << endl;
    return pokemons[0];
  }
  return pokemons[0];
}

// Return pokemon at the back, alphabetically last one
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "Error: Cannot access back for empty Pokedex" << endl;
    return pokemons[0];
  }
  return pokemons[msize - 1];
}

// Add pokemon to Pokedex, keep the Pokedex list sorted
void Pokedex::insert(const string &pokemon) {
  if (msize == MAX) {
    cerr << "Error: Cannot add any more elements to Pokedex" << endl;
    return;
  }

  // Find the index where the new pokemon should be inserted
  int index = msize;
  for (int i = 0; i < msize; i++) {
    if (pokemon < pokemons[i]) {
      index = i;
      break;
    }
  }

  // Shift all the elements from the index to the right
  for (int i = msize - 1; i >= index; i--) {
    pokemons[i + 1] = pokemons[i];
  }

  // Insert the new pokemon
  pokemons[index] = pokemon;
  msize++;
}

// Delete the last element
void Pokedex::pop_back() {
  if (empty()) {
    cerr << "Error: Cannot pop_back for empty Pokedex" << endl;
    return;
  }
  msize--;
}

// Erase element at index
void Pokedex::erase(int n) {
  if (n < 0 || n >= msize) {
    cerr << "Error: Cannot erase element at " << n << endl;
    return;
  }
  for (int i = n; i < msize - 1; i++) {
    pokemons[i] = pokemons[i + 1];
  }
  msize--;
}

// Overloaded insertion operator
ostream &operator<<(ostream &out, const Pokedex &pdx) {
  out << "[";
  if (!pdx.empty()) {
    out << pdx.at(0);
    for (int i = 1; i < pdx.size(); i++) {
      out << ", " << pdx.at(i);
    }
  }
  out << "]";
  return out;
}