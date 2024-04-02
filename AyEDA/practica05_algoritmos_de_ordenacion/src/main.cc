#include "options/options.h"
#include "sequence/sequence.h"
#include "key/key.h"
#include "position/position.h"
#include "sortmethod/sortmethod.h"

int main(int argc, char* argv[]) {
  auto options = parse_args(argc, argv);
  if (!options) {
    cerr << "Pruebe " << argv[0] << " -h o --help para más información" << endl;
    exit(EXIT_FAILURE);
  }

  Key key(12345, Position(0));
  Sequence* secuencia;
  secuencia = new StaticSequence(5);
  secuencia->Insert(key);
  Key ke1 = secuencia->operator[](Position(1));
  cout << ke1 << endl;
  
  



}