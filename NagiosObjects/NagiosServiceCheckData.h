#pragma once

#include "NagiosObject.h"
#include "Nebmodule.h"

namespace statusengine {
    class NagiosServiceCheckData : public NagiosObject {
      public:
        explicit NagiosServiceCheckData(const nebstruct_service_check_data *serviceCheckData);
    };
} // namespace statusengine
