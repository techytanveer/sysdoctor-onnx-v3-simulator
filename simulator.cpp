#include "../include/system_metrics.h"
#include <string>

SystemMetrics simulate_profile(const std::string& profile)
{
    SystemMetrics m{};

    if (profile == "HIGH_LOAD") {
        m.cpu_usage = 95;
        m.load_1min = 7.0;
    }
    else if (profile == "OVERHEAT") {
        m.cpu_temp = 92;
    }
    else if (profile == "DISK_PRESSURE") {
        m.disk_usage = 96;
    }
    else if (profile == "UNHEALTHY") {
        m.cpu_usage    = 92;
        m.cpu_temp     = 88;
        m.ram_usage    = 90;
        m.disk_usage   = 94;
        m.load_1min    = 6.5;
        m.uptime_hours = 980;
    }
    else {
        // HEALTHY default
        m.cpu_usage = 20;
        m.cpu_temp = 45;
        m.ram_usage = 35;
        m.disk_usage = 40;
        m.load_1min = 0.8;
        m.uptime_hours = 120;
    }

    return m;
}

