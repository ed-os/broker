#include "EventHandlerDataCallback.h"

#include "NagiosObjects/NagiosEventHandlerData.h"
#include "Statusengine.h"

namespace statusengine {
    EventHandlerDataCallback::EventHandlerDataCallback(Statusengine *se)
        : NebmoduleCallback(NEBCALLBACK_EVENT_HANDLER_DATA, se) {}

    void EventHandlerDataCallback::Callback(int event_type, void *vdata) {
        auto data = reinterpret_cast<nebstruct_event_handler_data *>(vdata);

        auto myData = NagiosEventHandlerData(data);
        se->SendMessage("statusngin_eventhandler", myData.ToString());
    }
} // namespace statusengine
