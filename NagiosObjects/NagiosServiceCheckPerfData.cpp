#include "NagiosServiceCheckPerfData.h"

#include "NagiosService.h"

namespace statusengine {

    NagiosServiceCheckPerfData::NagiosServiceCheckPerfData(const nebstruct_service_check_data *serviceCheckData) {
        SetData<>("type", serviceCheckData->type);
        SetData<>("flags", serviceCheckData->flags);
        SetData<>("attr", serviceCheckData->attr);
        SetData<>("timestamp", serviceCheckData->timestamp.tv_sec);

        NagiosObject servicecheck;

        servicecheck.SetData<>("host_name", serviceCheckData->host_name);
        servicecheck.SetData<>("service_description", serviceCheckData->service_description);
        servicecheck.SetData<>("perf_data", EncodeString(serviceCheckData->perf_data));
        servicecheck.SetData<>("start_time", serviceCheckData->start_time.tv_sec);
        SetData<>("servicecheck", &servicecheck);
    }
} // namespace statusengine
