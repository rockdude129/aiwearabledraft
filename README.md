# AI Wearable Glasses

A simple project to build AI-powered glasses using an ESP32-CAM with the XIAO ESP32S3 Sense module. Still a work in progress — more updates coming once parts arrive; read the very end to see more.

---

## What It Does

Captures a frame from the onboard camera, runs it through a MobileNetV1 object detection model, and prints what it sees to the Serial console.

## Hardware

- **AI Thinker ESP32-CAM** (OV2640 camera, 4MB PSRAM)
- **USB-to-TTL adapter** (for flashing and Serial monitor)

## Setup

1. Install the `TensorFlowLite_ESP32` library via the Arduino Library Manager
2. Set the board to **AI Thinker ESP32-CAM**, partition scheme to **Huge APP**
3. Add your TFLite model as a C byte array in `model_data.h` (see comments in that file)
4. Flash and open Serial monitor

## Files

- `esp32_camera_object_detection.ino` — main sketch
- `model_data.h` — model data and labels

## Example Output

```
Object  : cat
Score   : 0.87
```

## IMPORTANT NOTE
More research and development will go into the product once the parts come. I will use this as a basic sketch to finalize the product and then move onto more complex tasks such as face recognition, push notifications to mobile, and more.
