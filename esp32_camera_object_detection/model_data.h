/**
 * model_data.h
 *
 * Embed a quantised TensorFlow Lite flatbuffer here.
 *
 * How to generate / obtain the model array:
 *
 *   1. Train or download a quantised MobileNetV1 (96x96 input, 80 COCO classes
 *      or a custom label set) from TensorFlow Hub or the TFLite Model Maker.
 *
 *   2. Convert the .tflite file to a C byte array with:
 *        xxd -i model.tflite > model_data.h
 *
 *   3. Rename the generated symbol so that it matches the names used in the
 *      main sketch:
 *        extern const unsigned char g_model_data[];
 *        extern const unsigned int  g_model_data_len;
 *
 *   4. Paste the generated array content below, replacing the placeholder.
 *
 * A ready-to-use 96×96 person-detection model is available inside the
 * Arduino_TensorFlowLite library examples:
 *   File → Examples → Arduino_TensorFlowLite → person_detection → model.h
 */

#ifndef MODEL_DATA_H
#define MODEL_DATA_H

// ---------------------------------------------------------------------------
// Replace this placeholder with the actual flatbuffer byte array produced by
// `xxd -i model.tflite`.
// ---------------------------------------------------------------------------
alignas(8) const unsigned char g_model_data[] = {
    /* INSERT YOUR MODEL BYTES HERE */
    0x00
};
const unsigned int g_model_data_len = sizeof(g_model_data);

// ---------------------------------------------------------------------------
// Label strings for the model outputs.
// Edit this list to match the classes your model was trained on.
// The index of each label must correspond to the model output tensor index.
// ---------------------------------------------------------------------------
const char* const g_labels[] = {
    "person",
    "bicycle",
    "car",
    "motorbike",
    "aeroplane",
    "bus",
    "train",
    "truck",
    "boat",
    "traffic light",
    "fire hydrant",
    "stop sign",
    "parking meter",
    "bench",
    "bird",
    "cat",
    "dog",
    "horse",
    "sheep",
    "cow",
    "elephant",
    "bear",
    "zebra",
    "giraffe",
    "backpack",
    "umbrella",
    "handbag",
    "tie",
    "suitcase",
    "frisbee",
    "skis",
    "snowboard",
    "sports ball",
    "kite",
    "baseball bat",
    "baseball glove",
    "skateboard",
    "surfboard",
    "tennis racket",
    "bottle",
    "wine glass",
    "cup",
    "fork",
    "knife",
    "spoon",
    "bowl",
    "banana",
    "apple",
    "sandwich",
    "orange",
    "broccoli",
    "carrot",
    "hot dog",
    "pizza",
    "donut",
    "cake",
    "chair",
    "sofa",
    "pottedplant",
    "bed",
    "diningtable",
    "toilet",
    "tvmonitor",
    "laptop",
    "mouse",
    "remote",
    "keyboard",
    "cell phone",
    "microwave",
    "oven",
    "toaster",
    "sink",
    "refrigerator",
    "book",
    "clock",
    "vase",
    "scissors",
    "teddy bear",
    "hair drier",
    "toothbrush"
};
const int g_num_labels = sizeof(g_labels) / sizeof(g_labels[0]);

#endif  // MODEL_DATA_H
