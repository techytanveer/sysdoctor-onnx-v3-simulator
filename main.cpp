#include <iostream>
#include "../include/system_metrics.h"
#include "../include/ai_engine.h"
#include "../include/rules_config.h"
#include "../include/runtime_config.h"
#include "../include/simulator.h"

int main() {
    std::cout << "🧠 AI System Doctor (Configurable Rules)\n";
    std::cout << "=======================================\n";


    RuntimeConfig runtime = load_runtime_config("config/runtime.json");

    SystemMetrics metrics;

    if (runtime.simulation_enabled) {
        std::cout << "⚠️  SIMULATION MODE ENABLED ("
                  << runtime.simulation_profile << ")\n";

        metrics = simulate_profile(runtime.simulation_profile);
    } else {
        metrics = collect_metrics();
    }


    RulesConfig rules = load_rules_config("rules.json");

    auto diagnoses = run_ai_engine(metrics, rules);

    for (const auto& d : diagnoses) {
        std::cout << "\n❗ Problem : " << d.problem;
        std::cout << "\n🔍 Cause   : " << d.cause;
        std::cout << "\n✅ Fix     : " << d.solution << "\n";
    }

    return 0;
}

