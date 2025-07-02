#pragma once

#include <stdint.h>
#include <stddef.h> // for size_t

typedef struct {
  bool enabled;
  unsigned long interval;
  unsigned long* lastSent;
  void* packet;
  size_t size;
  uint8_t packetId;
  const char* name;
} PacketTask;
