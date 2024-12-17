#pragma once

#include "DeviceBase.h"
#include "MMDevice.h"

#define ERR_PORT_OPEN_FAILED 106
#define ERR_COMMUNICATION 107
#define ERR_NO_PORT_SET 108
#define ERR_VERSION_MISMATCH 109

const unsigned char cmd_version = 0;
const unsigned char cmd_start = 1;
const unsigned char cmd_stop = 2;
const unsigned char cmd_interval = 3; // interval in microseconds
const unsigned char cmd_pulse_duration = 4; // in microsconds
const unsigned char cmd_wait_for_input = 5;
const unsigned char cmd_number_of_pulses = 6;


class TeensyCom
{
public:

   TeensyCom(MM::Core* callback, MM::Device* device, const char* portLabel);

   ~TeensyCom() {};

   int SendCommand(uint8_t cmd, uint32_t param);
   int Enquire(uint8_t cmd);
   int GetResponse(uint8_t cmd, uint32_t& param);
   int GetVersion(uint32_t& version);
   int GetInterval(uint32_t& interval);


private:
   MM::Core* callback_;
   MM::Device* device_;
   const char* portLabel_;
};
