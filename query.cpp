#include <iostream>

#include "query.h"

using namespace std;

typedef unsigned char uchar;

int Query::getBits(const char*& buffer) throw() {
  int value = static_cast<uchar> (buffer[0]);
  value = value << 8;
  value += static_cast<uchar> (buffer[1]);
  buffer += 2;

  return value;
}

void Query::parseQueryHeader(const char*& buffer) {
  m_id = getBits(buffer);

  m_fields = getBits(buffer);
  m_qr = m_fields & QR_MASK;
  m_opcode = m_fields & OPCODE_MASK;
  m_aa = m_fields & AA_MASK;
  m_tc = m_fields & TC_MASK;
  m_rd = m_fields & RD_MASK;
  m_ra = m_fields & RA_MASK;
  m_rcode = m_fields & RCODE_MASK;

  m_qdCount = getBits(buffer);
  m_anCount = getBits(buffer);
  m_nsCount = getBits(buffer);
  m_arCount = getBits(buffer);
}

void Query::parseQueryBody(const char*& buffer) {
  int length = *buffer++;
  while (length != 0) {
    for (int i = 0; i < length; i++) {
      char c = *buffer++;
      m_qName.append(1, c);
    }
    length = *buffer++;
    if (length != 0) m_qName.append(1,'.');
  }
}

Query getQuery (const char* buffer) {
  Query query;
  query.parseQueryHeader(buffer);
  query.parseQueryBody(buffer);

  return query;
}
