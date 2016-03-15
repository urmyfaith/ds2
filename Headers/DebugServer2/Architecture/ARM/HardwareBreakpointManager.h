//
// Copyright (c) 2014-present, Facebook, Inc.
// All rights reserved.
//
// This source code is licensed under the University of Illinois/NCSA Open
// Source License found in the LICENSE file in the root directory of this
// source tree. An additional grant of patent rights can be found in the
// PATENTS file in the same directory.
//

#ifndef __DebugServer2_Architecture_ARM_HardwareBreakpointManager_h
#define __DebugServer2_Architecture_ARM_HardwareBreakpointManager_h

#include "DebugServer2/BreakpointManager.h"

namespace ds2 {
namespace Architecture {
namespace ARM {

class HardwareBreakpointManager : public BreakpointManager {
public:
  HardwareBreakpointManager(Target::Process *process);
  ~HardwareBreakpointManager() override;

protected:
  virtual bool hit(Target::Thread *thread) override { return false; };

protected:
  virtual void enableLocation(Site const &site) override{};
  virtual void disableLocation(Site const &site) override{};

public:
  virtual int maxWatchpoints();

protected:
  friend Target::ProcessBase;

private:
  int _maxBreakpoints;
  int _maxWatchpoints;
  int _maxWatchpointSize;
};
}
}
}

#endif // !__DebugServer2_Architecture_ARM_HardwareBreakpointManager_h
