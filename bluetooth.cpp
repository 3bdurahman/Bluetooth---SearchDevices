#include "windows.h"
#include "bluetoothapis.h"
#include <iostream>

using namespace std;

int main() {

  BLUETOOTH_DEVICE_SEARCH_PARAMS *search = new BLUETOOTH_DEVICE_SEARCH_PARAMS {
    sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS),
    true,
    true,
    true,
    true,
    true,
    7,
    nullptr
  };

  BLUETOOTH_DEVICE_INFO *deviceinfo = new BLUETOOTH_DEVICE_INFO {sizeof(BLUETOOTH_DEVICE_INFO)};
  HBLUETOOTH_DEVICE_FIND hfind = BluetoothFindFirstDevice(search, deviceinfo);

  if (!hfind) {
    cout << "Not Found";
    return 0;
  }
  wcout << L"Device: " << deviceinfo->szName;
  while (BluetoothFindNextDevice(hfind, deviceinfo)) wcout << L"Device: " << deviceinfo->szName;
    
  BluetoothFindDeviceClose(hfind);
  return 0;
}