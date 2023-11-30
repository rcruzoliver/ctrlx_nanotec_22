#pragma once

#include "common/log/trace/i_registration.h"

namespace comm {
namespace datalayer {

class ITrace
{
public:
  virtual ~ITrace() {}

  virtual void registerTrace(common::log::trace::IRegistrationRealTime2* traceRegistration) = 0;
  virtual void unregisterTrace(common::log::trace::IRegistrationRealTime2* traceRegistration) = 0;
protected:
private:
};

}
}
