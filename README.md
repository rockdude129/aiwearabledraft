# aiwearabledraft
Simple draft of the AI wearable glasses – will add more once the parts arrive.

---

## esp32_camera_object_detection

An Arduino sketch that runs on an **AI Thinker ESP32-CAM** board.  
It captures a frame from the built-in OV2640 camera, classifies the scene
with a quantised MobileNetV1 model via **TensorFlow Lite for Microcontrollers**,
and prints the top predicted object label and confidence score to the Serial
console.

### Hardware

| Item | Notes |
|------|-------|
| AI Thinker ESP32-CAM | Built-in OV2640 camera, 4 MB PSRAM |
| USB-to-TTL adapter | For programming and Serial monitor (3.3 V logic) |

### Required Libraries

Install these through **Sketch → Include Library → Manage Libraries…** in the
Arduino IDE:

| Library | Minimum version | Author |
|---------|-----------------|--------|
| `TensorFlowLite_ESP32` | 0.9.0 | TensorFlow / Espressif |
| ESP32 board support (`esp32`) | 2.x | Espressif |

### Board Settings (Tools menu)

| Setting | Value |
|---------|-------|
| Board | AI Thinker ESP32-CAM |
| Partition Scheme | Huge APP (3 MB No OTA / 1 MB SPIFFS) |
| Upload Speed | 115200 |

### Adding a Model

1. Obtain a quantised (int8) MobileNetV1 TFLite model trained on 96 × 96
   greyscale images.  A ready-to-use **person-detection** model ships with the
   `Arduino_TensorFlowLite` library examples.
2. Convert the `.tflite` file to a C byte array:
   ```bash
   xxd -i model.tflite > model_data.h
   ```
3. Open `model_data.h` and rename the generated symbols to match:
   ```c
   alignas(8) const unsigned char g_model_data[] = { … };
   const unsigned int g_model_data_len = sizeof(g_model_data);
   ```
4. Edit the `g_labels[]` array in `model_data.h` so that each index matches
   the corresponding output class of your model.

### Expected Serial Output

```
[INFO] ESP32-CAM Object Detection starting…
[INFO] Camera ready.
[INFO] TFLite model loaded. Input: 96x96x1  Output classes: 80
---- Detection result ----
Object  : cat
Score   : 0.87
--------------------------
---- Detection result ----
Object  : cat
Score   : 0.91
--------------------------
```

### File Overview

```
esp32_camera_object_detection/
├── esp32_camera_object_detection.ino   # Main Arduino sketch
└── model_data.h                        # Model byte array + label list
```
