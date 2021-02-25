#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "zone.h"

using namespace std;

namespace fs = std::filesystem;

void Zone::getZone(const string q_name) {
  string ZONES = "./zones";

  ifstream file(ZONES);

  if (file.is_open()) {
    string line; 
    while (getline(file, line)) {
      string ip_addr;
      istringstream iss(line);
      while (iss) {
        string subs;
        iss >> subs;
        if (subs == q_name) {
          m_ip_addr = ip_addr;
          m_domain = subs;
        }
        ip_addr = subs;
      }
    }
    file.close();
  }
}

Zone getZoneInfo(const string q_name) {
  Zone zone;
  zone.getZone(q_name);

  return zone;
}