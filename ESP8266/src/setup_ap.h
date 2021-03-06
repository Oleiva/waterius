#ifndef _SETUPAP_h
#define _SETUPAP_h

#include "setup.h"
#include "master_i2c.h"
#include <Arduino.h>
#include <WiFiManager.h>	

void setup_ap(Settings &sett, const SlaveData &data, const float &value0, const float &value1);
void storeConfig(const Settings &sett);
bool loadConfig(Settings &sett);

class IPAddressParameter : public WiFiManagerParameter {
public:

    IPAddressParameter(const char *id, const char *placeholder, IPAddress address)
        : WiFiManagerParameter("")
    {
        init(id, placeholder, address.toString().c_str(), 16, "") ;//, WFM_LABEL_BEFORE);
    }

    IPAddress getValue() {
        IPAddress ip;
        ip.fromString(WiFiManagerParameter::getValue());
        return ip;
    }
};

class LongParameter : public WiFiManagerParameter {
public:

    LongParameter(const char *id, const char *placeholder, long value, const uint8_t length = 10)
        : WiFiManagerParameter("") {

        init(id, placeholder, String(value).c_str(), length, "") ;//, WFM_LABEL_BEFORE);
    }

    long getValue() {
        return String(WiFiManagerParameter::getValue()).toInt();
    }
};

class FloatParameter : public WiFiManagerParameter {
public:

    FloatParameter(const char *id, const char *placeholder, float value, const uint8_t length = 10)
        : WiFiManagerParameter("") {
            
        init(id, placeholder, String(value).c_str(), length, "") ;//, WFM_LABEL_BEFORE);
    }

    float getValue() {
        return String(WiFiManagerParameter::getValue()).toFloat();
    }
};

#endif

