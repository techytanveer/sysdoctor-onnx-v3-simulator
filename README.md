# sysdoctor-onnx-v3-simulator
I wanted to simulate risk scenarios cleanly, without touching real hardware, and without breaking Rules-Based AI in json; by forcing ONNX ML to see Unhealthy-Patterns. Therefore, I thought to introduce a toggle in JSON and simulate by intentionally exceeding normal thresholds.
----------------------------------
Goal:
1- Force ONNX ML to see unhealthy patterns
2- Verify: The model loads > Inference runs > Labels change as expected > Hybrid logic behaves correctly
----------------------------------

Now I have fully functional, configurable SysDoctor ONNX setup with:

Option-A Rule-based AI ✅

Option-B ML inference (ONNX) ✅

Simulation profiles via JSON toggle ✅

No recompilation needed to switch modes ✅

-----------------------------------

Quick Tips

No recompilation needed — JSON toggle controls mode.

Try multiple profiles:

"profile": "OVERHEAT"
"profile": "HIGH_LOAD"
"profile": "DISK_PRESSURE"

Optional: add verbose flag in JSON if you want more metric logging.

{
  "simulation": {
    "enabled": true,
    "profile": "UNHEALTHY"
  }
}

| Mode       | How to toggle                | Behavior                       |
| ---------- | ---------------------------- | ------------------------------ |
| Simulation | runtime.json → enabled:true  | Injects fake unhealthy metrics |
| Normal     | runtime.json → enabled:false | Uses real system metrics       |


**Map for SysDoctor ONNX Version
**
Linux system diagnostics tool using Rule-based AI + ML inference (ONNX) + Simulator

**Key Features
**
Rule-based AI
Offline ML inference
JSON-based configuration (runtime toggle & rules)
Modular / future-ready for LLM explanations

**Architecture Overview
**
ASCII diagram showing:

System Metrics
     ↓
Rule Engine (Option A)
     ↓
ONNX ML Inference (Option B)
     ↓
Diagnosis Aggregation
     ↓
Human-Readable Output

**Project Structure
**

sysdoctoronnx/
├── src/
│   ├── main.cpp
│   ├── metrics.cpp/h
│   ├── ai_engine.cpp/h
│   ├── onnx_engine.cpp/h
│   ├── runtime_config.cpp/h
│   ├── simulator.cpp/h
│   └── rules_config.cpp/h
├── include/
│   └── *.h
├── model/
│   └── sysdoctor_model.onnx
├── config/
│   └── runtime.json
│   └── rules.json
├── CMakeLists.txt
└── README.md

**Running**

Simulation Mode via config/runtime.json
Normal Mode for real metrics
CLI / JSON toggle explanation
Example output for simulation and real system

**Configuration**

rules.json → threshold values for rules
runtime.json → simulation toggle & profile
Safe defaults, profile options

**Training / Creating ONNX Model
**

Python training script (offline)
Frameworks used (scikit-learn, skl2onnx)
Export to ONNX
Clarify: Python not needed at runtime

**Security & Privacy
**

Fully offline
No telemetry
Safe for enterprise / air-gapped systems
