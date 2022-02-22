# ESP32Servo
C++ Interface to control hobby-grade servo motors compatible with [Espressif's ESP32 SoC](https://www.espressif.com/en/products/hardware/esp32/overview) running [esp-idf](https://github.com/espressif/esp-idf)

## Getting Started
***NOTE: this code is not (yet) Production Ready.***   

You can use this as a [managed-component](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/tools/idf-component-manager.html) for your project by adding the following to your `idf_component.yml`:
```yaml
ESP32Servo:
  path: .
  git: https://github.com/ShellAddicted/ESP32Servo.git
```

Alternatively, you can use this as a component for your project: 
```bash
mkdir components/
cd components/
git clone https://github.com/ShellAddicted/ESP32Servo.git
```
for more details see [examples/](https://github.com/ShellAddicted/ESP32SimpleServo/tree/master/examples)  
