#pragma once
#include "datalayer_defs.h"
#include "memory_generated.h"
#include "memory_map_generated.h"
#include "datalayer_types.h"
#include "variant.h"

namespace comm
{
namespace datalayer
{

#define DL_RT_CHECK_REVISION            (uint8_t*)(0x0000C0EC)   //! Magic for only check revision in rt_user->beginAccess()
#define DL_RT_NON_BLOCKING              (uint8_t*)(0x0000A0EC)   //! Magic for non blocking rt->beginAccess() - returns DL_RT_WOULD_BLOCK in case of blocking

class IMemoryOwner {
public:
  IMemoryOwner() = default;
  virtual ~IMemoryOwner() = default;

  // all member functions are realtime capable

  //ID contract to write
  virtual DlResult beginAccess(uint8_t*& data, uint32_t revision) = 0;
  virtual DlResult endAccess() = 0;

  virtual DlResult getSize(size_t& sizeBytes) const = 0;
  virtual DlResult getType(MemoryType& type) const = 0;

  virtual DlResult getMemoryMap(Variant &memMap) = 0;
  virtual DlResult setMemoryMap(const Variant &memoryMap) = 0;
};

class IMemoryUser {
public:
  IMemoryUser() = default;
  virtual ~IMemoryUser() = default;

  // all member functions are realtime capable

  virtual DlResult beginAccess(uint8_t*& data, uint32_t revision) = 0;
  virtual DlResult endAccess() = 0;

  virtual DlResult getSize(size_t& sizeBytes) = 0;
  virtual DlResult getType(MemoryType& type) = 0;

  virtual DlResult getMemoryMap(Variant &memMap) = 0;
};

}
}
