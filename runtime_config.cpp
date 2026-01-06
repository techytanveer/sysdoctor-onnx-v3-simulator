#include "../include/runtime_config.h"
#include <fstream>
#include <nlohmann/json.hpp>

RuntimeConfig load_runtime_config(const std::string& path)
{
    RuntimeConfig cfg;

    std::ifstream file(path);
    if (!file.is_open()) {
        // Safe default: simulation OFF
        return cfg;
    }

    nlohmann::json j;
    file >> j;

    if (j.contains("simulation")) {
        auto sim = j["simulation"];

        cfg.simulation_enabled = sim.value("enabled", false);
        cfg.simulation_profile = sim.value("profile", "HEALTHY");
    }

    return cfg;
}

