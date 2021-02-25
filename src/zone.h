#include <iostream>
#include <map>

using namespace std;

class Zone {
  public:
    void getZone(const string q_name);

    string getIp() {
      return m_ip_addr;
    }

    string getDomain() {
      return m_domain;
    }

  protected:
    string m_ip_addr;
    string m_domain;
};
