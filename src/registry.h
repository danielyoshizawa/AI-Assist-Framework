#ifndef REGISTRY_H
#define REGISTRY_H

#include "service.h"
#include <unordered_map>

class Registry : public Service {
public:
    void SetupRoutes() override;
private:
    void registerService(std::string const& name, std::string const& address);
    void unregisterService(std::string const& name);

    std::unordered_map<std::string, std::string> services;
};

#endif // REGISTRY_H