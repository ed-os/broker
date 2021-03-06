#include "NagiosHostStatusData.h"

#include "NagiosHost.h"

namespace statusengine {

    NagiosHostStatusData::NagiosHostStatusData(const nebstruct_host_status_data *hostStatusData) {
        SetData<>("type", hostStatusData->type);
        SetData<>("flags", hostStatusData->flags);
        SetData<>("attr", hostStatusData->attr);
        SetData<>("timestamp", hostStatusData->timestamp.tv_sec);
        NagiosHost hostStatus(reinterpret_cast<host *>(hostStatusData->object_ptr));
        SetData<>("hoststatus", &hostStatus);
    }
} // namespace statusengine
