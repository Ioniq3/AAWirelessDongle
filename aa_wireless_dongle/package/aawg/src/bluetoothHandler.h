#pragma once

#include "bluetoothCommon.h"

class BluezAdapterProxy;
class AAWirelessProfile;
class HSPHSProfile;
class BLEAdvertisement;

class BluetoothHandler {
public:
    static BluetoothHandler& instance();

    void init();
    void connect();
    void powerOff();

private:
    BluetoothHandler() {};
    BluetoothHandler(BluetoothHandler const&);
    BluetoothHandler& operator=(BluetoothHandler const&);

    DBus::ManagedObjects getBluezObjects();

    void initAdapter();
    void setPower(bool on);
    void setPairable(bool pairable);
    void exportProfiles();
    void connectDevice();

    void startAdvertising();
    void stopAdvertising();

    std::shared_ptr<DBus::Dispatcher> m_dispatcher;
    std::shared_ptr<DBus::Connection> m_connection;
    std::shared_ptr<BluezAdapterProxy> m_adapter;

    std::shared_ptr<AAWirelessProfile> m_aawProfile;
    std::shared_ptr<HSPHSProfile> m_hspProfile;

    std::shared_ptr<BLEAdvertisement> m_leAdvertisement;

    std::string m_adapterAlias;
};
