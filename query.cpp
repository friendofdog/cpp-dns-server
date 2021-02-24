#include <iostream>

using namespace std;

typedef unsigned char uchar;

static const uint QR_MASK = 0x8000;
static const uint OPCODE_MASK = 0x7800;
static const uint AA_MASK = 0x0400;
static const uint TC_MASK = 0x0200;
static const uint RD_MASK = 0x0100;
static const uint RA_MASK = 0x8000;
static const uint RCODE_MASK = 0x000F;

int getBits(const char* buffer, int offset) throw () {
  buffer += offset;
  int value = static_cast<uchar> (buffer[0]);
  value = value << 8;
  value += static_cast<uchar> (buffer[1]);

  return value;
}

void getQueryHeader(char* buffer) {
  int id = getBits(buffer, 0);

  uint fields = getBits(buffer, 2);
  uint qr = fields & QR_MASK;
  uint opcode = fields & OPCODE_MASK;
  uint aa = fields & AA_MASK;
  uint tc = fields & TC_MASK;
  uint rd = fields & RD_MASK;
  uint ra = fields & RA_MASK;
  uint rcode = fields & RCODE_MASK;

  int qdCount = getBits(buffer, 4);
  int anCount = getBits(buffer, 6);
  int nsCount = getBits(buffer, 8);
  int arCount = getBits(buffer, 10);

  cout << "\nID: " << id << endl;
  cout << "\nFields: " << fields << endl;
  cout << "\nFlags: " << qr << ", " << opcode << ", " << aa << ", " << tc << ", " << rd << ", " << ra << ", " << rcode << endl;
  cout << "\nqdCount: " << qdCount << endl;
  cout << "\nanCount: " << anCount << endl;
  cout << "\nnsCount: " << nsCount << endl;
  cout << "\narCount: " << arCount << endl;
}
