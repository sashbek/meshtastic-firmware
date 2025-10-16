#include "PongModule.h"
#include "MeshService.h"
#include "MeshTypes.h"
#include "meshtastic/mesh.pb.h"
#include "meshtastic/portnums.pb.h"

#include <cstdio>
#include <cstring>

ProcessMessage PongModule::handleReceived(const meshtastic_MeshPacket &mp)
{
  meshtastic_MeshPacket* reply = allocDataPacket();
  char *message = new char[60];

  reply->channel = mp.channel;
  reply->to = NODENUM_BROADCAST;
  reply->want_ack = true;

  if (mp.hop_start == mp.hop_limit)
    // Direct ping, SNR/RSSI can be helpful
    sprintf(message, "Нет.\nR:%d S:%.2f, глупый %x!", mp.rx_rssi, mp.rx_snr, mp.from);
  else
    // Ping was obtained via mesh, SNR/RSSI can't be helpful, but hop count can
    sprintf(message, "Нет.\nHops:%d/%d, глупый %x!", mp.hop_start - mp.hop_limit, mp.hop_start, mp.from);

  reply->decoded.payload.size = strlen(message);
  memcpy(reply->decoded.payload.bytes, message, reply->decoded.payload.size);

  service->sendToMesh(reply, RX_SRC_LOCAL, true);
  delete[] message;

  return ProcessMessage::CONTINUE;
}

bool PongModule::wantPacket(const meshtastic_MeshPacket *p)
{
  if (!MeshService::isTextPayload(p) ||
      p->decoded.portnum != meshtastic_PortNum_TEXT_MESSAGE_APP ||
      p->from == 0) {
      return false;
  }

  if (strcasecmp("Помоги мне!", (const char*)p->decoded.payload.bytes) == 0
    || strcasecmp("Помоги мне", (const char*)p->decoded.payload.bytes) == 0
    || strcasecmp("Помоги мне, Аска!", (const char*)p->decoded.payload.bytes) == 0
    || strcasecmp("Помоги мне, Аска", (const char*)p->decoded.payload.bytes) == 0)
  {
    return true;
  }

  return false;
}