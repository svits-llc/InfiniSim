#pragma once

#include <cstdint>

#include <thread>

namespace Pinetime {
  namespace System {
    class SystemTask;
  }
  namespace Controllers {
    class IThinClient;
    class ThinClientService {
    public:
      explicit ThinClientService(Pinetime::System::SystemTask& system);
      ~ThinClientService();

      void Init();

      void event(char event);

      //int OnCommand(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt* ctxt);

      enum class States : uint8_t { Wait, ReceiveImage };

      void setClient(IThinClient* client);

      static constexpr uint8_t CHUNK_SIZE = 244;

    private:
      //struct ble_gatt_chr_def characteristicDefinition[14];
      //struct ble_gatt_svc_def serviceDefinition[2];

      //void SwapBytes(uint16_t* arr, uint16_t size);

      States state = States::Wait;

      Pinetime::System::SystemTask& m_system;

      IThinClient* thinClient = nullptr;

      std::thread updateThread;
    };

    class IThinClient {
      public:
          virtual ~IThinClient() {}
          virtual ThinClientService::States OnData(ThinClientService::States state, uint8_t* buffer, uint8_t len) = 0;
    };
  }
}
