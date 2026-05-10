# AI Wearable Glasses

A simple project to build AI-powered glasses using an ESP32-CAM with the XIAO ESP32S3 Sense module. Still a work in progress — more updates coming once parts arrive; read the very end to see more.

---
## What makes it different
<img width="679" height="263" alt="image" src="https://github.com/user-attachments/assets/7f3ef297-3a7f-4fd1-8b78-79ba07ab8dcb" />
<img width="1362" height="634" alt="image" src="https://github.com/user-attachments/assets/0bdfefe5-55b9-4313-bfc6-7691f3f5a0b2" />
This image describes it. I am using my own glasses and modifying them to fit my needs, making the glasses beautifully work.

## What It Does

Captures a frame from the onboard camera, runs it through a MobileNetV1 object detection model, and prints what it sees to the Serial console.

## Hardware

- **ESP32-SENSE CAM and Microcontroller** (OV2640 camera, 4MB PSRAM)
- **USB-to-TTL adapter** (for flashing and Serial monitor) - (or USB to UART driver if Type-C)

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
## Materials used to Make this Project
*Please refer to the BOM.csv ; Below is an easy to see visual
<img width="1033" height="107" alt="image" src="https://github.com/user-attachments/assets/4ba3cea6-3e66-435d-87db-6d91bcc6f05a" />


https://a.co/d/00o7x7ok - The Glasses!

https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html - The Microcontroller!

With these two things, you can get an extremely smart piece of tech!

## IMPORTANT NOTE
More research and development will go into the product once the parts come. I will use this as a basic sketch to finalize the product and then move onto more complex tasks such as face recognition, push notifications to mobile, and more.
