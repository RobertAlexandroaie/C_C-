enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument 
{
public:
  void play(note) const {}
};

// obiectele Wind sunt Instrumente
class Wind : public Instrument {};

void tune(Instrument& i) 
{
  // ... in metoda tune, codul functioneaza atat pentru Instruments cat si pentru derivatele din Instruments
  i.play(middleC);
}

int main() 
{
  Wind flute;
  tune(flute); // Upcasting - cast de la derivata spre baza; 'urcarea' in diagrama de mostenire
  return 0;
}