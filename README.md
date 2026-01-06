# sysdoctor-onnx-v3-simulator
I wanted to simulate risk scenarios cleanly, without touching real hardware, and without breaking Rules-Based AI in json; by forcing ONNX ML to see Unhealthy-Patterns. Therefore, I thought to introduce a toggle in JSON and simulate by intentionally exceeding normal thresholds.
----------------------------------
🧠 Goal:
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



