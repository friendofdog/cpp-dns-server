#include <iostream>

using namespace std;

class Query {
  public:
    void parseQueryHeader(const char*& buffer);
    void parseQueryBody(const char*& buffer);
    int getBits(const char*& buffer) throw();

    int returnId() {
      return m_id;
    }

  protected:
    int m_id;

    uint m_fields;
    uint m_qr;
    uint m_opcode;
    uint m_aa;
    uint m_tc;
    uint m_rd;
    uint m_ra;
    uint m_rcode;
  
    int m_qdCount;
    int m_anCount;
    int m_nsCount;
    int m_arCount;

    string m_qName;
  
  private:
    static const uint QR_MASK = 0x8000;
    static const uint OPCODE_MASK = 0x7800;
    static const uint AA_MASK = 0x0400;
    static const uint TC_MASK = 0x0200;
    static const uint RD_MASK = 0x0100;
    static const uint RA_MASK = 0x8000;
    static const uint RCODE_MASK = 0x000F;
};