#pragma once
#include <string>

struct RuntimeConfig
{
    bool simulation_enabled = false;
    std::string simulation_profile = "HEALTHY";
};

// Declare function here
RuntimeConfig load_runtime_config(const std::string& path);
