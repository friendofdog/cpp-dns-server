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

int getBits(const char*& buffer) throw () {
  int value = static_cast<uchar> (buffer[0]);
  value = value << 8;
  value += static_cast<uchar> (buffer[1]);
  buffer += 2;

  return value;
}

void getQueryHeader(const char*& buffer) {
  int id = getBits(buffer);

  uint fields = getBits(buffer);
  uint qr = fields & QR_MASK;
  uint opcode = fields & OPCODE_MASK;
  uint aa = fields & AA_MASK;
  uint tc = fields & TC_MASK;
  uint rd = fields & RD_MASK;
  uint ra = fields & RA_MASK;
  uint rcode = fields & RCODE_MASK;

  int qdCount = getBits(buffer);
  int anCount = getBits(buffer);
  int nsCount = getBits(buffer);
  int arCount = getBits(buffer);

  cout << "\nID: " << id << endl;
  cout << "\nFields: " << fields << endl;
  cout << "\nFlags: " << qr << ", " << opcode << ", " << aa << ", " << tc << ", " << rd << ", " << ra << ", " << rcode << endl;
  cout << "\nqdCount: " << qdCount << endl;
  cout << "\nanCount: " << anCount << endl;
  cout << "\nnsCount: " << nsCount << endl;
  cout << "\narCount: " << arCount << endl;
}

void getQueryBody(const char*& buffer) {
  std::string qName;

  int length = *buffer++;
  while (length != 0) {
    for (int i = 0; i < length; i++) {
      char c = *buffer++;
      qName.append(1, c);
    }
    length = *buffer++;
    if (length != 0) qName.append(1,'.');
  }
  cout << "\nqName: " << qName << endl;
}

void getQuery (const char* buffer) {
  getQueryHeader(buffer);
  getQueryBody(buffer);
}
