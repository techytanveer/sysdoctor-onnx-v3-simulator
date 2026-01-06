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
