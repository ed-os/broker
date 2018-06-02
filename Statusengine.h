#pragma once

#include <map>
#include <string>
#include <vector>

#include "LogStream.h"
#include "Nebmodule.h"

#include "MessageHandler/MessageHandlerList.h"

#include "NagiosCallbacks/NagiosCallbacks.h"

namespace statusengine {
    class Configuration;
    class Nebmodule;

    class Statusengine {
        friend class Nebmodule;

      public:
        Statusengine(const Statusengine &Statusengine) = delete;
        Statusengine(Statusengine &&Statusengine) = delete;
        Statusengine &operator=(const Statusengine &) = delete;

        int Init();

        LogStream &Log();
        void SendMessage(const std::string queue, const std::string message) const;
        void RegisterCallback(NebmoduleCallback *cb);

      private:
        Statusengine(nebmodule *handle, std::string configurationPath);
        ~Statusengine();

        int Callback(int event_type, void *data);

        void SetModuleInfo(int modinfo, std::string text);

        nebmodule *nebhandle;
        std::string configurationPath;
        Configuration *configuration;
        MessageHandlerList *messageHandlers;
        LogStream *ls;
        std::map<NEBCallbackType, std::vector<NebmoduleCallback *> *> *callbacks;
    };
} // namespace statusengine
