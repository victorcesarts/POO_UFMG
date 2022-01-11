#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream myfile("arq_teste.txt");
  char letter;
  int count = 0;
  if (myfile.is_open())
  {
    while (!myfile.eof())
    {
      myfile.get(letter);
      if (letter == ' ')
        count += 1;
    }
    myfile.close();
  }
  else cout << "Não foi possível abrir o arquivo";
  cout << count << endl;
  return 0;
}