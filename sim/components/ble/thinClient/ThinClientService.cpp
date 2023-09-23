/*  Copyright (C) 2020-2021 JF, Adam Pigg, Avamander

    This file is part of InfiniTime.

    InfiniTime is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    InfiniTime is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <chrono>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <netinet/in.h>

#include "ThinClientService.h"
#include "systemtask/SystemTask.h"
#include "nrf_log.h"

namespace {
  // 0000yyxx-78fc-48fe-8e23-433b3a1942d0
  //constexpr ble_uuid128_t CharUuid(uint8_t x, uint8_t y) {
  //  return ble_uuid128_t{
  //    .u = {.type = BLE_UUID_TYPE_128},
  //    .value =  { 0xd0, 0x42, 0x19, 0x3a, 0x3b, 0x43, 0x23, 0x8e, 0xfe, 0x48, 0xfc, 0x78, x, y, 0x00, 0x00 }
  //  };
  //}

  // 00000000-78fc-48fe-8e23-433b3a1942d0
  //constexpr ble_uuid128_t BaseUuid() {
  //  return CharUuid(0x00, 0x00);
  //}

  //constexpr ble_uuid128_t msUuid {BaseUuid()};

  //constexpr ble_uuid128_t msEventCharUuid {CharUuid(0x01, 0x00)};
  //constexpr ble_uuid128_t msStatusCharUuid {CharUuid(0x02, 0x00)};
  //constexpr ble_uuid128_t msArtistCharUuid {CharUuid(0x03, 0x00)};
  //constexpr ble_uuid128_t msTrackCharUuid {CharUuid(0x04, 0x00)};
  //constexpr ble_uuid128_t msAlbumCharUuid {CharUuid(0x05, 0x00)};
  //constexpr ble_uuid128_t msPositionCharUuid {CharUuid(0x06, 0x00)};
  //constexpr ble_uuid128_t msTotalLengthCharUuid {CharUuid(0x07, 0x00)};
  //constexpr ble_uuid128_t msTrackNumberCharUuid {CharUuid(0x08, 0x00)};
  //constexpr ble_uuid128_t msTrackTotalCharUuid {CharUuid(0x09, 0x00)};
  //constexpr ble_uuid128_t msPlaybackSpeedCharUuid {CharUuid(0x0a, 0x00)};
  //constexpr ble_uuid128_t msRepeatCharUuid {CharUuid(0x0b, 0x00)};
  //constexpr ble_uuid128_t msShuffleCharUuid {CharUuid(0x0c, 0x00)};

  //int MusicCallback(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt* ctxt, void* arg) {
  //  return static_cast<Pinetime::Controllers::MusicService*>(arg)->OnCommand(conn_handle, attr_handle, ctxt);
  //}
}

Pinetime::Controllers::ThinClientService::ThinClientService(Pinetime::System::SystemTask& system) : m_system(system) {
//  characteristicDefinition[0] = {.uuid = &msEventCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_NOTIFY,
//                                 .val_handle = &eventHandle};
//  characteristicDefinition[1] = {.uuid = &msStatusCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[2] = {.uuid = &msTrackCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[3] = {.uuid = &msArtistCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[4] = {.uuid = &msAlbumCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[5] = {.uuid = &msPositionCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[6] = {.uuid = &msTotalLengthCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[7] = {.uuid = &msTotalLengthCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[8] = {.uuid = &msTrackNumberCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[9] = {.uuid = &msTrackTotalCharUuid.u,
//                                 .access_cb = MusicCallback,
//                                 .arg = this,
//                                 .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[10] = {.uuid = &msPlaybackSpeedCharUuid.u,
//                                  .access_cb = MusicCallback,
//                                  .arg = this,
//                                  .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[11] = {.uuid = &msRepeatCharUuid.u,
//                                  .access_cb = MusicCallback,
//                                  .arg = this,
//                                  .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[12] = {.uuid = &msShuffleCharUuid.u,
//                                  .access_cb = MusicCallback,
//                                  .arg = this,
//                                  .flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_READ};
//  characteristicDefinition[13] = {0};
//
//  serviceDefinition[0] = {
//    .type = BLE_GATT_SVC_TYPE_PRIMARY, .uuid = &msUuid.u, .characteristics = characteristicDefinition};
//  serviceDefinition[1] = {0};
}

Pinetime::Controllers::ThinClientService::~ThinClientService() {
}

void Pinetime::Controllers::ThinClientService::Init() {
  //uint8_t res = 0;
  //res = ble_gatts_count_cfg(serviceDefinition);
  //ASSERT(res == 0);

  //res = ble_gatts_add_svcs(serviceDefinition);
  //ASSERT(res == 0);
}

void Pinetime::Controllers::ThinClientService::setClient(IThinClient* ptr) {
  thinClient = ptr;
  if (!updateThreadStarted) {
      std::thread([this](){
          std::this_thread::sleep_for(std::chrono::milliseconds(2000));
          while (true) {
              if (thinClient == nullptr) { std::this_thread::sleep_for(std::chrono::milliseconds(1000)); continue; }

              for (int i = 1; i <= 120; i++) {
                  std::ostringstream strStream;
                  strStream << std::setw(3) << std::setfill('0') << i;
                  std::string framePath = "../../240/bin_lz4/" + strStream.str() + ".comp"; // filename format: 000.bin
                  std::ifstream frame(framePath, std::ifstream::ate | std::ifstream::binary);

                  uint32_t fileSize = frame.tellg();
                  // header
                  // payload size
                  uint8_t buffer[CHUNK_SIZE];
                  ((uint32_t*) buffer)[0] = htonl(fileSize);
                  frame.seekg(0, std::ios_base::beg);
                  // frame id
                  buffer[4] = i;
                  // send header
                  state = thinClient->OnData(state, (uint8_t*) buffer, 5);

                  // send frame in chunks
                  while (frame.read((char*) buffer, sizeof(buffer)))
                      state = thinClient->OnData(state, (uint8_t*) buffer, frame.gcount());

                  int lastChunk = fileSize%sizeof(buffer);
                  if (lastChunk > 0)
                      state = thinClient->OnData(state, (uint8_t*) buffer, frame.gcount());

                  frame.close();
                  //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
              }
          }
      }).detach();
      updateThreadStarted = true;
  }
}

/*void Pinetime::Controllers::ThinClientService::SwapBytes(uint16_t* arr, uint16_t size) {
  for (uint16_t i = 0; i < size; i++)
    arr[i] = (arr[i]>>8) | (arr[i]<<8);
}*/

//int Pinetime::Controllers::ThinClientService::OnCommand(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt* ctxt) {
//  if (ctxt->op == BLE_GATT_ACCESS_OP_WRITE_CHR) {
//    size_t notifSize = OS_MBUF_PKTLEN(ctxt->om);
//    char data[notifSize + 1];
//    data[notifSize] = '\0';
//    os_mbuf_copydata(ctxt->om, 0, notifSize, data);
//    char* s = &data[0];
//    if (ble_uuid_cmp(ctxt->chr->uuid, &msArtistCharUuid.u) == 0) {
//      artistName = s;
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msTrackCharUuid.u) == 0) {
//      trackName = s;
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msAlbumCharUuid.u) == 0) {
//      albumName = s;
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msStatusCharUuid.u) == 0) {
//      playing = s[0];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msRepeatCharUuid.u) == 0) {
//      repeat = s[0];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msShuffleCharUuid.u) == 0) {
//      shuffle = s[0];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msPositionCharUuid.u) == 0) {
//      trackProgress = (s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msTotalLengthCharUuid.u) == 0) {
//      trackLength = (s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msTrackNumberCharUuid.u) == 0) {
//      trackNumber = (s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msTrackTotalCharUuid.u) == 0) {
//      tracksTotal = (s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3];
//    } else if (ble_uuid_cmp(ctxt->chr->uuid, &msPlaybackSpeedCharUuid.u) == 0) {
//      playbackSpeed = static_cast<float>(((s[0] << 24) | (s[1] << 16) | (s[2] << 8) | s[3])) / 100.0f;
//    }
//  }
//  return 0;
//}

void Pinetime::Controllers::ThinClientService::event(const char* data, uint16_t size) {
    char formattedString[size*10];
    uint16_t formattedStringCnt = 0;
    for (uint16_t i = 0; i < size; i++) {
        formattedStringCnt +=
                sprintf(formattedString+formattedStringCnt, " %2x", (unsigned char) data[i]);
    }
    NRF_LOG_INFO("Event:%s", std::string(formattedString,formattedStringCnt).c_str());
}

void Pinetime::Controllers::ThinClientService::logWrite(std::string message) {
    if (message.length() > LOG_MAX_LENGTH) {
        return;
    }
    NRF_LOG_INFO("%s", message.c_str());
}

void Pinetime::Controllers::ThinClientService::event(char event) {
  std::ignore = event;
  //auto* om = ble_hs_mbuf_from_flat(&event, 1);

  //uint16_t connectionHandle = m_system.nimble().connHandle();

  //if (connectionHandle == 0 || connectionHandle == BLE_HS_CONN_HANDLE_NONE) {
  //  return;
  //}

  //ble_gattc_notify_custom(connectionHandle, eventHandle, om);
}
